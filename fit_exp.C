#ifndef __CINT__`
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
using namespace RooFit ;

void fit_exp()
{



  float lo = 2.;
  float hi = 5.;
  static const int Nen = 1000;
  RooRealVar x("x","Mass (GeV/c^{2})",lo,hi) ;


  TFile *FG = new TFile("../FINAL/comb/1100.root");
  TH1F *hFg = (TH1F*)FG->Get("hmass_010");
  TFile *BG = new TFile("../FINAL/comb/1101.root");
  TH1F *hBg = (TH1F*)BG->Get("hmass_011");
  TFile *f3 = new TFile("../FINAL/comb/110.root");
  TH1F *h3 = (TH1F*)f3->Get("hmass_010");
  RooDataHist dh3("dh3","dh3",x,Import(*h3)) ;


  RooRealVar x("x","Mass (GeV/c^{2})",lo,hi) ;


  TH1F* hFg_c[Nen];//= (TH1F*)hFg->Clone("hFg_copy");
  TH1F* hBg_c[Nen];// = (TH1F*)hBg->Clone("hBg_copy");

  TH1F* hjpsi = new TH1F("hjpsi","",100,0,2000);
  TH1F* hpsi2 = new TH1F("hpsi2","",150,0,3000);
  TH1F* hjpsimean = new TH1F("hjpsimean","",150,3.114,3.165);
  TH1F* hpsi2mean = new TH1F("hpsi2mean","",150,3.699,3.760);
  TH1F* hbkg = new TH1F("hbkg","",150,0,1e4);
  TH1F* hjsigma = new TH1F("hjpsi","",0.15,0.132,0.162);
  TH1F* he0 = new TH1F("hjpsi","",-0.1,-10,-0.01);

  for (int itry = 0; itry<Nen; itry++){
  gRandom->SetSeed(itry);
  hFg_c[itry] = new TH1F("","",50,2,5);
  for (int k = 0; k<hFg->GetNbinsX(); k++){
  float val = hFg->GetBinContent(k);
  float err = hFg->GetBinError(k);
  float new_val = gRandom->Gaus(val,err);
  if (val<10){ new_val = gRandom->Poisson(val);}
  hFg_c[itry]->SetBinContent(k, new_val);
//  cout << new_val-val<< endl;

}
  gRandom->SetSeed(itry+2425);
  hBg_c[itry] = new TH1F("","",50,2,5);
  for (int k = 0; k<hBg->GetNbinsX(); k++){
  float val2 = hBg->GetBinContent(k);
  float err2 = hBg->GetBinError(k);
  float new_val2 = gRandom->Gaus(val2,err2);
  if (val2<10){ new_val2 = gRandom->Poisson(val2);}
  hBg_c[itry]->SetBinContent(k, new_val2);
//  cout << new_val2-val2 << endl;
  }

//cout << (new_val-val)-(new_val2-val2) << endl;
}

  RooDataHist *dh[Nen];
  RooDataHist *dh2[Nen];
  RooHistPdf h2pdf[Nen];

  RooRealVar mean1[Nen] ;
  RooRealVar sigma_1[Nen] ;
  RooRealVar a_1[Nen];
  RooRealVar n_1[Nen];
  RooCBShape signal1[Nen];
  RooRealVar mean2[Nen];
  RooCBShape signal2[Nen];

  RooRealVar e0[Nen];
  RooExponential bkg[Nen];

  RooRealVar nsig1[Nen];
  RooRealVar nsig2[Nen] ;
  RooRealVar nbkg[Nen] ;
  RooRealVar nbkg2[Nen];
  RooAddPdf model[Nen];
  RooArgList first[Nen];
  RooArgList second[Nen];

  RooPlot *xframe[Nen];
  RooHist *hpull[Nen];
  TF1 pullfit[Nen];
  RooPlot *framevis[Nen];

  float fg_int[Nen];
  float bg_int[Nen];
  float max_jpsi[Nen];
  for(int i=0; i<Nen; i++){

  fg_int[i] = hFg_c[i]->Integral();
  bg_int[i] = hBg_c[i]->Integral();
  max_jpsi[i] = fg_int[i]-bg_int[i];

  //get TH1 histogram into a data structure that RooFit understands
  dh[i] = new RooDataHist("dh","dh",x,Import(*hFg_c[i])) ;
  dh2[i] = new RooDataHist("dh2","dh2",x,Import(*hBg_c[i])) ;
  h2pdf[i]= new RooHistPdf("h2pdf","h2pdf",x,*dh2[i]);

//define the fit function://////////////////////////////////////////////////////////////

  //J/Psi signal = Crystal Ball
  mean1[i] = new RooRealVar("J/#psi #bar{x}","J/#psi Mean",3.159,3.153,3.165);  //mean of Crystal Ball, in this example we are fitting psi(2S) so mass = 3686 MeV, you will need to adjust range for Jpsi
  sigma_1[i] = new RooRealVar("J/#psi #sigma","J/#psi Width",.146,.14,.152) ; //width of Crystal Ball
  a_1[i] = new RooRealVar("a_1","a_1",1.17) ;//tail parameter alpha (currently fixed)
  n_1[i] = new RooRealVar("n_1","n_1",2.55) ;//tail parameter n (currently fixed)
  signal1[i] = new RooCBShape("signal1", "Cystal Ball Function", x, mean1[i], sigma_1[i], a_1[i], n_1[i]); //make the CB function and tell it which parameters to use
  mean2[i] = new RooRealVar("#psi(2S) #bar{x}","#psi(2S) Mean",3.748,3.736,3.76) ;  //mean of Crystal Ball, in this example we are fitting psi(2S) so mass = 3686 MeV, you will need to adjust range for J
  signal2[i] = new RooCBShape("signal2", "Cystal Ball Function2", x, mean2[i], sigma_1[i], a_1[i], n_1[i]); //make the CB function and tell it which parameters to use

//  cout<<"test4"<<endl;

  //background = Exponential Background
  e0[i]  = new RooRealVar("e0","e0",-5,-20,-0.001) ;
  //e0[i]  = new RooRealVar("e0","e0",0) ;
  bkg[i] = new RooExponential("bkg","Background",x,e0[i]) ;
//804
  // --- Construct signal+background PDF ---
  nsig1[i] = new RooRealVar("# of J/#psi (L)","# of J/#psi events",max_jpsi[i]*0.5,0, max_jpsi[i]) ;
  nsig2[i] = new RooRealVar("# of #psi(2S) (L)","# of #psi(2S) events",max_jpsi[i]*0.5,0, max_jpsi[i]) ;
 nbkg[i] = new RooRealVar("# of bkg","# of background events",max_jpsi[i]*0.01,0, 0.03*max_jpsi[i]) ;
//  nbkg[i] = new RooRealVar("# of bkg","# of background events",0) ;

  nbkg2[i] = new RooRealVar("# of bkg2", "# of background events2", bg_int[i]);
  first[i] = new RooArgList(signal1[i],h2pdf[i],bkg[i],signal2[i]);

  second[i] = new RooArgList(nsig1[i],nbkg2[i],nbkg[i],nsig2[i]);

//  first[i] = new RooArgList(signal1[i],h2pdf[i],signal2[i]);
//  second[i] = new RooArgList(nsig1[i],nbkg2[i],nsig2[i]);

  model[i] = new RooAddPdf("model","model",first[i],second[i]) ;

  // Fit model to data
  model[i].fitTo(*dh[i],Extended());
  float jpsi_itry = nsig1[i].getVal();
  float psi2_itry = nsig2[i].getVal();
  float nbkg_itry = nbkg[i].getVal();
  float e0_itry = e0[i].getVal();
  float jpsi_sig = sigma_1[i].getVal();
  float jpsi_mean = mean1[i].getVal();
  float psi2_mean = mean2[i].getVal();

  hjpsi->Fill(jpsi_itry);
  hpsi2->Fill(psi2_itry);
  hjpsimean->Fill(jpsi_mean);
  hpsi2mean->Fill(psi2_mean);
  hbkg->Fill(nbkg_itry);
  hjsigma->Fill(jpsi_sig);
  he0->Fill(e0_itry);

//  cout<<"test6"<<endl;

}
  //hjpsi->SaveAs("test.root");
//  hpsi2->SaveAs("../MES_Systematics/fine/BBC/comb/fit/counts/psi2s/000.root");

  RooRealVar final_jpsi("a","a",hjpsi->GetMean());
  RooRealVar final_psi2("b","b", hpsi2->GetMean());
  RooRealVar final_jpsimean("c","c",hjpsimean->GetMean());
  RooRealVar final_psi2mean("d","d",hpsi2mean->GetMean());
  RooRealVar final_bkg("f","f",hbkg->GetMean());
  RooRealVar final_jsigma("g","g",hjsigma->GetMean());
  RooRealVar final_e0("h","h",he0->GetMean());
  RooRealVar final_a_1("a_1","a_1",1.17) ;
  RooRealVar final_n_1("n_1","n_1",2.55) ;

  //cout << final_jpsi.getValV() << endl;

  RooCBShape signal1_vis("signal1 vis", "Cystal Ball Function vis", x, final_jpsimean, final_jsigma, final_a_1, final_n_1); //make the CB function and tell it which parameters to use

  RooCBShape signal2_vis("signal2 vis", "Cystal Ball Function2 vis", x, final_psi2mean, final_jsigma, final_a_1, final_n_1); //make the CB function and tell it which parameters to use

  RooExponential bkg_vis("bkg vis","Background vis",x,final_e0) ;

//  RooAddPdf model_vis("model vis","model vis",RooArgList(signal1_vis,signal2_vis),RooArgList(final_jpsi, final_psi2));

  RooAddPdf model_vis("model vis","model vis",RooArgList(signal1_vis,bkg_vis,signal2_vis),RooArgList(final_jpsi, final_bkg, final_psi2));

  model_vis.fitTo(dh3,Extended());
  RooPlot* xframevis = x.frame();
  dh3.plotOn(xframevis, RooFit::XErrorSize(0));

  TCanvas* csub = new TCanvas("csub","csub",600,600);
  dh3.Draw();
//  model_vis.plotOn(xframevis, Components(RooArgSet(signal1_vis,signal2_vis)), LineColor(kBlack)) ;
  model_vis.plotOn(xframevis, Components(RooArgSet(signal1_vis,signal2_vis,bkg_vis)), LineColor(kBlack)) ;


  model_vis.plotOn(xframevis,Components(bkg_vis),LineColor(kRed)) ;
  model_vis.plotOn(xframevis,RooFit::Components(RooArgSet(signal1_vis)),RooFit::LineColor(kGreen)) ;
  model_vis.plotOn(xframevis,RooFit::Components(RooArgSet(signal2_vis)),RooFit::LineColor(kBlue)) ;
  xframevis->GetXaxis()->SetTitle("");
  xframevis->GetYaxis()->SetTitle("");
  xframevis->Draw();

//  cout<<"test"<<endl;
//  cout<<"test"<<endl
  xframevis->SaveAs("test.root");
  float final_jpsi_err = hjpsi->GetRMS();
  cout << final_jpsi << " and " << final_jpsi_err<<endl;

}
                                                                                                                                                                                                                     
