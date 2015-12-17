#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TStyle.h"
#include "TLine.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TLorentzVector.h"
#include "TClonesArray.h"
#include "TLegend.h"
#include "TPaveStats.h"
#include "TLatex.h"
#include "TArrow.h"

#include <iostream>
#include <vector>

const double pi = 3.14159265358979323846;

using namespace std;

float getDphi(float phi1, float phi2) {
  float dphi = phi1 - phi2;
  if ( dphi > pi )
    dphi = dphi - 2.*pi;
  if ( dphi <= -pi ) 
    dphi = dphi + 2.*pi;
  return dphi;
}

//variables branches in ggNtuple
   UInt_t           run;
   ULong64_t        event;
   UInt_t           lumis;
   Bool_t          isData;
   Int_t           nEle;
   vector<int>     *eleCharge;
   vector<int>     *eleChargeConsistent;
   vector<float>   *eleEn;
   vector<float>   *eleD0;
   vector<float>   *eleDz;
   vector<float>   *eleD0Err;
   vector<float>   *eleDzErr;
   vector<float>   *eleTrkPt;
   vector<float>   *eleTrkEta;
   vector<float>   *eleTrkPhi;
   vector<int>     *eleTrkCharge;
   vector<float>   *eleTrkChi2;
   vector<float>   *eleTrkNdof;
   vector<float>   *eleTrkNormalizedChi2;
   vector<int>     *eleTrkValidHits;
   vector<int>     *eleTrkLayers;
   vector<float>   *elePt;
   vector<float>   *eleEta;
   vector<float>   *elePhi;
   vector<float>   *eleSCEn;
   vector<float>   *eleESEn;
   vector<float>   *eleSCEta;
   vector<float>   *eleSCPhi;
   vector<float>   *eleSCRawEn;
   vector<float>   *eleSCEtaWidth;
   vector<float>   *eleSCPhiWidth;
   vector<float>   *eleHoverE;
   vector<float>   *eleEoverP;
   vector<float>   *eleEoverPInv;
   vector<float>   *eleBrem;
   vector<float>   *eledEtaAtVtx;
   vector<float>   *eledPhiAtVtx;
   vector<float>   *eleSigmaIEtaIEta;
   vector<float>   *eleSigmaIEtaIEta_2012;
   vector<float>   *eleSigmaIPhiIPhi;
   vector<int>     *eleMissHits;
   vector<float>   *eleESEffSigmaRR;
   vector<float>   *elePFChIso;
   vector<float>   *elePFPhoIso;
   vector<float>   *elePFNeuIso;
   vector<float>   *elePFPUIso;
   vector<float>   *elePFChIso03;
   vector<float>   *elePFPhoIso03;
   vector<float>   *elePFNeuIso03;
   vector<float>   *elePFChIso04;
   vector<float>   *elePFPhoIso04;
   vector<float>   *elePFNeuIso04;
   vector<float>   *eleBC1E;
   vector<float>   *eleBC1Eta;
   vector<float>   *eleBC2E;
   vector<float>   *eleBC2Eta;
   Int_t           nPho;
   vector<float>   *phoE;
   vector<float>   *phoEt;
   vector<float>   *phoEta;
   vector<float>   *phoPhi;
   vector<float>   *phoSCE;
   vector<float>   *phoSCRawE;
   vector<float>   *phoESEn;
   vector<float>   *phoSCEta;
   vector<float>   *phoSCPhi;
   vector<float>   *phoSCEtaWidth;
   vector<float>   *phoSCPhiWidth;
   vector<float>   *phoSCBrem;
   vector<int>     *phohasPixelSeed;
   vector<float>   *phoR9;
   vector<float>   *phoHoverE;
   vector<float>   *phoSigmaIEtaIEta;
   vector<float>   *phoE1x3;
   vector<float>   *phoE2x2;
   vector<float>   *phoE3x3;
   vector<float>   *phoE2x5Max;
   vector<float>   *phoE1x5;
   vector<float>   *phoE2x5;
   vector<float>   *phoE5x5;
   vector<float>   *phoMaxEnergyXtal;
   vector<float>   *phoSigmaEtaEta;
   vector<float>   *phoR1x5;
   vector<float>   *phoR2x5;
   vector<float>   *phoESEffSigmaRR;
   vector<float>   *phoSigmaIEtaIEta_2012;
   vector<float>   *phoSigmaIEtaIPhi_2012;
   vector<float>   *phoSigmaIPhiIPhi_2012;
   vector<float>   *phoE1x3_2012;
   vector<float>   *phoE2x2_2012;
   vector<float>   *phoE3x3_2012;
   vector<float>   *phoE2x5Max_2012;
   vector<float>   *phoE5x5_2012;
   vector<float>   *phoBC1E;
   vector<float>   *phoBC1Eta;
   vector<float>   *phoBC2E;
   vector<float>   *phoBC2Eta;
   vector<float>   *pho_ecalClusterIsoR2;
   vector<float>   *pho_ecalClusterIsoR3;
   vector<float>   *pho_ecalClusterIsoR4;
   vector<float>   *pho_ecalClusterIsoR5;
   vector<float>   *pho_hcalRechitIsoR1;
   vector<float>   *pho_hcalRechitIsoR2;
   vector<float>   *pho_hcalRechitIsoR3;
   vector<float>   *pho_hcalRechitIsoR4;
   vector<float>   *pho_hcalRechitIsoR5;
   vector<float>   *pho_trackIsoR1PtCut20;
   vector<float>   *pho_trackIsoR2PtCut20;
   vector<float>   *pho_trackIsoR3PtCut20;
   vector<float>   *pho_trackIsoR4PtCut20;
   vector<float>   *pho_trackIsoR5PtCut20;
   vector<float>   *pho_swissCrx;
   vector<float>   *pho_seedTime;
   vector<float>   *pfcIso1;
   vector<float>   *pfcIso2;
   vector<float>   *pfcIso3;
   vector<float>   *pfcIso4;
   vector<float>   *pfcIso5;
   vector<float>   *pfpIso1;
   vector<float>   *pfpIso2;
   vector<float>   *pfpIso3;
   vector<float>   *pfpIso4;
   vector<float>   *pfpIso5;
   vector<float>   *pfnIso1;
   vector<float>   *pfnIso2;
   vector<float>   *pfnIso3;
   vector<float>   *pfnIso4;
   vector<float>   *pfnIso5;
   Int_t           nMu;
   vector<float>   *muPt;
   vector<float>   *muEta;
   vector<float>   *muPhi;
   vector<int>     *muCharge;
   vector<int>     *muType;
   vector<int>     *muIsGood;
   vector<float>   *muD0;
   vector<float>   *muDz;
   vector<float>   *muChi2NDF;
   vector<float>   *muInnerD0;
   vector<float>   *muInnerDz;
   vector<int>     *muTrkLayers;
   vector<int>     *muPixelLayers;
   vector<int>     *muPixelHits;
   vector<int>     *muMuonHits;
   vector<int>     *muTrkQuality;
   vector<int>     *muStations;
   vector<float>   *muIsoTrk;
   vector<float>   *muPFChIso;
   vector<float>   *muPFPhoIso;
   vector<float>   *muPFNeuIso;
   vector<float>   *muPFPUIso;

void initggTree(TTree *tree) {

   eleCharge = 0;
   eleChargeConsistent = 0;
   eleEn = 0;
   eleD0 = 0;
   eleDz = 0;
   eleD0Err = 0;
   eleDzErr = 0;
   eleTrkPt = 0;
   eleTrkEta = 0;
   eleTrkPhi = 0;
   eleTrkCharge = 0;
   eleTrkChi2 = 0;
   eleTrkNdof = 0;
   eleTrkNormalizedChi2 = 0;
   eleTrkValidHits = 0;
   eleTrkLayers = 0;
   elePt = 0;
   eleEta = 0;
   elePhi = 0;
   eleSCEn = 0;
   eleESEn = 0;
   eleSCEta = 0;
   eleSCPhi = 0;
   eleSCRawEn = 0;
   eleSCEtaWidth = 0;
   eleSCPhiWidth = 0;
   eleHoverE = 0;
   eleEoverP = 0;
   eleEoverPInv = 0;
   eleBrem = 0;
   eledEtaAtVtx = 0;
   eledPhiAtVtx = 0;
   eleSigmaIEtaIEta = 0;
   eleSigmaIEtaIEta_2012 = 0;
   eleSigmaIPhiIPhi = 0;
   eleMissHits = 0;
   eleESEffSigmaRR = 0;
   elePFChIso = 0;
   elePFPhoIso = 0;
   elePFNeuIso = 0;
   elePFPUIso = 0;
   elePFChIso03 = 0;
   elePFPhoIso03 = 0;
   elePFNeuIso03 = 0;
   elePFChIso04 = 0;
   elePFPhoIso04 = 0;
   elePFNeuIso04 = 0;
   eleBC1E = 0;
   eleBC1Eta = 0;
   eleBC2E = 0;
   eleBC2Eta = 0;
   phoE = 0;
   phoEt = 0;
   phoEta = 0;
   phoPhi = 0;
   phoSCE = 0;
   phoSCRawE = 0;
   phoESEn = 0;
   phoSCEta = 0;
   phoSCPhi = 0;
   phoSCEtaWidth = 0;
   phoSCPhiWidth = 0;
   phoSCBrem = 0;
   phohasPixelSeed = 0;
   phoR9 = 0;
   phoHoverE = 0;
   phoSigmaIEtaIEta = 0;
   phoE1x3 = 0;
   phoE2x2 = 0;
   phoE3x3 = 0;
   phoE2x5Max = 0;
   phoE1x5 = 0;
   phoE2x5 = 0;
   phoE5x5 = 0;
   phoMaxEnergyXtal = 0;
   phoSigmaEtaEta = 0;
   phoR1x5 = 0;
   phoR2x5 = 0;
   phoESEffSigmaRR = 0;
   phoSigmaIEtaIEta_2012 = 0;
   phoSigmaIEtaIPhi_2012 = 0;
   phoSigmaIPhiIPhi_2012 = 0;
   phoE1x3_2012 = 0;
   phoE2x2_2012 = 0;
   phoE3x3_2012 = 0;
   phoE2x5Max_2012 = 0;
   phoE5x5_2012 = 0;
   phoBC1E = 0;
   phoBC1Eta = 0;
   phoBC2E = 0;
   phoBC2Eta = 0;
   pho_ecalClusterIsoR2 = 0;
   pho_ecalClusterIsoR3 = 0;
   pho_ecalClusterIsoR4 = 0;
   pho_ecalClusterIsoR5 = 0;
   pho_hcalRechitIsoR1 = 0;
   pho_hcalRechitIsoR2 = 0;
   pho_hcalRechitIsoR3 = 0;
   pho_hcalRechitIsoR4 = 0;
   pho_hcalRechitIsoR5 = 0;
   pho_trackIsoR1PtCut20 = 0;
   pho_trackIsoR2PtCut20 = 0;
   pho_trackIsoR3PtCut20 = 0;
   pho_trackIsoR4PtCut20 = 0;
   pho_trackIsoR5PtCut20 = 0;
   pho_swissCrx = 0;
   pho_seedTime = 0;
   pfcIso1 = 0;
   pfcIso2 = 0;
   pfcIso3 = 0;
   pfcIso4 = 0;
   pfcIso5 = 0;
   pfpIso1 = 0;
   pfpIso2 = 0;
   pfpIso3 = 0;
   pfpIso4 = 0;
   pfpIso5 = 0;
   pfnIso1 = 0;
   pfnIso2 = 0;
   pfnIso3 = 0;
   pfnIso4 = 0;
   pfnIso5 = 0;
   muPt = 0;
   muEta = 0;
   muPhi = 0;
   muCharge = 0;
   muType = 0;
   muIsGood = 0;
   muD0 = 0;
   muDz = 0;
   muChi2NDF = 0;
   muInnerD0 = 0;
   muInnerDz = 0;
   muTrkLayers = 0;
   muPixelLayers = 0;
   muPixelHits = 0;
   muMuonHits = 0;
   muTrkQuality = 0;
   muStations = 0;
   muIsoTrk = 0;
   muPFChIso = 0;
   muPFPhoIso = 0;
   muPFNeuIso = 0;
   muPFPUIso = 0;

   tree->SetBranchAddress("run", &run);
   tree->SetBranchAddress("event", &event);
   tree->SetBranchAddress("lumis", &lumis);
   tree->SetBranchAddress("isData", &isData);
   tree->SetBranchAddress("nEle", &nEle);
   tree->SetBranchAddress("eleCharge", &eleCharge);
   tree->SetBranchAddress("eleChargeConsistent", &eleChargeConsistent);
   tree->SetBranchAddress("eleEn", &eleEn);
   tree->SetBranchAddress("eleD0", &eleD0);
   tree->SetBranchAddress("eleDz", &eleDz);
   tree->SetBranchAddress("eleD0Err", &eleD0Err);
   tree->SetBranchAddress("eleDzErr", &eleDzErr);
   tree->SetBranchAddress("eleTrkPt", &eleTrkPt);
   tree->SetBranchAddress("eleTrkEta", &eleTrkEta);
   tree->SetBranchAddress("eleTrkPhi", &eleTrkPhi);
   tree->SetBranchAddress("eleTrkCharge", &eleTrkCharge);
   tree->SetBranchAddress("eleTrkChi2", &eleTrkChi2);
   tree->SetBranchAddress("eleTrkNdof", &eleTrkNdof);
   tree->SetBranchAddress("eleTrkNormalizedChi2", &eleTrkNormalizedChi2);
   tree->SetBranchAddress("eleTrkValidHits", &eleTrkValidHits);
   tree->SetBranchAddress("eleTrkLayers", &eleTrkLayers);
   tree->SetBranchAddress("elePt", &elePt);
   tree->SetBranchAddress("eleEta", &eleEta);
   tree->SetBranchAddress("elePhi", &elePhi);
   tree->SetBranchAddress("eleSCEn", &eleSCEn);
   tree->SetBranchAddress("eleESEn", &eleESEn);
   tree->SetBranchAddress("eleSCEta", &eleSCEta);
   tree->SetBranchAddress("eleSCPhi", &eleSCPhi);
   tree->SetBranchAddress("eleSCRawEn", &eleSCRawEn);
   tree->SetBranchAddress("eleSCEtaWidth", &eleSCEtaWidth);
   tree->SetBranchAddress("eleSCPhiWidth", &eleSCPhiWidth);
   tree->SetBranchAddress("eleHoverE", &eleHoverE);
   tree->SetBranchAddress("eleEoverP", &eleEoverP);
   tree->SetBranchAddress("eleEoverPInv", &eleEoverPInv);
   tree->SetBranchAddress("eleBrem", &eleBrem);
   tree->SetBranchAddress("eledEtaAtVtx", &eledEtaAtVtx);
   tree->SetBranchAddress("eledPhiAtVtx", &eledPhiAtVtx);
   tree->SetBranchAddress("eleSigmaIEtaIEta", &eleSigmaIEtaIEta);
   tree->SetBranchAddress("eleSigmaIEtaIEta_2012", &eleSigmaIEtaIEta_2012);
   tree->SetBranchAddress("eleSigmaIPhiIPhi", &eleSigmaIPhiIPhi);
   tree->SetBranchAddress("eleMissHits", &eleMissHits);
   tree->SetBranchAddress("eleESEffSigmaRR", &eleESEffSigmaRR);
   tree->SetBranchAddress("elePFChIso", &elePFChIso);
   tree->SetBranchAddress("elePFPhoIso", &elePFPhoIso);
   tree->SetBranchAddress("elePFNeuIso", &elePFNeuIso);
   tree->SetBranchAddress("elePFPUIso", &elePFPUIso);
   tree->SetBranchAddress("elePFChIso03", &elePFChIso03);
   tree->SetBranchAddress("elePFPhoIso03", &elePFPhoIso03);
   tree->SetBranchAddress("elePFNeuIso03", &elePFNeuIso03);
   tree->SetBranchAddress("elePFChIso04", &elePFChIso04);
   tree->SetBranchAddress("elePFPhoIso04", &elePFPhoIso04);
   tree->SetBranchAddress("elePFNeuIso04", &elePFNeuIso04);
   tree->SetBranchAddress("eleBC1E", &eleBC1E);
   tree->SetBranchAddress("eleBC1Eta", &eleBC1Eta);
   tree->SetBranchAddress("eleBC2E", &eleBC2E);
   tree->SetBranchAddress("eleBC2Eta", &eleBC2Eta);
   tree->SetBranchAddress("nPho", &nPho);
   tree->SetBranchAddress("phoE", &phoE);
   tree->SetBranchAddress("phoEt", &phoEt);
   tree->SetBranchAddress("phoEta", &phoEta);
   tree->SetBranchAddress("phoPhi", &phoPhi);
   tree->SetBranchAddress("phoSCE", &phoSCE);
   tree->SetBranchAddress("phoSCRawE", &phoSCRawE);
   tree->SetBranchAddress("phoESEn", &phoESEn);
   tree->SetBranchAddress("phoSCEta", &phoSCEta);
   tree->SetBranchAddress("phoSCPhi", &phoSCPhi);
   tree->SetBranchAddress("phoSCEtaWidth", &phoSCEtaWidth);
   tree->SetBranchAddress("phoSCPhiWidth", &phoSCPhiWidth);
   tree->SetBranchAddress("phoSCBrem", &phoSCBrem);
   tree->SetBranchAddress("phohasPixelSeed", &phohasPixelSeed);
   tree->SetBranchAddress("phoR9", &phoR9);
   tree->SetBranchAddress("phoHoverE", &phoHoverE);
   tree->SetBranchAddress("phoSigmaIEtaIEta", &phoSigmaIEtaIEta);
   tree->SetBranchAddress("phoE1x3", &phoE1x3);
   tree->SetBranchAddress("phoE2x2", &phoE2x2);
   tree->SetBranchAddress("phoE3x3", &phoE3x3);
   tree->SetBranchAddress("phoE2x5Max", &phoE2x5Max);
   tree->SetBranchAddress("phoE1x5", &phoE1x5);
   tree->SetBranchAddress("phoE2x5", &phoE2x5);
   tree->SetBranchAddress("phoE5x5", &phoE5x5);
   tree->SetBranchAddress("phoMaxEnergyXtal", &phoMaxEnergyXtal);
   tree->SetBranchAddress("phoSigmaEtaEta", &phoSigmaEtaEta);
   tree->SetBranchAddress("phoR1x5", &phoR1x5);
   tree->SetBranchAddress("phoR2x5", &phoR2x5);
   tree->SetBranchAddress("phoESEffSigmaRR", &phoESEffSigmaRR);
   tree->SetBranchAddress("phoSigmaIEtaIEta_2012", &phoSigmaIEtaIEta_2012);
   tree->SetBranchAddress("phoSigmaIEtaIPhi_2012", &phoSigmaIEtaIPhi_2012);
   tree->SetBranchAddress("phoSigmaIPhiIPhi_2012", &phoSigmaIPhiIPhi_2012);
   tree->SetBranchAddress("phoE1x3_2012", &phoE1x3_2012);
   tree->SetBranchAddress("phoE2x2_2012", &phoE2x2_2012);
   tree->SetBranchAddress("phoE3x3_2012", &phoE3x3_2012);
   tree->SetBranchAddress("phoE2x5Max_2012", &phoE2x5Max_2012);
   tree->SetBranchAddress("phoE5x5_2012", &phoE5x5_2012);
   tree->SetBranchAddress("phoBC1E", &phoBC1E);
   tree->SetBranchAddress("phoBC1Eta", &phoBC1Eta);
   tree->SetBranchAddress("phoBC2E", &phoBC2E);
   tree->SetBranchAddress("phoBC2Eta", &phoBC2Eta);
   tree->SetBranchAddress("pho_ecalClusterIsoR2", &pho_ecalClusterIsoR2);
   tree->SetBranchAddress("pho_ecalClusterIsoR3", &pho_ecalClusterIsoR3);
   tree->SetBranchAddress("pho_ecalClusterIsoR4", &pho_ecalClusterIsoR4);
   tree->SetBranchAddress("pho_ecalClusterIsoR5", &pho_ecalClusterIsoR5);
   tree->SetBranchAddress("pho_hcalRechitIsoR1", &pho_hcalRechitIsoR1);
   tree->SetBranchAddress("pho_hcalRechitIsoR2", &pho_hcalRechitIsoR2);
   tree->SetBranchAddress("pho_hcalRechitIsoR3", &pho_hcalRechitIsoR3);
   tree->SetBranchAddress("pho_hcalRechitIsoR4", &pho_hcalRechitIsoR4);
   tree->SetBranchAddress("pho_hcalRechitIsoR5", &pho_hcalRechitIsoR5);
   tree->SetBranchAddress("pho_trackIsoR1PtCut20", &pho_trackIsoR1PtCut20);
   tree->SetBranchAddress("pho_trackIsoR2PtCut20", &pho_trackIsoR2PtCut20);
   tree->SetBranchAddress("pho_trackIsoR3PtCut20", &pho_trackIsoR3PtCut20);
   tree->SetBranchAddress("pho_trackIsoR4PtCut20", &pho_trackIsoR4PtCut20);
   tree->SetBranchAddress("pho_trackIsoR5PtCut20", &pho_trackIsoR5PtCut20);
   tree->SetBranchAddress("pho_swissCrx", &pho_swissCrx);
   tree->SetBranchAddress("pho_seedTime", &pho_seedTime);
   tree->SetBranchAddress("pfcIso1", &pfcIso1);
   tree->SetBranchAddress("pfcIso2", &pfcIso2);
   tree->SetBranchAddress("pfcIso3", &pfcIso3);
   tree->SetBranchAddress("pfcIso4", &pfcIso4);
   tree->SetBranchAddress("pfcIso5", &pfcIso5);
   tree->SetBranchAddress("pfpIso1", &pfpIso1);
   tree->SetBranchAddress("pfpIso2", &pfpIso2);
   tree->SetBranchAddress("pfpIso3", &pfpIso3);
   tree->SetBranchAddress("pfpIso4", &pfpIso4);
   tree->SetBranchAddress("pfpIso5", &pfpIso5);
   tree->SetBranchAddress("pfnIso1", &pfnIso1);
   tree->SetBranchAddress("pfnIso2", &pfnIso2);
   tree->SetBranchAddress("pfnIso3", &pfnIso3);
   tree->SetBranchAddress("pfnIso4", &pfnIso4);
   tree->SetBranchAddress("pfnIso5", &pfnIso5);
   tree->SetBranchAddress("nMu", &nMu);
   tree->SetBranchAddress("muPt", &muPt);
   tree->SetBranchAddress("muEta", &muEta);
   tree->SetBranchAddress("muPhi", &muPhi);
   tree->SetBranchAddress("muCharge", &muCharge);
   tree->SetBranchAddress("muType", &muType);
   tree->SetBranchAddress("muIsGood", &muIsGood);
   tree->SetBranchAddress("muD0", &muD0);
   tree->SetBranchAddress("muDz", &muDz);
   tree->SetBranchAddress("muChi2NDF", &muChi2NDF);
   tree->SetBranchAddress("muInnerD0", &muInnerD0);
   tree->SetBranchAddress("muInnerDz", &muInnerDz);
   tree->SetBranchAddress("muTrkLayers", &muTrkLayers);
   tree->SetBranchAddress("muPixelLayers", &muPixelLayers);
   tree->SetBranchAddress("muPixelHits", &muPixelHits);
   tree->SetBranchAddress("muMuonHits", &muMuonHits);
   tree->SetBranchAddress("muTrkQuality", &muTrkQuality);
   tree->SetBranchAddress("muStations", &muStations);
   tree->SetBranchAddress("muIsoTrk", &muIsoTrk);
   tree->SetBranchAddress("muPFChIso", &muPFChIso);
   tree->SetBranchAddress("muPFPhoIso", &muPFPhoIso);
   tree->SetBranchAddress("muPFNeuIso", &muPFNeuIso);
   tree->SetBranchAddress("muPFPUIso", &muPFPUIso);

}
