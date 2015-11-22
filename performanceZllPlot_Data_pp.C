#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TCut.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLegend.h>

#include <iostream>

const float maxEta = 2.4;

const float cutetaBarrel = 1.4791;          // cut to separate photons into Barrel and Endcap photons
const float cutetaEndCap = 2;

// final Z plots have x-axis range 60-120
const float final_xMin = 60;
const float final_xMax = 120;

const int entriesPerGeV = 2;

const bool doElectron = true;
const bool doMuon = true;
const bool doPhoton = true;
const bool doSameCharge = true;

void performanceZllPlot_Data_pp(const char* inputFile = "photonTree.root", const char* outputFile = "out_performancePhotonPlot.root", const char* sampleName = "");

void performanceZllPlot_Data_pp(const char* inputFile, const char* outputFile, const char* sampleName)
{
    TFile *input = new TFile(inputFile);
    TTree *tHLT = (TTree*)input->Get("hltTree");
    TTree *t_diele = (TTree*)input->Get("dielectron");
    TTree *t_dimu  = (TTree*)input->Get("dimuon");
    TTree *t_dipho = (TTree*)input->Get("diphoton");

    t_diele->AddFriend(tHLT,"t2");
    t_dimu->AddFriend(tHLT,"t2");
    t_dipho->AddFriend(tHLT,"t2");
    t_dipho->AddFriend(t_diele,"tEle");

    TFile* output = new TFile(outputFile, "RECREATE");

    TCanvas* c = new TCanvas("cnv","",600,600);

    const int nBins_pt = 2;
    const int nBins_eta = 4;
    int bins_pt[nBins_pt] = {15, 20};
    float bins_eta_gt[nBins_eta] = {-1,               -1, cutetaBarrel, cutetaBarrel};    // Barrel, Endcap1, Endcap2
    float bins_eta_lt[nBins_eta] = {maxEta, cutetaBarrel,          2.4, cutetaEndCap};

    TH1::SetDefaultSumw2();

    std::string histNames_e1e2_M    [nBins_pt][nBins_eta];
    std::string histNames_mu1mu2_M  [nBins_pt][nBins_eta];
    std::string histNames_pho1pho2_M[nBins_pt][nBins_eta];

//    const char* bins_eta_histoTitle  [nBins_eta]   = {" ,|#eta|<1.4791", " ,|#eta|<2", " ,|#eta|>2"};

    TH1::SetDefaultSumw2();
    TH1D* h1D_e1e2_M    [nBins_pt][nBins_eta];
    TH1D* h1D_mu1mu2_M  [nBins_pt][nBins_eta];
    TH1D* h1D_pho1pho2_M[nBins_pt][nBins_eta];

    // x-axis range : 60-120
    TH1D* h1D_e1e2_M_final    [nBins_pt][nBins_eta];
    TH1D* h1D_mu1mu2_M_final  [nBins_pt][nBins_eta];
    TH1D* h1D_pho1pho2_M_final[nBins_pt][nBins_eta];

    // histogram for same charge
    TH1D* h1D_sameCharge;
    std::string titleY = Form("Entries / (%d GeV/c^{2})", entriesPerGeV);

    for (int i=0; i<nBins_pt; ++i){
        for(int j=0; j<nBins_eta; ++j){
            histNames_e1e2_M    [i][j] = Form("e1e2_M_ptBin%d_etaBin%d", i, j);
            histNames_mu1mu2_M  [i][j] = Form("mu1mu2_M_ptBin%d_etaBin%d", i, j);
            histNames_pho1pho2_M[i][j] = Form("pho1pho2_M_ptBin%d_etaBin%d", i, j);

            h1D_e1e2_M[i][j]     = new TH1D(Form("h1D_%s", histNames_e1e2_M[i][j].c_str()),"",100,0,200);
            h1D_mu1mu2_M[i][j]   = new TH1D(Form("h1D_%s", histNames_mu1mu2_M[i][j].c_str()),"",100,0,200);
            h1D_pho1pho2_M[i][j] = new TH1D(Form("h1D_%s", histNames_pho1pho2_M[i][j].c_str()),"",100,0,200);
        }
    }

    // diElectron mass
    if (doElectron) {
    for(int i=0; i<nBins_pt; ++i){
        for(int j=0; j<nBins_eta; ++j){

            // cuts on e1+e2
            // https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2#Working_points_for_Spring15_MC_s
            TCut selection_event = " HLT_HIDoublePhoton15_Eta2p5_Mass50_1000_R9SigmaHECut_v1 == 1 ";
            TCut selection =  "";
            selection = selection && "eleSigmaIEtaIEta_1>0.002       && eleSigmaIEtaIEta_2>0.002";  // spike rejection
            selection = selection && "eleSigmaIPhiIPhi_1>0.002       && eleSigmaIPhiIPhi_2>0.002";  // spike rejection

            TCut selection_Barrel = "eleSigmaIEtaIEta_2012_1<0.0105 && eleSigmaIEtaIEta_2012_2<0.0105";
            selection_Barrel = selection_Barrel && "eledEtaAtVtx_1<0.00976         && eledEtaAtVtx_2<0.00976";
            selection_Barrel = selection_Barrel && "eledPhiAtVtx_1<0.0929          && eledPhiAtVtx_2<0.0929";
            selection_Barrel = selection_Barrel && "eleHoverE_1   <0.0765          && eleHoverE_2<0.0765";
            selection_Barrel = selection_Barrel && "eleEoverPInv_1<0.184           && eleEoverPInv_2<0.184";
            selection_Barrel = selection_Barrel && "eleD0_1<0.0227                 && eleD0_2<0.0227";
            selection_Barrel = selection_Barrel && "eleDz_1<0.379                  && eleDz_2<0.379";

            TCut selection_Endcap = "eleSigmaIEtaIEta_2012_1<0.0318 && eleSigmaIEtaIEta_2012_2<0.0318";
            selection_Endcap = selection_Endcap && "eledEtaAtVtx_1<0.00952         && eledEtaAtVtx_2<0.00952";
            selection_Endcap = selection_Endcap && "eledPhiAtVtx_1<0.181           && eledPhiAtVtx_2<0.181";
            selection_Endcap = selection_Endcap && "eleHoverE_1   <0.0824          && eleHoverE_2<0.0824";
            selection_Endcap = selection_Endcap && "eleEoverPInv_1<0.125           && eleEoverPInv_2<0.125";
            selection_Endcap = selection_Endcap && "eleD0_1<0.242                  && eleD0_2<0.242";
            selection_Endcap = selection_Endcap && "eleDz_1<0.921                  && eleDz_2<0.921";

            if (j == 0) {
                TCut selection_Barrel_eta = Form(" abs(eleEta_1) < %f && abs(eleEta_2) < %f", cutetaBarrel, cutetaBarrel);
                selection_Barrel = selection_Barrel && selection_Barrel_eta;
                TCut selection_Endcap_eta = Form(" abs(eleEta_1) > %f && abs(eleEta_2) > %f", cutetaBarrel, cutetaBarrel);
                selection_Endcap_eta = selection_Endcap_eta && Form(" abs(eleEta_1) < %f && abs(eleEta_2) < %f", maxEta, maxEta);
                selection_Endcap = selection_Endcap && selection_Endcap_eta;
                TCut selection_EB_EE = selection_Barrel || selection_Endcap;
                selection = selection && selection_EB_EE;
            }
            if (j == 1)     // Barrel,  |eta supercluster| <= 1.479
            {
                selection = selection && selection_Barrel;
                selection = selection && Form(" abs(eleEta_1) > %f && abs(eleEta_2) > %f", bins_eta_gt[j], bins_eta_gt[j]);
                selection = selection && Form(" abs(eleEta_1) < %f && abs(eleEta_2) < %f", bins_eta_lt[j], bins_eta_lt[j]);
            }
            if ( j>1 )           // Endcap,  1.479 < |eta supercluster| < 2.5
            {
                selection = selection && selection_Endcap;
                selection = selection && Form(" abs(eleEta_1) > %f && abs(eleEta_2) > %f", bins_eta_gt[j], bins_eta_gt[j]);
                selection = selection && Form(" abs(eleEta_1) < %f && abs(eleEta_2) < %f", bins_eta_lt[j], bins_eta_lt[j]);
            }
            selection = selection && Form(" elePt_1       > %d && elePt_2       > %d", bins_pt[i], bins_pt[i]);
            selection = selection && selection_event;

            TCut selection_sameCh = selection && "eleCharge_1 == eleCharge_2";
            selection             = selection && "eleCharge_1 != eleCharge_2";

            std::cout<< "selection = " << selection.GetTitle() <<std::endl;
            std::cout<< "h1D_e1e2_M[i][j]->GetName() = " << h1D_e1e2_M[i][j]->GetName() <<std::endl;

            std::string histoName  = Form("h_%s",histNames_e1e2_M[i][j].c_str());
            std::string histoTitle = Form("%s , p^{e#pm}_{T} > %d GeV/c, %f< |#eta^{e#pm}| <%.1f ",sampleName , bins_pt[i], bins_eta_gt[j], bins_eta_lt[j]);
            // special cases
            if (bins_eta_gt[j] < 0)   {
                histoTitle = Form("%s , p^{e#pm}_{T} > %d GeV/c, |#eta^{e#pm}| < %.2f ",sampleName , bins_pt[i], bins_eta_lt[j]);
            }
            h1D_e1e2_M[i][j]->SetTitle(Form("%s;M^{ee} (GeV/c^{2});%s",histoTitle.c_str(), titleY.c_str()));
//            h1D_e1e2_M[i][j]->SetTitleSize(h1D_e1e2_M[i][j]->GetTitleSize()*3);
            h1D_e1e2_M[i][j]->SetMarkerStyle(kFullCircle);
            h1D_e1e2_M[i][j]->SetMarkerColor(kBlack);
//            h1D_e1e2_M_final[i][j] = (TH1D*)h1D_e1e2_M[i][j]->Clone(Form("%s_final", h1D_e1e2_M[i][j]->GetName()));
//            h1D_e1e2_M_final[i][j]->SetAxisRange(final_xMin,final_xMax);

            c->SetName(Form("cnv_%s",histNames_e1e2_M[i][j].c_str()));
            c->cd();
            t_diele->Draw(Form("vSum_M >> %s", h1D_e1e2_M[i][j]->GetName()), selection.GetTitle() ,"goff");
            h1D_e1e2_M[i][j]->Draw("e");
            h1D_e1e2_M[i][j]->Write();
            h1D_e1e2_M[i][j]->SetStats(false);     // remove stat box from the canvas, but keep in the histograms.
            if (doSameCharge) {
                h1D_sameCharge = (TH1D*)h1D_e1e2_M[i][j]->Clone(Form("%s_sameCharge", h1D_e1e2_M[i][j]->GetName()));
                h1D_sameCharge->SetMarkerStyle(kOpenCircle);
                t_diele->Draw(Form("vSum_M >> %s", h1D_sameCharge->GetName()), selection_sameCh.GetTitle(), "goff");
                h1D_sameCharge->Draw("e same");
                h1D_sameCharge->Write();
                h1D_sameCharge->SetStats(false);
            }
            c->Write();
            c->Clear();

            c->SetName(Form("cnv_%s_final",histNames_e1e2_M[i][j].c_str()));
            c->cd();
//            t_diele->Draw(Form("vSum_M >> %s", h1D_e1e2_M_final[i][j]->GetName()), selection.GetTitle());
            h1D_e1e2_M_final[i][j] = (TH1D*)h1D_e1e2_M[i][j]->Clone(Form("%s_final", h1D_e1e2_M[i][j]->GetName()));
            h1D_e1e2_M_final[i][j]->SetAxisRange(final_xMin,final_xMax);
            h1D_e1e2_M_final[i][j]->Draw("e");
            h1D_e1e2_M_final[i][j]->Write();
            h1D_e1e2_M_final[i][j]->SetStats(false);     // remove stat box from the canvas, but keep in the histograms.
            if (doSameCharge) {
                h1D_sameCharge = (TH1D*)h1D_e1e2_M_final[i][j]->Clone(Form("%s_sameCharge", h1D_e1e2_M_final[i][j]->GetName()));
                h1D_sameCharge->SetMarkerStyle(kOpenCircle);
                t_diele->Draw(Form("vSum_M >> %s", h1D_sameCharge->GetName()), selection_sameCh.GetTitle(), "goff");
                h1D_sameCharge->Draw("e same");
                h1D_sameCharge->Write();
                h1D_sameCharge->SetStats(false);
            }
            c->Write();
            c->Clear();
        }
    }
    }

    // diMuon mass
    if (doMuon) {
    for(int i=0; i<nBins_pt; ++i){
        for(int j=0; j<nBins_eta; ++j){

            // cuts on mu1+mu2
            // https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2#Working_points_for_Spring15_MC_s
            TCut selection_event = " HLT_HIL1DoubleMu10_v1 == 1 ";
            TCut selection =  "";
            selection = selection && "muIsGood_1 == 1 && muIsGood_2 == 1";

            TCut selection_Barrel = "1";    // no extra selection at the moment
            TCut selection_Endcap = "1";    // no extra selection at the moment

            if (j==0){
                TCut selection_Barrel_eta = Form(" abs(muEta_1) < %f && abs(muEta_2) < %f", cutetaBarrel, cutetaBarrel);
                TCut selection_Endcap_eta = Form(" abs(muEta_1) > %f && abs(muEta_2) > %f", cutetaBarrel, cutetaBarrel);
                selection_Endcap_eta = selection_Endcap_eta && Form(" abs(muEta_1) < %f && abs(muEta_2) < %f", maxEta, maxEta);
                selection =  (selection && selection_Barrel && selection_Barrel_eta) || (selection && selection_Endcap && selection_Endcap_eta);
            }
            if (j == 1)     // Barrel,  |eta supercluster| <= 1.479
            {
                selection = selection && selection_Barrel;
                selection = selection && Form(" abs(muEta_1) > %f && abs(muEta_2) > %f", bins_eta_gt[j], bins_eta_gt[j]);
                selection = selection && Form(" abs(muEta_1) < %f && abs(muEta_2) < %f", bins_eta_lt[j], bins_eta_lt[j]);
            }
            else           // Endcap,  1.479 < |eta supercluster| < 2.5
            {
                selection = selection && selection_Endcap;
                selection = selection && Form(" abs(muEta_1) > %f && abs(muEta_2) > %f", bins_eta_gt[j], bins_eta_gt[j]);
                selection = selection && Form(" abs(muEta_1) < %f && abs(muEta_2) < %f", bins_eta_lt[j], bins_eta_lt[j]);
            }
            selection = selection && Form(" muPt_1       > %d && muPt_2       > %d", bins_pt[i], bins_pt[i]);
            selection = selection && selection_event;

            TCut selection_sameCh = selection && "muCharge_1 == muCharge_2";
            selection             = selection && "muCharge_1 != muCharge_2";

            std::cout<< "selection = " << selection.GetTitle() <<std::endl;
            std::cout<< "h1D_mu1mu2_M[i][j]->GetName() = " << h1D_mu1mu2_M[i][j]->GetName() <<std::endl;

            std::string histoName  = Form("h_%s",histNames_mu1mu2_M[i][j].c_str());
            std::string histoTitle = Form("%s ,p^{#mu#pm}_{T} > %d GeV/c, %f< |#eta^{#mu#pm}| <%.1f ",sampleName , bins_pt[i], bins_eta_gt[j], bins_eta_lt[j]);
            // special cases
            if (bins_eta_gt[j] < 0)   {
                histoTitle = Form("%s ,p^{#mu#pm}_{T} > %d GeV/c, |#eta^{#mu#pm}| < %.2f ",sampleName , bins_pt[i], bins_eta_lt[j]);
            }
            h1D_mu1mu2_M[i][j]->SetTitle(Form("%s;M^{#mu#mu} (GeV/c^{2});%s",histoTitle.c_str(), titleY.c_str()));
//            h1D_mu1mu2_M[i][j]->SetTitleSize(h1D_mu1mu2_M[i][j]->GetTitleSize()*3);
            h1D_mu1mu2_M[i][j]->SetMarkerStyle(kFullCircle);
            h1D_mu1mu2_M[i][j]->SetMarkerColor(kBlack);
            h1D_mu1mu2_M_final[i][j] = (TH1D*)h1D_mu1mu2_M[i][j]->Clone(Form("%s_final", h1D_mu1mu2_M[i][j]->GetName()));
            h1D_mu1mu2_M_final[i][j]->SetAxisRange(final_xMin,final_xMax);

            c->SetName(Form("cnv_%s",histNames_mu1mu2_M[i][j].c_str()));
            c->cd();
            t_dimu->Draw(Form("vSum_M >> %s", h1D_mu1mu2_M[i][j]->GetName()), selection.GetTitle(),"goff");
            h1D_mu1mu2_M[i][j]->Draw("e");
            h1D_mu1mu2_M[i][j]->Write();
            h1D_mu1mu2_M[i][j]->SetStats(false);     // remove stat box from the canvas, but keep in the histograms.
            if (doSameCharge) {
                h1D_sameCharge = (TH1D*)h1D_mu1mu2_M[i][j]->Clone(Form("%s_sameCharge", h1D_mu1mu2_M[i][j]->GetName()));
                h1D_sameCharge->SetMarkerStyle(kOpenCircle);
                t_diele->Draw(Form("vSum_M >> %s", h1D_sameCharge->GetName()), selection_sameCh.GetTitle(), "goff");
                h1D_sameCharge->Draw("e same");
                h1D_sameCharge->Write();
                h1D_sameCharge->SetStats(false);
            }
            c->Write();
            c->Clear();

            c->SetName(Form("cnv_%s_final",histNames_mu1mu2_M[i][j].c_str()));
            c->cd();
//            t_dimu->Draw(Form("vSum_M >> %s", h1D_mu1mu2_M_final[i][j]->GetName()), selection.GetTitle(),"goff");
            h1D_mu1mu2_M_final[i][j] = (TH1D*)h1D_mu1mu2_M[i][j]->Clone(Form("%s_final", h1D_mu1mu2_M[i][j]->GetName()));
            h1D_mu1mu2_M_final[i][j]->SetAxisRange(final_xMin,final_xMax);
            h1D_mu1mu2_M_final[i][j]->Draw("e");
            h1D_mu1mu2_M_final[i][j]->Write();
            h1D_mu1mu2_M_final[i][j]->SetStats(false);  // remove stat box from the canvas, but keep in the histograms.
            if (doSameCharge) {
                h1D_sameCharge = (TH1D*)h1D_mu1mu2_M_final[i][j]->Clone(Form("%s_sameCharge", h1D_mu1mu2_M_final[i][j]->GetName()));
                h1D_sameCharge->SetMarkerStyle(kOpenCircle);
                t_dimu->Draw(Form("vSum_M >> %s", h1D_sameCharge->GetName()), selection_sameCh.GetTitle(), "goff");
                h1D_sameCharge->Draw("e same");
                h1D_sameCharge->Write();
                h1D_sameCharge->SetStats(false);
            }
            c->Write();
            c->Clear();
        }
    }
    }

    // diPhoton mass
    if (doPhoton) {
    for(int i=0; i<nBins_pt; ++i){
        for(int j=0; j<nBins_eta; ++j){

            // cuts on pho1+pho2
            // https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2#Working_points_for_Spring15_MC_s
            TCut selection_event = " HLT_HIDoublePhoton15_Eta2p5_Mass50_1000_R9SigmaHECut_v1 == 1 ";
            TCut selection = "";
            selection = selection && "matched_eleIndex_1 > -1    && matched_eleIndex_2 > -1";
            selection = selection && "phoSigmaIEtaIEta_1 > 0.002 && phoSigmaIEtaIEta_2 > 0.002";  // spike rejection
            selection = selection && "phoHoverE_1 < 0.1          && phoHoverE_2 < 0.1";
            selection = selection && "phoSigmaIEtaIEta_1 < 0.01  && phoSigmaIEtaIEta_2 < 0.01";   // phoSigmaIEtaIEta cut

            TCut selection_Barrel = "1";    // no extra selection at the moment
            TCut selection_Endcap = "1";    // no extra selection at the moment

            /*
            ///// MATCHED ELECTRON SELECTION BLOCK
            ///// apply the Zee cuts to matched electrons
            ///// diele is added as friend to t_dipho.
            selection = selection && "eleSigmaIEtaIEta_1[matched_eleIndex_1]>0.002       && eleSigmaIEtaIEta_1[matched_eleIndex_2]>0.002";  // spike rejection
            selection = selection && "eleSigmaIPhiIPhi_1[matched_eleIndex_1]>0.002       && eleSigmaIPhiIPhi_1[matched_eleIndex_2]>0.002";  // spike rejection

            selection_Barrel = selection_Barrel && "eleSigmaIEtaIEta_2012_1[matched_eleIndex_1]<0.0105 && eleSigmaIEtaIEta_2012_1[matched_eleIndex_2]<0.0105";
            selection_Barrel = selection_Barrel && "eledEtaAtVtx_1[matched_eleIndex_1]<0.00976         && eledEtaAtVtx_1[matched_eleIndex_2]<0.00976";
            selection_Barrel = selection_Barrel && "eledPhiAtVtx_1[matched_eleIndex_1]<0.0929          && eledPhiAtVtx_1[matched_eleIndex_2]<0.0929";
            selection_Barrel = selection_Barrel && "eleHoverE_1[matched_eleIndex_1]   <0.0765          && eleHoverE_1[matched_eleIndex_2]<0.0765";
            selection_Barrel = selection_Barrel && "eleEoverPInv_1[matched_eleIndex_1]<0.184           && eleEoverPInv_1[matched_eleIndex_2]<0.184";
            selection_Barrel = selection_Barrel && "eleD0_1[matched_eleIndex_1]<0.0227                 && eleD0_1[matched_eleIndex_2]<0.0227";
            selection_Barrel = selection_Barrel && "eleDz_1[matched_eleIndex_1]<0.379                  && eleDz_1[matched_eleIndex_2]<0.379";

            selection_Endcap = selection_Endcap && "eleSigmaIEtaIEta_2012_1[matched_eleIndex_1]<0.0318 && eleSigmaIEtaIEta_2012_1[matched_eleIndex_2]<0.0318";
            selection_Endcap = selection_Endcap && "eledEtaAtVtx_1[matched_eleIndex_1]<0.00952         && eledEtaAtVtx_1[matched_eleIndex_2]<0.00952";
            selection_Endcap = selection_Endcap && "eledPhiAtVtx_1[matched_eleIndex_1]<0.181           && eledPhiAtVtx_1[matched_eleIndex_2]<0.181";
            selection_Endcap = selection_Endcap && "eleHoverE_1[matched_eleIndex_1]   <0.0824          && eleHoverE_1[matched_eleIndex_2]<0.0824";
            selection_Endcap = selection_Endcap && "eleEoverPInv_1[matched_eleIndex_1]<0.125           && eleEoverPInv_1[matched_eleIndex_2]<0.125";
            selection_Endcap = selection_Endcap && "eleD0_1[matched_eleIndex_1]<0.242                  && eleD0_1[matched_eleIndex_2]<0.242";
            selection_Endcap = selection_Endcap && "eleDz_1[matched_eleIndex_1]<0.921                  && eleDz_1[matched_eleIndex_2]<0.921";
            ///// MATCHED ELECTRON SELECTION BLOCK
             */

            if (j==0){
                TCut selection_Barrel_eta = Form(" abs(phoEta_1) < %f && abs(phoEta_2) < %f", cutetaBarrel, cutetaBarrel);
                TCut selection_Endcap_eta = Form(" abs(phoEta_1) > %f && abs(phoEta_2) > %f", cutetaBarrel, cutetaBarrel);
                selection_Endcap_eta = selection_Endcap_eta && Form(" abs(phoEta_1) < %f && abs(phoEta_2) < %f", maxEta, maxEta);
                selection =  (selection && selection_Barrel && selection_Barrel_eta) || (selection && selection_Endcap && selection_Endcap_eta);
            }
            if (j == 1)     // Barrel,  |eta supercluster| <= 1.479
            {
                selection = selection && selection_Barrel;
                selection = selection && Form(" abs(phoEta_1) > %f && abs(phoEta_2) > %f", bins_eta_gt[j], bins_eta_gt[j]);
                selection = selection && Form(" abs(phoEta_1) < %f && abs(phoEta_2) < %f", bins_eta_lt[j], bins_eta_lt[j]);
            }
            else           // Endcap,  1.479 < |eta supercluster| < 2.5
            {
                selection = selection && selection_Endcap;
                selection = selection && Form(" abs(phoEta_1) > %f && abs(phoEta_2) > %f", bins_eta_gt[j], bins_eta_gt[j]);
                selection = selection && Form(" abs(phoEta_1) < %f && abs(phoEta_2) < %f", bins_eta_lt[j], bins_eta_lt[j]);
            }
            selection = selection && Form(" phoEt_1       > %d && phoEt_2       > %d", bins_pt[i], bins_pt[i]);
            selection = selection && selection_event;

            TCut selection_sameCh = selection && "matched_eleCharge_1 == matched_eleCharge_2";
            selection             = selection && "matched_eleCharge_1 != matched_eleCharge_2";

            std::cout<< "selection = " << selection.GetTitle() <<std::endl;
            std::cout<< "h1D_pho1pho2_M[i][j]->GetName() = " << h1D_pho1pho2_M[i][j]->GetName() <<std::endl;

            std::string histoName  = Form("h_%s",histNames_pho1pho2_M[i][j].c_str());
            std::string histoTitle = Form("%s ,p^{#gamma}_{T} > %d GeV/c, %f< |#eta^{#gamma}| <%.1f ",sampleName , bins_pt[i], bins_eta_gt[j], bins_eta_lt[j]);
            // special cases
            if (bins_eta_gt[j] < 0)   {
                histoTitle = Form("%s ,p^{#gamma}_{T} > %d GeV/c, |#eta^{#gamma}| < %.2f ",sampleName , bins_pt[i], bins_eta_lt[j]);
            }
            h1D_pho1pho2_M[i][j]->SetTitle(Form("%s;M^{#gamma#gamma} (GeV/c^{2});%s",histoTitle.c_str(), titleY.c_str()));
//            h1D_pho1pho2_M[i][j]->SetTitleSize(h1D_mu1mu2_M[i][j]->GetTitleSize()*3);
            h1D_pho1pho2_M[i][j]->SetMarkerStyle(kFullCircle);
            h1D_pho1pho2_M[i][j]->SetMarkerColor(kBlack);
//            h1D_pho1pho2_M_final[i][j] = (TH1D*)h1D_pho1pho2_M[i][j]->Clone(Form("%s_final", h1D_pho1pho2_M[i][j]->GetName()));
//            h1D_pho1pho2_M_final[i][j]->SetAxisRange(final_xMin,final_xMax);

            c->SetName(Form("cnv_%s",histNames_pho1pho2_M[i][j].c_str()));
            c->cd();
            t_dipho->Draw(Form("vSum_M >> %s", h1D_pho1pho2_M[i][j]->GetName()), selection.GetTitle(),"goff");
            h1D_pho1pho2_M[i][j]->Draw("e");
            h1D_pho1pho2_M[i][j]->Write();
            h1D_pho1pho2_M[i][j]->SetStats(false);     // remove stat box from the canvas, but keep in the histograms.
            if (doSameCharge) {
                h1D_sameCharge = (TH1D*)h1D_pho1pho2_M[i][j]->Clone(Form("%s_sameCharge", h1D_pho1pho2_M[i][j]->GetName()));
                h1D_sameCharge->SetMarkerStyle(kOpenCircle);
                t_dipho->Draw(Form("vSum_M >> %s", h1D_sameCharge->GetName()), selection_sameCh.GetTitle(), "goff");
                h1D_sameCharge->Draw("e same");
                h1D_sameCharge->Write();
                h1D_sameCharge->SetStats(false);
            }
            c->Write();
            c->Clear();

            c->SetName(Form("cnv_%s_final",histNames_pho1pho2_M[i][j].c_str()));
            c->cd();
//            t_dipho->Draw(Form("vSum_M >> %s", h1D_pho1pho2_M_final[i][j]->GetName()), selection.GetTitle());
            h1D_pho1pho2_M_final[i][j] = (TH1D*)h1D_pho1pho2_M[i][j]->Clone(Form("%s_final", h1D_pho1pho2_M[i][j]->GetName()));
            h1D_pho1pho2_M_final[i][j]->SetAxisRange(final_xMin,final_xMax);
            h1D_pho1pho2_M_final[i][j]->Draw("e");
            h1D_pho1pho2_M_final[i][j]->Write();
            h1D_pho1pho2_M_final[i][j]->SetStats(false);  // remove stat box from the canvas, but keep in the histograms.
            if (doSameCharge) {
                h1D_sameCharge = (TH1D*)h1D_pho1pho2_M_final[i][j]->Clone(Form("%s_sameCharge", h1D_pho1pho2_M_final[i][j]->GetName()));
                h1D_sameCharge->SetMarkerStyle(kOpenCircle);
                t_dipho->Draw(Form("vSum_M >> %s", h1D_sameCharge->GetName()), selection_sameCh.GetTitle(), "goff");
                h1D_sameCharge->Draw("e same");
                h1D_sameCharge->Write();
                h1D_sameCharge->SetStats(false);
            }
            c->Write();
            c->Clear();
        }
    }
    }

    output->Write();

    input->Close();
    output->Close();
}

int main(int argc, char** argv)
{
    if      (argc == 4)    performanceZllPlot_Data_pp(argv[1], argv[2], argv[3]);
    else if (argc == 3)    performanceZllPlot_Data_pp(argv[1], argv[2]);
    else if (argc == 2)    performanceZllPlot_Data_pp(argv[1]);
    return 0;
}
