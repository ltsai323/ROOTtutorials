#include "TFile.h"
#include "TTree.h"
void accessROOT()
{
    const char* input_filename = "You need to put a root file here";
    //const char* input_filename = "madgraphMLM_GJetSample.root";
    TFile* input_file= TFile::Open(input_filename);
    TTree* input_tree = (TTree*) input_file->Get("ggNtuplizer/EventTree");
    
    std::cout << "=============== List of branches in tree ====================\n";
    input_tree->Print();
    std::cout << "=============== List of branches in tree ====================\n";
    std::cout << "Drawing photon eta distribution\n";
    input_tree->Draw("phoEta");
}
