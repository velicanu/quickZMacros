#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TLorentzVector.h"
#include "TMath.h"

#include <iostream>
#include <string>
#include <vector>

void quickZAnalysis(const char *inFileName, const char *outName)
{
  TFile* inFile_p = new TFile(inFileName, "READ");
  TTree* photonTree_p = (TTree*)inFile_p->Get("ggHiNtuplizerGED/EventTree");
  TTree* hltTree_p = (TTree*)inFile_p->Get("hltanalysis/HltTree");

  Int_t nEle;
  std::vector<float>* elePt = 0;
  std::vector<float>* eleEta = 0;
  std::vector<float>* elePhi = 0;
  std::vector<float>* eleHoverE = 0;
  std::vector<float>* eleSigmaIEtaIEta_2012 = 0;
  std::vector<float>* eleEoverPInv =0;
  std::vector<float>* eledEtaAtVtx=0;
  std::vector<float>* eledPhiAtVtx=0;
  std::vector<float>* eleD0=0;
  std::vector<float>* eleDz=0;
  std::vector<int>* eleMissHits=0;
  std::vector<int>* eleCharge=0;

  photonTree_p->SetBranchStatus("*", 0);
  photonTree_p->SetBranchStatus("nEle", 1);
  photonTree_p->SetBranchStatus("elePt", 1);
  photonTree_p->SetBranchStatus("eleEta", 1);
  photonTree_p->SetBranchStatus("elePhi", 1);
  photonTree_p->SetBranchStatus("eleHoverE", 1);
  photonTree_p->SetBranchStatus("eleSigmaIEtaIEta_2012", 1);
  photonTree_p->SetBranchStatus("eleEoverPInv", 1);
  photonTree_p->SetBranchStatus("eledEtaAtVtx", 1);
  photonTree_p->SetBranchStatus("eledPhiAtVtx", 1);
  photonTree_p->SetBranchStatus("eleD0", 1);
  photonTree_p->SetBranchStatus("eleDz", 1);
  photonTree_p->SetBranchStatus("eleMissHits", 1);
  photonTree_p->SetBranchStatus("eleCharge", 1);

  photonTree_p->SetBranchAddress("nEle", &nEle);
  photonTree_p->SetBranchAddress("elePt", &elePt);
  photonTree_p->SetBranchAddress("eleEta", &eleEta);
  photonTree_p->SetBranchAddress("elePhi", &elePhi);
  photonTree_p->SetBranchAddress("eleHoverE", &eleHoverE);
  photonTree_p->SetBranchAddress("eleSigmaIEtaIEta_2012", &eleSigmaIEtaIEta_2012);
  photonTree_p->SetBranchAddress("eleEoverPInv", &eleEoverPInv);
  photonTree_p->SetBranchAddress("eledEtaAtVtx", &eledEtaAtVtx);
  photonTree_p->SetBranchAddress("eledPhiAtVtx", &eledPhiAtVtx);
  photonTree_p->SetBranchAddress("eleD0", &eleD0);
  photonTree_p->SetBranchAddress("eleDz", &eleDz);
  photonTree_p->SetBranchAddress("eleMissHits", &eleMissHits);
  photonTree_p->SetBranchAddress("eleCharge", &eleCharge);


  Int_t HLT_HIDoublePhoton15_Eta1p5_Mass50_1000_v1;
  Int_t HLT_HIDoublePhoton15_Eta2p5_Mass50_1000_R9SigmaHECut_v1;

  hltTree_p->SetBranchStatus("*", 0);
  hltTree_p->SetBranchStatus("HLT_HIDoublePhoton15_Eta1p5_Mass50_1000_v1", 1);
  hltTree_p->SetBranchStatus("HLT_HIDoublePhoton15_Eta2p5_Mass50_1000_R9SigmaHECut_v1", 1);

  hltTree_p->SetBranchAddress("HLT_HIDoublePhoton15_Eta1p5_Mass50_1000_v1", &HLT_HIDoublePhoton15_Eta1p5_Mass50_1000_v1);
  hltTree_p->SetBranchAddress("HLT_HIDoublePhoton15_Eta2p5_Mass50_1000_R9SigmaHECut_v1", &HLT_HIDoublePhoton15_Eta2p5_Mass50_1000_R9SigmaHECut_v1);


  const Double_t electronMass = 0.000510998;
  TH1F* zMass_p = new TH1F("zMass_p", ";Z Mass; Events", 130, 0, 130);


  Int_t nentries = photonTree_p->GetEntries();

  for(Int_t entry = 0; entry < nentries; entry++){
    if(entry%10000 == 0) std::cout << "entry: " << entry << std::endl;

    photonTree_p->GetEntry(entry);
    hltTree_p->GetEntry(entry);

    if(HLT_HIDoublePhoton15_Eta2p5_Mass50_1000_R9SigmaHECut_v1)
    {
      for(Int_t iter = 0; iter < nEle; iter++){
	float tempEt = elePt->at(iter);
	float tempEta = eleEta->at(iter);
	float tempPhi = elePhi->at(iter);

	float tempHoverE = eleHoverE->at(iter);
	float tempSigmaIEtaIEta = eleSigmaIEtaIEta_2012->at(iter);

	float tempEoverPInv = eleEoverPInv->at(iter);
	float tempDEtaAtVtx = eledEtaAtVtx->at(iter);
	float tempDPhiAtVtx = eledPhiAtVtx->at(iter);
	float tempD0 = eleD0->at(iter);
	float tempDz = eleDz->at(iter);
	int tempMissHits = eleMissHits->at(iter);
	int tempCharge = eleCharge->at(iter);

	// https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2#Working_points_for_Spring15_MC_s
	// medium 25ns settings.
	if(TMath::Abs(tempEta) < 1.4791)
	{
	  if(tempSigmaIEtaIEta >  0.0101 ) continue;
	  if(tempDEtaAtVtx >  0.0103 ) continue;
	  if(tempDPhiAtVtx >  0.0336 ) continue;
	  if(tempHoverE > 0.0876) continue;
	  if(tempEoverPInv >  0.0174 ) continue;
	  if(tempD0 > 0.0118) continue;
	  if(tempDz > 0.373) continue;
	  if(tempMissHits > 2) continue;
	} else {
	  if(tempSigmaIEtaIEta >  0.0283 ) continue;
	  if(tempDEtaAtVtx >  0.00733 ) continue;
	  if(tempDPhiAtVtx >  0.114 ) continue;
	  if(tempHoverE > 0.0678) continue;
	  if(tempEoverPInv >  0.0898 ) continue;
	  if(tempD0 > 0.0739) continue;
	  if(tempDz > 0.602) continue;
	  if(tempMissHits > 1) continue;
	}

	for(Int_t iter2 = iter+1; iter2 < nEle; iter2++){
	  float temp2Et = elePt->at(iter2);
	  float temp2Eta = eleEta->at(iter2);
	  float temp2Phi = elePhi->at(iter2);

	  float temp2HoverE = eleHoverE->at(iter2);
	  float temp2SigmaIEtaIEta = eleSigmaIEtaIEta_2012->at(iter2);

	  float temp2EoverPInv = eleEoverPInv->at(iter2);
	  float temp2DEtaAtVtx = eledEtaAtVtx->at(iter2);
	  float temp2DPhiAtVtx = eledPhiAtVtx->at(iter2);
	  float temp2D0 = eleD0->at(iter2);
	  float temp2Dz = eleDz->at(iter2);
	  int temp2MissHits = eleMissHits->at(iter2);
	  int temp2Charge = eleCharge->at(iter2);

	  // https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2#Working_points_for_Spring15_MC_s
	  // medium 25ns settings
	  if (tempCharge == temp2Charge) continue;
	  if(TMath::Abs(temp2Eta) < 1.4791)
	  {
	    if(temp2SigmaIEtaIEta >  0.0101 ) continue;
	    if(temp2DEtaAtVtx >  0.0103 ) continue;
	    if(temp2DPhiAtVtx >  0.0336 ) continue;
	    if(temp2HoverE > 0.0876) continue;
	    if(temp2EoverPInv >  0.0174 ) continue;
	    if(temp2D0 > 0.0118) continue;
	    if(temp2Dz > 0.373) continue;
	    if(temp2MissHits > 2) continue;
	  } else {
	    if(temp2SigmaIEtaIEta >  0.0283 ) continue;
	    if(temp2DEtaAtVtx >  0.00733 ) continue;
	    if(temp2DPhiAtVtx >  0.114 ) continue;
	    if(temp2HoverE > 0.0678) continue;
	    if(temp2EoverPInv >  0.0898 ) continue;
	    if(temp2D0 > 0.0739) continue;
	    if(temp2Dz > 0.602) continue;
	    if(temp2MissHits > 1) continue;
	  }

	  TLorentzVector el1, el2;
	  el1.SetPtEtaPhiM(tempEt, tempEta, tempPhi, electronMass);
	  el2.SetPtEtaPhiM(temp2Et, temp2Eta, temp2Phi, electronMass);
	  TLorentzVector z = el1+el2;
	  if(z.M() != 0) zMass_p->Fill(z.M());
	}
      }
    }
  }

  TFile* outFile_p = new TFile(outName, "RECREATE");
  zMass_p->Write("", TObject::kOverwrite);
  outFile_p->Close();
  delete outFile_p;

  delete zMass_p;

  inFile_p->Close();
  delete inFile_p;

  return;
}

int main(int argc, char **argv)
{
  if(argc ==3) {
    quickZAnalysis(argv[1], argv[2]);
    return 0;
  }
  else {
    return 1;
  }
}
