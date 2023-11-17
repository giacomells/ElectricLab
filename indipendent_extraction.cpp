#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TCanvas.h"

void testCorrelation(Int_t nGen = 1000000)
{
    gStyle->SetOptStat(0);
    TH2F *h = new TH2F("h", "", 1000, 0, TMath::Pi(), 1000, 0, 2 * TMath::Pi());
    TH3F *hSpace = new TH3F("hSpace", "", 100, -1, 1, 100, -1, 1, 100, -1, 1);
    h->SetLineColor(1);
    h->GetYaxis()->SetTitleOffset(1.2);
    h->GetXaxis()->SetTitleSize(0.04);
    h->GetYaxis()-> SetTitleSize(0.04);
    h-> GetXaxis()-> SetTitle("#theta(rad)");
    h-> GetYaxis()-> SetTitle("#phi(rad)");
    Double_t phi, theta = 0;
    for (Int_t i = 0; i < nGen; ++i)
    {
        theta = gRandom-> Rndm() * TMath::Pi();
        phi = gRandom-> Rndm() * 2 * TMath::Pi();
        h-> Fill(theta, phi);
        hSpace-> Fill(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
    }
    TCanvas *canvas = new TCanvas("canvas", "test canvas", 200, 10, 600, 400);
    canvas-> Divide(2, 1);
    canvas->cd(1);
    h->Draw();
    canvas->cd(2);
    hSpace->Draw();
   
}