#include "ggTree.h"

void ggZjetPlots(bool pp = 1, float ptcutZ = 40, bool plotnear = 0) {

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

 TFile *fin;
 if(pp) fin = TFile::Open("Zevents_pp_ZMM_2Dec_withJetID.root");
 else   fin = TFile::Open("Zevents_PbPb_Express_262548-262837.root");

 int Zcharge, Ztype; //type 1 muon, type 2 electron
 float Zmass, Zpt, Zeta, Zrapidity, Zphi;
 int njet;
 float jetpt[20], jeteta[20], jetphi[20]; 
 int jetID[20];

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
 ztree->SetBranchAddress("jetID",	jetID);

 TH1F *dPhiZjet = new TH1F("dPhiZjet",";#Delta#phi_{Zjet};Counts",30,0,pi);
 TH1F *dEtaZjet = new TH1F("dEtaZjet",";|#Delta#eta_{Zjet}|;Counts",25,0,5);
 TH2F *dPhidEta = new TH2F("dPhidEta",";|#Delta#eta_{Zjet}|;#Delta#phi_{Zjet}",25,0,5,30,0,pi);
 TH1F *xZjet = new TH1F("xZjet",";p_{T}^{jet} / p_{T}^{Z};Counts",10,0,2);
 TH1F *xZjetNear = new TH1F("xZjetNear",";p_{T}^{jet} / p_{T}^{Z};Counts",10,0,2);

 for(int j=0; j<ztree->GetEntries(); j++) {

   ztree->GetEntry(j);
   if(Zcharge != 0 || Ztype != 1 || Zpt < ptcutZ || Zmass < 80 || Zmass > 110) continue;

   for(int ij=0; ij<njet; ij++) {

     if(fabs(jeteta[ij])>2.0) continue;
     if(jetID[ij] != 1) continue;
     float dphi = getDphi(Zphi,jetphi[ij]);
     dPhiZjet->Fill(fabs(dphi));
     float deta = Zeta - jeteta[ij];
     dEtaZjet->Fill(fabs(deta));
     dPhidEta->Fill(fabs(deta),fabs(dphi));
     float xj = jetpt[ij]/Zpt;
     if(dphi>2*pi/3) xZjet->Fill(xj);
     else xZjetNear->Fill(xj);

   }

 }

 TCanvas *c1 = new TCanvas();
 dPhiZjet->Draw();
 if(pp) tx->DrawLatex(0.13,0.94,"Prompt Skim 13 pb^{-1} (pp 5 TeV)");
 else   tx->DrawLatex(0.13,0.94,"Express 262548 - 262837 (PbPb 5 TeV)");
 tx->DrawLatex(0.17,0.86,"80 < m^{Z} < 110 GeV");
 tx->DrawLatex(0.17,0.80,Form("p_{T}^{Z} > %g GeV",ptcutZ));
 if(pp) tx->DrawLatex(0.17,0.74,"ak4PF jets");
 else   tx->DrawLatex(0.17,0.74,"akPu4Calo jets, muons rejected by dR>0.1");
 tx->DrawLatex(0.17,0.68,"p_{T}^{jet} > 30 GeV");
 tx->DrawLatex(0.17,0.62,"|#eta^{jet}| < 2.0");
 tx->DrawLatex(0.17,0.56,"jet ID 13 TeV");

 TCanvas *c2 = new TCanvas();
 dEtaZjet->Draw();
 if(pp) tx->DrawLatex(0.13,0.94,"Prompt Skim 13 pb^{-1} (pp 5 TeV)");
 else   tx->DrawLatex(0.13,0.94,"Express 262548 - 262837 (PbPb 5 TeV)");
 tx->DrawLatex(0.63,0.86,"80 < m^{Z} < 110 GeV");
 tx->DrawLatex(0.63,0.80,Form("p_{T}^{Z} > %g GeV",ptcutZ));
 if(pp) tx->DrawLatex(0.63,0.74,"ak4PF jets");
 else   tx->DrawLatex(0.63,0.74,"akPu4Calo jets, muons rejected by dR>0.1");
 tx->DrawLatex(0.63,0.68,"p_{T}^{jet} > 30 GeV");
 tx->DrawLatex(0.63,0.62,"|#eta^{jet}| < 2.0");

 TCanvas *c3 = new TCanvas();
 dPhidEta->Draw("colz");

 TArrow *arrow = new TArrow();
 arrow->SetLineColor(kRed);
 arrow->SetFillColor(kRed);
 arrow->SetLineWidth(2);
 arrow->SetArrowSize(0.03);

 TArrow *arrow2 = (TArrow*)arrow->Clone();
 arrow2->SetLineColor(kBlue);
 arrow2->SetFillColor(kBlue);

 TCanvas *c4 = new TCanvas();
 xZjet->Draw();
 xZjetNear->SetMarkerColor(kBlue);
 xZjetNear->SetLineColor(kBlue);
 xZjetNear->SetMarkerStyle(24);
 if(plotnear) xZjetNear->Draw("same");
 if(pp) tx->DrawLatex(0.13,0.94,"Prompt Skim 13 pb^{-1} (pp 5 TeV)");
 else   tx->DrawLatex(0.13,0.94,"Express 262548 - 262837 (PbPb 5 TeV)");
 tx->DrawLatex(0.63,0.86,"80 < m^{Z} < 110 GeV");
 tx->DrawLatex(0.63,0.80,Form("p_{T}^{Z} > %g GeV",ptcutZ));
 if(pp) tx->DrawLatex(0.63,0.74,"ak4PF jets");
 else tx->DrawLatex(0.63,0.74,"akPu4Calo jets");
 tx->DrawLatex(0.63,0.68,"p_{T}^{jet} > 30 GeV");
 tx->DrawLatex(0.63,0.62,"#Delta#phi_{Zjet} > 2#pi/3");
 arrow->DrawArrow(xZjet->GetMean(),xZjet->GetMaximum()*0.2,xZjet->GetMean(),0);
 if(plotnear) arrow2->DrawArrow(xZjetNear->GetMean(),xZjet->GetMaximum()*0.2,xZjetNear->GetMean(),0);

}
