
#pragma once

#include "Artus/Configuration/interface/SettingsBase.h"
#include "Artus/Configuration/interface/SettingMacros.h"
#include "Artus/Configuration/interface/PropertyTreeSupport.h"

/**
   \brief Reads settings for all parts of the KappaAnalysis code from a prepared
   json configuration file. 

   Defines settings that can be obtained from the json configuration file.
*/

class KappaSettings: public SettingsBase {
public:

	IMPL_SETTING_DEFAULT(bool, BatchMode, false);
	
	IMPL_SETTING(std::string, Nickname);

	/// name of electron collection in kappa tuple	
	IMPL_SETTING_DEFAULT(std::string, Electrons, "");
    IMPL_SETTING_DEFAULT(std::string, ElectronMetadata, "");

	/// name of muon collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, Muons, "");

	/// name of tau collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, Taus, "");
	IMPL_SETTING_DEFAULT(std::string, TauMetadata, "");
	IMPL_SETTING_DEFAULT(std::string, GenTaus, "");
	IMPL_SETTING_DEFAULT(std::string, GenTauJets, "");

	/// name of jet collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, BasicJets, "");
	IMPL_SETTING_DEFAULT(std::string, GenJets, "");

	/// name of tagged jet collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, TaggedJets, "");

	/// name of pileup density branch in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, PileupDensity, "");

	/// name of MET collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, Met, "");
	
	/// name of GenMET collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, GenMet, "");

	/// names of PF candidate collections in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, PFChargedHadronsPileUp, "");
	IMPL_SETTING_DEFAULT(std::string, PFChargedHadronsNoPileUp, "");
	IMPL_SETTING_DEFAULT(std::string, PFNeutralHadronsNoPileUp, "");
	IMPL_SETTING_DEFAULT(std::string, PFPhotonsNoPileUp, "");

	/// name of beamspot collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, BeamSpot, "");

	/// name of vertexSummary collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, VertexSummary, "");
	
	/// name of track summary collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, TrackSummary, "");

	/// name of HCALNoise summary collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, HCALNoiseSummary, "");

	/// name of trigger infos and objects collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, TriggerInfos, "");
	IMPL_SETTING_DEFAULT(std::string, TriggerObjects, "");

	/// name of genParticle collection in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, GenParticles, "");

	/// name of eventMetaData in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, EventMetadata, "");

	/// name of lumiMetaData in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, LumiMetadata, "");

	/// name of filterMetaData in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, FilterMetadata, "");

	/// name of filterSummary in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, FilterSummary, "");

	/// name of TaggerMetaData in kappa tuple
	IMPL_SETTING_DEFAULT(std::string, JetMetadata, "");


	IMPL_SETTING_DEFAULT(float, CrossSection, -1.);
	IMPL_SETTING(int, NumberGeneratedEvents);
	
	IMPL_SETTING_STRINGLIST(JsonFiles);
	IMPL_SETTING_DEFAULT(int, PassRunLow, 0);
	IMPL_SETTING_DEFAULT(int, PassRunHigh, 0);
	
	// Good Primary Vertex Filter
	IMPL_SETTING(float, MaxPrimaryVertexZ);
	IMPL_SETTING(float, MaxPrimaryVertexRho);
	IMPL_SETTING(int, MinPrimaryVertexFitnDOF);

	// Beam Scraping Filter
	IMPL_SETTING(double, MinPurityRatio);

	IMPL_SETTING_UINT64LIST(RunWhitelist);
	IMPL_SETTING_UINT64LIST(RunBlacklist);
	IMPL_SETTING_UINT64LIST(LumiWhitelist);
	IMPL_SETTING_UINT64LIST(LumiBlacklist);
	IMPL_SETTING_UINT64LIST(EventWhitelist);
	IMPL_SETTING_UINT64LIST(EventBlacklist);
	IMPL_SETTING_DEFAULT(bool, MatchRunLumiEventTuples, false);
	
	IMPL_SETTING_STRINGLIST(HltPaths);
	IMPL_SETTING_DEFAULT(bool, AllowPrescaledTrigger, true);
	
	IMPL_SETTING_STRINGLIST(ElectronTriggerFilterNames);
	IMPL_SETTING_STRINGLIST(MuonTriggerFilterNames);
	IMPL_SETTING_STRINGLIST(TauTriggerFilterNames);
	IMPL_SETTING_STRINGLIST(JetTriggerFilterNames);
	
	IMPL_SETTING_DEFAULT(float, DeltaRTriggerMatchingElectrons, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRTriggerMatchingMuons, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRTriggerMatchingTaus, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRTriggerMatchingJets, 0.5);
	
	IMPL_SETTING_DEFAULT(bool, InvalidateNonMatchingElectrons, true);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonMatchingMuons, true);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonMatchingTaus, true);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonMatchingJets, true);
	
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoElectronsGenParticle, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoMuonGenParticle, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoTauGenParticle, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoJetGenParticle, 0.3);
	
	IMPL_SETTING_DEFAULT(std::string, JetMatchingAlgorithm, "algorithmic");
	
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenParticleMatchingRecoElectrons, false);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenParticleMatchingRecoMuons, false);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenParticleMatchingRecoTaus, false);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenParticleMatchingRecoJets, false);

	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoElectronGenTau, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoMuonGenTau, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoTauGenTau, 0.5);
	
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenTauMatchingRecoElectrons, false);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenTauMatchingRecoMuons, false);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenTauMatchingRecoTaus, false);

	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoElectronGenTauJet, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoMuonGenTauJet, 0.5);
	IMPL_SETTING_DEFAULT(float, DeltaRMatchingRecoTauGenTauJet, 0.5);
	
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenTauJetMatchingRecoElectrons, false);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenTauJetMatchingRecoMuons, false);
	IMPL_SETTING_DEFAULT(bool, InvalidateNonGenTauJetMatchingRecoTaus, false);
	
	IMPL_SETTING(int, Year);
	
	IMPL_SETTING(bool, DirectIso);
	
	IMPL_SETTING_DEFAULT(std::string, ValidMuonsInput, "auto");
	IMPL_SETTING(std::string, MuonID);
	IMPL_SETTING(std::string, MuonIsoType);
	IMPL_SETTING(std::string, MuonIso);
	
	IMPL_SETTING_DEFAULT(std::string, ValidElectronsInput, "auto");
	IMPL_SETTING(std::string, ElectronID);
	IMPL_SETTING(std::string, ElectronIsoType);
	IMPL_SETTING(std::string, ElectronIso);
	IMPL_SETTING(std::string, ElectronReco);
	
	IMPL_SETTING_DEFAULT(std::string, ValidTausInput, "auto");
	IMPL_SETTING_STRINGLIST(TauDiscriminators);
	
	IMPL_SETTING_STRINGLIST(JetEnergyCorrectionParameters);
	IMPL_SETTING_DEFAULT(std::string, JetEnergyCorrectionUncertaintyParameters, "");
	IMPL_SETTING_DEFAULT(float, JetEnergyCorrectionUncertaintyShift, 0.0);
	
	IMPL_SETTING_DEFAULT(std::string, ValidJetsInput, "auto");
	IMPL_SETTING(std::string, JetID);
	IMPL_SETTING_DEFAULT(float, JetLeptonLowerDeltaRCut, -1.0);
	IMPL_SETTING_DEFAULT(std::string, JetIDVersion, "2010");
	IMPL_SETTING_STRINGLIST(PuJetIDs);
	IMPL_SETTING_STRINGLIST(JetTaggerLowerCuts);
	IMPL_SETTING_STRINGLIST(JetTaggerUpperCuts);
	
	IMPL_SETTING(int, NElectrons);
	IMPL_SETTING(int, NMuons);
	IMPL_SETTING(int, NTaus);
	IMPL_SETTING(int, NJets);
	
	IMPL_SETTING(int, MinNElectrons);
	IMPL_SETTING(int, MinNMuons);
	IMPL_SETTING(int, MinNTaus);
	IMPL_SETTING(int, MinNJets);
	
	IMPL_SETTING(int, MaxNElectrons);
	IMPL_SETTING(int, MaxNMuons);
	IMPL_SETTING(int, MaxNTaus);
	IMPL_SETTING(int, MaxNJets);
	
	IMPL_SETTING_DEFAULT(size_t, MinNMatchedElectrons, 0);
	IMPL_SETTING_DEFAULT(size_t, MinNMatchedMuons, 0);
	IMPL_SETTING_DEFAULT(size_t, MinNMatchedTaus, 0);
	IMPL_SETTING_DEFAULT(size_t, MinNMatchedJets, 0);
	
	IMPL_SETTING_STRINGLIST(ElectronLowerPtCuts);
	IMPL_SETTING_STRINGLIST(MuonLowerPtCuts);
	IMPL_SETTING_STRINGLIST(TauLowerPtCuts);
	IMPL_SETTING_STRINGLIST(JetLowerPtCuts);
	
	IMPL_SETTING_STRINGLIST(ElectronUpperAbsEtaCuts);
	IMPL_SETTING_STRINGLIST(MuonUpperAbsEtaCuts);
	IMPL_SETTING_STRINGLIST(TauUpperAbsEtaCuts);
	IMPL_SETTING_STRINGLIST(JetUpperAbsEtaCuts);
	
	IMPL_SETTING_DEFAULT(float, BTaggedJetAbsEtaCut, 0.0);
	IMPL_SETTING_DEFAULT(float, BTaggedJetCombinedSecondaryVertexMediumWP, 0.0);
	IMPL_SETTING_DEFAULT(bool, ApplyBTagSF, false);
	IMPL_SETTING(std::string, BTagSFMethod);
	IMPL_SETTING_DEFAULT(float, BTagShift, 0.0);
	IMPL_SETTING_DEFAULT(float, BMistagShift, 0.0);
	
	//Reading Boson PdgId for GenTauDecayProducer studies.
	IMPL_SETTING(int, BosonPdgId);
	
	/// Needed by the GenDiLeptonDecayModeFilter
	IMPL_SETTING(std::string, GenDiLeptonDecayMode);
	IMPL_SETTING_DEFAULT(bool, InvertGenDiLeptonDecayMode, false);

	IMPL_SETTING_STRINGLIST(GenParticleTypes);
	IMPL_SETTING_INTLIST(GenParticlePdgIds);
	IMPL_SETTING_DEFAULT(int, GenParticleStatus, 0);

	IMPL_SETTING(std::string, PileupWeightFile);
	
	IMPL_SETTING(std::string, EventWeight);

	// TMVA reader settings
	IMPL_SETTING_STRINGLIST(TmvaInputQuantities);
	IMPL_SETTING_STRINGLIST(TmvaMethods);
	IMPL_SETTING_STRINGLIST(TmvaWeights);
	
	// KappaCollectionsConsumer settings
	IMPL_SETTING_DEFAULT(bool, BranchGenMatchedElectrons, false);
	IMPL_SETTING_DEFAULT(bool, BranchGenMatchedMuons, false);
	IMPL_SETTING_DEFAULT(bool, BranchGenMatchedTaus, false);
	IMPL_SETTING_DEFAULT(bool, BranchGenMatchedJets, false);

};
