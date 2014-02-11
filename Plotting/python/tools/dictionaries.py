# This module contains the dictionaries for the plotting framework

# Dictionary for the interaction with the root tuple
ntuple_dict = {
	'ptbalance': '(jet1pt/zpt)',
	'balresp': '(jet1pt/zpt)',
	'mpfresp': '(mpf)',
	'alpha': '(jet2pt/zpt)',
	'genbalance': '(matchedgenjet1pt/zpt)',
	'mpf-raw': '(rawmpf)',
	'jet1photonresponsefraction': '(jet1photonfraction*jet1pt/zpt)',
	'jet1chargedemresponsefraction': '(jet1chargedemfraction*jet1pt/zpt)',
	'jet1chargedhadresponsefraction': '(jet1chargedhadfraction*jet1pt/zpt)',
	'jet1neutralhadresponsefraction': '(jet1neutralhadfraction*jet1pt/zpt)',
	'jet1HFemresponsefraction': '(jet1HFemfraction*jet1pt/zpt)',
	'jet1HFhadresponsefraction': '(jet1HFhadfraction*jet1pt/zpt)',
	'deltaphi-jet1-jet2': '(abs(abs(abs(jet1phi-jet2phi)-TMath::Pi())-TMath::Pi()))',
	'deltaphi-z-MET': '(abs(abs(abs(zphi-METphi)-TMath::Pi())-TMath::Pi()))',
	'deltaphi-MET-rawMET': '(abs(abs(abs(METphi-rawMETphi)-TMath::Pi())-TMath::Pi()))',
	'jet1abseta': '(abs(jet1eta))',
	'jet2abseta': '(abs(jet2eta))',
	'recogen': '(jet1pt/genjet1pt)',
	'btag': 'combinedsecondaryvertexbjettag',
	'qgtag': 'qglikelihood',
	}

d_format = {
	'phi': '\phi',
	'pt': 'p_\mathrm{T}',
	'eta': '\eta',
	'delta':'\Delta',
}

#   Quantity:[ax_min, ax_max, Name, unit, z_min, z_max]
d_axes = {
	'abseta': [0.0, 5.5, r"$|\eta^\mathrm{%s}|$", ""],
	'absphi': [0, 3.141593, r"$|\phi^\mathrm{%s}|$", ""],
	'alpha': [0, 0.5, r"$p_\mathrm{T}^\mathrm{Jet 2}/p_\mathrm{T}^\mathrm{Z}$", ""],
	'bal': [0.0, 1.8, r"$p_\mathrm{T}$ balance", ""],
	'balparton': [0.0, 1.8, r"Matching parton$p_\mathrm{T}$ / GenZ $p_\mathrm{T}$ ", ""],
	'balrespjet2': [0, 1, r"$p_\mathrm{T}^\mathrm{Jet 2}/p_\mathrm{T}^{Z}$", ""],
	'balresp': [0.0, 1.8, r"$p_\mathrm{T}$ balance", ""],
	'balresp_ratio': [0.9, 1.1, r"$p_\mathrm{T}$ balance", ""],
	'baltwojet': [0.0, 1.8, r"$p_\mathrm{T}$ balance for 2 jets", ""],
	'chargedem': [0, 1, r"%s charged em fraction", ""],
	'chargedhad': [0, 1, r"%s charged hadron fraction", ""],
	'components-diff': [-0.1, 0.1, r"Leading Jet Components", ""],
	'components-response-diff': [-0.1, 0.1, r"jet fraction * response", ""],
	'components-diff-response': [-0.1, 0.1, r"Leading Jet Component Fraction * Response", ""],
	'components': [0, 1, r"Leading Jet ParticleFlow Component Fraction", ""],
	'components-response': [0, 1.2, r"Leading Jet Component Fraction * Response", ""],
	'constituents': [0, 60, r"Number of Jet Constituents", ""],
	'correction': [0.85, 1.02, "Correction factor", ""],
	'cut': [0, 1.1, r"Cut Inefficiency (%s)", ""],
	'datamcratio': [0.93, 1.07, r"data/MC ratio", ""],
	'deltaeta': [0, 15, r"$\Delta \eta(\mathrm{%s})$", ""],
	'deltaeta': [0, 5, r"$\Delta \eta(\mathrm{%s,\/ %s})$", ""],
	'deltaphi': [0, 3.141593, r"$\Delta \phi(\mathrm{%s,\/%s})$", ""],
	'deltar': [0, 20, r"$\Delta \/R(\mathrm{%s,\/ %s})$", ""],
	'electron': [0, 1, r"%s electron fraction", ""],
	'eta': [-5, 5, r"$\eta^\mathrm{%s}$", ""],
	'eventcount': [0, 1.1, r"Eventcount", ""],
	'events': [0, 1, r"Events", ""],
	'extrapol': [0.86, 1.04, r"Response", ""],
	'filters': [-0.5, 12.5, r"Filters", ""],
	'flavour': [-0.5, 24.5, r"Flavour", ""],
	'physflavour': [-0.5, 24.5, r"Flavour (Physics definition)", ""],
	'physflavourfrac': [0, 1, r"Flavour fraction (Physics definition)", ""],
	'algoflavour': [-0.5, 24.5, r"Flavour (Algorithmic definition)", ""],
	'algoflavourfrac': [0, 1, r"Flavour fraction (Algorithmic definition)", ""],
	'genalpha': [0, 0.4, r"$p_\mathrm{T}^\mathrm{GenJet 2}/p_\mathrm{T}^\mathrm{GenZ}$", ""],
	'genbal-tobalparton': [0.501, 1.501, r"Parton Response $p_\mathrm{T}^\mathrm{GenJet}/p_\mathrm{T}^\mathrm{Parton}$", ""],
	'genbal-toparton': [0.501, 1.501, r"Parton Response $p_\mathrm{T}^\mathrm{GenJet}/p_\mathrm{T}^\mathrm{Parton_1}$", ""],
	'genbalance': [0.7, 1.1, r"$p_\mathrm{T}$ balance (Gen Jet / Reco Z)", ""],
	'genbal': [0.501, 1.501, r"$p_\mathrm{T}$ balance (Gen Jet / Gen Z)", ""],
	'genjet1pt': [0, 250, r"$p_\mathrm{T}^\mathrm{Leading Gen Jet}$", 'GeV'],
	'genjet2pt': [0, 100, r"$p_\mathrm{T}^\mathrm{GenJet2}$", 'GeV'],
	'genmpf': [0.501, 1.501, r"Gen MPF Response", ""],
	'genzep': [0.0, 3.0, r"Zeppenfeld variable (Gen level)", ""],
	'genzetarapidityratio': [-4, 4, r"$\eta^\mathrm{GenZ} / y^\mathrm{GenZ}$", ""],
	'genzmass': [70, 110, r"$m^\mathrm{GenZ}$", "GeV"],
	'genzrapidity': [-4, 4, r"$y^\mathrm{GenZ}$", ""],
	'genzpt': [0, 250, r"$p_\mathrm{T}^\mathrm{GenZ}$", 'GeV'],
	'HFem': [0, 1, r"%s HF em fraction", ""],
	'HFhad': [0, 1, r"%s HF hadron fraction", ""],
	'jet1area': [0.6, 1, r"Leading Jet area", ""],
	'jet1charged': [0, 30, r"Charged constituents of the leading jet", ""],
	'jet1const': [0, 30, r"%Leading jet constituents", ""],
	'jet1pt': [0, 250, r"$p_\mathrm{T}^\mathrm{Leading Jet}$", 'GeV'],
	'jet2area': [0.6, 1, r"Second Jet area", ""],
	'jet2pt': [0, 100, r"$p_\mathrm{T}^\mathrm{Jet2}$", 'GeV'],
	'jet2ratio': [0, 0.4, r"$p_\mathrm{T}^\mathrm{Jet_2}/p_\mathrm{T}^{Z}$", ""],
	'jet3pt': [0, 100, r"$p_\mathrm{T}^\mathrm{Jet3}$", 'GeV'],
	'jetpt': [0, 250, r"$p_\mathrm{T}^\mathrm{Z}$", 'GeV'],
	'jetptabsdiff': [0, 100, r"$p_\mathrm{T}^\mathrm{Jet 1} - p_\mathrm{T}^{Jet 2}$", "GeV"],
	'jetptratio': [0, 10, r"$p_\mathrm{T}^\mathrm{Jet 1} / p_\mathrm{T}^{Jet 2}$", ""],
	'jetsvalid': [0, 100, r"Number of valid jets $n$", ""],
	'L1': [0, 1.2, r"L1 correction factor", ""],
	'L1abs': [0, 30, r"L1 absolute correction", "GeV"],
	'L1L2L3': [0, 1.2, r"L1L2L3 correction factor", ""],
	'L1L2L3abs': [-25, 25, r"L1L2L3 absolute correction", "GeV"],
	'L2': [0, 1.2, r"L2 correction factor", ""],
	'L2abs': [-25, 25, r"L2 absolute correction", "GeV"],
	'L3': [0, 1.2, r"L3 correction factor", ""],
	'L3abs': [-25, 25, r"L3 absolute correction", "GeV"],
	'matchedgenjet1pt': [0, 250, r"$p_\mathrm{T}^\mathrm{Matched Leading Gen Jet}$", 'GeV'],
	'METeta': [-0.1, 0.1, r"$\eta^\mathrm{MET}$", ""],
	'METfraction': [0, 0.2, r"MET / $E^T_Total$", ""],
	'METpt': [0, 80, r"$E_\mathrm{T}^\mathrm{miss}$", 'GeV'],
	'METpt-diff': [0, 10, r"$\Delta E_\mathrm{T}^\mathrm{miss}$ (TypeI-corrected - raw)", 'GeV'],
	'METsumEt': [0, 2500, r"$\sum E^\mathrm{T}$", "GeV"],
	'mpf': [0., 2., r"MPF Response", ""],
	'mpf-raw': [0.75, 1.2, r"MPF Response (no type I)", ""],
	'mpf-diff': [0., 0.1, r"TypeI-Correction", ""],
	'mpfresp-raw': [0.0, 1.8, r"MPF Response (raw MET)", ""],
	'mpfresp': [0.0, 1.8, r"MPF Response", ""],
	'muminuspt': [0, 250, r"$p_\mathrm{T}^\mathrm{\mu^-}$", 'GeV'],
	'mu1pt': [0, 250, r"$p_\mathrm{T}^\mathrm{\mu1}$", 'GeV'],
	'mu2pt': [0, 250, r"$p_\mathrm{T}^\mathrm{\mu2}$", 'GeV'],	'muon': [0, 1, r"%s muon fraction", ""],
	'muonsinvalid': [0, 5, "Number of invalid muons", ""],
	'muonsvalid': [0, 5, "Number of valid muons", ""],
	'mupluspt': [0, 250, r"$p_\mathrm{T}^\mathrm{\mu+}$", 'GeV'],
	'muresp': [0.501, 1.501, r"Muon Response $p_\mathrm{T}^\mathrm{\mu,reco}/p_\mathrm{T}^\mathrm{\mu,gen}$", ""],
	'neutralem': [0, 1, r"%s neutral em fraction", ""],
	'neutralhad': [0, 1., r"%s neutral hadron fraction", ""],
	'npv': [-0.5, 35.5, r"Number of Reconstructed Vertices $n_\mathrm{PV}$", ""],
	'npu': [-0.5, 35.5, r"Number of Pile-up Vertices $n_\mathrm{PU}$", ""],
	'nputruth': [-0.5, 35.5, r"Pile-up Truth (Poisson mean) $n_\mathrm{PU}^\mathrm{mean}$", ""],
	'parton': [0.0, 1.8, r"Leading parton$p_\mathrm{T}$ / $p_\mathrm{T}^\mathrm{GenZ}$ ", ""],
	'phi': [-3.141592653, 3.141592653, r"$\phi^\mathrm{%s}$", ""],
	'photon': [0, 1., r"%s photon fraction", ""],
	'photonresponse': [0, 1., r"%s photon fraction * response", ""],
	'pt': [0, 250, r"$p_\mathrm{T}^\mathrm{%s}$", 'GeV'],
	'ptbalance': [0., 2., r"$p_\mathrm{T}$ balance", ""],
	'ratio': [0.93, 1.07, r"%s / %s ratio", ""],
	'rawMETpt': [0, 80, r"$E_\mathrm{T}^\mathrm{miss}$ (RAW)", 'GeV'],
	'reco': [0, 35, r"Number of Reconstructed Vertices $n$", ""],
	'recogen': [0.501, 1.501, r"Jet Response $p_\mathrm{T}^\mathrm{RecoJet}/p_\mathrm{T}^\mathrm{GenJet}$", ""],
	'response': [0.84, 1.07, r"Jet Response", ""],
	'responseratio': [0.88, 1.07, r"data/MC ratio", ""],
	'resolution': [0, 0.3, r"Jet response resolution", ""],
	'resolutionratio': [.5, 1.5, r"Jet response resolution data/MC ratio", ""],
	'rho': [0, 30, r"$\rho$", "GeV"],
	'run': [190000, 210000, r"Run", ""],
	'subleadingjetspt': [0, 1000, r"$p_\mathrm{T}^\mathrm{Subleading Jets}$", 'GeV'],
	'sumEt': [0, 2500, r"$\sum E^\mathrm{T}$", "GeV"],
	'summedf': [0.8, 1.2, r"$%s$ fraction sum", ""],
	'summedfr': [0.8, 1.2, r"$%s$ fraction sum2", ""],
	'tagflavour': [-0.5, 24.5, r"Flavour (from tagging)", ""],
	'uept': [0, 250, r"$p_\mathrm{T}^\mathrm{Unclustered Energy}$", 'GeV'],
	'unc': [0, 0.25, r"Leading jet uncertainty", ''],
	'xsec': [0, 20, r"$n_\mathrm{Events} / \mathcal{L}$", "pb$^{-1}$"],
	'zeppenfeld': [0.0, 3, r"Zeppenfeld variable", ""],
	'zmass': [70, 110, r"$m^\mathrm{Z}$", "GeV"],
	'zones': [-0.5, 24.5, r"Tagging zone", ""],
	'zpt': [0, 1000, r"$p_\mathrm{T}^\mathrm{Z}$", 'GeV'],
	'oldbalresp': [0.0, 1.8, r"$p_\mathrm{T}$ balance (old version)", ""],
	'genbal_tobalparton': [0.0, 1.8, r"", ""],
	'genbal_toparton': [0.0, 1.8, r"", ""],
	'genquality': [0.0, 1.8, r"Distance of Parton/Z matching", ""],
	'genmpf': [0.75, 1.2, r"$MPF$ Response (Gen level)", ""],
	'zone': [-0.5, 24.5, r"Tagging Zones", ""],
	'zresp': [0.501, 1.501, r"Z Response $p_\mathrm{T}^\mathrm{Z, reco}/p_\mathrm{T}^\mathrm{Z,gen}$", ""],
	'zy': [-2.2, 2.2, r"$y^Z$", ""],
	}

d_plots = {
	   # plot:[arguments, function, name]
	'L1L2L3_npv': ["changes={'rebin': 1}"],
	'L1L2L3abs_npv': ["changes={'rebin': 1}"],
	'L1_npv': ["changes={'rebin': 1}"],
	'L2_npv': ["changes={'rebin': 1}"],
	'bal_twojet': ['legloc="lower right"'],
	'balresp': ['changes={"fit": "vertical"}'],
	'balresp_all': ['changes={"fit": "vertical"}', 'datamc_all', 'balresp'],
	'filters': ['rebin=1, legloc="upper left"'],
	'filters_all': ['rebin=1, legloc="upper left"', 'datamc_all', 'filters'],
	'jet1pt': ['changes={"log": True}'],
	'jet2eta_jet2phi': ['rebin=2'],
	'jet3pt': ['log=True, rebin=2'],
	'jeteta_jetphi': ['rebin=2'],
	'jetpt_zeta': ['rebin=5, legloc="upper left"'],
	'mpf-diff_alpha': ['rebin=2, changes={"var": "var_CutSecondLeadingToZPt_0_3"}'],
	'mpf_deltaphi-jet1-MET_all': ['', 'datamc_all', 'mpf_deltaphi-jet1-MET'],
	'mpf_deltaphi-z-MET_all': ['', 'datamc_all', 'mpf_deltaphi-z-MET'],
	'mpfresp': ['changes={"fit": "vertical"}'],
	'mpfresp-raw': ['fit="vertical"'],
	'mpfresp_all': ['', 'datamc_all', 'mpfresp'],
	'muminusphi': ['legloc="lower center"'],
	'npv': ["changes={'rebin': 1}"],
	'npv_nocuts': ["changes={'rebin': 1, 'folder': 'allevents'}", 'datamcplot', 'npv'],
	'tworesp': ['legloc="lower right"', 'datamcplot', 'bal_twojet'],
	'zresp': ['rebin=1, fit="vertical"'],
	'parton': ['fit="vertical"'],
	'balparton': ['fit="vertical"'],
	'genbal-tobalparton': ['fit="vertical"'],
	'genbal-tobalparton_alpha03': ['fit="vertical", changes={"var": "var_CutSecondLeadingToZPt_0_3"}', 'datamcplot', 'genbal-tobalparton'],
	}