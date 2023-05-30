ifndef __CINT__`
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
#include <cmath>
using namespace RooFit ;

  //define crystal ball function
  double crystalball_function(double x, double alpha, double n, double sigma, double mean) {
  if (sigma < 0.)     return 0.;
  double z = (x - mean)/sigma;
  if (alpha < 0) z = -z;
  double abs_alpha = std::abs(alpha);
  if (z  > - abs_alpha)
    return std::exp(- 0.5 * z * z);
  else {
    double nDivAlpha = n/abs_alpha;
    double AA =  std::exp(-0.5*abs_alpha*abs_alpha);
    double B = nDivAlpha -abs_alpha;
    double arg = nDivAlpha/(B-z);
    return AA * std::pow(arg,n);
    }
   }

  //define v2 function 
  double v2function(const double *x, const double *p) {
  double CB = p[0]*crystalball_function(x[0], p[3], p[4], p[2], p[1]);
  return CB*p[5]+(1-CB)*p[6];
  }


void fit_true()
{

  //define initial parameters
  float lo = 2.;
  float hi = 5.;
  static const int Nen = 1000;
  RooRealVar x("x","Mass (GeV/c^{2})",lo,hi) ;

  //read in files
  TFile *SB = new TFile("../../../SIDEBAND/comb/000.root"); //sideband: v2vsmass
  TFile *FG = new TFile("../FIT/000.root"); //foreground
  TFile *BG = new TFile("../FIT/010.root"); //background
  TFile *S = new TFile("../FIT/00.root"); //signal

  //read in histograms
  TH1F *hFg = (TH1F*)FG->Get("h_00");
  TH1F *hBg = (TH1F*)BG->Get("h_10");
  TH1F *hS = (TH1F*)S->Get("h_00");
  TH2D *hSB = (TH2D*)SB->Get("h2_00");
  hSB->RebinY(10);
  TProfile *hprof;
  hprof = hSB->ProfileX();

  //convert histograms to be readable by RooFit
  RooDataHist dh3("dh3","dh3",x,Import(*hS)) ;
  RooDataHist dh1("dh1","dh1",x,Import(*hFg)) ;
  RooDataHist dh2_true("dh2_true","dh2_true",x,Import(*hBg)) ;
  RooHistPdf h2pdf_true("h2pdf_true","h2pdf_true",x,dh2_true);

  float BG_INT = hBg->Integral();

  TH1F* hFg_c[Nen];
  TH1F* hBg_c[Nen];
  TH1F* hFg_int[Nen];
  TH1F* hBg_int[Nen];
  TH1F* h3_int[Nen];

  TH1F* hjpsi = new TH1F("hjpsi","",200,0,1e6);
  TH1F* hpsi2 = new TH1F("hpsi2","",250,0,5000);
  TH1F* hjpsimean = new TH1F("hjpsimean","",25,3.114,3.165);
  TH1F* hpsi2mean = new TH1F("hpsi2mean","",25,3.699,3.760);
  TH1F* hbkg = new TH1F("hbkg","",2500,0,1e7);
  TH1F* hjsigma = new TH1F("hjpsi","",25,0.132,0.162);
  TH1F* he0 = new TH1F("hjpsi","",25,-1,-0.00001);

  for (int itry = 0; itry<Nen; itry++){
  gRandom->SetSeed(itry);
  hFg_c[itry] = new TH1F("","",25, 2, 5);
  for (int k = 0; k<hFg->GetNbinsX(); k++){
  float val = hFg->GetBinContent(k);
  float err = hFg->GetBinError(k);
  float new_val = gRandom->Gaus(val,err);
  if (val<10){ new_val = gRandom->Poisson(val);}
  hFg_c[itry]->SetBinContent(k, new_val);
  hFg_int[itry] = hFg;
  }
  gRandom->SetSeed(itry+2426);
  hBg_c[itry] = new TH1F("","",25, 2, 5);
  for (int k = 0; k<hBg->GetNbinsX(); k++){
  float val2 = hBg->GetBinContent(k);
  float err2 = hBg->GetBinError(k);
  float new_val2 = gRandom->Gaus(val2,err2);
  if (val2<10){ new_val2 = gRandom->Poisson(val2);}
  hBg_c[itry]->SetBinContent(k, new_val2);
  hBg_int[itry] = hBg;
  h3_int[itry]=hS;
  }
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

  float fg_int2[Nen];
  float bg_int2[Nen];
  float max_bg[Nen];

  float fg_int3[Nen];
  float bg_int3[Nen];



 for(int i=0; i<Nen; i++){

  fg_int[i] = hFg_c[i]->Integral(5,14); //J/psi region foreground
  bg_int[i] = hBg_c[i]->Integral(5,14); //J/psi region background
  max_jpsi[i] = fg_int[i]-bg_int[i]; //max J/psi count if no residual bg in J/psi region
  fg_int2[i] = hFg_c[i]->Integral(); //Total foreground count
  bg_int2[i] = hBg_c[i]->Integral(); //Total background count
  fg_int3[i] = hFg_c[i]->Integral(6,14); //J/psi region foreground
  bg_int3[i] = hBg_c[i]->Integral(6,14); //J/psi region background
  max_bg[i] = (fg_int2[i]-bg_int2[i])-0.5*max_jpsi[i]; //maximum residual background guess

  //get TH1 histogram into a data structure that RooFit understands
  dh[i] = new RooDataHist("dh","dh",x,Import(*hFg_c[i])) ;
  dh2[i] = new RooDataHist("dh2","dh2",x,Import(*hBg_c[i])) ;
  h2pdf[i]= new RooHistPdf("h2pdf","h2pdf",x,*dh2[i]);

  //J/Psi signal = Crystal Ball
  mean1[i] = new RooRealVar("J/#psi #bar{x}","J/#psi Mean",3.125,3.122,3.128);
  sigma_1[i] = new RooRealVar("J/#psi #sigma","J/#psi Width",.135,.132,.138);
  a_1[i] = new RooRealVar("a_1","a_1",1.19);
  n_1[i] = new RooRealVar("n_1","n_1",3.94);
  signal1[i] = new RooCBShape("signal1", "Cystal Ball Function", x, mean1[i], sigma_1[i], a_1[i], n_1[i]);
  mean2[i] = new RooRealVar("#psi(2S) #bar{x}","#psi(2S) Mean",3.714,3.708,3.72);
  signal2[i] = new RooCBShape("signal2", "Cystal Ball Function2", x, mean2[i], sigma_1[i], a_1[i], n_1[i]);


  //background = Exponential Background
  e0[i]  = new RooRealVar("e0","e0",-0.05,-1,-0.00001) ;
  bkg[i] = new RooExponential("bkg","Background",x,e0[i]) ;

  //Construct signal+background PDF
  nsig1[i] = new RooRealVar("# of J/#psi (L)","# of J/#psi events",0.5*max_jpsi[i],0, max_jpsi[i]) ;
  nsig2[i] = new RooRealVar("# of #psi(2S) (L)","# of #psi(2S) events",0.005*max_jpsi[i],0,0.01*max_jpsi[i]) ;
  nbkg[i] = new RooRealVar("# of bkg","# of background events",0.2*max_bg[i],0, max_bg[i]) ;
  nbkg2[i] = new RooRealVar("# of bkg2", "# of background events2",bg_int2[i]);
  first[i] = new RooArgList(signal1[i],h2pdf[i],bkg[i],signal2[i]);
  second[i] = new RooArgList(nsig1[i],nbkg2[i],nbkg[i],nsig2[i]);
  model[i] = new RooAddPdf("model","model",first[i],second[i]) ;

  // Fit model to data
  model[i].fitTo(*dh[i],Extended(),SumW2Error(kTRUE));
  float jpsi_itry = nsig1[i].getVal();
  float psi2_itry = nsig2[i].getVal();
  float nbkg_itry = nbkg[i].getVal();
  float e0_itry = e0[i].getVal();
  float jpsi_sig = sigma_1[i].getVal();
  float jpsi_mean = mean1[i].getVal();
  float psi2_mean = mean2[i].getVal();

  // Fill paramter histograms
  hjpsi->Fill(jpsi_itry);
  hpsi2->Fill(psi2_itry);
  hjpsimean->Fill(jpsi_mean);
  hpsi2mean->Fill(psi2_mean);
  hbkg->Fill(nbkg_itry);
  hjsigma->Fill(jpsi_sig);
  he0->Fill(e0_itry);
  }

  // Set parameters for visualization to mean
  RooRealVar final_jpsi("a","a",hjpsi->GetMean());
  RooRealVar final_psi2("b","b", hpsi2->GetMean());
  RooRealVar final_jpsimean("c","c",hjpsimean->GetMean());
  RooRealVar final_psi2mean("d","d",hpsi2mean->GetMean());
  RooRealVar final_bkg("f","f",hbkg->GetMean());
  RooRealVar final_jsigma("g","g",hjsigma->GetMean());
  RooRealVar final_e0("h","h",he0->GetMean());
  RooRealVar final_a_1("a_1","a_1",1.19) ;
  RooRealVar final_n_1("n_1","n_1",3.94) ;

  RooCBShape signal1_vis("signal1 vis", "Cystal Ball Function vis", x, final_jpsimean, final_jsigma, final_a_1, final_n_1);
  RooCBShape signal2_vis("signal2 vis", "Cystal Ball Function2 vis", x, final_psi2mean, final_jsigma, final_a_1, final_n_1);
  RooExponential bkg_vis("bkg vis","Background vis",x,final_e0) ;
  RooAddPdf model_vis("model vis","model vis",RooArgList(signal1_vis,bkg_vis,signal2_vis),RooArgList(final_jpsi, final_bkg, final_psi2));
  model_vis.fitTo(dh3,Extended(),SumW2Error(kTRUE));
  RooPlot* xframevis = x.frame();

  dh3.plotOn(xframevis, RooFit::XErrorSize(0));

  TCanvas* csub = new TCanvas("csub","csub",600,600);
  dh3.Draw();

  model_vis.plotOn(xframevis, Components(RooArgSet(signal1_vis,signal2_vis,bkg_vis)), LineColor(kBlack)) ;
  model_vis.plotOn(xframevis,Components(bkg_vis),LineColor(kRed)) ;
  model_vis.plotOn(xframevis,RooFit::Components(RooArgSet(signal1_vis)),RooFit::LineColor(kGreen)) ;
  model_vis.plotOn(xframevis,RooFit::Components(RooArgSet(signal2_vis)),RooFit::LineColor(kBlue)) ;
  xframevis->GetXaxis()->SetTitle("");
  xframevis->GetYaxis()->SetTitle("");
  xframevis->Draw();
  xframevis->SaveAs("test.root");
  hjpsi->SaveAs("test2.root");
  float final_jpsi_err = hjpsi->GetRMS();
  float final_psi2_err = hpsi2->GetRMS();
  float final_bkg_err = hbkg->GetRMS();

cout << final_jpsi << "    " <<final_jpsi_err <<endl;

  float Rval[25];
  float Mval[25];
  TF1* func = (TF1*)signal1_vis.asTF(x,RooArgList(final_jpsimean, final_jsigma, final_a_1, final_n_1));
  float blurp = hS->GetMaximum();
  TH1F* testhist = new TH1F("test","test",25,2,5);
  TH1F* testhist2 = new TH1F("test","test",25,2,5);
  cout<<blurp<<endl;
        for(int po=0; po<25; po++){
        float valx = 2.06+0.12*po;
//      Mval[po] = 1195*func->Eval(valx);
        Rval[po] = (1115*func->Eval(valx))/(hFg->GetBinContent(po+1));
        testhist->SetBinContent(po+1,Rval[po]);
        testhist->SetBinError(po+1,0.02*Rval[po]);
        }

  testhist->SaveAs("truetest.root");
  float bork = testhist->GetMaximum();
  RooDataHist dhtest("dhtest","dhtest",x,Import(*testhist)) ;

  RooRealVar mean_test("mean","mean",3.1,3.,3.2);
  RooRealVar sigma_test("sigma_1","sigma_1",0.5,0,1);
  RooRealVar a_test("a_1","a_1",1,-1,10);
  RooRealVar n_test("n_1","n_1",1,-1,10);
  RooCBShape signal_test("signal", "Cystal Ball Function", x, mean_test, sigma_test, a_test, n_test);

  RooRealVar nsig_test("nsig","#signal events",10,0, 100) ;
  RooAddPdf model_test("model","model",RooArgList(signal_test),RooArgList(nsig_test)) ;

  model_test.fitTo(dhtest,Extended());

  float mean_testf = mean_test.getVal();
  float sigma_testf = sigma_test.getVal();
  float a_testf = a_test.getVal();
  float n_testf = n_test.getVal();

  cout<<bork<<endl;

        for(int po=0; po<25; po++){
//      testhist2->SetBinContent(po+1,hprof->GetBinContent(po+1));
//        testhist2->SetBinError(po+1,sqrt(hFg->GetBinError(po+1)/hFg->GetBinContent(po+1))*hprof->GetBinContent(po+1));
        testhist2->SetBinContent(po+1,hprof->GetBinContent(po+1));
        testhist2->SetBinError(po+1,hprof->GetBinError(po+1));
}


  TF1 *fv2 = new TF1("fv2", v2function, lo, hi, 7);

  fv2->FixParameter(0,bork);
  fv2->FixParameter(1,mean_testf);
  fv2->FixParameter(2,sigma_testf);
  fv2->FixParameter(3,a_testf);
  fv2->FixParameter(4,n_testf);
  fv2->SetParameter(5,0.0);
  fv2->SetParameter(6,0.0);

  fv2->SetParLimits(5,-0.2,0.2);
  fv2->SetParLimits(6,-0.2,0.2);

  hprof->SetMaximum(0.1);
  hprof->SetMinimum(-0.1);
  hprof->Fit(fv2);
  hprof->SaveAs("v2.root");
}                                                                                        
