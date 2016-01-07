 ./ztree.exe data/pbpbmumudata.z.root mumupbpbdata.root pbpbdata &
 ./ztree.exe data/ppmumudata.z.root mumuppdata.root ppdata &
 ./ztree.exe mc/Pythia8_Z30mumuJet_pthat30Norm_TuneCUETP8M1_5020GeV_cff_FOREST_PrivMC_v4.z.root mumupbpbmc.root pbpbmc &
./ztree.exe Pythia8_Z30mumuJet_pthat30Norm_TuneCUETP8M1_5020GeV_cff_ppFOREST_PrivMC_v4.z.root mumuppmc.root ppmc &

wait

hadd -f all.root mumupbpbdata.root mumuppdata.root mumupbpbmc.root mumuppmc.root
