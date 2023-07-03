#include "TF1.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TProfile.h"
#include "TRandom3.h"
#include "TTree.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define PI2 2.0*3.141592653589793

const Int_t maxnh = 200000;
Int_t b_npg, b_n, n;
Float_t b_ptg[maxnh], b_etag[maxnh], b_phig[maxnh], b_dphi[maxnh];
Float_t b_phirg;
Int_t b_centg;

void EFF()
{

  int tot_num=100;  // number of events
  double MeanMult=200; // number of particle per event
  double RMSMult=0;

  Int_t b_n;
  Float_t pt[maxnh];
  Float_t eta[maxnh];
  Float_t phi[maxnh];
  Float_t phir;
  Float_t dphi[maxnh];
  Int_t cent;

  TProfile *h2_00 = new TProfile("h2_00", "",25, 0,5);
  TProfile *h2_01 = new TProfile("h2_01", "",25, 0,5);

  TH1F *diff = new TH1F("diff", "",25, 0,5);


//  TProfile *h2_11 = new TProfile("h2_01", "",6, massbins);

  TF1 *EtaDistr = new TF1("EtaDistr","exp(-(x-1.71)^2/0.259)+exp(-(x+1.67)^2/0.220)",-2.2,2.2);
  TF1 *CentDistr = new TF1("CentDistr","exp(-0.5*((x+4.13)/26.9)^2)",10,60);
  TF1 *PhiDistr = new TF1("PhiDistr","1+2*[0]*cos(2*x)",0,PI2);
  TF1 *PtDistr  = new TF1("PtDistr","3.10810e+04*TMath::Landau(x,1.20545e+00,5.44020e-01)", 0,5);
  TF1 *V2vsPt = new TF1("V2vsPt","((x/3.4)^1.8/(1+(x/3)^1.8))*(.00005+(1/x)^0.8)",0,5);


  TRandom3 *rnd;
  rnd = new TRandom3(0);

  double myphi, mypt, myeta;
  double v2, Psi, Cent;

  for(int i=0; i<tot_num; i++){

    Psi = rnd->Uniform(0,PI2);
    Cent = CentDistr->GetRandom();
    //Psi = 0;
    phir = Psi;
    cent = Cent;
    b_npg = rnd->Gaus(MeanMult,RMSMult);
    n = 0;

    for(int j=0; j<b_npg;j++ ){

      mypt = PtDistr->GetRandom();
      myeta =  EtaDistr->GetRandom();
      while (TMath::Abs(myeta)<1.2) myeta = EtaDistr->GetRandom();

      v2=V2vsPt->Eval(mypt);

      eta[n] = myeta;
      pt[n]  = mypt;

      PhiDistr->SetParameters(v2,0.0);

      myphi = PhiDistr->GetRandom(); // randon selection dn/dphi

      phi[n] = myphi; // save angle in lab frame
      dphi[n] = myphi+Psi;
      if (dphi[n]>PI2) dphi[n]=dphi[n]-PI2;

      float v2samp00 = cos(2*dphi[n]);

      if (pt[n]<2 && eta[n]<0){
      Float_t w00 =(0.179+0.014*Cent)*(0.600*exp(-0.5*pow((TMath::Abs(myeta)-1.810)/0.231,2.0)));
      } else if(pt[n]>=2 && eta[n]<0){
      Float_t w00 =(0.522+0.008*Cent)*(0.465*exp(-0.5*pow((TMath::Abs(myeta)-1.737)/0.231,2.0)));
      } else if(pt[n]<2 && eta[n]>0){
      Float_t w00 =(-0.059+0.018*Cent)*(0.435*exp(-0.5*pow((TMath::Abs(myeta)-1.774)/0.231,2.0)));
      } else if(pt[n]>=2 && eta[n]>0){
      Float_t w00 =(0.147+0.017*Cent)*(0.353*exp(-0.5*pow((TMath::Abs(myeta)-1.703)/0.231,2.0)));}


      Prob = rnd->Uniform(0,1);
      h2_00->Fill(mypt,v2);
      if(Prob<w00){
      h2_01->Fill(mypt,v2);
      }
       n++;

    } // End of loop over particles

    if (i%20 == 0) cout << i << " " << "events processed" << endl;

    b_n = n;
//    tree->Fill();
  } // End of loop over events


  for(int bin=0; bin<diff->GetNbinsX(); bin++){
  diff->SetBinContent(bin+1,TMath::Abs(h2_00->GetBinContent(bin+1)-h2_01->GetBinContent(bin+1))/h2_00->GetBinContent(bin+1));

  diff->SetBinError(bin+1,sqrt(h2_00->GetBinError(bin+1)*h2_00->GetBinError(bin+1)+h2_01->GetBinError(bin+1)*h2_01->GetBinError(bin+1)));
}




h2_00->SaveAs("v2signal0.root");
h2_01->SaveAs("v2signal1.root");
diff->SaveAs("diff.root");
}
                                                                           
