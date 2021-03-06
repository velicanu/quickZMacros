#define ztree_cxx
#include "ztree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TMath.h>
#include <TCanvas.h>
#include "ggTree.h"

void ztree::Loop(std::string outfname , std::string tag)
{
  TFile * fcentweight = new TFile("/export/d00/scratch/dav2105/ztrees/centweight.root");
  TH1D * h_zmm_data_hibin = (TH1D*) fcentweight->Get("h_zmm_data_hibin");
  TH1D * h_zmm_mcjet_hibin = (TH1D*) fcentweight->Get("h_zmm_mcjet_hibin");
  h_zmm_data_hibin->Divide(h_zmm_mcjet_hibin);
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  TFile * fout = new TFile(outfname.data(),"recreate");
  TH1D * hdphi = new TH1D("hdphi",";#Delta#phi",100,0,TMath::Pi());
  TH1D * hdr = new TH1D("hdr",";#DeltaR",100,0,1);
  TH1D * hdeta = new TH1D("hdeta",";#Delta#eta",100,-2.5,2.5);
  TH1D * hdpt = new TH1D("hdpt",";#Deltap_{T}",100,-2.5,2.5);
  TH1D * hzpt = new TH1D(Form("hzpt_%s",tag.data()),";Z p_{T}",25,0,100);
  TH1D * hzmass = new TH1D(Form("hzmass_%s",tag.data()),";Z p_{T}",60,60,120);
  TH2D * hdptdr = new TH2D("hdptdr",";#Deltap_{T};#DeltaR",100,-2.5,2.5,100,0,1);

  int jetptbins[] = {30,40,50,1000};
  const int njetbins = 3;
  
  TH1D * hnTrkincone[njetbins];
  TH1D * hnTrkoutcone[njetbins];
  TH1D * htotalPtincone[njetbins];
  TH1D * htotalPtoutcone[njetbins];
  TH1D * htrkPtincone[njetbins];
  TH1D * htrkPtoutcone[njetbins];
  TH1D * hnjets[njetbins];
  TH1D * hjetpt[njetbins];
  TH1D * hjeteta[njetbins];
  TH1D * hjetphi[njetbins];
  TH1D * hhiBin[njetbins];
  TH1D * hhiBinWeighted[njetbins];
  for(int k = 0 ; k < njetbins ; ++k)
  {
    hnTrkincone[k] = new TH1D(Form("hnTrkincone_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";nTrk #DeltaR<0.4;",100,0,50);
    hnTrkoutcone[k] = new TH1D(Form("hnTrkoutcone_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";nTrk #DeltaR>0.4;",100,0,50);
    htotalPtincone[k] = new TH1D(Form("htotalPtincone_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";#Sigmap_{T} #DeltaR<0.4;",100,0,50);
    htotalPtoutcone[k] = new TH1D(Form("htotalPtoutcone_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";#Sigmap_{T} #DeltaR>0.4;",100,0,50);
    htrkPtincone[k] = new TH1D(Form("htrkPtincone_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";p_{T} #DeltaR<0.4;",100,0,50);
    htrkPtoutcone[k] = new TH1D(Form("htrkPtoutcone_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";p_{T} #DeltaR>0.4;",100,0,50);
    hnjets[k] = new TH1D(Form("hnjets_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),"",1,0,2);
    hjetpt[k] = new TH1D(Form("hjetpt_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),"",25,0,100);
    hjeteta[k] = new TH1D(Form("hjeteta_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),"",100,-2.5,2.5);
    hjetphi[k] = new TH1D(Form("hjetphi_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),"",100,-TMath::Pi(),TMath::Pi());
    hhiBin[k] = new TH1D(Form("hhiBin_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";hiBin;",200,0,200);
    hhiBinWeighted[k] = new TH1D(Form("hhiBinWeighted_%s_jt%d_%d",tag.data(),jetptbins[k],jetptbins[k+1]),";hiBin;",200,0,200);
  }
  std::vector< std::vector< int > > jetindecies ( njetbins, std::vector<int> ( 0, 0 ) );
  // std::cout<<jetindecies.size()<<" "<<jetindecies[2].size()<<std::endl;
  // jetindecies[2].clear();
  // std::cout<<jetindecies.size()<<" "<<jetindecies[2].size()<<std::endl;
  // return;
  // TH1D * htrkPtincone = new TH1D(Form("htrkPtincone_%s",tag.data()),";p_{T} #DeltaR<0.4;",100,0,50);
  
  
  float jetradius = 0.3;
  for(int k = 0 ; k < njetbins ; ++k)
  {
    hnjets[k]->Sumw2();
    hjeteta[k]->Sumw2();
    hjetphi[k]->Sumw2();
    
    hnTrkincone[k]->Sumw2();
    hnTrkoutcone[k]->Sumw2();
    htotalPtincone[k]->Sumw2();
    htotalPtoutcone[k]->Sumw2();
    htrkPtincone[k]->Sumw2();
    htrkPtoutcone[k]->Sumw2();
    hhiBin[k]->Sumw2();
    hhiBinWeighted[k]->Sumw2();
  }
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if(weight==0)
    {
      weight=1; //data has MC weight = 0 in the tree
    }
    else if(hiBin>-1) //no centrality weight for pp mc
    {
      // weight *= h_zmm_data_hibin->GetBinContent(h_zmm_data_hibin->FindBin(hiBin));
    }
    if(Zpt < 40) continue;
    hzpt->Fill(Zpt,weight);
    hzmass->Fill(Zmass,weight);
    for(int k = 0 ; k < njetbins ; ++k)
    {
      for(int j = 0 ; j < njet ; ++j)
      {
        if(jeteta[j]<jetradius) continue;
        if(jetID==0) continue;
        if(jetpt[j] < jetptbins[k] || jetpt[j] > jetptbins[k+1]) continue;
        jetindecies[k].push_back(j);
        
        hnjets[k]->Fill(1,weight);
        hjetpt[k]->Fill(jetpt[j],weight);
        hjeteta[k]->Fill(jeteta[j],weight);
        hjetphi[k]->Fill(jetphi[j],weight);
      }
    }
    
    
    for(int k = 0 ; k < njetbins ; ++k)
    {
      for(unsigned int j = 0 ; j < jetindecies[k].size() ; ++j)
      {
        int jidx = jetindecies[k][j];
        int ntrkincone = 0 ;
        int ntrkoutcone = 0 ;
        float totalptincone = 0;
        float totalptoutcone = 0;
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
          float dpt1 = (Zlepton1Pt - trkPt[i])/Zlepton1Pt;
          float dpt2 = (Zlepton2Pt - trkPt[i])/Zlepton2Pt;
          
          hdr->Fill(dR1);
          hdr->Fill(dR2);
          hdptdr->Fill(dpt1,dR1);
          hdptdr->Fill(dpt2,dR2);
          
          if( ( dpt1 < 0.2 && dR1 < 0.1 ) || ( dpt2 < 0.2 && dR2 < 0.1 ) ) continue; // skip Z tracks
          
          // Trk pt distribution in and out of cone
        
          float dRjet = sqrt( (jeteta[jidx]-trkEta[i])*(jeteta[jidx]-trkEta[i]) + getDphi(jetphi[jidx],trkPhi[i])*getDphi(jetphi[jidx],trkPhi[i]) );
          float dRcone = sqrt( (-jeteta[jidx]-trkEta[i])*(-jeteta[jidx]-trkEta[i]) + getDphi(jetphi[jidx],trkPhi[i])*getDphi(jetphi[jidx],trkPhi[i]) );
          if(dRjet < jetradius)   
          {
            ntrkincone++;
            htrkPtincone[k]->Fill(trkPt[i],weight);
            totalptincone+=trkPt[i];
          }
          if(dRcone < jetradius)
          {
            ntrkoutcone++;
            htrkPtoutcone[k]->Fill(trkPt[i],weight);
            totalptoutcone+=trkPt[i];
          }
        }
        hnTrkincone[k]->Fill(ntrkincone,weight);
        hnTrkoutcone[k]->Fill(ntrkoutcone,weight);
        htotalPtincone[k]->Fill(totalptincone,weight);
        htotalPtoutcone[k]->Fill(totalptoutcone,weight);
        jetindecies[k].clear(); //clean up vector for next iteration
      }
      hhiBin[k]->Fill(hiBin);
      hhiBinWeighted[k]->Fill(hiBin,weight);
    }
  }
  
  // for(int k = 0 ; k < njetbins ; ++k)
  // {
    // hjetpt[k]->Scale(1.0/hnjets[k]->Integral());
    // hjeteta[k]->Scale(1.0/hnjets[k]->Integral());
    // hjetphi[k]->Scale(1.0/hnjets[k]->Integral());
    // htrkPtincone[k]->Scale(1.0/hnjets[k]->Integral());
    // htrkPtoutcone[k]->Scale(1.0/hnjets[k]->Integral());
  // }
  
  fout->Write();
  fout->Close();
}


int main(int argc, char *argv[])
{
  if(argc != 3 && argc != 4)
  {    
    std::cout<<"usage: ./ztree.exe <infilename> <outfilename>"<<std::endl;
    exit(1);
  }
  ztree * t = new ztree(argv[1]);
  if(argc==3) t->Loop(argv[2]);
  if(argc==4) t->Loop(argv[2],argv[3]);
  return 0;
}


