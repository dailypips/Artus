
#pragma once

#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/regex.hpp>

#include <Math/VectorUtil.h>

#include "Kappa/DataFormats/interface/Kappa.h"

#include "Artus/KappaAnalysis/interface/KappaProducerBase.h"
#include "Artus/KappaAnalysis/interface/Utility/ValidPhysicsObjectTools.h"
#include "Artus/KappaAnalysis/interface/Consumers/KappaLambdaNtupleConsumer.h"
#include "Artus/Utility/interface/Utility.h"
#include "Artus/KappaAnalysis/interface/KappaProduct.h"

/**
   \brief Producer for valid jets.
   
   Valid jets pass the particle flow JetID ("tight", "medium" or "loose") by JetMET. There are no
   pileupJetID requirements applied at the moment.

   This producer requires the "JetID" config tag to be set to "tight", "medium" or "loose".
   
   This producer should be run after the ValidElectronsProducer, ValidMuonsProducer and ValidTausProducer,
   because it cleans the list of jets according to the valid leptons.
   
   This is a templated base version. Use the actual versions for KBasicJets or KJets
   at the end of this file.
*/


template<class TJet, class TValidJet>
class ValidJetsProducerBase: public KappaProducerBase, public ValidPhysicsObjectTools<KappaTypes, TValidJet>
{

public:

	enum class ValidJetsInput : int
	{
		AUTO = 0,
		UNCORRECTED = 1,
		CORRECTED = 2,
	};
	static ValidJetsInput ToValidJetsInput(std::string const& validJetsInput)
	{
		if (validJetsInput == "uncorrected") return ValidJetsInput::UNCORRECTED;
		else if (validJetsInput == "corrected") return ValidJetsInput::CORRECTED;
		else return ValidJetsInput::AUTO;
	}

	enum class JetID : int
	{
		NONE  = -1,
		TIGHT = 0,
		MEDIUM = 1,
		LOOSE  = 2,
	};
	enum class JetIDVersion : int
	{
		ID2010 = 0,
		ID2014 = 1,
	};

	static JetID ToJetID(std::string const& jetID)
	{
		if (jetID == "tight") return JetID::TIGHT;
		else if (jetID == "medium") return JetID::MEDIUM;
		else if (jetID == "loose") return JetID::LOOSE;
		else return JetID::NONE;
	}

	static JetIDVersion ToJetIDVersion(std::string const& jetIDVersion)
	{
		if (jetIDVersion == "2010") return JetIDVersion::ID2010;
		else if (jetIDVersion == "2014") return JetIDVersion::ID2014;
		else return JetIDVersion::ID2010;
	}
	ValidJetsProducerBase(std::vector<TJet>* KappaEvent::*jets,
	                      std::vector<std::shared_ptr<TJet> > KappaProduct::*correctJets,
	                      std::vector<TValidJet*> KappaProduct::*validJets) :
		KappaProducerBase(),
		ValidPhysicsObjectTools<KappaTypes, TValidJet>(&KappaSettings::GetJetLowerPtCuts,
		                                               &KappaSettings::GetJetUpperAbsEtaCuts,
		                                               validJets),
		m_basicJetsMember(jets),
		m_correctedJetsMember(correctJets)
	{
	}

	virtual void Init(KappaSettings const& settings) ARTUS_CPP11_OVERRIDE
	{
		KappaProducerBase::Init(settings);
		ValidPhysicsObjectTools<KappaTypes, TValidJet>::Init(settings);
		
		validJetsInput = ToValidJetsInput(boost::algorithm::to_lower_copy(boost::algorithm::trim_copy(settings.GetValidJetsInput())));
		jetID = ToJetID(boost::algorithm::to_lower_copy(boost::algorithm::trim_copy(settings.GetJetID())));
		jetIDVersion = ToJetIDVersion(boost::algorithm::to_lower_copy(boost::algorithm::trim_copy(settings.GetJetIDVersion())));
		
		// add possible quantities for the lambda ntuples consumers
		LambdaNtupleConsumer<KappaTypes>::AddIntQuantity("nJets",[](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validJets.size();
		} );
		LambdaNtupleConsumer<KappaTypes>::AddIntQuantity("nJets20",[this](KappaEvent const& event, KappaProduct const& product) {
			return KappaProduct::GetNJetsAbovePtThreshold(product.m_validJets, 20.0);
		} );
		LambdaNtupleConsumer<KappaTypes>::AddIntQuantity("nJets30",[this](KappaEvent const& event, KappaProduct const& product) {
			return KappaProduct::GetNJetsAbovePtThreshold(product.m_validJets, 30.0);
		} );
		
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("leadingJetPt",[](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validJets.size() >= 1 ? product.m_validJets.at(0)->p4.Pt() : DefaultValues::UndefinedDouble;
		} );
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("leadingJetEta",[](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validJets.size() >= 1 ? product.m_validJets.at(0)->p4.Eta() : DefaultValues::UndefinedDouble;
		} );
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("leadingJetPhi",[](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validJets.size() >= 1 ? product.m_validJets.at(0)->p4.Phi() : DefaultValues::UndefinedDouble;
		} );
		
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("trailingJetPt",[](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validJets.size() >= 2 ? product.m_validJets.at(1)->p4.Pt() : DefaultValues::UndefinedDouble;
		} );
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("trailingJetEta",[](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validJets.size() >= 2 ? product.m_validJets.at(1)->p4.Eta() : DefaultValues::UndefinedDouble;
		} );
		LambdaNtupleConsumer<KappaTypes>::AddFloatQuantity("trailingJetPhi",[](KappaEvent const& event, KappaProduct const& product) {
			return product.m_validJets.size() >= 2 ? product.m_validJets.at(1)->p4.Phi() : DefaultValues::UndefinedDouble;
		} );
	}

	virtual void Produce(KappaEvent const& event, KappaProduct& product,
	                     KappaSettings const& settings) const ARTUS_CPP11_OVERRIDE
	{
		assert((event.*m_basicJetsMember));
	
		// select input source
		std::vector<TJet*> jets;
		if ((validJetsInput == ValidJetsInput::AUTO && ((product.*m_correctedJetsMember).size() > 0)) || (validJetsInput == ValidJetsInput::CORRECTED))
		{
			jets.resize((product.*m_correctedJetsMember).size());
			size_t jetIndex = 0;
			for (typename std::vector<std::shared_ptr<TJet> >::iterator jet = (product.*m_correctedJetsMember).begin();
			     jet != (product.*m_correctedJetsMember).end(); ++jet)
			{
				jets[jetIndex] = jet->get();
				++jetIndex;
			}
		}
		else
		{
			jets.resize((event.*m_basicJetsMember)->size());
			size_t jetIndex = 0;
			for (typename std::vector<TJet>::iterator jet = (event.*m_basicJetsMember)->begin(); jet != (event.*m_basicJetsMember)->end(); ++jet)
			{
				jets[jetIndex] = &(*jet);
				++jetIndex;
			}
		}
		
		for (typename std::vector<TJet*>::iterator jet = jets.begin(); jet != jets.end(); ++jet)
		{
			bool validJet = true;

			// JetID
			// https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetID
			// jets, all eta
			float maxNeutralFraction = this->GetMaxNeutralFraction();
			
			validJet = validJet
					   && (*jet)->neutralHadronFraction + (*jet)->hfHadronFraction < maxNeutralFraction
					   && (*jet)->photonFraction + (*jet)->hfEMFraction < maxNeutralFraction
					   && (*jet)->nConstituents > 1;
			// jets, |eta| < 2.4 (tracker)
			if (std::abs((*jet)->p4.eta()) < 2.4)
			{
				validJet = validJet
						   && (*jet)->chargedHadronFraction > 0.0
						   && (*jet)->nCharged > 0
						   && (*jet)->electronFraction < 0.99;
			}
			if (jetIDVersion == JetIDVersion::ID2014) 
			{
				validJet = validJet
						   && (*jet)->muonFraction < 0.8
						   && (*jet)->electronFraction < 0.9;
			}
			
			// remove leptons from list of jets via simple DeltaR isolation
			for (std::vector<KLepton*>::const_iterator lepton = product.m_validLeptons.begin();
			     validJet && lepton != product.m_validLeptons.end(); ++lepton)
			{
				validJet = validJet && ROOT::Math::VectorUtil::DeltaR((*jet)->p4, (*lepton)->p4) > settings.GetJetLeptonLowerDeltaRCut();
			}
			
			// kinematic cuts
			validJet = validJet && this->PassKinematicCuts(*jet, event, product);
			
			// check possible analysis-specific criteria
			validJet = validJet && AdditionalCriteria(*jet, event, product, settings);

			if (validJet)
			{
				product.m_validJets.push_back(*jet);
			}
			else
			{
				product.m_invalidJets.push_back(*jet);
			}
		}
	}


protected:
	
	// Can be overwritten for analysis-specific use cases
	virtual bool AdditionalCriteria(TJet* jet, KappaEvent const& event,
	                                KappaProduct& product, KappaSettings const& settings) const
	{
		bool validJet = true;
		
		return validJet;
	}


private:
	std::vector<TJet>* KappaEvent::*m_basicJetsMember;
	std::vector<std::shared_ptr<TJet> > KappaProduct::*m_correctedJetsMember;
	
	ValidJetsInput validJetsInput;
	JetID jetID;
	JetIDVersion jetIDVersion;

	float GetMaxNeutralFraction() const
	{
		float maxNeutralFraction = 0.0;
		
		if (jetID == JetID::TIGHT)
		{
			maxNeutralFraction = 0.90;
		}
		else if (jetID == JetID::MEDIUM)
		{
			maxNeutralFraction = 0.95;
		}
		else if (jetID == JetID::LOOSE)
		{
			maxNeutralFraction = 0.99;
		}
		else if (jetID != JetID::NONE)
		{
			LOG(FATAL) << "Jet ID of type " << Utility::ToUnderlyingValue(jetID) << " not yet implemented!";
		}
		
		return maxNeutralFraction;
	}

};



/**
   \brief Producer for valid jets (simple PF jets).
   
   Operates on the vector event.m_basicJets.
*/
class ValidJetsProducer: public ValidJetsProducerBase<KBasicJet, KBasicJet>
{
public:
	ValidJetsProducer();
	
	virtual std::string GetProducerId() const ARTUS_CPP11_OVERRIDE;
};



/**
   \brief Producer for valid jets (tagged PF jets).
   
   Operates on the vector event.m_tjets.
   
   Required config tags:
   - PuJetIDs
   - JetTaggerLowerCuts
*/
class ValidTaggedJetsProducer: public ValidJetsProducerBase<KJet, KBasicJet>
{
public:
	
	ValidTaggedJetsProducer();
	
	virtual std::string GetProducerId() const ARTUS_CPP11_OVERRIDE;

	virtual void Init(KappaSettings const& settings) ARTUS_CPP11_OVERRIDE;


protected:
	
	// Can be overwritten for analysis-specific use cases
	virtual bool AdditionalCriteria(KJet* jet, KappaEvent const& event,
	                                KappaProduct& product, KappaSettings const& settings) const;

private:
	std::map<size_t, std::vector<std::string> > puJetIdsByIndex;
	std::map<std::string, std::vector<std::string> > puJetIdsByHltName;
	std::map<std::string, std::vector<float> > jetTaggerLowerCutsByTaggerName;
	std::map<std::string, std::vector<float> > jetTaggerUpperCutsByTaggerName;
	
	bool PassPuJetIds(KJet* jet, std::vector<std::string> const& puJetIds, KJetMetadata* taggerMetadata) const;

};


