/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */

#pragma once

#include "TFile.h"

#include "Artus/Core/interface/Cpp11Support.h"
#include "Artus/Configuration/interface/PropertyTreeSupport.h"
#include "Artus/Configuration/interface/SettingMacros.h"
#include "Artus/Configuration/interface/PropertyMacros.h"
#include "Artus/Configuration/interface/VarCache.h"

/**
   \brief Reads setting of local parts of PipelineRunner from a prepared json configuration file.

   Defines what is needed to read configurations for Artus event processing from a prepared json 
   file and passes it on to LocalProducers, Filters and Consumers.
*/

class SettingsUtil {
public:
	static stringvector ExtractFilters ( stringvector const& allProcessors );
};

class SettingsBase {
public:

	SettingsBase() :
			m_RootOutFile(ARTUS_CPP11_NULLPTR) {
	}

	SettingsBase( std::string const& name ) : m_Name ( name ),
			m_RootOutFile(ARTUS_CPP11_NULLPTR){
	}

	virtual ~SettingsBase() {
	}

	/// path in the config file to reach the settings for this pipeline
	IMPL_PROPERTY(std::string, PropTreePath)
	/// pointer to the global, loaded property tree
	IMPL_PROPERTY(boost::property_tree::ptree*, PropTree)

	/// pipeline level, the default if no entry is in the json file will be 1
	IMPL_SETTING_DEFAULT(size_t, Level, 1 )

	IMPL_PROPERTY( std::string, Name )

	IMPL_SETTING_DEFAULT( std::string , LogLevel, "unknown" )

	/// the folder name in the output root file where plots or ntuples of this pipeline will end 
	/// up, if you want it not to be the pipeline name, override it
	virtual std::string GetRootFileFolder() const {
		return GetName();
	}

	std::string GetPipelinePrefix() const {
		if ( GetName() == "")
			return "";
		else
			return  "Pipelines." + GetName() + ".";
	}

	/// a pointer to the root file where all the output will be stored must be set by the 
	/// application
	IMPL_PROPERTY(TFile *, RootOutFile)

	/// detemine whether this is data or MC
	IMPL_GLOBAL_SETTING(bool, InputIsData);

	virtual std::string ToString() const {
		return "SettingsBase - Pipeline name: " + GetName();
	}

	/// get list of all local producers
	IMPL_SETTING_STRINGLIST( Processors )
	IMPL_SETTING_STRINGLIST( Consumers )
	
	// list of quantities needed for ntuple consumers
	IMPL_SETTING_STRINGLIST(Quantities);
	//IMPL_SETTING_SORTED_STRINGLIST(Quantities);

	virtual stringvector GetFilters () const {
		return SettingsUtil::ExtractFilters(GetProcessors());
	}

	typedef std::pair < std::string, size_t > PipelineInfo;
	typedef std::vector<PipelineInfo> PipelineInfos;

	// returns the name and level of all pipelines
	// in the config file
	PipelineInfos GetPipelineInfos () const;

private:
	VarCache < PipelineInfos > m_pipelineInfos;

};

