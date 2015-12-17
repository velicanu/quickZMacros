#define ztree_cxx
#include "ztree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TMath.h>
#include <TCanvas.h>
#include "ggTree.h"

void ztree::Loop()
{
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  TFile * fout = new TFile("fout.root","recreate");
  TH1D * hdphi = new TH1D("hdphi",";#Delta#phi",100,0,TMath::Pi());
  TH1D * hdr = new TH1D("hdr",";#DeltaR",100,0,1);
  TH1D * hdeta = new TH1D("hdeta",";#Delta#eta",100,-2.5,2.5);
  TH1D * hdpt = new TH1D("hdpt",";#Deltap_{T}",100,-2.5,2.5);
  TH2D * hdptdr = new TH2D("hdptdr",";#Deltap_{T};#DeltaR",100,-2.5,2.5,100,0,1);
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    
    for(int i = 0 ; i < nTrk ; ++i)
    {
      hdphi->Fill(getDphi(Zlepton1Phi,trkPhi[i]));
      hdphi->Fill(getDphi(Zlepton2Phi,trkPhi[i]));
      hdeta->Fill(Zlepton1Eta - trkEta[i]);
      hdeta->Fill(Zlepton2Eta - trkEta[i]);
      hdpt->Fill((Zlepton1Pt - trkPt[i])/Zlepton1Pt);
      hdpt->Fill((Zlepton2Pt - trkPt[i])/Zlepton2Pt);
      float dR1 = sqrt( (Zlepton1Eta-trkEta[i])*(Zlepton1Eta-trkEta[i]) + getDphi(Zlepton1Phi,trkPhi[i])*getDphi(Zlepton1Phi,trkPhi[i]) );
      float dR2 = sqrt( (Zlepton2Eta-trkEta[i])*(Zlepton2Eta-trkEta[i]) + getDphi(Zlepton2Phi,trkPhi[i])*getDphi(Zlepton2Phi,trkPhi[i]) );
      hdr->Fill(dR1);
      hdr->Fill(dR2);
      hdptdr->Fill((Zlepton1Pt - trkPt[i])/Zlepton1Pt,dR1);
      hdptdr->Fill((Zlepton2Pt - trkPt[i])/Zlepton2Pt,dR2);
    }
  }
  fout->Write();
  fout->Close();
}

