#include "TAxis.h"
#include "TArrow.h"
#include "TAttFill.h"
#include "TBranch.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TColor.h"
#include "TDirectory.h"
#include "TF1.h"
#include "TF2.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH1D.h"
#include "TH2.h"
#include "TH2D.h"
#include "TH3.h"
#include "TH3D.h"
#include "TLatex.h"
#include "TLeaf.h"
#include "TLegend.h"
#include "TLine.h"
#include "TMarker.h"
#include "TNamed.h"
#include "TPad.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TSpectrum.h"
#include "TStyle.h"
#include "TTree.h"

using namespace std;

int GetV2()
{
  gStyle->SetOptStat(0);
  TCanvas *canvas = new TCanvas("canvas", "canvas", 203, 126, 657, 676);
  canvas->SetTopMargin(0.03);
  canvas->SetRightMargin(0.05);
  canvas->SetBottomMargin(0.18);
  canvas->SetLeftMargin(0.18);

  const int MAX = 8;

  /// for Au
  TProfile *AuPro[MAX];
  char AuName[256];
  TFile *AuFile = new TFile("./Au-going.root");
  for (int i = 0; i != MAX; ++i)
    {
      sprintf(AuName, "V2_dNdEta%d", i);
      AuPro[i] = (TProfile*)AuFile->Get(AuName);
    }
  AuPro[1]->GetYaxis()->SetRangeUser(0.005, 0.06);
  AuPro[1]->GetXaxis()->SetTitle("dN_{ch}^{local}/d#eta");
  AuPro[1]->GetXaxis()->SetTitleSize(0.08);
  AuPro[1]->GetXaxis()->CenterTitle(true);
  AuPro[1]->GetYaxis()->SetTitle("V_{2}");
  AuPro[1]->GetYaxis()->SetTitleSize(0.08);
  AuPro[1]->GetYaxis()->CenterTitle(true);
  AuPro[1]->SetMarkerStyle(20);
  AuPro[1]->SetMarkerSize(3);
  AuPro[1]->SetMarkerColor(4);
  AuPro[1]->SetLabelSize(0.06, "x");
  AuPro[1]->SetLabelSize(0.06, "y");
  AuPro[1]->SetTitleOffset(0.9, "x");
  AuPro[1]->SetTitleOffset(0.9, "y");
  AuPro[1]->SetNdivisions(507, "x");
  AuPro[1]->SetNdivisions(504, "y");
  AuPro[1]->Draw("P");
  AuPro[1]->SetTitle("");

  /// for Cu
  TProfile *CuPro[MAX];
  char CuName[256];
  TFile *CuFile = new TFile("./Cu-going.root");
  for (int i = 0; i != MAX; ++i)
    {
      sprintf(CuName, "V2_dNdEta%d", i);
      CuPro[i] = (TProfile*)CuFile->Get(CuName);
    }
  CuPro[1]->SetMarkerStyle(20);
  CuPro[1]->SetMarkerSize(3);
  CuPro[1]->SetMarkerColor(2);

  CuPro[1]->Draw("P same");

  TLegend *leg = new TLegend(0.5938931,0.7461059,0.7847328,0.923676,NULL,"brNDC");
  leg->AddEntry(AuPro[1], "Au-going", "p");
  leg->AddEntry(CuPro[1], "Cu-going", "p");
  leg->SetTextSize(0.06);
  leg->SetLineColor(0);
  leg->Draw("same");

  return 0;
}
