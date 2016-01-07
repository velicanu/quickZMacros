
{
  
    ////////////////////////// Jet pT 40-60 //////////////////////////
  // TCanvas c1;
  // hjetpt_pbpbdata_jt40_60->GetXaxis()->SetTitle("jet p_{T}");
  // hjetpt_pbpbdata_jt40_60->GetXaxis()->CenterTitle();
  // hjetpt_pbpbdata_jt40_60->GetXaxis()->SetRange(39,65);
  // hjetpt_pbpbdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  // hjetpt_pbpbdata_jt40_60->GetYaxis()->CenterTitle();
  // hjetpt_pbpbdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  // hjetpt_pbpbdata_jt40_60->DrawNormalized("pe");
  // hjetpt_pbpbmc_jt40_60->SetMarkerColor(kRed);
  // hjetpt_pbpbmc_jt40_60->DrawNormalized("pesame");
  // TLegend * legpbpb = new TLegend(0.44,0.76,0.74,0.91);
  // legpbpb->SetFillColor(0);
  // legpbpb->SetTextSize(0.06);
  // legpbpb->SetFillStyle(0);
  // legpbpb->SetTextFont(42);
  // legpbpb->AddEntry(hjetpt_pbpbdata_jt40_60,Form("PbPb #sqrt{s_{NN}}=5 TeV"),"p");
  // legpbpb->AddEntry(hjetpt_pbpbmc_jt40_60,Form("Z Pythia + Hydjet"),"p");
  // legpbpb->Draw();
  
  

  
  
  // TCanvas c1;
  // hjetpt_pbpbdata_jt30_40->GetXaxis()->SetTitle("jet p_{T}");
  // hjetpt_pbpbdata_jt30_40->GetXaxis()->CenterTitle();
  // hjetpt_pbpbdata_jt30_40->GetXaxis()->SetRange(25,45);
  // hjetpt_pbpbdata_jt30_40->GetYaxis()->SetTitle("dN/dp_{T}");
  // hjetpt_pbpbdata_jt30_40->GetYaxis()->CenterTitle();
  // hjetpt_pbpbdata_jt30_40->GetYaxis()->SetTitleOffset(1.3);
  // hjetpt_pbpbdata_jt30_40->DrawNormalized("pe");
  // hjetpt_pbpbmc_jt30_40->SetMarkerColor(kRed);
  // hjetpt_pbpbmc_jt30_40->DrawNormalized("pesame");
  // TLegend * legpbpb = new TLegend(0.44,0.76,0.74,0.91);
  // legpbpb->SetFillColor(0);
  // legpbpb->SetTextSize(0.06);
  // legpbpb->SetFillStyle(0);
  // legpbpb->SetTextFont(42);
  // legpbpb->AddEntry(hjetpt_pbpbdata_jt30_40,Form("PbPb #sqrt{s_{NN}}=5 TeV"),"p");
  // legpbpb->AddEntry(hjetpt_pbpbmc_jt30_40,Form("Z Pythia + Hydjet"),"p");
  // legpbpb->Draw();
  
  
  // TCanvas c2;
  // hjetpt_ppdata_jt30_40->GetXaxis()->SetTitle("jet p_{T}");
  // hjetpt_ppdata_jt30_40->GetXaxis()->CenterTitle();
  // hjetpt_ppdata_jt30_40->GetXaxis()->SetRange(25,45);
  // hjetpt_ppdata_jt30_40->GetYaxis()->SetTitle("dN/dp_{T}");
  // hjetpt_ppdata_jt30_40->GetYaxis()->CenterTitle();
  // hjetpt_ppdata_jt30_40->GetYaxis()->SetTitleOffset(1.3);
  // hjetpt_ppdata_jt30_40->DrawNormalized("pe");
  // hjetpt_ppmc_jt30_40->SetMarkerColor(kRed);
  // hjetpt_ppmc_jt30_40->DrawNormalized("pesame");
  // TLegend * legpp = new TLegend(0.44,0.76,0.74,0.91);
  // legpp->SetFillColor(0);
  // legpp->SetTextSize(0.06);
  // legpp->SetFillStyle(0);
  // legpp->SetTextFont(42);
  // legpp->AddEntry(hjetpt_ppdata_jt30_40,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legpp->AddEntry(hjetpt_ppmc_jt30_40,Form("Z Pythia"),"p");
  // legpp->Draw();
  
  
  ////////////////////////// ZPT //////////////////////////
  
  // TCanvas czptpbpb;
  // hzpt_pbpbdata->GetXaxis()->SetTitle("Z p_{T}");
  // hzpt_pbpbdata->GetXaxis()->CenterTitle();
  // hzpt_pbpbdata->GetYaxis()->SetTitle("dN/dp_{T}");
  // hzpt_pbpbdata->GetYaxis()->CenterTitle();
  // hzpt_pbpbdata->GetYaxis()->SetTitleOffset(1.3);
  // hzpt_pbpbdata->DrawNormalized("pe");
  // hzpt_pbpbmc->SetMarkerColor(kRed);
  // hzpt_pbpbmc->DrawNormalized("pesame");
  // TLegend * legzptpbpb = new TLegend(0.44,0.76,0.74,0.91);
  // legzptpbpb->SetFillColor(0);
  // legzptpbpb->SetTextSize(0.06);
  // legzptpbpb->SetFillStyle(0);
  // legzptpbpb->SetTextFont(42);
  // legzptpbpb->AddEntry(hzpt_pbpbdata,Form("PbPb #sqrt{s_{NN}}=5 TeV"),"p");
  // legzptpbpb->AddEntry(hzpt_pbpbmc,Form("Z Pythia + Hydjet"),"p");
  // legzptpbpb->Draw();
  
  
  TCanvas czptpp;
  hzpt_ppdata->GetXaxis()->SetTitle("Z p_{T}");
  hzpt_ppdata->GetXaxis()->CenterTitle();
  hzpt_ppdata->GetYaxis()->SetTitle("dN/dp_{T}");
  hzpt_ppdata->GetYaxis()->CenterTitle();
  hzpt_ppdata->GetYaxis()->SetTitleOffset(1.3);
  int ilow_hzpt_ppdata = hzpt_ppdata->FindBin(40);
  int ihigh_hzpt_ppdata = hzpt_ppdata->FindBin(100);
  float norm_hzpt_ppdata = hzpt_ppdata->Integral(ilow_hzpt_ppdata,ihigh_hzpt_ppdata);
  int ilow_hzpt_ppmc = hzpt_ppmc->FindBin(40);
  int ihigh_hzpt_ppmc = hzpt_ppmc->FindBin(100);
  float norm_hzpt_ppmc = hzpt_ppmc->Integral(ilow_hzpt_ppmc,ihigh_hzpt_ppmc);
  hzpt_ppdata->Sumw2();
  hzpt_ppmc->Sumw2();
  hzpt_ppdata->Scale(1/norm_hzpt_ppdata);
  hzpt_ppmc->Scale(1/norm_hzpt_ppmc);
  hzpt_ppdata->Draw("pe");
  // hzpt_ppdata->DrawNormalized("pe");
  hzpt_ppmc->SetMarkerColor(kRed);
  hzpt_ppmc->Draw("pesame");
  // hzpt_ppmc->DrawNormalized("pesame");
  TLegend * legzptpp = new TLegend(0.44,0.76,0.74,0.91);
  legzptpp->SetFillColor(0);
  legzptpp->SetTextSize(0.06);
  legzptpp->SetFillStyle(0);
  legzptpp->SetTextFont(42);
  legzptpp->AddEntry(hzpt_ppdata,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  legzptpp->AddEntry(hzpt_ppmc,Form("Z Pythia"),"p");
  legzptpp->Draw();
  czptpp.SaveAs("czptpp.png");
  
  
   ////////////////////////// Zmass //////////////////////////
  
  // TCanvas czmasspbpb;
  // hzmass_pbpbdata->GetXaxis()->SetTitle("Z mass");
  // hzmass_pbpbdata->GetXaxis()->CenterTitle();
  // hzmass_pbpbdata->GetYaxis()->SetTitle("dN/dp_{T}");
  // hzmass_pbpbdata->GetYaxis()->CenterTitle();
  // hzmass_pbpbdata->GetYaxis()->SetTitleOffset(1.3);
  // hzmass_pbpbdata->DrawNormalized("pe");
  // hzmass_pbpbmc->SetMarkerColor(kRed);
  // hzmass_pbpbmc->DrawNormalized("pesame");
  // TLegend * legzmasspbpb = new TLegend(0.44,0.76,0.74,0.91);
  // legzmasspbpb->SetFillColor(0);
  // legzmasspbpb->SetTextSize(0.06);
  // legzmasspbpb->SetFillStyle(0);
  // legzmasspbpb->SetTextFont(42);
  // legzmasspbpb->AddEntry(hzmass_pbpbdata,Form("PbPb #sqrt{s_{NN}}=5 TeV"),"p");
  // legzmasspbpb->AddEntry(hzmass_pbpbmc,Form("Z Pythia + Hydjet"),"p");
  // legzmasspbpb->Draw();
  
  
  // TCanvas czmasspp;
  // hzmass_ppdata->GetXaxis()->SetTitle("Z mass");
  // hzmass_ppdata->GetXaxis()->CenterTitle();
  // hzmass_ppdata->GetYaxis()->SetTitle("dN/dp_{T}");
  // hzmass_ppdata->GetYaxis()->CenterTitle();
  // hzmass_ppdata->GetYaxis()->SetTitleOffset(1.3);
  // hzmass_ppdata->DrawNormalized("pe");
  // hzmass_ppmc->SetMarkerColor(kRed);
  // hzmass_ppmc->DrawNormalized("pesame");
  // TLegend * legzmasspp = new TLegend(0.44,0.76,0.74,0.91);
  // legzmasspp->SetFillColor(0);
  // legzmasspp->SetTextSize(0.06);
  // legzmasspp->SetFillStyle(0);
  // legzmasspp->SetTextFont(42);
  // legzmasspp->AddEntry(hzmass_ppdata,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legzmasspp->AddEntry(hzmass_ppmc,Form("Z Pythia"),"p");
  // legzmasspp->Draw();
  
    ////////////////////////// incone outcone //////////////////////////
    /*
  TCanvas cinconepbpb;
  htrkPtincone_pbpbdata_jt40_60->GetXaxis()->SetTitle("incone trk p_{T}");
  htrkPtincone_pbpbdata_jt40_60->GetXaxis()->CenterTitle();
  htrkPtincone_pbpbdata_jt40_60->GetXaxis()->SetRange(0,20);
  htrkPtincone_pbpbdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  htrkPtincone_pbpbdata_jt40_60->GetYaxis()->CenterTitle();
  htrkPtincone_pbpbdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  // htrkPtincone_pbpbdata_jt40_60->DrawNormalized("pe");
  htrkPtincone_pbpbdata_jt40_60->Draw("pe");
  htrkPtincone_pbpbmc_jt40_60->SetMarkerColor(kRed);
  // htrkPtincone_pbpbmc_jt40_60->DrawNormalized("pesame");
  htrkPtincone_pbpbmc_jt40_60->Draw("pesame");
  TLegend * legpbpbincone = new TLegend(0.44,0.76,0.74,0.91);
  legpbpbincone->SetFillColor(0);
  legpbpbincone->SetTextSize(0.06);
  legpbpbincone->SetFillStyle(0);
  legpbpbincone->SetTextFont(42);
  legpbpbincone->AddEntry(htrkPtincone_pbpbdata_jt40_60,Form("PbPb #sqrt{s_{NN}}=5 TeV"),"p");
  legpbpbincone->AddEntry(htrkPtincone_pbpbmc_jt40_60,Form("Z Pythia + Hydjet"),"p");
  legpbpbincone->Draw();
  */
  
  TCanvas cinconepp;
  htrkPtincone_ppdata_jt40_60->GetXaxis()->SetTitle("incone trk p_{T}");
  htrkPtincone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  htrkPtincone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  htrkPtincone_ppdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  htrkPtincone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  htrkPtincone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  htrkPtincone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  htrkPtincone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // htrkPtincone_ppdata_jt40_60->DrawNormalized("pe");
  htrkPtincone_ppdata_jt40_60->Draw("pe");
  htrkPtincone_ppmc_jt40_60->SetMarkerColor(kRed);
  // htrkPtincone_ppmc_jt40_60->DrawNormalized("pesame");
  htrkPtincone_ppmc_jt40_60->Draw("pesame");
  TLegend * legppincone = new TLegend(0.44,0.76,0.74,0.91);
  legppincone->SetFillColor(0);
  legppincone->SetTextSize(0.06);
  legppincone->SetFillStyle(0);
  legppincone->SetTextFont(42);
  legppincone->AddEntry(htrkPtincone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  legppincone->AddEntry(htrkPtincone_ppmc_jt40_60,Form("Z Pythia"),"p");
  legppincone->Draw();
  cinconepp.SaveAs("cinconepp.png");
  
  /*
  TCanvas coutconepbpb;
  htrkPtoutcone_pbpbdata_jt40_60->GetXaxis()->SetTitle("outcone trk p_{T}");
  htrkPtoutcone_pbpbdata_jt40_60->GetXaxis()->CenterTitle();
  htrkPtoutcone_pbpbdata_jt40_60->GetXaxis()->SetRange(0,20);
  htrkPtoutcone_pbpbdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  htrkPtoutcone_pbpbdata_jt40_60->GetYaxis()->CenterTitle();
  htrkPtoutcone_pbpbdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  htrkPtoutcone_pbpbdata_jt40_60->Draw("pe");
  // htrkPtoutcone_pbpbdata_jt40_60->DrawNormalized("pe");
  htrkPtoutcone_pbpbmc_jt40_60->SetMarkerColor(kRed);
  htrkPtoutcone_pbpbmc_jt40_60->Draw("pesame");
  // htrkPtoutcone_pbpbmc_jt40_60->DrawNormalized("pesame");
  TLegend * legpbpboutcone = new TLegend(0.44,0.76,0.74,0.91);
  legpbpboutcone->SetFillColor(0);
  legpbpboutcone->SetTextSize(0.06);
  legpbpboutcone->SetFillStyle(0);
  legpbpboutcone->SetTextFont(42);
  legpbpboutcone->AddEntry(htrkPtoutcone_pbpbdata_jt40_60,Form("PbPb #sqrt{s_{NN}}=5 TeV"),"p");
  legpbpboutcone->AddEntry(htrkPtoutcone_pbpbmc_jt40_60,Form("Z Pythia + Hydjet"),"p");
  legpbpboutcone->Draw();
  */
  
  TCanvas coutconepp;
  htrkPtoutcone_ppdata_jt40_60->GetXaxis()->SetTitle("outcone trk p_{T}");
  htrkPtoutcone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  htrkPtoutcone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  htrkPtoutcone_ppdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  htrkPtoutcone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  htrkPtoutcone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  htrkPtoutcone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  htrkPtoutcone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // htrkPtoutcone_ppdata_jt40_60->DrawNormalized("pe");
  htrkPtoutcone_ppdata_jt40_60->Draw("pe");
  htrkPtoutcone_ppmc_jt40_60->SetMarkerColor(kRed);
  // htrkPtoutcone_ppmc_jt40_60->DrawNormalized("pesame");
  htrkPtoutcone_ppmc_jt40_60->Draw("pesame");
  TLegend * legppoutcone = new TLegend(0.44,0.76,0.74,0.91);
  legppoutcone->SetFillColor(0);
  legppoutcone->SetTextSize(0.06);
  legppoutcone->SetFillStyle(0);
  legppoutcone->SetTextFont(42);
  legppoutcone->AddEntry(htrkPtoutcone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  legppoutcone->AddEntry(htrkPtoutcone_ppmc_jt40_60,Form("Z Pythia"),"p");
  legppoutcone->Draw();
  coutconepp.SaveAs("coutconepp.png");
  
  
  TCanvas c2jetpt_ppdata_jt40_60;
  hjetpt_ppdata_jt40_60->GetXaxis()->SetTitle("jet p_{T}");
  hjetpt_ppdata_jt40_60->GetXaxis()->CenterTitle();
  hjetpt_ppdata_jt40_60->GetXaxis()->SetRange(39,65);
  hjetpt_ppdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  hjetpt_ppdata_jt40_60->GetYaxis()->CenterTitle();
  hjetpt_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  hjetpt_ppdata_jt40_60->Sumw2();
  hjetpt_ppmc_jt40_60->Sumw2();
  hjetpt_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  hjetpt_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  hjetpt_ppdata_jt40_60->Draw("pe");
  hjetpt_ppmc_jt40_60->SetMarkerColor(kRed);
  hjetpt_ppmc_jt40_60->Draw("pesame");
  TLegend * legpp = new TLegend(0.44,0.76,0.74,0.91);
  legpp->SetFillColor(0);
  legpp->SetTextSize(0.06);
  legpp->SetFillStyle(0);
  legpp->SetTextFont(42);
  legpp->AddEntry(hjetpt_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  legpp->AddEntry(hjetpt_ppmc_jt40_60,Form("Z Pythia"),"p");
  legpp->Draw();
  c2jetpt_ppdata_jt40_60.SaveAs("c2jetpt_ppdata_jt40_60.png");
  
  
    int ilow_hzpt_ppdata = hzpt_ppdata->FindBin(40);
  int ihigh_hzpt_ppdata = hzpt_ppdata->FindBin(100);
  float norm_hzpt_ppdata = hzpt_ppdata->Integral(ilow_hzpt_ppdata,ihigh_hzpt_ppdata);
  int ilow_hzpt_ppmc = hzpt_ppmc->FindBin(40);
  int ihigh_hzpt_ppmc = hzpt_ppmc->FindBin(100);
  float norm_hzpt_ppmc = hzpt_ppmc->Integral(ilow_hzpt_ppmc,ihigh_hzpt_ppmc);
  TCanvas coutconepp;
  hnTrkoutcone_ppdata_jt40_60->GetXaxis()->SetTitle("outcone nTrk");
  hnTrkoutcone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  hnTrkoutcone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  hnTrkoutcone_ppmc_jt40_60->GetXaxis()->SetRange(0,20);
  hnTrkoutcone_ppdata_jt40_60->GetYaxis()->SetTitle("");
  hnTrkoutcone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  hnTrkoutcone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  hnTrkoutcone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  hnTrkoutcone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // hnTrkoutcone_ppdata_jt40_60->DrawNormalized("pe");
  hnTrkoutcone_ppmc_jt40_60->SetMarkerColor(kRed);
  // hnTrkoutcone_ppmc_jt40_60->DrawNormalized("pesame");
  hnTrkoutcone_ppmc_jt40_60->Draw("pe");
  hnTrkoutcone_ppdata_jt40_60->Draw("pesame");
  TLegend * legppoutcone = new TLegend(0.44,0.76,0.74,0.91);
  legppoutcone->SetFillColor(0);
  legppoutcone->SetTextSize(0.06);
  legppoutcone->SetFillStyle(0);
  legppoutcone->SetTextFont(42);
  legppoutcone->AddEntry(hnTrkoutcone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  legppoutcone->AddEntry(hnTrkoutcone_ppmc_jt40_60,Form("Z Pythia"),"p");
  legppoutcone->Draw();
  coutconepp.SetLogy(1);
  coutconepp.SaveAs("coutconepp_ntrk.png");
  
  TCanvas cinconepp;
  hnTrkincone_ppdata_jt40_60->GetXaxis()->SetTitle("incone nTrk");
  hnTrkincone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  hnTrkincone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  hnTrkincone_ppmc_jt40_60->GetXaxis()->SetRange(0,20);
  hnTrkincone_ppdata_jt40_60->GetYaxis()->SetTitle("");
  hnTrkincone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  hnTrkincone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  hnTrkincone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  hnTrkincone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // hnTrkincone_ppdata_jt40_60->DrawNormalized("pe");
  hnTrkincone_ppmc_jt40_60->SetMarkerColor(kRed);
  // hnTrkincone_ppmc_jt40_60->DrawNormalized("pesame");
  hnTrkincone_ppmc_jt40_60->Draw("pe");
  hnTrkincone_ppdata_jt40_60->Draw("pesame");
  TLegend * legppincone = new TLegend(0.44,0.76,0.74,0.91);
  legppincone->SetFillColor(0);
  legppincone->SetTextSize(0.06);
  legppincone->SetFillStyle(0);
  legppincone->SetTextFont(42);
  legppincone->AddEntry(hnTrkincone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  legppincone->AddEntry(hnTrkincone_ppmc_jt40_60,Form("Z Pythia"),"p");
  legppincone->Draw();
  
  cinconepp.SaveAs("cinconepp_ntrk.png");
  
  
  
}


