#define Final1_cxx
#include "Final1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>
#include <iostream>

void Final1::Loop()
{

double massbins[26];
double cosdphibins[21];

for(int mb = 0; mb<26; mb++){
massbins[mb]=2+((3.0*mb)/25);
}

for(int ag = 0; ag<21; ag++){
cosdphibins[ag]=-1+((2.0*ag)/20);
}

TH2D *h2_00 = new TH2D("h2_00", "",25, massbins, 20, cosdphibins);
TH2D *h2_01 = new TH2D("h2_01", "",25, massbins, 20, cosdphibins);
TH2D *h2_02 = new TH2D("h2_02", "",25, massbins, 20, cosdphibins);
TH2D *h2_03 = new TH2D("h2_03", "",25, massbins, 20, cosdphibins);
TH2D *h2_10 = new TH2D("h2_10", "",25, massbins, 20, cosdphibins);
TH2D *h2_11 = new TH2D("h2_11", "",25, massbins, 20, cosdphibins);
TH2D *h2_12 = new TH2D("h2_12", "",25, massbins, 20, cosdphibins);
TH2D *h2_13 = new TH2D("h2_13", "",25, massbins, 20, cosdphibins);

TH1D *h_00 = new TH1D("h_00", "", 25, massbins);
TH1D *h_01 = new TH1D("h_01", "", 25, massbins);
TH1D *h_02 = new TH1D("h_02", "", 25, massbins);
TH1D *h_03 = new TH1D("h_03", "", 25, massbins);
TH1D *h_10 = new TH1D("h_10", "", 25, massbins);
TH1D *h_11 = new TH1D("h_11", "", 25, massbins);
TH1D *h_12 = new TH1D("h_12", "", 25, massbins);
TH1D *h_13 = new TH1D("h_13", "", 25, massbins);

h_00->Sumw2();
h_01->Sumw2();
h_02->Sumw2();
h_03->Sumw2();
h_10->Sumw2();
h_11->Sumw2();
h_12->Sumw2();
h_13->Sumw2();

h2_00->Sumw2();
h2_01->Sumw2();
h2_02->Sumw2();
h2_03->Sumw2();
h2_10->Sumw2();
h2_11->Sumw2();
h2_12->Sumw2();
h2_13->Sumw2();

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   cout<<nentries<<endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

if (jentry%150000==0)
{
cout<<jentry<<" of "<<nentries<<endl;
}

      Float_t psi_s = CompactEPArray_psi[17];   //TRUE
      Float_t psi_n = CompactEPArray_psi[18];   //TRUE
//      Float_t psi_n = CompactEPArray_psi[17];   //SAME_ARM (Systematic)
//      Float_t psi_s = CompactEPArray_psi[18];   //SAME_ARM (Systematic)
//      Float_t psi_s = CompactEPArray_psi[16];   //CNT (Systematic)
//      Float_t psi_n = CompactEPArray_psi[16];   //CNT (Systematic)
//      Float_t psi_s = CompactEPArray_psi[10];   //BBC REACTION PLANE (Systematic)
//      Float_t psi_n = CompactEPArray_psi[11];   //BBC REACTION PLANE (Systematic)



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


        if (charge==0 && pt>=0 && pt<=5 && octant0!=octant1 && chi<3 && rapidity<=2.2 && rapidity>=1.2 && mass>=2 && mass<=5 && TMath::Abs(rap0)<2.2 && TMath::Abs(rap0)>1.2 && TMath::Abs(rap1)<2.2 && TMath::Abs(rap1)>1.2 && Evt_Cent<=60 && Evt_Cent>=10 && px!=-9999.900 && py!=-9999.900 && (lg0==3||lg0==4) && (lg1==3||lg1==4) && pt0>=1 && pt1>=1 && DG0cut0<80 && DG0cut1<80 && DDG0cut0<40 && DDG0cut1<40 && trchi2_0<10 && trchi2_1<10 && idchi2_0<3 && idchi2_1<3 && ntrhits0>=6 && ntrhits1>=6 && nidhits0>3 && nidhits1>3 && TMath::Abs(pz0)>=3 && TMath::Abs(pz1)>=3) {
//cout << w0 << endl; 

        Float_t phi = atan2(py,px);
        Float_t qxn = cos(2*(phi-psi_s));
        Float_t qyn = sin(2*(phi-psi_s));
        Float_t qxs = cos(2*(phi-psi_n));
        Float_t qys = sin(2*(phi-psi_n));

        Float_t dphi = atan2(qyn,qxn);
        if (dphi < - TMath::Pi()/2){
        dphi = TMath::Abs(dphi + TMath::Pi());
        } else if (dphi > TMath::Pi()/2){
        dphi = TMath::Abs(dphi - TMath::Pi());
        } else if (TMath::Abs(dphi) <= TMath::Pi()/2){
        dphi = TMath::Abs(dphi);
        }

if(se && pt>=0 && pt<=1){
Float_t mass_00 = mass;
Float_t v2samp_00 = cos(2*dphi);
h_00->Fill(mass_00);
h2_00->Fill(mass_00,v2samp_00);

}
else if(se && pt>=1 && pt<=2){
Float_t mass_01 = mass;
Float_t v2samp_01 = cos(2*dphi);
h_01->Fill(mass_01);
h2_01->Fill(mass_01,v2samp_01);
}
else if(se && pt>=2 && pt<=3){
Float_t mass_02 = mass;
Float_t v2samp_02 = cos(2*dphi);
h_02->Fill(mass_02);
h2_02->Fill(mass_02,v2samp_02);

}
else if(se && pt>=3 && pt<=5){
Float_t mass_03 = mass;
Float_t v2samp_03 = cos(2*dphi);
h_03->Fill(mass_03);
h2_03->Fill(mass_03,v2samp_03);

}
else if(!se && pt>=0 && pt<=1){
Float_t mass_10 = mass;
Float_t v2samp_10 = cos(2*dphi);
h_10->Fill(mass_10);
h2_10->Fill(mass_10,v2samp_10);

}
else if(!se && pt>=1 && pt<=2){
Float_t mass_11 = mass;
Float_t v2samp_11 = cos(2*dphi);
h_11->Fill(mass_11);
h2_11->Fill(mass_11,v2samp_11);

}
else if(!se && pt>=2 && pt<=3){
Float_t mass_12 = mass;
Float_t v2samp_12 = cos(2*dphi);
h_12->Fill(mass_12);
h2_12->Fill(mass_12,v2samp_12);

}
else if(!se && pt>=3 && pt<=5){
Float_t mass_13 = mass;
Float_t v2samp_13 = cos(2*dphi);
h_13->Fill(mass_13);
h2_13->Fill(mass_13,v2samp_13);

}
}



        }


}


        h2_00->SaveAs("../MES_TRUE/SIDEBAND/100_0.root");
        h2_01->SaveAs("../MES_TRUE/SIDEBAND/101_0.root");
        h2_02->SaveAs("../MES_TRUE/SIDEBAND/102_0.root");
        h2_03->SaveAs("../MES_TRUE/SIDEBAND/103_0.root");
        h2_10->SaveAs("../MES_TRUE/SIDEBAND/110_0.root");
        h2_11->SaveAs("../MES_TRUE/SIDEBAND/111_0.root");
        h2_12->SaveAs("../MES_TRUE/SIDEBAND/112_0.root");
        h2_13->SaveAs("../MES_TRUE/SIDEBAND/113_0.root");


        h_00->SaveAs("../MES_TRUE/MES/100_0.root");
        h_01->SaveAs("../MES_TRUE/MES/101_0.root");
        h_02->SaveAs("../MES_TRUE/MES/102_0.root");
        h_03->SaveAs("../MES_TRUE/MES/103_0.root");
        h_10->SaveAs("../MES_TRUE/MES/110_0.root");
        h_11->SaveAs("../MES_TRUE/MES/111_0.root");
        h_12->SaveAs("../MES_TRUE/MES/112_0.root");
        h_13->SaveAs("../MES_TRUE/MES/113_0.root");


}
