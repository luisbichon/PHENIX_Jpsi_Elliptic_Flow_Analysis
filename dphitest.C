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

const Int_t nEvent = 10000;
Float_t phi[event], psi[event], dphi0[event], dphi1[event], ddphi[event];
Float_t v20[event], v21[event], dv2[event];

void dphitest(){

  TRandom3 *rnd;
  rnd = new TRandom3(0);
  TH1F *hddphi = new TH1F("","",50,-2*TMath::Pi(),2*TMath::Pi());
  TH1F *hv2 = new TH1F("","",50,-2,2);


  for(int i=0; i<nEvent; i++){

    psi[i] = rnd->Uniform(-TMath::Pi()/2,TMath::Pi()/2);
    phi[i] = rnd->Uniform(-TMath::Pi(),TMath::Pi());

    dphi0[i] = phi[i]-psi[i];
    dphi1[i] = atan2(sin(2*(phi[i]-psi[i])),cos(2*(phi[i]-psi[i])));

    ddphi[i] = dphi1[i]-dphi0[i];

    v20[i] = cos(2*dphi0[i]);
    v21[i] = cos(2*dphi1[i]);
    dv2[i] = v21[i]-v20[i];

    hddphi->Fill(ddphi[i]);
    hv2->Fill(dv2[i]);

//    cout<<"The difference of "<< dphi1[i] <<" and "<< dphi0[i]<< " is " <<ddphi[i]<<endl;
    cout<<"The difference of "<< v21[i] <<" and "<< v20[i]<< " is " <<dv2[i]<<endl;

}
hv2->Draw("e");
}
