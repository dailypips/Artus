
#pragma once

#include "Artus/Utility/interface/ArtusLogging.h"


/**
*/
class KappaEnumTypes {

public:

	enum class DiLeptonDecayMode : int
	{
		NONE = -1,
		EE = 0,
		MM = 1,
		TT = 2,
		LL = 3,
	};
	static DiLeptonDecayMode ToDiLeptonDecayMode(std::string const& diLeptonDecayMode)
	{
		if (diLeptonDecayMode == "ee") return DiLeptonDecayMode::EE;
		else if (diLeptonDecayMode == "mm") return DiLeptonDecayMode::MM;
		else if (diLeptonDecayMode == "tt") return DiLeptonDecayMode::TT;
		else if (diLeptonDecayMode == "ll") return DiLeptonDecayMode::LL;
		return DiLeptonDecayMode::NONE;
	}

};

