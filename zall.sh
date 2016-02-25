./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.HIPhoton40AndZ_HIRun2015-ZEE-PromptReco_FORESTjec_v8.root eepbpbdata.root eepbpbdata &
./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.HIRun2015-ZMM-PromptReco-v1-FOREST-v10.root mumupbpbdata.root mumupbpbdata &
./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.PromptReco-AOD-DielectronSkim_ppFORESTjec_v8.root eeppdata.root eeppdata &
./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.PromptReco-AOD-DimuonSkim-Mass40_ppFORESTjec_v8.root mumuppdata.root mumuppdata &
./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.Pythia8_Z30eeJet_pthat30Norm_TuneCUETP8M1_5020GeV_cff_FOREST_PrivMCjec_v9.root eepbpbmc.root eepbpbmc &
./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.Pythia8_Z30eeJet_pthat30Norm_TuneCUETP8M1_5020GeV_cff_ppFOREST_PrivMCjec_v9.root eeppmc.root eeppmc &
./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.Pythia8_Z30mumuJet_pthat30Norm_TuneCUETP8M1_5020GeV_cff_FOREST_PrivMCjec_v9.root mumupbpbmc.root mumupbpbmc &
./ztree.exe /export/d00/scratch/dav2105/quickZMacros/z.Pythia8_Z30mumuJet_pthat30Norm_TuneCUETP8M1_5020GeV_cff_ppFOREST_PrivMCjec_v9.root mumuppmc.root mumuppmc &

wait

hadd -f all.root mumupbpbdata.root mumuppdata.root mumupbpbmc.root mumuppmc.root eepbpbdata.root eeppdata.root eepbpbmc.root eeppmc.root
