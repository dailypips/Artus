#pragma once

#include "Kappa/DataFormats/interface/Kappa.h"

#include "Artus/Core/interface/FilterBase.h"
#include "Artus/KappaAnalysis/interface/KappaTypes.h"
#include "Artus/KappaAnalysis/interface/KappaEnumTypes.h"


class BeamScrapingFilter: public FilterBase<KappaTypes>
{
public:
	virtual std::string GetFilterId() const ARTUS_CPP11_OVERRIDE;
	virtual void Init(setting_type const& settings) ARTUS_CPP11_OVERRIDE;
	virtual bool DoesEventPass(KappaEvent const& event, KappaProduct const& product,
	                           KappaSettings const& settings) const ARTUS_CPP11_OVERRIDE;
private:
	double m_purityRatio;
};
