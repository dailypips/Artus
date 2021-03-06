
#pragma once

#include "Kappa/DataFormats/interface/Kappa.h"

#include "Artus/KappaAnalysis/interface/KappaProducerBase.h"


/**
   \brief Producer for electron four momentum corrections.
   
   (No correction implemented yet.)
*/
class ElectronCorrectionsProducer: public KappaProducerBase
{

public:

	virtual std::string GetProducerId() const ARTUS_CPP11_OVERRIDE;
	
	virtual void Init(KappaSettings const& settings)  ARTUS_CPP11_OVERRIDE;

	virtual void Produce(KappaEvent const& event, KappaProduct & product,
	                     KappaSettings const& settings) const ARTUS_CPP11_OVERRIDE;


protected:

	// Can be overwritten for analysis-specific use cases
	virtual void AdditionalCorrections(KElectron* electron, KappaEvent const& event,
	                                   KappaProduct& product, KappaSettings const& settings) const
	{
	}

};

