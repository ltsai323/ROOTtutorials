#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
void accessTreeVariables()
{
    const char* input_filename = "You need to put a root file here";
    //const char* input_filename = "madgraphMLM_GJetSample.root";
    TFile* input_file= TFile::Open(input_filename);
    TTree* input_tree = (TTree*) input_file->Get("ggNtuplizer/EventTree");
    
    std::vector<Float_t>* et = nullptr;
    std::vector<Float_t>* eta = nullptr;
    std::vector<Float_t>* phi = nullptr;

    input_tree->SetBranchAddress("phoEt", &et);
    input_tree->SetBranchAddress("phoEta", &eta);
    input_tree->SetBranchAddress("phoPhi", &phi);

    TH1F* hist = new TH1F("hist", "Px of photon", 100, -10., 10.);
    for ( int ievt = 0; ievt < 10; ++ievt )
    {
        input_tree->GetEntry(ievt);
        for ( int phoIdx = 0 ; phoIdx < et->size(); ++phoIdx )
        {
            TLorentzVector photon;
            photon.SetPtEtaPhiM( et->at(phoIdx), eta->at(phoIdx), phi->at(phoIdx), 0 );
            hist->Fill(photon.X());
        }
    }

    TCanvas* c1 = new TCanvas("c1", "", 1000,1000);
    hist->Draw();
    c1->SaveAs("pxOFphoton.png");
}
