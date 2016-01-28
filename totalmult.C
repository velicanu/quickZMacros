{
  TCanvas cmeanmultpbpb;
  TH2D * hmeanmultpbpb = new TH2D("hmeanmultpbpb",";jet p_{T} bin 30_40;incone - outcone #bar{totalPt} (GeV/c)",3,0,3,1,0,20);
  hmeanmultpbpb->GetYaxis()->CenterTitle();
  hmeanmultpbpb->GetXaxis()->CenterTitle();
  hmeanmultpbpb->GetYaxis()->SetTitleOffset(1.1);
  hmeanmultpbpb->Draw();
  
  float xmumupbpbinconedata_30_40[] = {0.5};
  float xmumupbpbinconedata_30_40err[] = {0.0};
  float ymumupbpbinconedata_30_40[] = {0};
  float ymumupbpbinconedata_30_40err[] = {0};
  ymumupbpbinconedata_30_40[0] = htotalPtincone_mumupbpbdata_jt30_40->GetMean() - htotalPtoutcone_mumupbpbdata_jt30_40->GetMean();
  incerr = htotalPtincone_mumupbpbdata_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_mumupbpbdata_jt30_40->GetMeanError();
  ymumupbpbinconedata_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumupbpbinconedata_30_40 = new TGraphErrors(1,xmumupbpbinconedata_30_40,ymumupbpbinconedata_30_40,xmumupbpbinconedata_30_40err,ymumupbpbinconedata_30_40err); 
  float xeepbpbinconedata_30_40[] = {0.55};
  float xeepbpbinconedata_30_40err[] = {0.0};
  float yeepbpbinconedata_30_40[] = {0};
  float yeepbpbinconedata_30_40err[] = {0};
  yeepbpbinconedata_30_40[0] = htotalPtincone_eepbpbdata_jt30_40->GetMean() - htotalPtoutcone_eepbpbdata_jt30_40->GetMean();
  incerr = htotalPtincone_eepbpbdata_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_eepbpbdata_jt30_40->GetMeanError();
  yeepbpbinconedata_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eepbpbinconedata_30_40 = new TGraphErrors(1,xeepbpbinconedata_30_40,yeepbpbinconedata_30_40,xeepbpbinconedata_30_40err,yeepbpbinconedata_30_40err); 
  float xmumupbpbinconemc_30_40[] = {0.6};
  float xmumupbpbinconemc_30_40err[] = {0.0};
  float ymumupbpbinconemc_30_40[] = {0};
  float ymumupbpbinconemc_30_40err[] = {0};
  ymumupbpbinconemc_30_40[0] = htotalPtincone_mumupbpbmc_jt30_40->GetMean() - htotalPtoutcone_mumupbpbmc_jt30_40->GetMean();
  incerr = htotalPtincone_mumupbpbmc_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_mumupbpbmc_jt30_40->GetMeanError();
  ymumupbpbinconemc_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumupbpbinconemc_30_40 = new TGraphErrors(1,xmumupbpbinconemc_30_40,ymumupbpbinconemc_30_40,xmumupbpbinconemc_30_40err,ymumupbpbinconemc_30_40err); 
  float xeepbpbinconemc_30_40[] = {0.65};
  float xeepbpbinconemc_30_40err[] = {0.0};
  float yeepbpbinconemc_30_40[] = {0};
  float yeepbpbinconemc_30_40err[] = {0};
  yeepbpbinconemc_30_40[0] = htotalPtincone_eepbpbmc_jt30_40->GetMean() - htotalPtoutcone_eepbpbmc_jt30_40->GetMean();
  incerr = htotalPtincone_eepbpbmc_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_eepbpbmc_jt30_40->GetMeanError();
  yeepbpbinconemc_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eepbpbinconemc_30_40 = new TGraphErrors(1,xeepbpbinconemc_30_40,yeepbpbinconemc_30_40,xeepbpbinconemc_30_40err,yeepbpbinconemc_30_40err); 
  
  float xmumupbpboutconedata_30_40[] = {0.5};
  float xmumupbpboutconedata_30_40err[] = {0.0};
  float ymumupbpboutconedata_30_40[] = {0};
  float ymumupbpboutconedata_30_40err[] = {0};
  ymumupbpboutconedata_30_40[0] = htotalPtoutcone_mumupbpbdata_jt30_40->GetMean();
  ymumupbpboutconedata_30_40err[0] = htotalPtoutcone_mumupbpbdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_mumupbpboutconedata_30_40 = new TGraphErrors(1,xmumupbpboutconedata_30_40,ymumupbpboutconedata_30_40,xmumupbpboutconedata_30_40err,ymumupbpboutconedata_30_40err); 
  float xeepbpboutconedata_30_40[] = {0.55};
  float xeepbpboutconedata_30_40err[] = {0.0};
  float yeepbpboutconedata_30_40[] = {0};
  float yeepbpboutconedata_30_40err[] = {0};
  yeepbpboutconedata_30_40[0] = htotalPtoutcone_eepbpbdata_jt30_40->GetMean();
  yeepbpboutconedata_30_40err[0] = htotalPtoutcone_eepbpbdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_eepbpboutconedata_30_40 = new TGraphErrors(1,xeepbpboutconedata_30_40,yeepbpboutconedata_30_40,xeepbpboutconedata_30_40err,yeepbpboutconedata_30_40err); 
  float xmumupbpboutconemc_30_40[] = {0.60};
  float xmumupbpboutconemc_30_40err[] = {0.0};
  float ymumupbpboutconemc_30_40[] = {0};
  float ymumupbpboutconemc_30_40err[] = {0};
  ymumupbpboutconemc_30_40[0] = htotalPtoutcone_mumupbpbmc_jt30_40->GetMean();
  ymumupbpboutconemc_30_40err[0] = htotalPtoutcone_mumupbpbmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_mumupbpboutconemc_30_40 = new TGraphErrors(1,xmumupbpboutconemc_30_40,ymumupbpboutconemc_30_40,xmumupbpboutconemc_30_40err,ymumupbpboutconemc_30_40err); 
  float xeepbpboutconemc_30_40[] = {0.65};
  float xeepbpboutconemc_30_40err[] = {0.0};
  float yeepbpboutconemc_30_40[] = {0};
  float yeepbpboutconemc_30_40err[] = {0};
  yeepbpboutconemc_30_40[0] = htotalPtoutcone_eepbpbmc_jt30_40->GetMean();
  yeepbpboutconemc_30_40err[0] = htotalPtoutcone_eepbpbmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_eepbpboutconemc_30_40 = new TGraphErrors(1,xeepbpboutconemc_30_40,yeepbpboutconemc_30_40,xeepbpboutconemc_30_40err,yeepbpboutconemc_30_40err); 
  
  
  
  
  
  gmeanmult_mumupbpbinconedata_30_40->Draw("pesame");
  gmeanmult_eepbpbinconedata_30_40->SetMarkerStyle(21);
  gmeanmult_eepbpbinconedata_30_40->Draw("pesame");
  gmeanmult_mumupbpbinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult_mumupbpbinconemc_30_40->Draw("pesame");
  gmeanmult_eepbpbinconemc_30_40->SetMarkerStyle(21);
  gmeanmult_eepbpbinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult_eepbpbinconemc_30_40->Draw("pesame");
  
  gmeanmult_mumupbpboutconedata_30_40->SetMarkerStyle(24);
  // gmeanmult_mumupbpboutconedata_30_40->Draw("pesame");
  gmeanmult_eepbpboutconedata_30_40->SetMarkerStyle(25);
  // gmeanmult_eepbpboutconedata_30_40->Draw("pesame");
  gmeanmult_mumupbpboutconemc_30_40->SetMarkerColor(kRed);
  gmeanmult_mumupbpboutconemc_30_40->SetMarkerStyle(24);
  // gmeanmult_mumupbpboutconemc_30_40->Draw("pesame");
  gmeanmult_eepbpboutconemc_30_40->SetMarkerStyle(25);
  gmeanmult_eepbpboutconemc_30_40->SetMarkerColor(kRed);
  // gmeanmult_eepbpboutconemc_30_40->Draw("pesame");
  
  TLegend * legmeanmultpbpb = new TLegend(0.39,0.61,0.74,0.91);
  legmeanmultpbpb->SetFillColor(0);
  legmeanmultpbpb->SetTextSize(0.06);
  legmeanmultpbpb->SetFillStyle(0);
  legmeanmultpbpb->SetTextFont(42);
  legmeanmultpbpb->AddEntry(gmeanmult_mumupbpbinconedata_30_40,Form("PbPb #mu#mu #sqrt{s_{NN}}=5 TeV"),"p");
  legmeanmultpbpb->AddEntry(gmeanmult_eepbpbinconedata_30_40,Form("PbPb ee "),"p");
  legmeanmultpbpb->AddEntry(gmeanmult_mumupbpbinconemc_30_40,Form("Pythia+Hydjet #mu#mu "),"p");
  legmeanmultpbpb->AddEntry(gmeanmult_eepbpbinconemc_30_40,Form("Pythia+Hydjet ee "),"p");
  // legmeanmultpbpb->AddEntry(gmeanmult_mumupbpbinconedata_30_40,Form("in cone"),"p");
  // legmeanmultpbpb->AddEntry(gmeanmult_mumupbpboutconedata_30_40,Form("out of cone"),"p");
  legmeanmultpbpb->Draw();
  cmeanmultpbpb.SaveAs("cmeanmultpbpb_30_40.png");

//===========================================================================================//

   TCanvas c1meanmultpbpb;
  TH2D * h1meanmultpbpb = new TH2D("h1meanmult1pbpb",";jet p_{T} bin 30_40;#bar{totalPt} (GeV/c)",3,0,3,1,0,30);
  h1meanmult1pbpb->GetYaxis()->CenterTitle();
  h1meanmult1pbpb->GetXaxis()->CenterTitle();
  h1meanmult1pbpb->GetYaxis()->SetTitleOffset(1.1);
  h1meanmult1pbpb->Draw();
  
  float x1mumupbpbinconedata_30_40[] = {0.5};
  float x1mumupbpbinconedata_30_40err[] = {0.0};
  float y1mumupbpbinconedata_30_40[] = {0};
  float y1mumupbpbinconedata_30_40err[] = {0};
  y1mumupbpbinconedata_30_40[0] = htotalPtincone_mumupbpbdata_jt30_40->GetMean();
  y1mumupbpbinconedata_30_40err[0] = htotalPtincone_mumupbpbdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumupbpbinconedata_30_40 = new TGraphErrors(1,x1mumupbpbinconedata_30_40,y1mumupbpbinconedata_30_40,x1mumupbpbinconedata_30_40err,y1mumupbpbinconedata_30_40err); 
  float x1eepbpbinconedata_30_40[] = {0.55};
  float x1eepbpbinconedata_30_40err[] = {0.0};
  float y1eepbpbinconedata_30_40[] = {0};
  float y1eepbpbinconedata_30_40err[] = {0};
  y1eepbpbinconedata_30_40[0] = htotalPtincone_eepbpbdata_jt30_40->GetMean();
  y1eepbpbinconedata_30_40err[0] = htotalPtincone_eepbpbdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eepbpbinconedata_30_40 = new TGraphErrors(1,x1eepbpbinconedata_30_40,y1eepbpbinconedata_30_40,x1eepbpbinconedata_30_40err,y1eepbpbinconedata_30_40err); 
  float x1mumupbpbinconemc_30_40[] = {0.60};
  float x1mumupbpbinconemc_30_40err[] = {0.0};
  float y1mumupbpbinconemc_30_40[] = {0};
  float y1mumupbpbinconemc_30_40err[] = {0};
  y1mumupbpbinconemc_30_40[0] = htotalPtincone_mumupbpbmc_jt30_40->GetMean();
  y1mumupbpbinconemc_30_40err[0] = htotalPtincone_mumupbpbmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumupbpbinconemc_30_40 = new TGraphErrors(1,x1mumupbpbinconemc_30_40,y1mumupbpbinconemc_30_40,x1mumupbpbinconemc_30_40err,y1mumupbpbinconemc_30_40err); 
  float x1eepbpbinconemc_30_40[] = {0.65};
  float x1eepbpbinconemc_30_40err[] = {0.0};
  float y1eepbpbinconemc_30_40[] = {0};
  float y1eepbpbinconemc_30_40err[] = {0};
  y1eepbpbinconemc_30_40[0] = htotalPtincone_eepbpbmc_jt30_40->GetMean();
  y1eepbpbinconemc_30_40err[0] = htotalPtincone_eepbpbmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eepbpbinconemc_30_40 = new TGraphErrors(1,x1eepbpbinconemc_30_40,y1eepbpbinconemc_30_40,x1eepbpbinconemc_30_40err,y1eepbpbinconemc_30_40err); 
  
  float x1mumupbpboutconedata_30_40[] = {0.5};
  float x1mumupbpboutconedata_30_40err[] = {0.0};
  float y1mumupbpboutconedata_30_40[] = {0};
  float y1mumupbpboutconedata_30_40err[] = {0};
  y1mumupbpboutconedata_30_40[0] = htotalPtoutcone_mumupbpbdata_jt30_40->GetMean();
  y1mumupbpboutconedata_30_40err[0] = htotalPtoutcone_mumupbpbdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumupbpboutconedata_30_40 = new TGraphErrors(1,x1mumupbpboutconedata_30_40,y1mumupbpboutconedata_30_40,x1mumupbpboutconedata_30_40err,y1mumupbpboutconedata_30_40err); 
  float x1eepbpboutconedata_30_40[] = {0.55};
  float x1eepbpboutconedata_30_40err[] = {0.0};
  float y1eepbpboutconedata_30_40[] = {0};
  float y1eepbpboutconedata_30_40err[] = {0};
  y1eepbpboutconedata_30_40[0] = htotalPtoutcone_eepbpbdata_jt30_40->GetMean();
  y1eepbpboutconedata_30_40err[0] = htotalPtoutcone_eepbpbdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eepbpboutconedata_30_40 = new TGraphErrors(1,x1eepbpboutconedata_30_40,y1eepbpboutconedata_30_40,x1eepbpboutconedata_30_40err,y1eepbpboutconedata_30_40err); 
  float x1mumupbpboutconemc_30_40[] = {0.60};
  float x1mumupbpboutconemc_30_40err[] = {0.0};
  float y1mumupbpboutconemc_30_40[] = {0};
  float y1mumupbpboutconemc_30_40err[] = {0};
  y1mumupbpboutconemc_30_40[0] = htotalPtoutcone_mumupbpbmc_jt30_40->GetMean();
  y1mumupbpboutconemc_30_40err[0] = htotalPtoutcone_mumupbpbmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumupbpboutconemc_30_40 = new TGraphErrors(1,x1mumupbpboutconemc_30_40,y1mumupbpboutconemc_30_40,x1mumupbpboutconemc_30_40err,y1mumupbpboutconemc_30_40err); 
  float x1eepbpboutconemc_30_40[] = {0.65};
  float x1eepbpboutconemc_30_40err[] = {0.0};
  float y1eepbpboutconemc_30_40[] = {0};
  float y1eepbpboutconemc_30_40err[] = {0};
  y1eepbpboutconemc_30_40[0] = htotalPtoutcone_eepbpbmc_jt30_40->GetMean();
  y1eepbpboutconemc_30_40err[0] = htotalPtoutcone_eepbpbmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eepbpboutconemc_30_40 = new TGraphErrors(1,x1eepbpboutconemc_30_40,y1eepbpboutconemc_30_40,x1eepbpboutconemc_30_40err,y1eepbpboutconemc_30_40err); 
  
  
  
  
  
  gmeanmult1_mumupbpbinconedata_30_40->Draw("pesame");
  gmeanmult1_eepbpbinconedata_30_40->SetMarkerStyle(21);
  gmeanmult1_eepbpbinconedata_30_40->Draw("pesame");
  gmeanmult1_mumupbpbinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_mumupbpbinconemc_30_40->Draw("pesame");
  gmeanmult1_eepbpbinconemc_30_40->SetMarkerStyle(21);
  gmeanmult1_eepbpbinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_eepbpbinconemc_30_40->Draw("pesame");
  
  gmeanmult1_mumupbpboutconedata_30_40->SetMarkerStyle(24);
  gmeanmult1_mumupbpboutconedata_30_40->Draw("pesame");
  gmeanmult1_eepbpboutconedata_30_40->SetMarkerStyle(25);
  gmeanmult1_eepbpboutconedata_30_40->Draw("pesame");
  gmeanmult1_mumupbpboutconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_mumupbpboutconemc_30_40->SetMarkerStyle(24);
  gmeanmult1_mumupbpboutconemc_30_40->Draw("pesame");
  gmeanmult1_eepbpboutconemc_30_40->SetMarkerStyle(25);
  gmeanmult1_eepbpboutconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_eepbpboutconemc_30_40->Draw("pesame");
  
  TLegend * leg1meanmultpbpb = new TLegend(0.39,0.55,0.74,0.91);
  leg1meanmultpbpb->SetFillColor(0);
  leg1meanmultpbpb->SetTextSize(0.06);
  leg1meanmultpbpb->SetFillStyle(0);
  leg1meanmultpbpb->SetTextFont(42);
  leg1meanmultpbpb->AddEntry(gmeanmult1_mumupbpbinconedata_30_40,Form("PbPb #mu#mu #sqrt{s_{NN}}=5 TeV"),"p");
  leg1meanmultpbpb->AddEntry(gmeanmult1_eepbpbinconedata_30_40,Form("PbPb ee "),"p");
  leg1meanmultpbpb->AddEntry(gmeanmult1_mumupbpbinconemc_30_40,Form("Pythia+Hydjet #mu#mu "),"p");
  leg1meanmultpbpb->AddEntry(gmeanmult1_eepbpbinconemc_30_40,Form("Pythia+Hydjet ee "),"p");
  leg1meanmultpbpb->AddEntry(gmeanmult1_mumupbpbinconedata_30_40,Form("in cone"),"p");
  leg1meanmultpbpb->AddEntry(gmeanmult1_mumupbpboutconedata_30_40,Form("out of cone"),"p");
  leg1meanmultpbpb->Draw();
  c1meanmultpbpb.SaveAs("c1meanmultpbpb_30_40.png");





  TCanvas cmeanmultpp;
  TH2D * hmeanmultpp = new TH2D("hmeanmultpp",";jet p_{T} bin 30_40;incone - outcone #bar{totalPt} (GeV/c)",3,0,3,1,0,30);
  hmeanmultpp->GetYaxis()->CenterTitle();
  hmeanmultpp->GetXaxis()->CenterTitle();
  hmeanmultpp->GetYaxis()->SetTitleOffset(1.1);
  hmeanmultpp->Draw();
  
  float xmumuppinconedata_30_40[] = {0.5};
  float xmumuppinconedata_30_40err[] = {0.0};
  float ymumuppinconedata_30_40[] = {0};
  float ymumuppinconedata_30_40err[] = {0};
  ymumuppinconedata_30_40[0] = htotalPtincone_mumuppdata_jt30_40->GetMean() - htotalPtoutcone_mumuppdata_jt30_40->GetMean();
  incerr = htotalPtincone_mumuppdata_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_mumuppdata_jt30_40->GetMeanError();
  ymumuppinconedata_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumuppinconedata_30_40 = new TGraphErrors(1,xmumuppinconedata_30_40,ymumuppinconedata_30_40,xmumuppinconedata_30_40err,ymumuppinconedata_30_40err); 
  float xeeppinconedata_30_40[] = {0.55};
  float xeeppinconedata_30_40err[] = {0.0};
  float yeeppinconedata_30_40[] = {0};
  float yeeppinconedata_30_40err[] = {0};
  yeeppinconedata_30_40[0] = htotalPtincone_eeppdata_jt30_40->GetMean() - htotalPtoutcone_eeppdata_jt30_40->GetMean();
  incerr = htotalPtincone_eeppdata_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_eeppdata_jt30_40->GetMeanError();
  yeeppinconedata_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eeppinconedata_30_40 = new TGraphErrors(1,xeeppinconedata_30_40,yeeppinconedata_30_40,xeeppinconedata_30_40err,yeeppinconedata_30_40err); 
  float xmumuppinconemc_30_40[] = {0.6};
  float xmumuppinconemc_30_40err[] = {0.0};
  float ymumuppinconemc_30_40[] = {0};
  float ymumuppinconemc_30_40err[] = {0};
  ymumuppinconemc_30_40[0] = htotalPtincone_mumuppmc_jt30_40->GetMean() - htotalPtoutcone_mumuppmc_jt30_40->GetMean();
  incerr = htotalPtincone_mumuppmc_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_mumuppmc_jt30_40->GetMeanError();
  ymumuppinconemc_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_mumuppinconemc_30_40 = new TGraphErrors(1,xmumuppinconemc_30_40,ymumuppinconemc_30_40,xmumuppinconemc_30_40err,ymumuppinconemc_30_40err); 
  float xeeppinconemc_30_40[] = {0.65};
  float xeeppinconemc_30_40err[] = {0.0};
  float yeeppinconemc_30_40[] = {0};
  float yeeppinconemc_30_40err[] = {0};
  yeeppinconemc_30_40[0] = htotalPtincone_eeppmc_jt30_40->GetMean() - htotalPtoutcone_eeppmc_jt30_40->GetMean();
  incerr = htotalPtincone_eeppmc_jt30_40->GetMeanError();
  outcerr = htotalPtoutcone_eeppmc_jt30_40->GetMeanError();
  yeeppinconemc_30_40err[0] = sqrt((incerr*incerr)+(outcerr*outcerr));
  TGraphErrors * gmeanmult_eeppinconemc_30_40 = new TGraphErrors(1,xeeppinconemc_30_40,yeeppinconemc_30_40,xeeppinconemc_30_40err,yeeppinconemc_30_40err); 
  
  float xmumuppoutconedata_30_40[] = {0.5};
  float xmumuppoutconedata_30_40err[] = {0.0};
  float ymumuppoutconedata_30_40[] = {0};
  float ymumuppoutconedata_30_40err[] = {0};
  ymumuppoutconedata_30_40[0] = htotalPtoutcone_mumuppdata_jt30_40->GetMean();
  ymumuppoutconedata_30_40err[0] = htotalPtoutcone_mumuppdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_mumuppoutconedata_30_40 = new TGraphErrors(1,xmumuppoutconedata_30_40,ymumuppoutconedata_30_40,xmumuppoutconedata_30_40err,ymumuppoutconedata_30_40err); 
  float xeeppoutconedata_30_40[] = {0.55};
  float xeeppoutconedata_30_40err[] = {0.0};
  float yeeppoutconedata_30_40[] = {0};
  float yeeppoutconedata_30_40err[] = {0};
  yeeppoutconedata_30_40[0] = htotalPtoutcone_eeppdata_jt30_40->GetMean();
  yeeppoutconedata_30_40err[0] = htotalPtoutcone_eeppdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_eeppoutconedata_30_40 = new TGraphErrors(1,xeeppoutconedata_30_40,yeeppoutconedata_30_40,xeeppoutconedata_30_40err,yeeppoutconedata_30_40err); 
  float xmumuppoutconemc_30_40[] = {0.60};
  float xmumuppoutconemc_30_40err[] = {0.0};
  float ymumuppoutconemc_30_40[] = {0};
  float ymumuppoutconemc_30_40err[] = {0};
  ymumuppoutconemc_30_40[0] = htotalPtoutcone_mumuppmc_jt30_40->GetMean();
  ymumuppoutconemc_30_40err[0] = htotalPtoutcone_mumuppmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_mumuppoutconemc_30_40 = new TGraphErrors(1,xmumuppoutconemc_30_40,ymumuppoutconemc_30_40,xmumuppoutconemc_30_40err,ymumuppoutconemc_30_40err); 
  float xeeppoutconemc_30_40[] = {0.65};
  float xeeppoutconemc_30_40err[] = {0.0};
  float yeeppoutconemc_30_40[] = {0};
  float yeeppoutconemc_30_40err[] = {0};
  yeeppoutconemc_30_40[0] = htotalPtoutcone_eeppmc_jt30_40->GetMean();
  yeeppoutconemc_30_40err[0] = htotalPtoutcone_eeppmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult_eeppoutconemc_30_40 = new TGraphErrors(1,xeeppoutconemc_30_40,yeeppoutconemc_30_40,xeeppoutconemc_30_40err,yeeppoutconemc_30_40err); 
  
  
  
  
  
  gmeanmult_mumuppinconedata_30_40->Draw("pesame");
  gmeanmult_eeppinconedata_30_40->SetMarkerStyle(21);
  gmeanmult_eeppinconedata_30_40->Draw("pesame");
  gmeanmult_mumuppinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult_mumuppinconemc_30_40->Draw("pesame");
  gmeanmult_eeppinconemc_30_40->SetMarkerStyle(21);
  gmeanmult_eeppinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult_eeppinconemc_30_40->Draw("pesame");
  
  gmeanmult_mumuppoutconedata_30_40->SetMarkerStyle(24);
  // gmeanmult_mumuppoutconedata_30_40->Draw("pesame");
  gmeanmult_eeppoutconedata_30_40->SetMarkerStyle(25);
  // gmeanmult_eeppoutconedata_30_40->Draw("pesame");
  gmeanmult_mumuppoutconemc_30_40->SetMarkerColor(kRed);
  gmeanmult_mumuppoutconemc_30_40->SetMarkerStyle(24);
  // gmeanmult_mumuppoutconemc_30_40->Draw("pesame");
  gmeanmult_eeppoutconemc_30_40->SetMarkerStyle(25);
  gmeanmult_eeppoutconemc_30_40->SetMarkerColor(kRed);
  // gmeanmult_eeppoutconemc_30_40->Draw("pesame");
  
  TLegend * legmeanmultpp = new TLegend(0.39,0.61,0.74,0.91);
  legmeanmultpp->SetFillColor(0);
  legmeanmultpp->SetTextSize(0.06);
  legmeanmultpp->SetFillStyle(0);
  legmeanmultpp->SetTextFont(42);
  legmeanmultpp->AddEntry(gmeanmult_mumuppinconedata_30_40,Form("pp #mu#mu #sqrt{s_{NN}}=5 TeV"),"p");
  legmeanmultpp->AddEntry(gmeanmult_eeppinconedata_30_40,Form("pp ee "),"p");
  legmeanmultpp->AddEntry(gmeanmult_mumuppinconemc_30_40,Form("Pythia #mu#mu "),"p");
  legmeanmultpp->AddEntry(gmeanmult_eeppinconemc_30_40,Form("Pythia ee "),"p");
  // legmeanmultpp->AddEntry(gmeanmult_mumuppinconedata_30_40,Form("in cone"),"p");
  // legmeanmultpp->AddEntry(gmeanmult_mumuppoutconedata_30_40,Form("out of cone"),"p");
  legmeanmultpp->Draw();
  cmeanmultpp.SaveAs("cmeanmultpp_30_40.png");

//===========================================================================================//

   TCanvas c1meanmultpp;
  TH2D * h1meanmultpp = new TH2D("h1meanmult1pp",";jet p_{T} bin 30_40;#bar{totalPt} (GeV/c)",3,0,3,1,0,30);
  h1meanmult1pp->GetYaxis()->CenterTitle();
  h1meanmult1pp->GetXaxis()->CenterTitle();
  h1meanmult1pp->GetYaxis()->SetTitleOffset(1.1);
  h1meanmult1pp->Draw();
  
  float x1mumuppinconedata_30_40[] = {0.5};
  float x1mumuppinconedata_30_40err[] = {0.0};
  float y1mumuppinconedata_30_40[] = {0};
  float y1mumuppinconedata_30_40err[] = {0};
  y1mumuppinconedata_30_40[0] = htotalPtincone_mumuppdata_jt30_40->GetMean();
  y1mumuppinconedata_30_40err[0] = htotalPtincone_mumuppdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumuppinconedata_30_40 = new TGraphErrors(1,x1mumuppinconedata_30_40,y1mumuppinconedata_30_40,x1mumuppinconedata_30_40err,y1mumuppinconedata_30_40err); 
  float x1eeppinconedata_30_40[] = {0.55};
  float x1eeppinconedata_30_40err[] = {0.0};
  float y1eeppinconedata_30_40[] = {0};
  float y1eeppinconedata_30_40err[] = {0};
  y1eeppinconedata_30_40[0] = htotalPtincone_eeppdata_jt30_40->GetMean();
  y1eeppinconedata_30_40err[0] = htotalPtincone_eeppdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eeppinconedata_30_40 = new TGraphErrors(1,x1eeppinconedata_30_40,y1eeppinconedata_30_40,x1eeppinconedata_30_40err,y1eeppinconedata_30_40err); 
  float x1mumuppinconemc_30_40[] = {0.60};
  float x1mumuppinconemc_30_40err[] = {0.0};
  float y1mumuppinconemc_30_40[] = {0};
  float y1mumuppinconemc_30_40err[] = {0};
  y1mumuppinconemc_30_40[0] = htotalPtincone_mumuppmc_jt30_40->GetMean();
  y1mumuppinconemc_30_40err[0] = htotalPtincone_mumuppmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumuppinconemc_30_40 = new TGraphErrors(1,x1mumuppinconemc_30_40,y1mumuppinconemc_30_40,x1mumuppinconemc_30_40err,y1mumuppinconemc_30_40err); 
  float x1eeppinconemc_30_40[] = {0.65};
  float x1eeppinconemc_30_40err[] = {0.0};
  float y1eeppinconemc_30_40[] = {0};
  float y1eeppinconemc_30_40err[] = {0};
  y1eeppinconemc_30_40[0] = htotalPtincone_eeppmc_jt30_40->GetMean();
  y1eeppinconemc_30_40err[0] = htotalPtincone_eeppmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eeppinconemc_30_40 = new TGraphErrors(1,x1eeppinconemc_30_40,y1eeppinconemc_30_40,x1eeppinconemc_30_40err,y1eeppinconemc_30_40err); 
  
  float x1mumuppoutconedata_30_40[] = {0.5};
  float x1mumuppoutconedata_30_40err[] = {0.0};
  float y1mumuppoutconedata_30_40[] = {0};
  float y1mumuppoutconedata_30_40err[] = {0};
  y1mumuppoutconedata_30_40[0] = htotalPtoutcone_mumuppdata_jt30_40->GetMean();
  y1mumuppoutconedata_30_40err[0] = htotalPtoutcone_mumuppdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumuppoutconedata_30_40 = new TGraphErrors(1,x1mumuppoutconedata_30_40,y1mumuppoutconedata_30_40,x1mumuppoutconedata_30_40err,y1mumuppoutconedata_30_40err); 
  float x1eeppoutconedata_30_40[] = {0.55};
  float x1eeppoutconedata_30_40err[] = {0.0};
  float y1eeppoutconedata_30_40[] = {0};
  float y1eeppoutconedata_30_40err[] = {0};
  y1eeppoutconedata_30_40[0] = htotalPtoutcone_eeppdata_jt30_40->GetMean();
  y1eeppoutconedata_30_40err[0] = htotalPtoutcone_eeppdata_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eeppoutconedata_30_40 = new TGraphErrors(1,x1eeppoutconedata_30_40,y1eeppoutconedata_30_40,x1eeppoutconedata_30_40err,y1eeppoutconedata_30_40err); 
  float x1mumuppoutconemc_30_40[] = {0.60};
  float x1mumuppoutconemc_30_40err[] = {0.0};
  float y1mumuppoutconemc_30_40[] = {0};
  float y1mumuppoutconemc_30_40err[] = {0};
  y1mumuppoutconemc_30_40[0] = htotalPtoutcone_mumuppmc_jt30_40->GetMean();
  y1mumuppoutconemc_30_40err[0] = htotalPtoutcone_mumuppmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_mumuppoutconemc_30_40 = new TGraphErrors(1,x1mumuppoutconemc_30_40,y1mumuppoutconemc_30_40,x1mumuppoutconemc_30_40err,y1mumuppoutconemc_30_40err); 
  float x1eeppoutconemc_30_40[] = {0.65};
  float x1eeppoutconemc_30_40err[] = {0.0};
  float y1eeppoutconemc_30_40[] = {0};
  float y1eeppoutconemc_30_40err[] = {0};
  y1eeppoutconemc_30_40[0] = htotalPtoutcone_eeppmc_jt30_40->GetMean();
  y1eeppoutconemc_30_40err[0] = htotalPtoutcone_eeppmc_jt30_40->GetMeanError();
  TGraphErrors * gmeanmult1_eeppoutconemc_30_40 = new TGraphErrors(1,x1eeppoutconemc_30_40,y1eeppoutconemc_30_40,x1eeppoutconemc_30_40err,y1eeppoutconemc_30_40err); 
  
  
  
  
  
  gmeanmult1_mumuppinconedata_30_40->Draw("pesame");
  gmeanmult1_eeppinconedata_30_40->SetMarkerStyle(21);
  gmeanmult1_eeppinconedata_30_40->Draw("pesame");
  gmeanmult1_mumuppinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_mumuppinconemc_30_40->Draw("pesame");
  gmeanmult1_eeppinconemc_30_40->SetMarkerStyle(21);
  gmeanmult1_eeppinconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_eeppinconemc_30_40->Draw("pesame");
  
  gmeanmult1_mumuppoutconedata_30_40->SetMarkerStyle(24);
  gmeanmult1_mumuppoutconedata_30_40->Draw("pesame");
  gmeanmult1_eeppoutconedata_30_40->SetMarkerStyle(25);
  gmeanmult1_eeppoutconedata_30_40->Draw("pesame");
  gmeanmult1_mumuppoutconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_mumuppoutconemc_30_40->SetMarkerStyle(24);
  gmeanmult1_mumuppoutconemc_30_40->Draw("pesame");
  gmeanmult1_eeppoutconemc_30_40->SetMarkerStyle(25);
  gmeanmult1_eeppoutconemc_30_40->SetMarkerColor(kRed);
  gmeanmult1_eeppoutconemc_30_40->Draw("pesame");
  
  TLegend * leg1meanmultpp = new TLegend(0.39,0.55,0.74,0.91);
  leg1meanmultpp->SetFillColor(0);
  leg1meanmultpp->SetTextSize(0.06);
  leg1meanmultpp->SetFillStyle(0);
  leg1meanmultpp->SetTextFont(42);
  leg1meanmultpp->AddEntry(gmeanmult1_mumuppinconedata_30_40,Form("pp #mu#mu #sqrt{s_{NN}}=5 TeV"),"p");
  leg1meanmultpp->AddEntry(gmeanmult1_eeppinconedata_30_40,Form("pp ee "),"p");
  leg1meanmultpp->AddEntry(gmeanmult1_mumuppinconemc_30_40,Form("Pythia #mu#mu "),"p");
  leg1meanmultpp->AddEntry(gmeanmult1_eeppinconemc_30_40,Form("Pythia ee "),"p");
  leg1meanmultpp->AddEntry(gmeanmult1_mumuppinconedata_30_40,Form("in cone"),"p");
  leg1meanmultpp->AddEntry(gmeanmult1_mumuppoutconedata_30_40,Form("out of cone"),"p");
  leg1meanmultpp->Draw();
  c1meanmultpp.SaveAs("c1meanmultpp_30_40.png");


}