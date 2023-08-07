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

const Int_t maxnh = 1000000;
Int_t b_npg, b_n, n;
Float_t b_ptg[maxnh], b_etag[maxnh], b_phig[maxnh], b_dphi[maxnh];
Float_t b_phirg;
Int_t b_centg;

void EFF()
{
  int scale = 5;
  int tot_num=144000;  // number of events
  double MeanMult=1; // number of particle per event
  double RMSMult=0;

  Int_t b_n;
  Float_t pt[maxnh];
  Float_t eta[maxnh];
  Float_t phi[maxnh];
  Float_t phir;
  Float_t dphi[maxnh];
  Float_t True;
  Float_t eta2[maxnh];




  TProfile *v2sigCent0 = new TProfile("v2sigCent0", "",10, 10,60);
  TProfile *v2sigPt0 = new TProfile("v2sigPt0", "",10, 0,5);
  TProfile *v2sigEta0 = new TProfile("v2sigEta0", "",10, 1.2,2.2);


  TProfile *v2sigCent1 = new TProfile("v2sigCent1", "",10, 10,60);
  TProfile *v2sigPt1 = new TProfile("v2sigPt1", "",10, 0,5);
  TProfile *v2sigEta1 = new TProfile("v2sigEta1", "",10, 1.2,2.2);

  TH1F *diff0 = new TH1F("diff0", "",10, 1.2,2.2);
  TH1F *diff1 = new TH1F("diff1", "",10, 0,5);
  TH1F *diff2 = new TH1F("diff2", "",10, 10,60);


  TH1F *hcent= new TH1F("hcent", "",100, 0,100);
  TH1F *heta = new TH1F("heta", "",100, 1.2,2.2);
  TH1F *hpt = new TH1F("hpt", "",100, 0,5);
  TF1 *PhiDistr0 = new TF1("PhiDistr0","1+2*[0]*cos(2*x)",0,PI2);
  TF1 *PhiDistr1 = new TF1("PhiDistr1","1+2*[0]*cos(2*x)",0,PI2);
  TF1 *PhiDistr2 = new TF1("PhiDistr2","1+2*[0]*cos(2*x)",0,PI2);


  TF1 *V2vsPt = new TF1("V2vsPt","(((x/3.4)^1.8/(1+(x/3)^1.8))*(.00005+(1/x)^0.8))",0,5);
  TF1 *V2vsCent = new TF1("V2vsCent","0.00218438+0.0068432*x-0.00015199*x^2+0.0000010545*x^3",10,60);
  TF1 *V2vsEta = new TF1("V2vsEta","0.177*TMath::Exp(-0.09452*x)",1.2,2.2);

  TF2 *fCent = new TF2("fCENT","1171*TMath::Exp(-x/21.0)*TMath::Exp(-((y - 1.67)/0.375)*((y - 1.67)/0.375))",10,60,1.2,2.2);
  TF1 *fEta = new TF1("fETA","1171*TMath::Exp(-[0]/21.0)*TMath::Exp(-((x - 1.67)/0.375)*((x - 1.67)/0.375))",1.2,2.2);
  TF1 *fPt = new TF1("fPT","1451*TMath::Landau(x,1.20,0.659)*TMath::Exp(-(([1] - 1.64)/0.755)*(([1] - 1.64)/0.755))",0,5);


  TRandom3 *rnd;
  rnd = new TRandom3(0);

  double myphi, mypt, myeta;
  double v2pt,v2cent, v2eta, Psi, cent,eta_false;

  for(int i=0; i<tot_num; i++){

   fCent->GetRandom2(cent,eta_false);
   b_npg = rnd->Gaus(MeanMult,RMSMult);
    n = 0;
   hcent->Fill(cent);
   fEta->FixParameter(0,cent);

    for(int j=0; j<b_npg;j++ ){


      float eta_true=fEta->GetRandom();
      fPt->FixParameter(1,eta_true);
      float ptval=fPt->GetRandom();



      heta->Fill(eta_true);
      hpt->Fill(ptval);


      v2eta = V2vsEta->Eval(eta_true);
      v2pt = V2vsPt->Eval(ptval);
      v2cent=V2vsCent->Eval(cent);



      PhiDistr0->SetParameter(0,v2eta);
      PhiDistr1->SetParameter(0,v2pt);
      PhiDistr2->SetParameter(0,v2cent);

      myphi0 = PhiDistr0->GetRandom(); // randon selection dn/dphi
      myphi1 = PhiDistr1->GetRandom(); // randon selection dn/dphi
      myphi2 = PhiDistr2->GetRandom(); // randon selection dn/dphi


      float v2samp0 = cos(2*myphi0);
      float v2samp1 = cos(2*myphi1);
      float v2samp2 = cos(2*myphi2);

      v2sigEta0->Fill(eta_true,v2samp0);
      v2sigPt0->Fill(ptval,v2samp1);
      v2sigCent0->Fill(cent,v2samp2);

      Float_t w00 =0.435203*(exp(-0.5*pow((TMath::Abs(eta_true)-1.82244)/0.412087,2.0)))*(exp(-0.5*pow((TMath::Abs(cent)-56.8104)/19.5672,2.0)));
  //    cout<<w00<<endl;
      Prob = rnd->Uniform(0,1);

      if(Prob<w00){
      v2sigEta1->Fill(eta_true,v2samp0);
      v2sigPt1->Fill(ptval,v2samp1);
      v2sigCent1->Fill(cent,v2samp2);
      }
       n++;

    } // End of loop over particles

    if (i%20 == 0) cout << i << " " << "events processed" << endl;

    b_n = n;
  } // End of loop over events

  for(int bin=0; bin<v2sigEta0->GetNbinsX(); bin++){

  diff0->SetBinContent(bin+1,TMath::Abs(v2sigEta0->GetBinContent(bin+1)-v2sigEta1->GetBinContent(bin+1)));
  diff0->SetBinError(bin+1,sqrt(TMath::Abs(v2sigEta0->GetBinError(bin+1)*v2sigEta0->GetBinError(bin+1)-v2sigEta1->GetBinError(bin+1)*v2sigEta1->GetBinError(bin+1))));

  diff1->SetBinContent(bin+1,TMath::Abs(v2sigPt0->GetBinContent(bin+1)-v2sigPt1->GetBinContent(bin+1)));
  diff1->SetBinError(bin+1,sqrt(TMath::Abs(v2sigPt0->GetBinError(bin+1)*v2sigPt0->GetBinError(bin+1)-v2sigPt1->GetBinError(bin+1)*v2sigPt1->GetBinError(bin+1))));

  diff2->SetBinContent(bin+1,TMath::Abs(v2sigCent0->GetBinContent(bin+1)-v2sigCent1->GetBinContent(bin+1)));
  diff2->SetBinError(bin+1,sqrt(TMath::Abs(v2sigCent0->GetBinError(bin+1)*v2sigCent0->GetBinError(bin+1)-v2sigCent1->GetBinError(bin+1)*v2sigCent1->GetBinError(bin+1))));

}
/*
v2sigEta0->SaveAs("etadist0_4.root");
v2sigEta1->SaveAs("etadist1_4.root");
v2sigPt0->SaveAs("ptdist0_4.root");
v2sigPt1->SaveAs("ptdist1_4.root");
v2sigCent0->SaveAs("centdist0_4.root");
v2sigCent1->SaveAs("centdist1_4.root");

diff0->SaveAs("etadiff_4.root");
diff1->SaveAs("ptdiff_4.root");
diff2->SaveAs("centdiff_4.root");
*/

diff0->Fit("pol0","0");
diff1->Fit("pol0","0");
diff2->Fit("pol0","0");
cout << v2sigEta1->GetEntries()<<endl;

}
