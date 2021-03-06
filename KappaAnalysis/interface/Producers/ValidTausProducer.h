
#pragma once

#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/regex.hpp>

#include "Kappa/DataFormats/interface/Kappa.h"

#include "Artus/KappaAnalysis/interface/KappaProducerBase.h"
#include "Artus/KappaAnalysis/interface/Utility/ValidPhysicsObjectTools.h"
#include "Artus/KappaAnalysis/interface/Consumers/KappaLambdaNtupleConsumer.h"
#include "Artus/Utility/interface/SafeMap.h"
#include "Artus/Utility/interface/Utility.h"

/**
   \brief GlobalProducer, for valid taus.
   
   Required config tags in addtion to the ones of the base class:
   - ValidTausInput (default: auto)
   - TauDiscriminators
   - TauLowerPtCuts
   - TauUpperAbsEtaCuts
   - DirectIso
*/
class ValidTausProducer: public KappaProducerBase, public ValidPhysicsObjectTools<KappaTypes, KTau>
{

public:

	enum class ValidTausInput : int
	{
		AUTO = 0,
		UNCORRECTED = 1,
		CORRECTED = 2,
	};
	static ValidTausInput ToValidTausInput(std::string const& validTausInput)
	{
		if (validTausInput == "uncorrected") return ValidTausInput::UNCORRECTED;
		else if (validTausInput == "corrected") return ValidTausInput::CORRECTED;
		else return ValidTausInput::AUTO;
	}

	virtual std::string GetProducerId() const ARTUS_CPP11_OVERRIDE {
		return "ValidTausProducer";
	}
	
	ValidTausProducer() :
		KappaProducerBase(),
		ValidPhysicsObjectTools<KappaTypes, KTau>(&KappaSettings::GetTauLowerPtCuts,
		                                    &KappaSettings::GetTauUpperAbsEtaCuts,
		                                    &KappaProduct::m_validTaus)
	{
	}
	
	virtual void Init(KappaSettings const& settings)  ARTUS_CPP11_OVERRIDE
	{
		KappaProducerBase::Init(settings);
		ValidPhysicsObjectTools<KappaTypes, KTau>::Init(settings);
		
		validTausInput = ToValidTausInput(boost::algorithm::to_lower_copy(boost::algorithm::trim_copy(settings.GetValidTausInput())));
	
		// parse additional config tags
		discriminatorsByIndex = Utility::ParseMapTypes<size_t, std::string>(Utility::ParseVectorToMap(settings.GetTauDiscriminators()),
		                                                                    discriminatorsByHltName);
		
		// add possible quantities for the lambda ntuples consumers
		LambdaNtupleConsumer<KappaTypes>::AddIntQuantity("nTaus", [](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validTaus.size();
		} );
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("leadingTauPt", [](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validTaus.size() >= 1 ? product.m_validTaus[0]->p4.Pt() : DefaultValues::UndefinedDouble;
		});
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("leadingTauEta", [](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validTaus.size() >= 1 ? product.m_validTaus[0]->p4.Eta() : DefaultValues::UndefinedDouble;
		});
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("trailingTauPt", [](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validTaus.size() >= 2 ? product.m_validTaus[1]->p4.Pt() : DefaultValues::UndefinedDouble;
		});
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("trailingTauEta", [](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validTaus.size() >= 2 ? product.m_validTaus[1]->p4.Eta() : DefaultValues::UndefinedDouble;
		});
	}

	virtual void Produce(KappaEvent const& event, KappaProduct& product,
	                     KappaSettings const& settings) const ARTUS_CPP11_OVERRIDE
	{
		assert(event.m_taus);
		assert(event.m_tauMetadata);
	
		// select input source
		std::vector<KTau*> taus;
		if ((validTausInput == ValidTausInput::AUTO && (product.m_correctedTaus.size() > 0)) || (validTausInput == ValidTausInput::CORRECTED))
		{
			taus.resize(product.m_correctedTaus.size());
			size_t tauIndex = 0;
			for (std::vector<std::shared_ptr<KTau> >::iterator tau = product.m_correctedTaus.begin();
			     tau != product.m_correctedTaus.end(); ++tau)
			{
				taus[tauIndex] = tau->get();
				++tauIndex;
			}
		}
		else
		{
			taus.resize(event.m_taus->size());
			size_t tauIndex = 0;
			for (KTaus::iterator tau = event.m_taus->begin(); tau != event.m_taus->end(); ++tau)
			{
				taus[tauIndex] = &(*tau);
				++tauIndex;
			}
		}
		
		for (std::vector<KTau*>::iterator tau = taus.begin(); tau != taus.end(); ++tau)
		{
			bool validTau = true;
			
			// check discriminators
			for (std::map<size_t, std::vector<std::string> >::const_iterator discriminatorByIndex = discriminatorsByIndex.begin();
				 validTau && (discriminatorByIndex != discriminatorsByIndex.end()); ++discriminatorByIndex)
			{
				if (discriminatorByIndex->first == product.m_validTaus.size())
				{
					validTau = validTau && ApplyDiscriminators(*tau, discriminatorByIndex->second, event);
				}
			}
			
			for (std::map<std::string, std::vector<std::string> >::const_iterator discriminatorByHltName = discriminatorsByHltName.begin();
				 validTau && (discriminatorByHltName != discriminatorsByHltName.end()); ++discriminatorByHltName)
			{
				if ((discriminatorByHltName->first == "default") ||
					boost::regex_search(product.m_selectedHltName, boost::regex(discriminatorByHltName->first, boost::regex::icase | boost::regex::extended)))
				{
					validTau = validTau && ApplyDiscriminators(*tau, discriminatorByHltName->second, event);
				}
			}
			
			// kinematic cuts
			validTau = validTau && this->PassKinematicCuts(*tau, event, product);
			
			// check possible analysis-specific criteria
			validTau = validTau && AdditionalCriteria(*tau, event, product, settings);
			
			if (validTau)
			{
				product.m_validTaus.push_back(*tau);
			}
			else
			{
				product.m_invalidTaus.push_back(*tau);
			}
		}
	}


protected:
	
	// Can be overwritten for analysis-specific use cases
	virtual bool AdditionalCriteria(KTau* tau, KappaEvent const& event,
	                                KappaProduct& product, KappaSettings const& settings) const
	{
		bool validTau = true;
		return validTau;
	}


private:
	ValidTausInput validTausInput;
	
	std::map<size_t, std::vector<std::string> > discriminatorsByIndex;
	std::map<std::string, std::vector<std::string> > discriminatorsByHltName;
	
	bool ApplyDiscriminators(KTau* tau, std::vector<std::string> const& discriminators,
	                         KappaEvent const& event) const
	{
		bool validTau = true;
		
		for (std::vector<std::string>::const_iterator discriminator = discriminators.begin();
		     validTau && (discriminator != discriminators.end()); ++discriminator)
		{
			validTau = validTau && tau->getId(*discriminator, event.m_tauMetadata);
		}
		
		return validTau;
	}

};

