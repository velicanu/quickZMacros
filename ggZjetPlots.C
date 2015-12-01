#include "ggTree.h"

void ggZjetPlots() {

 gStyle->SetOptStat(0);
 TH1::SetDefaultSumw2();

 TLatex *tx = new TLatex();
 tx->SetTextFont(42);
 tx->SetTextSize(0.04);
 tx->SetNDC(kTRUE);

 TLatex *tx2 = new TLatex();
 tx2->SetTextFont(62);
 tx2->SetTextSize(0.04);
 tx2->SetNDC(kTRUE);

 TLatex *tx3 = new TLatex();
 tx3->SetTextFont(52);
 tx3->SetTextSize(0.04);
 tx3->SetNDC(kTRUE);

 bool pp = 0;

 TFile *fin;
 if(pp) fin = TFile::Open("Zevents_pp_ZMM_1Dec.root");
 else   fin = TFile::Open("Zevents_PbPb_Express_262548-262837.root");

 int Zcharge, Ztype; //type 1 muon, type 2 electron
 float Zmass, Zpt, Zeta, Zrapidity, Zphi;
 int njet;
 float jetpt[20], jeteta[20], jetphi[20]; 

 TTree *ztree = (TTree*)fin->Get("ztree");
 ztree->SetBranchAddress("Ztype",	&Ztype);
 ztree->SetBranchAddress("Zmass",	&Zmass);
 ztree->SetBranchAddress("Zpt",		&Zpt);
 ztree->SetBranchAddress("Zeta",	&Zeta);
 ztree->SetBranchAddress("Zphi",	&Zphi);
 ztree->SetBranchAddress("Zrapidity",	&Zrapidity);
 ztree->SetBranchAddress("Zcharge",	&Zcharge);
 ztree->SetBranchAddress("njet",	&njet);
 ztree->SetBranchAddress("jetpt",	jetpt);
 ztree->SetBranchAddress("jeteta",	jeteta);
 ztree->SetBranchAddress("jetphi",	jetphi);

 TH1F *dPhiZjet = new TH1F("dPhiZjet",";#Delta#phi_{Zjet};Counts",30,0,pi);
 TH1F *xZjet = new TH1F("xZjet",";p_{T}^{jet} / p_{T}^{Z};Counts",10,0,2);

 for(int j=0; j<ztree->GetEntries(); j++) {

   ztree->GetEntry(j);
   if(Zcharge != 0 || Ztype != 1 || Zpt < 40 || Zmass < 80 || Zmass > 110) continue;
   cout << "Event " << j << "   ";

   for(int ij=0; ij<njet; ij++) {

     float dphi = -1;
     if(Zphi > jetphi[ij]) dphi = Zphi - jetphi[ij];
     else dphi = jetphi[ij] - Zphi;
     if(dphi > pi) dphi = dphi - pi;
     cout << "phi=" << dphi << "   ";
     dPhiZjet->Fill(dphi);
     if(dphi>2*pi/3) {
       float xj = jetpt[ij]/Zpt;
       xZjet->Fill(xj);
       cout << "x=" << xj << "   ";
     }

   }
   cout << endl;

 }

 TCanvas *c1 = new TCanvas();
 dPhiZjet->Draw();
 if(pp) tx->DrawLatex(0.13,0.94,"Prompt Skim 13 pb^{-1} (pp 5 TeV)");
 else   tx->DrawLatex(0.13,0.94,"Express 262548 - 262837 (PbPb 5 TeV)");
 tx->DrawLatex(0.17,0.86,"80 < m^{Z} < 110 GeV");
 tx->DrawLatex(0.17,0.80,"p_{T}^{Z} > 40 GeV");
 if(pp) tx->DrawLatex(0.17,0.74,"ak4PF jets, muons rejected by dR>0.1");
 else   tx->DrawLatex(0.17,0.74,"akPu4Calo jets, muons rejected by dR>0.1");
 tx->DrawLatex(0.17,0.68,"p_{T}^{jet} > 30 GeV");

 TArrow *arrow = new TArrow();
 arrow->SetLineColor(kRed);
 arrow->SetFillColor(kRed);
 arrow->SetLineWidth(2);
 arrow->SetArrowSize(0.03);

 TCanvas *c2 = new TCanvas();
 xZjet->Draw();
 if(pp) tx->DrawLatex(0.13,0.94,"Prompt Skim 13 pb^{-1} (pp 5 TeV)");
 else   tx->DrawLatex(0.13,0.94,"Express 262548 - 262837 (PbPb 5 TeV)");
 tx->DrawLatex(0.63,0.86,"80 < m^{Z} < 110 GeV");
 tx->DrawLatex(0.63,0.80,"p_{T}^{Z} > 40 GeV");
 if(pp) tx->DrawLatex(0.17,0.74,"ak4PF jets");
 else tx->DrawLatex(0.63,0.74,"akPu4Calo jets");
 tx->DrawLatex(0.63,0.68,"p_{T}^{jet} > 30 GeV");
 tx->DrawLatex(0.63,0.62,"#Delta#phi_{Zjet} > 2#pi/3");
 arrow->DrawArrow(xZjet->GetMean(),xZjet->GetMaximum()*0.2,xZjet->GetMean(),0);

}
