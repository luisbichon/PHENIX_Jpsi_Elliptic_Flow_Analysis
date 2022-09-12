#include <TH2.h>
#include <TFile.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include "TMath.h"

void mesbg()

{
TFile *s_1[5][4];// = new TFile(Form("mass/hmass_%d%d0_0.root",j));
TFile *s_2[5][4];// = new TFile(Form("mass/hmass_s_%d_0_1.root",j));

//TCanvas *c_1[4];
//TCanvas *c_2[4];

TH1F *h_1[5][4];
TH1F *h_2[5][4];


TH1F *e1[5][4];
TH1F *e2[5][4];

TH1F *fg[5][4];
TH1F *bg[5][4];

for (int j=0; j<2; j++){
for (int k=0; k<4; k++){

s_1[j][k] = new TFile(Form("FINAL_2060/1%d%d0.root",j,k));
s_2[j][k] = new TFile(Form("FINAL_2060/1%d%d1.root",j,k));

h_1[j][k] = (TH1F*)s_1[j][k]->Get(Form("hmass_0%d0",j));
h_2[j][k] = (TH1F*)s_2[j][k]->Get(Form("hmass_0%d1",j));

h_1[j][k]->Rebin(2);
h_2[j][k]->Rebin(2);

e1[j][k] = (TH1F*)h_1[j][k]->Clone();
e2[j][k] = (TH1F*)h_2[j][k]->Clone();

fg[j][k] = (TH1F*)h_1[j][k]->Clone();
bg[j][k] = (TH1F*)h_2[j][k]->Clone();

for(int i=0; i<fg[j][k]->GetNbinsX(); i++){
   fg[j][k]->SetBinError(i+1, sqrt(fg[j][k]->GetBinContent(i+1)));
}

fg[j][k]->SaveAs(Form("FINAL_2060/comb/1%d%d0.root",j,k));


//float num = 0.1749; //South
//float num = 0.1681; //minus 3% South
//float num = 0.1785; //plus 3% South

float num = 0.1847; //North
//float num = 0.1841; //minus 3% North
//float num = 0.1955; //plus 3% North

//float num = 0.1681; //south 10-20
//float num = 0.1709; //south 20-30
//float num = 0.1738; //south 30-40
//float num = 0.1767; //south 40-50
//float num = 0.1831; //south 50-60

//float num = 0.2174; //north 10-20
//float num = 0.1933; //north 20-30
//float num = 0.1788; //north 30-40 
////float num = 0.1823; //north 40-50
//float num = 0.1855; //north 50-60


bg[j][k]->Scale(num);

for(int i=0; i<bg[j][k]->GetNbinsX(); i++){
   bg[j][k]->SetBinError(i+1, num*sqrt(bg[j][k]->GetBinContent(i+1)));
}

bg[j][k]->SaveAs(Form("FINAL_2060/comb/1%d%d1.root",j,k));


fg[j][k]->Add(bg[j][k],-1);

for(int i=0; i<fg[j][k]->GetNbinsX(); i++){
   fg[j][k]->SetBinError(i+1, sqrt(e1[j][k]->GetBinContent(i+1)+(num*num*e2[j][k]->GetBinContent(i+1))));
}

fg[j][k]->Draw();

fg[j][k]->SaveAs(Form("FINAL_2060/comb/1%d%d.root",j,k));

}
}
}               
