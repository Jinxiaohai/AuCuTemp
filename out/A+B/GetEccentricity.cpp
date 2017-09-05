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

int GetEccentricity()
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
  TFile *AuFile = new TFile("./AuCu_Augoing.root");
  for (int i = 0; i != MAX; ++i)
    {
      sprintf(AuName, "epsilonCharge%d", i);
      AuPro[i] = (TProfile*)AuFile->Get(AuName);
    }
  AuPro[0]->GetYaxis()->SetRangeUser(0, 0.55);
  AuPro[0]->GetXaxis()->SetTitle("dN_{ch}^{local}/d#eta");
  AuPro[0]->GetXaxis()->SetTitleSize(0.08);
  AuPro[0]->GetXaxis()->CenterTitle(true);
  AuPro[0]->GetYaxis()->SetTitle("#varepsilon_{2,A+B}");
  AuPro[0]->GetYaxis()->SetTitleSize(0.08);
  AuPro[0]->GetYaxis()->CenterTitle(true);
  AuPro[0]->SetMarkerStyle(20);
  AuPro[0]->SetMarkerSize(3);
  AuPro[0]->SetMarkerColor(4);
  AuPro[0]->SetLabelSize(0.06, "x");
  AuPro[0]->SetLabelSize(0.06, "y");
  AuPro[0]->SetTitleOffset(0.9, "x");
  AuPro[0]->SetTitleOffset(0.9, "y");
  AuPro[0]->SetNdivisions(507, "x");
  AuPro[0]->Draw("P");
  AuPro[0]->SetTitle("");

  /// for Cu
  TProfile *CuPro[MAX];
  char CuName[256];
  TFile *CuFile = new TFile("./AuCu_Cugoing.root");
  for (int i = 0; i != MAX; ++i)
    {
      sprintf(CuName, "epsilonCharge%d", i);
      CuPro[i] = (TProfile*)CuFile->Get(CuName);
    }
  CuPro[0]->SetMarkerStyle(20);
  CuPro[0]->SetMarkerSize(3);
  CuPro[0]->SetMarkerColor(2);

  CuPro[0]->Draw("P same");

  TLegend *leg = new TLegend(0.5572519,0.682243,0.7480916,0.8598131,NULL,"brNDC");
  leg->AddEntry(AuPro[0], "Cu+Au Au", "p");
  leg->AddEntry(CuPro[0], "Cu+Au Cu", "p");
  leg->SetTextSize(0.06);
  leg->SetLineColor(0);
  leg->Draw("same");

  return 0;
}
