#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TCanvas.h"

#include <iostream>

void myMacro(){
    //TF1 *eff = new TF1("eff", "0.7" ,0., 5.);        metodo alternativo: definisco una funzione
    TH1F *hAcc = new TH1F("hAcc", " ", 500, 0., 5.);
    TH1F *hGen = new TH1F("hGen", " ", 500, 0., 5.);
    Float_t x, y;
    for(Int_t i = 0; i < 1.E6; i++){
        x = gRandom->Gaus(2.5, 1);       //genera una popolazione gaussiana
        y = gRandom->Rndm();            //genera numeri da 0 A 1
        hGen->Fill(x);

        if(y < 0.7) hAcc->Fill(x);
        // if(y<eff->Eval(x)) hAcc->Fill(x);
        
    }

    TCanvas *c = new TCanvas("c", "effficiency", 200, 10, 600, 400);
    c->Divide(3,1);
    TH1F *hEff = new TH1F(*hGen);
    hEff->Divide(hAcc, hGen, 1, 1, "B");

    c->cd(1);
    hGen->Draw("H");
    c->cd(2);
    hAcc->Draw("H");
    c->cd(3);
    hEff->Draw("H");
    
    Double_t num_Gen = hGen->GetEntries();
    Double_t num_Oss= hAcc->GetEntries();

    

    cout<< "Differential Efficiency = "<< num_Oss / num_Gen << '\n' <<
           "Integral efficiency =" << hAcc->Integral() / hGen->Integral() << '\n'<<
           "Differential Efficiency(first bin)= " << hAcc->GetBinContent(1) / hGen->GetBinContent(1)<<'\n'<<endl;


}
