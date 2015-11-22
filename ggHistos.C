#include "ggTree.h"

bool goodMuon(int imu) {
   if(muChi2NDF->at(imu)<10
      && muMuonHits->at(imu)>0
      && muStations->at(imu)>1
      && muTrkLayers->at(imu)>5
      && muPixelHits->at(imu)>0
      && fabs(muInnerD0->at(imu))<0.2
      && fabs(muInnerDz->at(imu))<0.5
      ) return true;
   else return false;
}

bool goodElectron(int i) {
 if(fabs(eleSCEta->at(i))<1.479) {
   if(  fabs(eledEtaAtVtx->at(i))<0.0094
	&& fabs(eledPhiAtVtx->at(i))<0.0296
	&& eleSigmaIEtaIEta->at(i)<0.0101
	&& eleHoverE->at(i)<0.0372
	&& fabs(eleD0->at(i))<0.0151
	&& fabs(eleDz->at(i))<0.238
	&& fabs(eleEoverPInv->at(i))<0.118
	&& eleMissHits->at(i) <= 2
	) return true;
   else return false;
 }
 if(fabs(eleSCEta->at(i))>1.479) {
   if(  fabs(eledEtaAtVtx->at(i))<0.00773
	&& fabs(eledPhiAtVtx->at(i))<0.148
	&& eleSigmaIEtaIEta->at(i)<0.0287
	&& eleHoverE->at(i)<0.0546
	&& fabs(eleD0->at(i))<0.0535
	&& fabs(eleDz->at(i))<0.572
	&& fabs(eleEoverPInv->at(i))<0.104
	&& eleMissHits->at(i) <= 1
	) return true;
   else return false;
 }
 else return false;
}

void ggHistos(TString infilename="HiForest.root", TString outfilename="histos.root") {

 TH1::SetDefaultSumw2();

 typedef struct {
   Float_t mass, pt, rapidity, eta, phi;
   Int_t charge;
 } CAND;
 static CAND Zmumu;
 static CAND Zee;

 TTree *mutree = new TTree("mutree","Zmumu candidates from ggHiNtuplizer");
 mutree->Branch("Zmumu",&Zmumu,"mass:pt:rapidity:eta:phi/F:charge/I");
 TTree *eltree = new TTree("eltree","Zee candidates from ggHiNtuplizer");
 eltree->Branch("Zee",&Zee,"mass:pt:rapidity:eta:phi/F:charge/I");

 const int nPtBins = 13;
 const double PtBins[nPtBins+1]={0,2.5,5.0,7.5,10.0,12.5,15.0,20,30,40,50,70,100,150};
 const int nYBins = 13;

 TH1F *mmMass = new TH1F("mmMass",";m^{#mu#mu} (GeV/c^{2});Events",30,60,120);
 TH1F *mmMassSS = new TH1F("mmMassSS",";m^{#mu#mu} (GeV/c^{2});Events",30,60,120);

 TH1F *mmPt = new TH1F("mmPt",";p_{T}^{#mu#mu} (GeV/c);dN/dp_{T}",nPtBins,PtBins);
 TH1F *mmY = new TH1F("mmY",";y^{#mu#mu};Events",nYBins,-2.6,2.6);
 TH1F *mmPhi = new TH1F("mmPhi",";#phi^{#mu#mu};Events",20,-pi,pi);

 TH1F *eeMass = new TH1F("eeMass",";m^{ee} (GeV/c^{2});Events",30,60,120);
 TH1F *eeMassSS = new TH1F("eeMassSS",";m^{ee} (GeV/c^{2});Events",30,60,120);

 TH1F *eePt = new TH1F("eePt",";p_{T}^{ee} (GeV/c);dN/dp_{T}",nPtBins,PtBins);
 TH1F *eeY = new TH1F("eeY",";y^{ee};Events",nYBins,-2.6,2.6);
 TH1F *eePhi = new TH1F("eePhi",";#phi^{ee};Events",20,-pi,pi);

 int nMuPair = 0;
 int nElPair = 0;

 TFile fin(infilename);

 TFile *fout = new TFile(outfilename,"recreate");

 TTree *inTree = (TTree*)fin.Get("ggHiNtuplizer/EventTree");
 if(!inTree){
    cout<<"Could not access tree!"<<endl;
    return;
 }
 initTree(inTree);

 int nEv = inTree->GetEntries();

 for (int j=0; j<nEv; j++) {

   inTree->GetEntry(j);
   if(j%40000 == 0) cout << "Processing event: " << j << endl;

   for(int i1 = 0; i1 < nMu; i1++) {

    if(muPt->at(i1)>10 && fabs(muEta->at(i1))<2.4 && goodMuon(i1)) {

       for(int i2 = i1; i2 < nMu; i2++) {

          if(muPt->at(i2)>10 && fabs(muEta->at(i2))<2.4 && goodMuon(i2)) {

	    TLorentzVector muon1, muon2;
	    muon1.SetPtEtaPhiM(muPt->at(i1), muEta->at(i1), muPhi->at(i1), 0.105658);
	    muon2.SetPtEtaPhiM(muPt->at(i2), muEta->at(i2), muPhi->at(i2), 0.105658);
            TLorentzVector pair = muon1 + muon2;

	    if(pair.M()>60 && pair.M()<120) {

	     Zmumu.mass = pair.M();
	     Zmumu.pt = pair.Pt();
	     Zmumu.rapidity = pair.Rapidity();
	     Zmumu.eta = pair.Eta();
	     Zmumu.phi = pair.Phi();
	     Zmumu.charge = muCharge->at(i1) + muCharge->at(i2);
	     mutree->Fill();

             if(muCharge->at(i1) != muCharge->at(i2)) {
		mmMass->Fill(pair.M());
		mmPt->Fill(pair.Pt());
		mmY->Fill(pair.Rapidity());
		mmPhi->Fill(pair.Phi());
	        nMuPair++;
	     }
	     else {
		mmMassSS->Fill(pair.M());
	     }

	    }
          }
       }
    }
   } //end of muon loop

   for(int i1 = 0; i1 < nEle; i1++) {

    if(elePt->at(i1)>10 && fabs(eleSCEta->at(i1))<2.5 && goodElectron(i1) && (fabs(eleSCEta->at(i1))<1.4442 || fabs(eleSCEta->at(i1))>1.566)) {

       for(int i2 = i1; i2 < nEle; i2++) {

          if(elePt->at(i2)>10 && fabs(eleSCEta->at(i2))<2.5 && goodElectron(i2) && (fabs(eleSCEta->at(i2))<1.4442 || fabs(eleSCEta->at(i2))>1.566)) {

	    TLorentzVector ele1, ele2;
	    ele1.SetPtEtaPhiM(elePt->at(i1), eleEta->at(i1), elePhi->at(i1), 0.000511);
	    ele2.SetPtEtaPhiM(elePt->at(i2), eleEta->at(i2), elePhi->at(i2), 0.000511);
            TLorentzVector pair = ele1 + ele2;

	    if(pair.M()>60 && pair.M()<120) {

	     Zee.mass = pair.M();
	     Zee.pt = pair.Pt();
	     Zee.rapidity = pair.Rapidity();
	     Zee.eta = pair.Eta();
	     Zee.phi = pair.Phi();
	     Zee.charge = eleCharge->at(i1) + eleCharge->at(i2);
	     eltree->Fill();

             if(eleCharge->at(i1) != eleCharge->at(i2)) {
		eeMass->Fill(pair.M());
		eePt->Fill(pair.Pt());
		eeY->Fill(pair.Rapidity());
		eePhi->Fill(pair.Phi());
	        nElPair++;
	     }
	     else {
		eeMassSS->Fill(pair.M());
	     }

	    }
          }
       }
    }
   } //end of electron loop

 } //end of loop over events

 for(int i=0; i<nPtBins; i++) {
   double width = PtBins[i+1]-PtBins[i];
   mmPt->SetBinContent(i+1,mmPt->GetBinContent(i+1)/width);
   mmPt->SetBinError(i+1,mmPt->GetBinError(i+1)/width);
 }

 for(int i=0; i<nPtBins; i++) {
   double width = PtBins[i+1]-PtBins[i];
   eePt->SetBinContent(i+1,eePt->GetBinContent(i+1)/width);
   eePt->SetBinError(i+1,eePt->GetBinError(i+1)/width);
 }

 cout << mmMass->GetEntries() << endl;
 cout << "Number of muon pairs " << nMuPair << endl;
 cout << "same sign = " << mmMassSS->GetEntries() << endl << endl;

 cout << eeMass->GetEntries() << endl;
 cout << "Number of electron pairs " << nElPair << endl;
 cout << "same sign = " << eeMassSS->GetEntries() << endl << endl;

 fout->cd();
 mutree->Write();
 eltree->Write();
 mmMass->Write();
 mmMassSS->Write();
 mmPt->Write();
 mmY->Write();
 mmPhi->Write();
 eeMass->Write();
 eeMassSS->Write();
 eePt->Write();
 eeY->Write();
 eePhi->Write();
 fout->Write();

}
