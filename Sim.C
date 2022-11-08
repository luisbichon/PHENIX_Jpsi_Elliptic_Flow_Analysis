#define Sim_cxx
#include "Sim.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Sim::Loop()
{
//(mc/emb)(s/n)(v2sim)(psi_sim)

TH1D *hdphi000 = new TH1D("hdphi000", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi001 = new TH1D("hdphi001", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi002 = new TH1D("hdphi002", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi003 = new TH1D("hdphi003", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi004 = new TH1D("hdphi004", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi005 = new TH1D("hdphi005", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi006 = new TH1D("hdphi006", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi007 = new TH1D("hdphi007", ";dphi;Counts", 25, 0, TMath::Pi()/2);

TH1D *hdphi010 = new TH1D("hdphi010", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi011 = new TH1D("hdphi011", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi012 = new TH1D("hdphi012", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi013 = new TH1D("hdphi013", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi014 = new TH1D("hdphi014", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi015 = new TH1D("hdphi015", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi016 = new TH1D("hdphi016", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi017 = new TH1D("hdphi017", ";dphi;Counts", 25, 0, TMath::Pi()/2);

TH1D *hdphi100 = new TH1D("hdphi100", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi101 = new TH1D("hdphi101", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi102 = new TH1D("hdphi102", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi103 = new TH1D("hdphi103", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi104 = new TH1D("hdphi104", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi105 = new TH1D("hdphi105", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi106 = new TH1D("hdphi106", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi107 = new TH1D("hdphi107", ";dphi;Counts", 25, 0, TMath::Pi()/2);

TH1D *hdphi110 = new TH1D("hdphi110", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi111 = new TH1D("hdphi111", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi112 = new TH1D("hdphi112", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi113 = new TH1D("hdphi113", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi114 = new TH1D("hdphi114", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi115 = new TH1D("hdphi115", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi116 = new TH1D("hdphi116", ";dphi;Counts", 25, 0, TMath::Pi()/2);
TH1D *hdphi117 = new TH1D("hdphi117", ";dphi;Counts", 25, 0, TMath::Pi()/2);

TRandom *rnd = new TRandom();
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
cout<<nentries<<endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      Float_t Evt_Cent = Evt_Cent[nentries];

      for (Int_t imcd = 0; imcd<nMCDiMuons; imcd++){
        Float_t mc_mass = MCDiMuons_mc_mass[imcd];
        Float_t mc_ptot0 = MCDiMuons_mc0_ptot[imcd];
        Float_t mc_ptot1 = MCDiMuons_mc1_ptot[imcd];
        Float_t mc_px0 = MCDiMuons_mc0_px[imcd];
        Float_t mc_py0 = MCDiMuons_mc0_py[imcd];
        Float_t mc_pz0 = MCDiMuons_mc0_pz[imcd];
        Float_t mc_pt0 = TMath::Sqrt(mc_px0*mc_px0+mc_py0*mc_py0);
        Float_t mc_px1 = MCDiMuons_mc1_px[imcd];
        Float_t mc_py1 = MCDiMuons_mc1_py[imcd];
        Float_t mc_pz1 = MCDiMuons_mc1_pz[imcd];
        Float_t mc_px = mc_px0+mc_px1;
        Float_t mc_py = mc_py0+mc_py1;
        Float_t mc_pz = mc_pz0+mc_pz1;;
        Float_t mc_pt1 = TMath::Sqrt(mc_px1*mc_px1+mc_py1*mc_py1);
        Float_t mc_pt = TMath::Sqrt(mc_px*mc_px+mc_py*mc_py);

        Float_t mc_x0 = MCDiMuons_mc0_x[imcd];
        Float_t mc_y0 = MCDiMuons_mc0_y[imcd];
        Float_t mc_x1 = MCDiMuons_mc1_x[imcd];
        Float_t mc_y1 = MCDiMuons_mc1_y[imcd];
        Float_t pid0 = MCDiMuons_mc0_p_pid[imcd];
        Float_t pid1 = MCDiMuons_mc1_p_pid[imcd];
        Float_t pid00 = MCDiMuons_mc1_pid[imcd];
        Float_t pid11 = MCDiMuons_mc0_pid[imcd];

        Float_t mc_ptot = TMath::Sqrt(mc_px*mc_px+mc_py*mc_py+mc_pz*mc_pz);


        Float_t mc_E = TMath::Sqrt((mc_ptot*mc_ptot)+(mc_mass*mc_mass));
        Float_t phi_mc = atan2(mc_py,mc_px);

        Float_t w0 = 1+2*(-0.01)*cos(2*phi_mc);
        Float_t w1 = 1+2*(-0.02)*cos(2*phi_mc);
        Float_t w2 = 1+2*(-0.03)*cos(2*phi_mc);
        Float_t w3 = 1+2*(-0.04)*cos(2*phi_mc);
        Float_t w4 = 1+2*(-0.05)*cos(2*phi_mc);
        Float_t w5 = 1+2*(-0.06)*cos(2*phi_mc);
        Float_t w6 = 1+2*(-0.07)*cos(2*phi_mc);

        Float_t mc_R = 0.5*TMath::Log((mc_E+mc_pz)/(mc_E-mc_pz));

        Float_t psi0 = TMath::Pi()/2;

        Float_t qx0 = cos(2*(phi_mc-psi0));
        Float_t qy0 = sin(2*(phi_mc-psi0));
        Float_t rng = rnd->Gaus(0,0.5);   //sin(2*TMath::Pi()*)*sqrt(-2*log(rndm));

        if(pid00==13 && pid11==-13&&pid0==443&& pid1==443 && mc_mass>0 && mc_R<=-1.2 && mc_R>=-2.2 && Evt_Cent!=50 && Evt_Cent>=10 && Evt_Cent<=60 && mc_pt0>=1 && mc_pt1>=1 && mc_ptot0!=-999 && mc_ptot1!=-999 && mc_pt>0 && mc_pt<=1){
Float_t RAP = TMath::Abs(mc_R);
//      Float_t dphi000 = phi_mc+rng;
        Float_t dphi000 = phi_mc;
        if (dphi000 < - TMath::Pi()/2){
        dphi000 = TMath::Abs(dphi000 + TMath::Pi());
        } else if (dphi000 > TMath::Pi()/2){
        dphi000 = TMath::Abs(dphi000 - TMath::Pi());
        } else if (TMath::Abs(dphi000) <= TMath::Pi()/2){
        dphi000 = TMath::Abs(dphi000);
        }

        hdphi000->Fill(dphi000);
        Float_t w_true_00 = hdphi000->GetEntries()*w0/25;
        Float_t w_true_01 = hdphi000->GetEntries()*w1/25;
        Float_t w_true_02 = hdphi000->GetEntries()*w2/25;
        Float_t w_true_03 = hdphi000->GetEntries()*w3/25;
        Float_t w_true_04 = hdphi000->GetEntries()*w4/25;
        Float_t w_true_05 = hdphi000->GetEntries()*w5/25;
        Float_t w_true_06 = hdphi000->GetEntries()*w6/25;

        hdphi001->Fill(dphi000,w_true_00);
        hdphi002->Fill(dphi000,w_true_01);
        hdphi003->Fill(dphi000,w_true_02);
        hdphi004->Fill(dphi000,w_true_03);
        hdphi005->Fill(dphi000,w_true_04);
        hdphi006->Fill(dphi000,w_true_05);
        hdphi007->Fill(dphi000,w_true_06);
}

        if(pid00==13 && pid11==-13&&pid0==443&& pid1==443 && mc_mass>0 && mc_R>=1.2 && mc_R<=2.2 && Evt_Cent!=50 && Evt_Cent>=10 && Evt_Cent<=60 && mc_pt0>=1 && mc_pt1>=1 && mc_ptot0!=-999 && mc_ptot1!=-999 && mc_pt>0 && mc_pt<=1){
Float_t RAP = TMath::Abs(mc_R);

//        Float_t dphi010 = phi_mc+rng;
        Float_t dphi010 = phi_mc;

        if (dphi010 < - TMath::Pi()/2){
        dphi010 = TMath::Abs(dphi010 + TMath::Pi());
        } else if (dphi010 > TMath::Pi()/2){
        dphi010 = TMath::Abs(dphi010 - TMath::Pi());
        } else if (TMath::Abs(dphi010) <= TMath::Pi()/2){
        dphi010 = TMath::Abs(dphi010);
                }

        hdphi010->Fill(dphi010);
        Float_t w_true_10 = hdphi000->GetEntries()*w0/25;
        Float_t w_true_11 = hdphi000->GetEntries()*w1/25;
        Float_t w_true_12 = hdphi000->GetEntries()*w2/25;
        Float_t w_true_13 = hdphi000->GetEntries()*w3/25;
        Float_t w_true_14 = hdphi000->GetEntries()*w4/25;
        Float_t w_true_15 = hdphi000->GetEntries()*w5/25;
        Float_t w_true_16 = hdphi000->GetEntries()*w6/25;

        hdphi011->Fill(dphi010,w_true_10);
        hdphi012->Fill(dphi010,w_true_11);
        hdphi013->Fill(dphi010,w_true_12);
        hdphi014->Fill(dphi010,w_true_13);
        hdphi015->Fill(dphi010,w_true_14);
        hdphi016->Fill(dphi010,w_true_15);
        hdphi017->Fill(dphi010,w_true_16);

}


}


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

        Float_t psi1 = TMath::Pi()/2;

        Float_t qx1 = cos(2*(phi-psi1));
        Float_t qy1 = sin(2*(phi-psi1));

        if (charge==0 && octant0!=octant1 && Evt_Cent!=50 && chi<3 && se && rapidity<=-1.2 && rapidity>=-2.2 && mass>=2 && mass<=5 && TMath::Abs(rap0)<2.2 && TMath::Abs(rap0)>1.2 && TMath::Abs(rap1)<2.2 && TMath::Abs(rap1)>1.2 && pt>0 && pt<=1 && Evt_Cent<=60 && Evt_Cent>=10 && px!=-9999.900 && py!=-9999.900 && (lg0==3||lg0==4) && (lg1==3||lg1==4) && pt0>=1 && pt1>=1 && DG0cut0<80 && DG0cut1<80 && DDG0cut0<40 && DDG0cut1<40 && trchi2_0<10 && trchi2_1<10 && idchi2_0<3 && idchi2_1<3 && ntrhits0>=6 && ntrhits1>=6 && nidhits0>3 && nidhits1>3 && TMath::Abs(pz0)>=3 && TMath::Abs(pz1)>=3) {
//        Float_t dphi100 = phi+rng;
        Float_t dphi100 = phi;

        if (dphi100 < - TMath::Pi()/2){
        dphi100 = TMath::Abs(dphi100 + TMath::Pi());
        } else if (dphi100 > TMath::Pi()/2){
        dphi100 = TMath::Abs(dphi100 - TMath::Pi());
        } else if (TMath::Abs(dphi100) <= TMath::Pi()/2){
        dphi100 = TMath::Abs(dphi100);
        }

        hdphi100->Fill(dphi100);
        hdphi101->Fill(dphi100,w_true_00);
        hdphi102->Fill(dphi100,w_true_01);
        hdphi103->Fill(dphi100,w_true_02);
        hdphi104->Fill(dphi100,w_true_03);
        hdphi105->Fill(dphi100,w_true_04);
        hdphi106->Fill(dphi100,w_true_05);
        hdphi107->Fill(dphi100,w_true_06);

        }

                if (charge==0 && octant0!=octant1 && Evt_Cent!=50 && chi<3 && se && rapidity>=1.2 && rapidity<=2.2 && mass>=2 && mass<=5 && TMath::Abs(rap0)<2.2 && TMath::Abs(rap0)>1.2 && TMath::Abs(rap1)<2.2 && TMath::Abs(rap1)>1.2 && pt>0 && pt<=1 && Evt_Cent<=60 && Evt_Cent>=10 && px!=-9999.900 && py!=-9999.900 && (lg0==3||lg0==4) && (lg1==3||lg1==4) && pt0>=1 && pt1>=1 && DG0cut0<80 && DG0cut1<80 && DDG0cut0<40 && DDG0cut1<40 && trchi2_0<10 && trchi2_1<10 && idchi2_0<3 && idchi2_1<3 && ntrhits0>=6 && ntrhits1>=6 && nidhits0>3 && nidhits1>3 && TMath::Abs(pz0)>=3 && TMath::Abs(pz1)>=3) {
//      Float_t dphi110 = phi+rng;
        Float_t dphi110 = phi;

        if (dphi110 < - TMath::Pi()/2){
        dphi110 = TMath::Abs(dphi110 + TMath::Pi());
        } else if (dphi110 > TMath::Pi()/2){
        dphi110 = TMath::Abs(dphi110 - TMath::Pi());
        } else if (TMath::Abs(dphi110) <= TMath::Pi()/2){
        dphi110 = TMath::Abs(dphi110);
        }

        hdphi110->Fill(dphi110);
        hdphi111->Fill(dphi110,w_true_10);
        hdphi112->Fill(dphi110,w_true_11);
        hdphi113->Fill(dphi110,w_true_12);
        hdphi114->Fill(dphi110,w_true_13);
        hdphi115->Fill(dphi110,w_true_14);
        hdphi116->Fill(dphi110,w_true_15);
        hdphi117->Fill(dphi110,w_true_16);

        }


}
}
hdphi100->Draw("e");
hdphi100->SaveAs("v2smallspt/1000n.root");
hdphi101->Draw("e");
hdphi101->SaveAs("v2smallspt/1010n.root");
hdphi102->Draw("e");
hdphi102->SaveAs("v2smallspt/1020n.root");
hdphi103->Draw("e");
hdphi103->SaveAs("v2smallspt/1030n.root");
hdphi104->Draw("e");
hdphi104->SaveAs("v2smallspt/1040n.root");
hdphi105->Draw("e");
hdphi105->SaveAs("v2smallspt/1050n.root");
hdphi106->Draw("e");
hdphi106->SaveAs("v2smallspt/1060n.root");
hdphi107->Draw("e");
hdphi107->SaveAs("v2smallspt/1070n.root");

hdphi110->Draw("e");
hdphi110->SaveAs("v2smallspt/1100n.root");
hdphi111->Draw("e");
hdphi111->SaveAs("v2smallspt/1110n.root");
hdphi112->Draw("e");
hdphi112->SaveAs("v2smallspt/1120n.root");
hdphi113->Draw("e");
hdphi113->SaveAs("v2smallspt/1130n.root");
hdphi114->Draw("e");
hdphi114->SaveAs("v2smallspt/1140n.root");
hdphi115->Draw("e");
hdphi115->SaveAs("v2smallspt/1150n.root");
hdphi116->Draw("e");
hdphi116->SaveAs("v2smallspt/1160n.root");
hdphi117->Draw("e");
hdphi117->SaveAs("v2smallspt/1170n.root");

}
