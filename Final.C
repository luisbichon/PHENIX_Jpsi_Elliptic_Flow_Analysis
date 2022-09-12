#define Final_cxx
#include "Final.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>
#include <iostream>

void Final::Loop()
{

TFile *F1 =TFile::Open("/direct/phenix+u/lbichon/Run14AuAu200/17923/Jpsi/Efficiency/Eff_10.root");
TH2D *Eff = (TH2D*)F1->Get("Eff_10");


TH1D *hmass_000 = new TH1D("hmass_000", ";Mass;Counts", 50, 2, 5);
TH1D *hmass_010 = new TH1D("hmass_010", ";Mass;Counts", 50, 2, 5);
TH1D *hmass_001 = new TH1D("hmass_001", ";Mass;Counts", 50, 2, 5);
TH1D *hmass_011 = new TH1D("hmass_011", ";Mass;Counts", 50, 2, 5);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   cout<<nentries<<endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

//      Float_t psi_s = CompactEPArray_psi[10];   //BBC REACTION PLANE
//      Float_t psi_n = CompactEPArray_psi[11];   //BBC REACTION PLANE
//
      Float_t psi_s = CompactEPArray_psi[17];   //TRUE
      Float_t psi_n = CompactEPArray_psi[18];   //TRUE

//      Float_t psi_n = CompactEPArray_psi[17];     //SAME_ARM
//      Float_t psi_s = CompactEPArray_psi[18];     //SAME_ARM
//
//      Float_t psi_s = CompactEPArray_psi[16];   //CNT
//      Float_t psi_n = CompactEPArray_psi[16];   //CNT



      Float_t Evt_Cent = Evt_Cent[nentries];

      for (Int_t idmu = 0; idmu<nDiMuons; idmu++){

        Float_t mass = DiMuons_mass[idmu];
        Bool_t se = DiMuons_same_event[idmu];
        Short_t charge = DiMuons_charge[idmu];
        Float_t dcar = DiMuons_dca_r[idmu];
        Float_t px = DiMuons_Px[idmu];
        Float_t py = DiMuons_Py[idmu];
        Float_t rapidity = DiMuons_rapidity[idmu];
        Short_t lg0 = DiMuons_Tr0_lastgap[idmu];
        Short_t lg1 = DiMuons_Tr1_lastgap[idmu];
        Float_t chi = DiMuons_Evt_vtxchi2[idmu];
        Float_t px0 = DiMuons_Tr0_px[idmu];
        Float_t py0 = DiMuons_Tr0_py[idmu];
        Float_t rap0 = DiMuons_Tr0_rapidity[idmu];
        Float_t rap1 = DiMuons_Tr1_rapidity[idmu];
        Float_t px1 = DiMuons_Tr1_px[idmu];
        Float_t py1 = DiMuons_Tr1_py[idmu];
        Float_t pz0 = DiMuons_Tr0_pz[idmu];
        Float_t pz1 = DiMuons_Tr1_pz[idmu];
        Float_t DG0_0 = DiMuons_Tr0_DG0[idmu];
        Float_t DG0_1 = DiMuons_Tr1_DG0[idmu];
        Float_t DDG0_0 = DiMuons_Tr0_DDG0[idmu];
        Float_t DDG0_1 = DiMuons_Tr1_DDG0[idmu];
        Float_t trchi2_0 = DiMuons_Tr0_trchi2[idmu];
        Float_t trchi2_1 = DiMuons_Tr1_trchi2[idmu];
        Float_t idchi2_0 = DiMuons_Tr0_idchi2[idmu];
        Float_t idchi2_1 = DiMuons_Tr1_idchi2[idmu];
        Float_t fvtxchi2_0 = DiMuons_Tr0_chi2_fvtxmutr[idmu];
        Float_t fvtxchi2_1 = DiMuons_Tr1_chi2_fvtxmutr[idmu];
        Float_t fvtxnhits_0 = DiMuons_Tr0_nhits_fvtx[idmu];
        Float_t fvtxnhits_1 = DiMuons_Tr1_nhits_fvtx[idmu];
        Float_t dcar0 = DiMuons_Tr0_dca_r[idmu];
        Float_t dcar1 = DiMuons_Tr1_dca_r[idmu];
        Float_t xst01 = DiMuons_Tr0_xst1[idmu];
        Float_t xst11 = DiMuons_Tr1_xst1[idmu];
        Float_t yst01 = DiMuons_Tr0_yst1[idmu];
        Float_t yst11 = DiMuons_Tr1_yst1[idmu];

        Short_t ntrhits0 = DiMuons_Tr0_ntrhits[idmu];
        Short_t ntrhits1 = DiMuons_Tr1_ntrhits[idmu];
        Short_t nidhits0 = DiMuons_Tr0_nidhits[idmu];
        Short_t nidhits1 = DiMuons_Tr1_nidhits[idmu];

        Float_t pt = TMath::Sqrt(px*px + py*py);
        Float_t pt0 = TMath::Sqrt(px0*px0 + py0*py0);
        Float_t pt1 = TMath::Sqrt(px1*px1 + py1*py1);
        Float_t p0 = TMath::Sqrt(px0*px0 + py0*py0 + pz0*pz0);
        Float_t p1 = TMath::Sqrt(px1*px1 + py1*py1 + pz1*pz1);

        Int_t octant0 = ((int((atan2(xst01,yst01)+TMath::Pi())/(TMath::Pi()/8))+1)/2)%8;
        Int_t octant1 = ((int((atan2(xst11,yst11)+TMath::Pi())/(TMath::Pi()/8))+1)/2)%8;

        Float_t DG0cut0 = p0*DG0_0;
        Float_t DG0cut1 = p1*DG0_1;

        Float_t DDG0cut0 = p0*DDG0_0;
        Float_t DDG0cut1 = p1*DDG0_1;

        Float_t phi = atan2(py,px);
        Float_t qxn = cos(2*(phi-psi_s));
        Float_t qyn = sin(2*(phi-psi_s));
        Float_t qxs = cos(2*(phi-psi_n));
        Float_t qys = sin(2*(phi-psi_n));

        if (TMath::Abs(rapidity)>1.2 && TMath::Abs(rapidity)<=1.4){
        Int_t i = 1;
        } else if (TMath::Abs(rapidity)>1.4 && TMath::Abs(rapidity)<=1.6){
        Int_t i = 2;
        } else if (TMath::Abs(rapidity)>1.6 && TMath::Abs(rapidity)<=1.8){
        Int_t i = 3;
        } else if (TMath::Abs(rapidity)>1.8 && TMath::Abs(rapidity)<=2.0){
        Int_t i = 4;
        } else if (TMath::Abs(rapidity)>2.0 && TMath::Abs(rapidity)<=2.2){
        Int_t i = 5;
        }

        if (Evt_Cent>10 && Evt_Cent<=20){
        Int_t j = 1;
        } else if (Evt_Cent>20 && Evt_Cent<=30){
        Int_t j = 2;
        } else if (Evt_Cent>30 && Evt_Cent<=40){
        Int_t j = 3;
        } else if (Evt_Cent>40 && Evt_Cent<=50){
        Int_t j = 4;
        } else if (Evt_Cent>50 && Evt_Cent<=60){
        Int_t j = 5;
        }

        Float_t w = 1./Eff->GetBinContent(j,i);

//      cout << i << j <<" " << w <<endl;

        if (charge==0 && octant0!=octant1 && chi<3 && se && rapidity>0.0 && mass>=2 && mass<=5 && TMath::Abs(rap0)<2.2 && TMath::Abs(rap0)>1.2 && TMath::Abs(rap1)<2.2 && TMath::Abs(rap1)>1.2 && pt>=0 && pt<=1 && Evt_Cent<=60 && Evt_Cent>=20 && px!=-9999.900 && py!=-9999.900 && (lg0==3||lg0==4) && (lg1==3||lg1==4) && pt0>=1 && pt1>=1 && DG0cut0<80 && DG0cut1<80 && DDG0cut0<40 && DDG0cut1<40 && trchi2_0<10 && trchi2_1<10 && idchi2_0<3 && idchi2_1<3 && ntrhits0>=6 && ntrhits1>=6 && nidhits0>3 && nidhits1>3 && TMath::Abs(pz0)>=3 && TMath::Abs(pz1)>=3) {
        Float_t dphi_1 = atan2(qys,qxs);
//        Float_t dphi_1 = atan2(qyn,qxn);
        if (dphi_1 < - TMath::Pi()/2){
        dphi_1 = TMath::Abs(dphi_1 + TMath::Pi());
        } else if (dphi_1 > TMath::Pi()/2){
        dphi_1 = TMath::Abs(dphi_1 - TMath::Pi());
        } else if (TMath::Abs(dphi_1) <= TMath::Pi()/2){
        dphi_1 = TMath::Abs(dphi_1);
        }
        if (dphi_1 <= TMath::Pi()/4){
        Float_t mass_01 = mass;
        hmass_000->Fill(mass_01,w);
        }
        if (dphi_1 > TMath::Pi()/4){
        Float_t mass_11 = mass;
        hmass_010->Fill(mass_11,w);
        }

}

        if (charge==0 && octant0!=octant1 && chi<3 && !se && rapidity>0.0 && mass>=2 && mass<=5 && TMath::Abs(rap0)<2.2 && TMath::Abs(rap0)>1.2 && TMath::Abs(rap1)<2.2 && TMath::Abs(rap1)>1.2 && pt>=0 && pt<=1 && Evt_Cent<=60 && Evt_Cent>=20 && px!=-9999.900 && py!=-9999.900 && (lg0==3||lg0==4) && (lg1==3||lg1==4) && pt0>=1 && pt1>=1 && DG0cut0<80 && DG0cut1<80 && DDG0cut0<40 && DDG0cut1<40 && trchi2_0<10 && trchi2_1<10 && idchi2_0<3 && idchi2_1<3 && ntrhits0>=6 && ntrhits1>=6 && nidhits0>3 && nidhits1>3 && TMath::Abs(pz0)>=3 && TMath::Abs(pz1)>=3) {
        Float_t dphi_2 = atan2(qys,qxs);
    //    Float_t dphi_2 = atan2(qyn,qxn);
        if (dphi_2 < - TMath::Pi()/2){
        dphi_2 = TMath::Abs(dphi_2 + TMath::Pi());
        } else if (dphi_2 > TMath::Pi()/2){
        dphi_2 = TMath::Abs(dphi_2 - TMath::Pi());
        } else if (TMath::Abs(dphi_2) <= TMath::Pi()/2){
        dphi_2 = TMath::Abs(dphi_2);
        }
        if (dphi_2 <= TMath::Pi()/4){
        Float_t mass_02 = mass;
        hmass_001->Fill(mass_02,w);
        }
        if (dphi_2 > TMath::Pi()/4){
        Float_t mass_12 = mass;
        hmass_011->Fill(mass_12,w);
        }


}

//cout<<"Rapidity: "<<rapidity<<" Centrality:  "<< Evt_Cent<<" "<<i<<" "<< j<< " " << w<<endl;

        }
//cout<<"Rapidity: "<<rapidity<<" Centrality:  "<< Evt_Cent<<" "<<i<<" "<< j<< " " << w<<endl;


}
//cout<<"Rapidity: "<<rapidity<<" Centrality:  "<< Evt_Cent<<" "<<i<<" "<< j<< " " << w<<endl;



        hmass_000->Draw("e");
        hmass_000->SaveAs("FINAL_2060/1000.root"); //(arm)(dphi)(pt)(event)Q4

        hmass_010->Draw("e");
        hmass_010->SaveAs("FINAL_2060/1100.root"); //(arm)(inout)(pt)(charge)

        hmass_001->Draw("e");
        hmass_001->SaveAs("FINAL_2060/1001.root"); //(arm)(centrality)(inout)(pt)(event) For SB

        hmass_011->Draw("e");
        hmass_011->SaveAs("FINAL_2060/1101.root"); //(arm)(centrality)(inout)(event)(charge) For Normalization



}              
