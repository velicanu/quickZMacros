
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
  // hjetpt_pbpbdata_jt50_1000->GetXaxis()->SetTitle("jet p_{T}");
  // hjetpt_pbpbdata_jt50_1000->GetXaxis()->CenterTitle();
  // hjetpt_pbpbdata_jt50_1000->GetXaxis()->SetRange(25,45);
  // hjetpt_pbpbdata_jt50_1000->GetYaxis()->SetTitle("dN/dp_{T}");
  // hjetpt_pbpbdata_jt50_1000->GetYaxis()->CenterTitle();
  // hjetpt_pbpbdata_jt50_1000->GetYaxis()->SetTitleOffset(1.3);
  // hjetpt_pbpbdata_jt50_1000->DrawNormalized("pe");
  // hjetpt_pbpbmc_jt50_1000->SetMarkerColor(kRed);
  // hjetpt_pbpbmc_jt50_1000->DrawNormalized("pesame");
  // TLegend * legpbpb = new TLegend(0.44,0.76,0.74,0.91);
  // legpbpb->SetFillColor(0);
  // legpbpb->SetTextSize(0.06);
  // legpbpb->SetFillStyle(0);
  // legpbpb->SetTextFont(42);
  // legpbpb->AddEntry(hjetpt_pbpbdata_jt50_1000,Form("PbPb #sqrt{s_{NN}}=5 TeV"),"p");
  // legpbpb->AddEntry(hjetpt_pbpbmc_jt50_1000,Form("Z Pythia + Hydjet"),"p");
  // legpbpb->Draw();
  
  
  // TCanvas c2;
  // hjetpt_ppdata_jt50_1000->GetXaxis()->SetTitle("jet p_{T}");
  // hjetpt_ppdata_jt50_1000->GetXaxis()->CenterTitle();
  // hjetpt_ppdata_jt50_1000->GetXaxis()->SetRange(25,45);
  // hjetpt_ppdata_jt50_1000->GetYaxis()->SetTitle("dN/dp_{T}");
  // hjetpt_ppdata_jt50_1000->GetYaxis()->CenterTitle();
  // hjetpt_ppdata_jt50_1000->GetYaxis()->SetTitleOffset(1.3);
  // hjetpt_ppdata_jt50_1000->DrawNormalized("pe");
  // hjetpt_ppmc_jt50_1000->SetMarkerColor(kRed);
  // hjetpt_ppmc_jt50_1000->DrawNormalized("pesame");
  // TLegend * legpp = new TLegend(0.44,0.76,0.74,0.91);
  // legpp->SetFillColor(0);
  // legpp->SetTextSize(0.06);
  // legpp->SetFillStyle(0);
  // legpp->SetTextFont(42);
  // legpp->AddEntry(hjetpt_ppdata_jt50_1000,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legpp->AddEntry(hjetpt_ppmc_jt50_1000,Form("Z Pythia"),"p");
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
  
  
  // int ilow_hzpt_ppdata = hzpt_ppdata->FindBin(40);
  // int ihigh_hzpt_ppdata = hzpt_ppdata->FindBin(100);
  // int ilow_hzpt_ppmc = hzpt_ppmc->FindBin(40);
  // int ihigh_hzpt_ppmc = hzpt_ppmc->FindBin(100);
  // float norm_hzpt_ppdata = hzpt_ppdata->Integral(ilow_hzpt_ppdata,ihigh_hzpt_ppdata);
  // float norm_hzpt_ppmc = hzpt_ppmc->Integral(ilow_hzpt_ppmc,ihigh_hzpt_ppmc);
  
  // TCanvas czptpp;
  // hzpt_ppdata->GetXaxis()->SetTitle("Z p_{T}");
  // hzpt_ppdata->GetXaxis()->CenterTitle();
  // hzpt_ppdata->GetYaxis()->SetTitle("dN/dp_{T}");
  // hzpt_ppdata->GetYaxis()->CenterTitle();
  // hzpt_ppdata->GetYaxis()->SetTitleOffset(1.3);
  // hzpt_ppdata->Sumw2();
  // hzpt_ppmc->Sumw2();
  // hzpt_ppdata->Scale(1/norm_hzpt_ppdata);
  // hzpt_ppmc->Scale(1/norm_hzpt_ppmc);
  // hzpt_ppdata->Draw("pe");
  // hzpt_ppmc->SetMarkerColor(kRed);
  // hzpt_ppmc->Draw("pesame");
  // TLegend * legzptpp = new TLegend(0.44,0.76,0.74,0.91);
  // legzptpp->SetFillColor(0);
  // legzptpp->SetTextSize(0.06);
  // legzptpp->SetFillStyle(0);
  // legzptpp->SetTextFont(42);
  // legzptpp->AddEntry(hzpt_ppdata,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legzptpp->AddEntry(hzpt_ppmc,Form("Z Pythia"),"p");
  // legzptpp->Draw();
  // czptpp.SaveAs("czptpp.png");
  
  
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
  
  // TCanvas cinconepp;
  // htrkPtincone_ppdata_jt40_60->GetXaxis()->SetTitle("incone trk p_{T}");
  // htrkPtincone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  // htrkPtincone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  // htrkPtincone_ppdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  // htrkPtincone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  // htrkPtincone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  // htrkPtincone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  // htrkPtincone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // htrkPtincone_ppdata_jt40_60->Draw("pe");
  // htrkPtincone_ppmc_jt40_60->SetMarkerColor(kRed);
  // htrkPtincone_ppmc_jt40_60->Draw("pesame");
  // TLegend * legppincone = new TLegend(0.44,0.76,0.74,0.91);
  // legppincone->SetFillColor(0);
  // legppincone->SetTextSize(0.06);
  // legppincone->SetFillStyle(0);
  // legppincone->SetTextFont(42);
  // legppincone->AddEntry(htrkPtincone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legppincone->AddEntry(htrkPtincone_ppmc_jt40_60,Form("Z Pythia"),"p");
  // legppincone->Draw();
  // cinconepp.SaveAs("cinconepp.png");
  
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
  
  // TCanvas coutconepp;
  // htrkPtoutcone_ppdata_jt40_60->GetXaxis()->SetTitle("outcone trk p_{T}");
  // htrkPtoutcone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  // htrkPtoutcone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  // htrkPtoutcone_ppdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  // htrkPtoutcone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  // htrkPtoutcone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  // htrkPtoutcone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  // htrkPtoutcone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // htrkPtoutcone_ppdata_jt40_60->Draw("pe");
  // htrkPtoutcone_ppmc_jt40_60->SetMarkerColor(kRed);
  // htrkPtoutcone_ppmc_jt40_60->Draw("pesame");
  // TLegend * legppoutcone = new TLegend(0.44,0.76,0.74,0.91);
  // legppoutcone->SetFillColor(0);
  // legppoutcone->SetTextSize(0.06);
  // legppoutcone->SetFillStyle(0);
  // legppoutcone->SetTextFont(42);
  // legppoutcone->AddEntry(htrkPtoutcone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legppoutcone->AddEntry(htrkPtoutcone_ppmc_jt40_60,Form("Z Pythia"),"p");
  // legppoutcone->Draw();
  // coutconepp.SaveAs("coutconepp.png");
  
  
  // TCanvas c2jetpt_ppdata_jt40_60;
  // hjetpt_ppdata_jt40_60->GetXaxis()->SetTitle("jet p_{T}");
  // hjetpt_ppdata_jt40_60->GetXaxis()->CenterTitle();
  // hjetpt_ppdata_jt40_60->GetXaxis()->SetRange(39,65);
  // hjetpt_ppdata_jt40_60->GetYaxis()->SetTitle("dN/dp_{T}");
  // hjetpt_ppdata_jt40_60->GetYaxis()->CenterTitle();
  // hjetpt_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  // hjetpt_ppdata_jt40_60->Sumw2();
  // hjetpt_ppmc_jt40_60->Sumw2();
  // hjetpt_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  // hjetpt_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // hjetpt_ppdata_jt40_60->Draw("pe");
  // hjetpt_ppmc_jt40_60->SetMarkerColor(kRed);
  // hjetpt_ppmc_jt40_60->Draw("pesame");
  // TLegend * legpp = new TLegend(0.44,0.76,0.74,0.91);
  // legpp->SetFillColor(0);
  // legpp->SetTextSize(0.06);
  // legpp->SetFillStyle(0);
  // legpp->SetTextFont(42);
  // legpp->AddEntry(hjetpt_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legpp->AddEntry(hjetpt_ppmc_jt40_60,Form("Z Pythia"),"p");
  // legpp->Draw();
  // c2jetpt_ppdata_jt40_60.SaveAs("c2jetpt_ppdata_jt40_60.png");
  
  
    // int ilow_hzpt_ppdata = hzpt_ppdata->FindBin(40);
  // int ihigh_hzpt_ppdata = hzpt_ppdata->FindBin(100);
  // float norm_hzpt_ppdata = hzpt_ppdata->Integral(ilow_hzpt_ppdata,ihigh_hzpt_ppdata);
  // int ilow_hzpt_ppmc = hzpt_ppmc->FindBin(40);
  // int ihigh_hzpt_ppmc = hzpt_ppmc->FindBin(100);
  // float norm_hzpt_ppmc = hzpt_ppmc->Integral(ilow_hzpt_ppmc,ihigh_hzpt_ppmc);
  // TCanvas coutconepp;
  // hnTrkoutcone_ppdata_jt40_60->GetXaxis()->SetTitle("outcone nTrk");
  // hnTrkoutcone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  // hnTrkoutcone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  // hnTrkoutcone_ppmc_jt40_60->GetXaxis()->SetRange(0,20);
  // hnTrkoutcone_ppdata_jt40_60->GetYaxis()->SetTitle("");
  // hnTrkoutcone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  // hnTrkoutcone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  // hnTrkoutcone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  // hnTrkoutcone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // hnTrkoutcone_ppmc_jt40_60->SetMarkerColor(kRed);
  // hnTrkoutcone_ppmc_jt40_60->Draw("pe");
  // hnTrkoutcone_ppdata_jt40_60->Draw("pesame");
  // TLegend * legppoutcone = new TLegend(0.44,0.76,0.74,0.91);
  // legppoutcone->SetFillColor(0);
  // legppoutcone->SetTextSize(0.06);
  // legppoutcone->SetFillStyle(0);
  // legppoutcone->SetTextFont(42);
  // legppoutcone->AddEntry(hnTrkoutcone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legppoutcone->AddEntry(hnTrkoutcone_ppmc_jt40_60,Form("Z Pythia"),"p");
  // legppoutcone->Draw();
  // coutconepp.SetLogy(1);
  // coutconepp.SaveAs("coutconepp_ntrk.png");
  
  // TCanvas cinconepp;
  // hnTrkincone_ppdata_jt40_60->GetXaxis()->SetTitle("incone nTrk");
  // hnTrkincone_ppdata_jt40_60->GetXaxis()->CenterTitle();
  // hnTrkincone_ppdata_jt40_60->GetXaxis()->SetRange(0,20);
  // hnTrkincone_ppmc_jt40_60->GetXaxis()->SetRange(0,20);
  // hnTrkincone_ppdata_jt40_60->GetYaxis()->SetTitle("");
  // hnTrkincone_ppdata_jt40_60->GetYaxis()->CenterTitle();
  // hnTrkincone_ppdata_jt40_60->GetYaxis()->SetTitleOffset(1.3);
  // hnTrkincone_ppdata_jt40_60->Scale(1/norm_hzpt_ppdata);
  // hnTrkincone_ppmc_jt40_60->Scale(1/norm_hzpt_ppmc);
  // hnTrkincone_ppmc_jt40_60->SetMarkerColor(kRed);
  // hnTrkincone_ppmc_jt40_60->Draw("pe");
  // hnTrkincone_ppdata_jt40_60->Draw("pesame");
  // TLegend * legppincone = new TLegend(0.44,0.76,0.74,0.91);
  // legppincone->SetFillColor(0);
  // legppincone->SetTextSize(0.06);
  // legppincone->SetFillStyle(0);
  // legppincone->SetTextFont(42);
  // legppincone->AddEntry(hnTrkincone_ppdata_jt40_60,Form("pp #sqrt{s_{NN}}=5 TeV"),"p");
  // legppincone->AddEntry(hnTrkincone_ppmc_jt40_60,Form("Z Pythia"),"p");
  // legppincone->Draw();
  
  // cinconepp.SaveAs("cinconepp_ntrk.png");
  float incerr = 0, outcerr = 0;


  TCanvas cmeanmultpbpb;
  TH2D * hmeanmultpbpb = new TH2D("hmeanmultpbpb",";jet p_{T} bin 50_1000;incone - outcone #bar{nTrk}",3,0,3,1,0,4);
  hmeanmultpbpb->GetYaxis()->CenterTitle();
  hmeanmultpbpb->GetXaxis()->CenterTitle();
  hmeanmultpbpb->GetYaxis()->SetTitleOffset(1.1);
  hmeanmultpbpb->Draw();
  
  float xmumupbpbinconedata_50_1000[] = {0.5};
  float xmumupbpbinconedata_50_1000err[] = {0.0};
  float ymumupbpbinconedata_50_1000[] = {0};
  float ymumupbpbinconedata_50_1000err[] = {0};
  ymumupbpbinconedata_50_1000[0] = hnTrkincone_mumupbpbdata_jt50_1000->GetMean() - hnTrkoutcone_mumupbpbdata_jt50_1000->GetMean();
  incerr = hnTrkincone_mumupbpbdata_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_mumupbpbdata_jt50_1000->GetMeanError();
  ymumupbpbinconedata_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumupbpbinconedata_50_1000 = new TGraphErrors(1,xmumupbpbinconedata_50_1000,ymumupbpbinconedata_50_1000,xmumupbpbinconedata_50_1000err,ymumupbpbinconedata_50_1000err); 
  float xeepbpbinconedata_50_1000[] = {0.55};
  float xeepbpbinconedata_50_1000err[] = {0.0};
  float yeepbpbinconedata_50_1000[] = {0};
  float yeepbpbinconedata_50_1000err[] = {0};
  yeepbpbinconedata_50_1000[0] = hnTrkincone_eepbpbdata_jt50_1000->GetMean() - hnTrkoutcone_eepbpbdata_jt50_1000->GetMean();
  incerr = hnTrkincone_eepbpbdata_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_eepbpbdata_jt50_1000->GetMeanError();
  yeepbpbinconedata_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eepbpbinconedata_50_1000 = new TGraphErrors(1,xeepbpbinconedata_50_1000,yeepbpbinconedata_50_1000,xeepbpbinconedata_50_1000err,yeepbpbinconedata_50_1000err); 
  float xmumupbpbinconemc_50_1000[] = {0.6};
  float xmumupbpbinconemc_50_1000err[] = {0.0};
  float ymumupbpbinconemc_50_1000[] = {0};
  float ymumupbpbinconemc_50_1000err[] = {0};
  ymumupbpbinconemc_50_1000[0] = hnTrkincone_mumupbpbmc_jt50_1000->GetMean() - hnTrkoutcone_mumupbpbmc_jt50_1000->GetMean();
  incerr = hnTrkincone_mumupbpbmc_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_mumupbpbmc_jt50_1000->GetMeanError();
  ymumupbpbinconemc_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumupbpbinconemc_50_1000 = new TGraphErrors(1,xmumupbpbinconemc_50_1000,ymumupbpbinconemc_50_1000,xmumupbpbinconemc_50_1000err,ymumupbpbinconemc_50_1000err); 
  float xeepbpbinconemc_50_1000[] = {0.65};
  float xeepbpbinconemc_50_1000err[] = {0.0};
  float yeepbpbinconemc_50_1000[] = {0};
  float yeepbpbinconemc_50_1000err[] = {0};
  yeepbpbinconemc_50_1000[0] = hnTrkincone_eepbpbmc_jt50_1000->GetMean() - hnTrkoutcone_eepbpbmc_jt50_1000->GetMean();
  incerr = hnTrkincone_eepbpbmc_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_eepbpbmc_jt50_1000->GetMeanError();
  yeepbpbinconemc_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eepbpbinconemc_50_1000 = new TGraphErrors(1,xeepbpbinconemc_50_1000,yeepbpbinconemc_50_1000,xeepbpbinconemc_50_1000err,yeepbpbinconemc_50_1000err); 
  
  float xmumupbpboutconedata_50_1000[] = {0.5};
  float xmumupbpboutconedata_50_1000err[] = {0.0};
  float ymumupbpboutconedata_50_1000[] = {0};
  float ymumupbpboutconedata_50_1000err[] = {0};
  ymumupbpboutconedata_50_1000[0] = hnTrkoutcone_mumupbpbdata_jt50_1000->GetMean();
  ymumupbpboutconedata_50_1000err[0] = hnTrkoutcone_mumupbpbdata_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_mumupbpboutconedata_50_1000 = new TGraphErrors(1,xmumupbpboutconedata_50_1000,ymumupbpboutconedata_50_1000,xmumupbpboutconedata_50_1000err,ymumupbpboutconedata_50_1000err); 
  float xeepbpboutconedata_50_1000[] = {0.52};
  float xeepbpboutconedata_50_1000err[] = {0.0};
  float yeepbpboutconedata_50_1000[] = {0};
  float yeepbpboutconedata_50_1000err[] = {0};
  yeepbpboutconedata_50_1000[0] = hnTrkoutcone_eepbpbdata_jt50_1000->GetMean();
  yeepbpboutconedata_50_1000err[0] = hnTrkoutcone_eepbpbdata_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_eepbpboutconedata_50_1000 = new TGraphErrors(1,xeepbpboutconedata_50_1000,yeepbpboutconedata_50_1000,xeepbpboutconedata_50_1000err,yeepbpboutconedata_50_1000err); 
  float xmumupbpboutconemc_50_1000[] = {0.54};
  float xmumupbpboutconemc_50_1000err[] = {0.0};
  float ymumupbpboutconemc_50_1000[] = {0};
  float ymumupbpboutconemc_50_1000err[] = {0};
  ymumupbpboutconemc_50_1000[0] = hnTrkoutcone_mumupbpbmc_jt50_1000->GetMean();
  ymumupbpboutconemc_50_1000err[0] = hnTrkoutcone_mumupbpbmc_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_mumupbpboutconemc_50_1000 = new TGraphErrors(1,xmumupbpboutconemc_50_1000,ymumupbpboutconemc_50_1000,xmumupbpboutconemc_50_1000err,ymumupbpboutconemc_50_1000err); 
  float xeepbpboutconemc_50_1000[] = {0.56};
  float xeepbpboutconemc_50_1000err[] = {0.0};
  float yeepbpboutconemc_50_1000[] = {0};
  float yeepbpboutconemc_50_1000err[] = {0};
  yeepbpboutconemc_50_1000[0] = hnTrkoutcone_eepbpbmc_jt50_1000->GetMean();
  yeepbpboutconemc_50_1000err[0] = hnTrkoutcone_eepbpbmc_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_eepbpboutconemc_50_1000 = new TGraphErrors(1,xeepbpboutconemc_50_1000,yeepbpboutconemc_50_1000,xeepbpboutconemc_50_1000err,yeepbpboutconemc_50_1000err); 
  
  
  
  
  
  gmeanmult_mumupbpbinconedata_50_1000->Draw("pesame");
  gmeanmult_eepbpbinconedata_50_1000->SetMarkerStyle(21);
  gmeanmult_eepbpbinconedata_50_1000->Draw("pesame");
  gmeanmult_mumupbpbinconemc_50_1000->SetMarkerColor(kRed);
  gmeanmult_mumupbpbinconemc_50_1000->Draw("pesame");
  gmeanmult_eepbpbinconemc_50_1000->SetMarkerStyle(21);
  gmeanmult_eepbpbinconemc_50_1000->SetMarkerColor(kRed);
  gmeanmult_eepbpbinconemc_50_1000->Draw("pesame");
  
  gmeanmult_mumupbpboutconedata_50_1000->SetMarkerStyle(24);
  // gmeanmult_mumupbpboutconedata_50_1000->Draw("pesame");
  gmeanmult_eepbpboutconedata_50_1000->SetMarkerStyle(25);
  // gmeanmult_eepbpboutconedata_50_1000->Draw("pesame");
  gmeanmult_mumupbpboutconemc_50_1000->SetMarkerColor(kRed);
  gmeanmult_mumupbpboutconemc_50_1000->SetMarkerStyle(24);
  // gmeanmult_mumupbpboutconemc_50_1000->Draw("pesame");
  gmeanmult_eepbpboutconemc_50_1000->SetMarkerStyle(25);
  gmeanmult_eepbpboutconemc_50_1000->SetMarkerColor(kRed);
  // gmeanmult_eepbpboutconemc_50_1000->Draw("pesame");
  
  TLegend * legmeanmultpbpb = new TLegend(0.39,0.61,0.74,0.91);
  legmeanmultpbpb->SetFillColor(0);
  legmeanmultpbpb->SetTextSize(0.06);
  legmeanmultpbpb->SetFillStyle(0);
  legmeanmultpbpb->SetTextFont(42);
  legmeanmultpbpb->AddEntry(gmeanmult_mumupbpbinconedata_50_1000,Form("PbPb #mu#mu #sqrt{s_{NN}}=5 TeV"),"p");
  legmeanmultpbpb->AddEntry(gmeanmult_eepbpbinconedata_50_1000,Form("PbPb ee "),"p");
  legmeanmultpbpb->AddEntry(gmeanmult_mumupbpbinconemc_50_1000,Form("Pythia #mu#mu "),"p");
  legmeanmultpbpb->AddEntry(gmeanmult_eepbpbinconemc_50_1000,Form("Pythia ee "),"p");
  // legmeanmultpbpb->AddEntry(gmeanmult_mumupbpbinconedata_50_1000,Form("in cone"),"p");
  // legmeanmultpbpb->AddEntry(gmeanmult_mumupbpboutconedata_50_1000,Form("out of cone"),"p");
  legmeanmultpbpb->Draw();
  cmeanmultpbpb.SaveAs("cmeanmultpbpb_50_1000.png");
  
  TCanvas cmeanmultpp;
  TH2D * hmeanmultpp = new TH2D("hmeanmultpp",";jet p_{T} bin 50_1000;incone - outcone #bar{nTrk}",3,0,3,1,0,4);
  hmeanmultpp->GetYaxis()->CenterTitle();
  hmeanmultpp->GetXaxis()->CenterTitle();
  hmeanmultpp->GetYaxis()->SetTitleOffset(1.1);
  hmeanmultpp->Draw();
  
  float xmumuppinconedata_50_1000[] = {0.5};
  float xmumuppinconedata_50_1000err[] = {0.0};
  float ymumuppinconedata_50_1000[] = {0};
  float ymumuppinconedata_50_1000err[] = {0};
  ymumuppinconedata_50_1000[0] = hnTrkincone_mumuppdata_jt50_1000->GetMean() - hnTrkoutcone_mumuppdata_jt50_1000->GetMean();
  incerr = hnTrkincone_mumuppdata_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_mumuppdata_jt50_1000->GetMeanError();
  ymumuppinconedata_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumuppinconedata_50_1000 = new TGraphErrors(1,xmumuppinconedata_50_1000,ymumuppinconedata_50_1000,xmumuppinconedata_50_1000err,ymumuppinconedata_50_1000err); 
  float xeeppinconedata_50_1000[] = {0.55};
  float xeeppinconedata_50_1000err[] = {0.0};
  float yeeppinconedata_50_1000[] = {0};
  float yeeppinconedata_50_1000err[] = {0};
  yeeppinconedata_50_1000[0] = hnTrkincone_eeppdata_jt50_1000->GetMean() - hnTrkoutcone_eeppdata_jt50_1000->GetMean();
  incerr = hnTrkincone_eeppdata_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_eeppdata_jt50_1000->GetMeanError();
  yeeppinconedata_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eeppinconedata_50_1000 = new TGraphErrors(1,xeeppinconedata_50_1000,yeeppinconedata_50_1000,xeeppinconedata_50_1000err,yeeppinconedata_50_1000err); 
  float xmumuppinconemc_50_1000[] = {0.6};
  float xmumuppinconemc_50_1000err[] = {0.0};
  float ymumuppinconemc_50_1000[] = {0};
  float ymumuppinconemc_50_1000err[] = {0};
  ymumuppinconemc_50_1000[0] = hnTrkincone_mumuppmc_jt50_1000->GetMean() - hnTrkoutcone_mumuppmc_jt50_1000->GetMean();
  incerr = hnTrkincone_mumuppmc_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_mumuppmc_jt50_1000->GetMeanError();
  ymumuppinconemc_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumuppinconemc_50_1000 = new TGraphErrors(1,xmumuppinconemc_50_1000,ymumuppinconemc_50_1000,xmumuppinconemc_50_1000err,ymumuppinconemc_50_1000err); 
  float xeeppinconemc_50_1000[] = {0.65};
  float xeeppinconemc_50_1000err[] = {0.0};
  float yeeppinconemc_50_1000[] = {0};
  float yeeppinconemc_50_1000err[] = {0};
  yeeppinconemc_50_1000[0] = hnTrkincone_eeppmc_jt50_1000->GetMean() - hnTrkoutcone_eeppmc_jt50_1000->GetMean();
  incerr = hnTrkincone_eeppmc_jt50_1000->GetMeanError();
  outcerr = hnTrkoutcone_eeppmc_jt50_1000->GetMeanError();
  yeeppinconemc_50_1000err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eeppinconemc_50_1000 = new TGraphErrors(1,xeeppinconemc_50_1000,yeeppinconemc_50_1000,xeeppinconemc_50_1000err,yeeppinconemc_50_1000err); 
  
  float xmumuppoutconedata_50_1000[] = {0.5};
  float xmumuppoutconedata_50_1000err[] = {0.0};
  float ymumuppoutconedata_50_1000[] = {0};
  float ymumuppoutconedata_50_1000err[] = {0};
  ymumuppoutconedata_50_1000[0] = hnTrkoutcone_mumuppdata_jt50_1000->GetMean();
  ymumuppoutconedata_50_1000err[0] = hnTrkoutcone_mumuppdata_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_mumuppoutconedata_50_1000 = new TGraphErrors(1,xmumuppoutconedata_50_1000,ymumuppoutconedata_50_1000,xmumuppoutconedata_50_1000err,ymumuppoutconedata_50_1000err); 
  float xeeppoutconedata_50_1000[] = {0.52};
  float xeeppoutconedata_50_1000err[] = {0.0};
  float yeeppoutconedata_50_1000[] = {0};
  float yeeppoutconedata_50_1000err[] = {0};
  yeeppoutconedata_50_1000[0] = hnTrkoutcone_eeppdata_jt50_1000->GetMean();
  yeeppoutconedata_50_1000err[0] = hnTrkoutcone_eeppdata_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_eeppoutconedata_50_1000 = new TGraphErrors(1,xeeppoutconedata_50_1000,yeeppoutconedata_50_1000,xeeppoutconedata_50_1000err,yeeppoutconedata_50_1000err); 
  float xmumuppoutconemc_50_1000[] = {0.54};
  float xmumuppoutconemc_50_1000err[] = {0.0};
  float ymumuppoutconemc_50_1000[] = {0};
  float ymumuppoutconemc_50_1000err[] = {0};
  ymumuppoutconemc_50_1000[0] = hnTrkoutcone_mumuppmc_jt50_1000->GetMean();
  ymumuppoutconemc_50_1000err[0] = hnTrkoutcone_mumuppmc_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_mumuppoutconemc_50_1000 = new TGraphErrors(1,xmumuppoutconemc_50_1000,ymumuppoutconemc_50_1000,xmumuppoutconemc_50_1000err,ymumuppoutconemc_50_1000err); 
  float xeeppoutconemc_50_1000[] = {0.56};
  float xeeppoutconemc_50_1000err[] = {0.0};
  float yeeppoutconemc_50_1000[] = {0};
  float yeeppoutconemc_50_1000err[] = {0};
  yeeppoutconemc_50_1000[0] = hnTrkoutcone_eeppmc_jt50_1000->GetMean();
  yeeppoutconemc_50_1000err[0] = hnTrkoutcone_eeppmc_jt50_1000->GetMeanError();
  TGraphErrors * gmeanmult_eeppoutconemc_50_1000 = new TGraphErrors(1,xeeppoutconemc_50_1000,yeeppoutconemc_50_1000,xeeppoutconemc_50_1000err,yeeppoutconemc_50_1000err); 
  
  
  
  
  
  gmeanmult_mumuppinconedata_50_1000->Draw("pesame");
  gmeanmult_eeppinconedata_50_1000->SetMarkerStyle(21);
  gmeanmult_eeppinconedata_50_1000->Draw("pesame");
  gmeanmult_mumuppinconemc_50_1000->SetMarkerColor(kRed);
  gmeanmult_mumuppinconemc_50_1000->Draw("pesame");
  gmeanmult_eeppinconemc_50_1000->SetMarkerStyle(21);
  gmeanmult_eeppinconemc_50_1000->SetMarkerColor(kRed);
  gmeanmult_eeppinconemc_50_1000->Draw("pesame");
  
  gmeanmult_mumuppoutconedata_50_1000->SetMarkerStyle(24);
  // gmeanmult_mumuppoutconedata_50_1000->Draw("pesame");
  gmeanmult_eeppoutconedata_50_1000->SetMarkerStyle(25);
  // gmeanmult_eeppoutconedata_50_1000->Draw("pesame");
  gmeanmult_mumuppoutconemc_50_1000->SetMarkerColor(kRed);
  gmeanmult_mumuppoutconemc_50_1000->SetMarkerStyle(24);
  // gmeanmult_mumuppoutconemc_50_1000->Draw("pesame");
  gmeanmult_eeppoutconemc_50_1000->SetMarkerStyle(25);
  gmeanmult_eeppoutconemc_50_1000->SetMarkerColor(kRed);
  // gmeanmult_eeppoutconemc_50_1000->Draw("pesame");
  
  TLegend * legmeanmultpp = new TLegend(0.39,0.61,0.74,0.91);
  legmeanmultpp->SetFillColor(0);
  legmeanmultpp->SetTextSize(0.06);
  legmeanmultpp->SetFillStyle(0);
  legmeanmultpp->SetTextFont(42);
  legmeanmultpp->AddEntry(gmeanmult_mumuppinconedata_50_1000,Form("pp #mu#mu #sqrt{s_{NN}}=5 TeV"),"p");
  legmeanmultpp->AddEntry(gmeanmult_eeppinconedata_50_1000,Form("pp ee "),"p");
  legmeanmultpp->AddEntry(gmeanmult_mumuppinconemc_50_1000,Form("Pythia #mu#mu "),"p");
  legmeanmultpp->AddEntry(gmeanmult_eeppinconemc_50_1000,Form("Pythia ee "),"p");
  // legmeanmultpp->AddEntry(gmeanmult_mumuppinconedata_50_1000,Form("in cone"),"p");
  // legmeanmultpp->AddEntry(gmeanmult_mumuppoutconedata_50_1000,Form("out of cone"),"p");
  legmeanmultpp->Draw();
  cmeanmultpp.SaveAs("cmeanmultpp_50_1000.png");
  
  // TCanvas cmeanmultpp;
  // TH2D * hmeanmultpp = new TH2D("hmeanmultpp",";jet p_{T} bin 50_1000;#bar{nTrk}",3,0,3,1,0,10);
  // hmeanmultpp->GetYaxis()->CenterTitle();
  // hmeanmultpp->GetXaxis()->CenterTitle();
  // hmeanmultpp->GetYaxis()->SetTitleOffset(1.1);
  // hmeanmultpp->Draw();
  
  // float xmumuppinconedata_50_1000[] = {0.5};
  // float xmumuppinconedata_50_1000err[] = {0.0};
  // float ymumuppinconedata_50_1000[] = {0};
  // float ymumuppinconedata_50_1000err[] = {0};
  // ymumuppinconedata_50_1000[0] = hnTrkincone_mumuppdata_jt50_1000->GetMean();
  // ymumuppinconedata_50_1000err[0] = hnTrkincone_mumuppdata_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_mumuppinconedata_50_1000 = new TGraphErrors(1,xmumuppinconedata_50_1000,ymumuppinconedata_50_1000,xmumuppinconedata_50_1000err,ymumuppinconedata_50_1000err); 
  // float xeeppinconedata_50_1000[] = {0.52};
  // float xeeppinconedata_50_1000err[] = {0.0};
  // float yeeppinconedata_50_1000[] = {0};
  // float yeeppinconedata_50_1000err[] = {0};
  // yeeppinconedata_50_1000[0] = hnTrkincone_eeppdata_jt50_1000->GetMean();
  // yeeppinconedata_50_1000err[0] = hnTrkincone_eeppdata_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_eeppinconedata_50_1000 = new TGraphErrors(1,xeeppinconedata_50_1000,yeeppinconedata_50_1000,xeeppinconedata_50_1000err,yeeppinconedata_50_1000err); 
  // float xmumuppinconemc_50_1000[] = {0.54};
  // float xmumuppinconemc_50_1000err[] = {0.0};
  // float ymumuppinconemc_50_1000[] = {0};
  // float ymumuppinconemc_50_1000err[] = {0};
  // ymumuppinconemc_50_1000[0] = hnTrkincone_mumuppmc_jt50_1000->GetMean();
  // ymumuppinconemc_50_1000err[0] = hnTrkincone_mumuppmc_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_mumuppinconemc_50_1000 = new TGraphErrors(1,xmumuppinconemc_50_1000,ymumuppinconemc_50_1000,xmumuppinconemc_50_1000err,ymumuppinconemc_50_1000err); 
  // float xeeppinconemc_50_1000[] = {0.56};
  // float xeeppinconemc_50_1000err[] = {0.0};
  // float yeeppinconemc_50_1000[] = {0};
  // float yeeppinconemc_50_1000err[] = {0};
  // yeeppinconemc_50_1000[0] = hnTrkincone_eeppmc_jt50_1000->GetMean();
  // yeeppinconemc_50_1000err[0] = hnTrkincone_eeppmc_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_eeppinconemc_50_1000 = new TGraphErrors(1,xeeppinconemc_50_1000,yeeppinconemc_50_1000,xeeppinconemc_50_1000err,yeeppinconemc_50_1000err); 
  
   // float xmumuppoutconedata_50_1000[] = {0.5};
  // float xmumuppoutconedata_50_1000err[] = {0.0};
  // float ymumuppoutconedata_50_1000[] = {0};
  // float ymumuppoutconedata_50_1000err[] = {0};
  // ymumuppoutconedata_50_1000[0] = hnTrkoutcone_mumuppdata_jt50_1000->GetMean();
  // ymumuppoutconedata_50_1000err[0] = hnTrkoutcone_mumuppdata_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_mumuppoutconedata_50_1000 = new TGraphErrors(1,xmumuppoutconedata_50_1000,ymumuppoutconedata_50_1000,xmumuppoutconedata_50_1000err,ymumuppoutconedata_50_1000err); 
  // float xeeppoutconedata_50_1000[] = {0.52};
  // float xeeppoutconedata_50_1000err[] = {0.0};
  // float yeeppoutconedata_50_1000[] = {0};
  // float yeeppoutconedata_50_1000err[] = {0};
  // yeeppoutconedata_50_1000[0] = hnTrkoutcone_eeppdata_jt50_1000->GetMean();
  // yeeppoutconedata_50_1000err[0] = hnTrkoutcone_eeppdata_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_eeppoutconedata_50_1000 = new TGraphErrors(1,xeeppoutconedata_50_1000,yeeppoutconedata_50_1000,xeeppoutconedata_50_1000err,yeeppoutconedata_50_1000err); 
  // float xmumuppoutconemc_50_1000[] = {0.54};
  // float xmumuppoutconemc_50_1000err[] = {0.0};
  // float ymumuppoutconemc_50_1000[] = {0};
  // float ymumuppoutconemc_50_1000err[] = {0};
  // ymumuppoutconemc_50_1000[0] = hnTrkoutcone_mumuppmc_jt50_1000->GetMean();
  // ymumuppoutconemc_50_1000err[0] = hnTrkoutcone_mumuppmc_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_mumuppoutconemc_50_1000 = new TGraphErrors(1,xmumuppoutconemc_50_1000,ymumuppoutconemc_50_1000,xmumuppoutconemc_50_1000err,ymumuppoutconemc_50_1000err); 
  // float xeeppoutconemc_50_1000[] = {0.56};
  // float xeeppoutconemc_50_1000err[] = {0.0};
  // float yeeppoutconemc_50_1000[] = {0};
  // float yeeppoutconemc_50_1000err[] = {0};
  // yeeppoutconemc_50_1000[0] = hnTrkoutcone_eeppmc_jt50_1000->GetMean();
  // yeeppoutconemc_50_1000err[0] = hnTrkoutcone_eeppmc_jt50_1000->GetMeanError();
  // TGraphErrors * gmeanmult_eeppoutconemc_50_1000 = new TGraphErrors(1,xeeppoutconemc_50_1000,yeeppoutconemc_50_1000,xeeppoutconemc_50_1000err,yeeppoutconemc_50_1000err); 
  
  
  
  
  
  // gmeanmult_mumuppinconedata_50_1000->Draw("pesame");
  // gmeanmult_eeppinconedata_50_1000->SetMarkerStyle(21);
  // gmeanmult_eeppinconedata_50_1000->Draw("pesame");
  // gmeanmult_mumuppinconemc_50_1000->SetMarkerColor(kRed);
  // gmeanmult_mumuppinconemc_50_1000->Draw("pesame");
  // gmeanmult_eeppinconemc_50_1000->SetMarkerStyle(21);
  // gmeanmult_eeppinconemc_50_1000->SetMarkerColor(kRed);
  // gmeanmult_eeppinconemc_50_1000->Draw("pesame");
  
  // gmeanmult_mumuppoutconedata_50_1000->SetMarkerStyle(24);
  // gmeanmult_mumuppoutconedata_50_1000->Draw("pesame");
  // gmeanmult_eeppoutconedata_50_1000->SetMarkerStyle(25);
  // gmeanmult_eeppoutconedata_50_1000->Draw("pesame");
  // gmeanmult_mumuppoutconemc_50_1000->SetMarkerColor(kRed);
  // gmeanmult_mumuppoutconemc_50_1000->SetMarkerStyle(24);
  // gmeanmult_mumuppoutconemc_50_1000->Draw("pesame");
  // gmeanmult_eeppoutconemc_50_1000->SetMarkerStyle(25);
  // gmeanmult_eeppoutconemc_50_1000->SetMarkerColor(kRed);
  // gmeanmult_eeppoutconemc_50_1000->Draw("pesame");
  
  // TLegend * legmeanmultpp = new TLegend(0.39,0.55,0.74,0.91);
  // legmeanmultpp->SetFillColor(0);
  // legmeanmultpp->SetTextSize(0.06);
  // legmeanmultpp->SetFillStyle(0);
  // legmeanmultpp->SetTextFont(42);
  // legmeanmultpp->AddEntry(gmeanmult_mumuppinconedata_50_1000,Form("pp #mu#mu #sqrt{s_{NN}}=5 TeV"),"p");
  // legmeanmultpp->AddEntry(gmeanmult_eeppinconedata_50_1000,Form("pp ee "),"p");
  // legmeanmultpp->AddEntry(gmeanmult_mumuppinconemc_50_1000,Form("Pythia #mu#mu "),"p");
  // legmeanmultpp->AddEntry(gmeanmult_eeppinconemc_50_1000,Form("Pythia ee "),"p");
  // legmeanmultpp->AddEntry(gmeanmult_mumuppinconedata_50_1000,Form("in cone"),"p");
  // legmeanmultpp->AddEntry(gmeanmult_mumuppoutconedata_50_1000,Form("out of cone"),"p");
  // legmeanmultpp->Draw();
  // cmeanmultpp.SaveAs("cmeanmultpp_50_1000.png");
}


