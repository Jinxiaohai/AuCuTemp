/********************************************************/
/*                 Created  by  xiaohai                 */
/*                 Telphone : 18501781924               */
/*            E-mail : jinxiaohai@sinap.ac.cn           */
/*            E-mail : xiaohaijin@outlook.com           */
/*   Address : Shanghai Institute of Applied Physics    */
/********************************************************/
//root
#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ class PlotFile;
#endif
#ifndef __CINT__
#include "TH3D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TTree.h"
#include "TNtuple.h"
#include "TRandom.h"
#include "TMath.h"
#include "TSystem.h"
#include "TUnixSystem.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TROOT.h"
#include "TFile.h"
#include "TChain.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TGaxis.h"
#include "TPaveStats.h"
#include "TObject.h"
#include "TClonesArray.h"
#include "TRefArray.h"
#include "TRef.h"
#include "TBits.h"
#endif

//c++
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <fstream>
#include <sstream>

#include "Head.h"

using namespace std;

int main(int argc, char *argv[])
{
  /// definition some Profiles.
  DefineRoot();

  /// event head
  int EventNum = 0, RunNum = 0, Multi = 0, Nparp = 0, Npart = 0,
    NelP = 0, NinP = 0, NelT = 0, NinT = 0;
  double bimp = 0., passhead = 0.;
  /// track
  int ID = 0;
  double PX = 0., PY = 0., PZ = 0., MASS = 0.;
  double X = 0., Y = 0., Z = 0., TIME = 0.;
  /// epsilon
  double epsilon = 0.;

  char fileList[256];
  char fileEpsilon[256];

  ifstream inputFile(argv[1]);
  if (inputFile.fail())
    {
      cerr << "open error." << endl;
      return -1;
    }
  ifstream inputEpsilonFile(argv[2]);
  if (inputEpsilonFile.fail())
    {
      cerr << "open error." << endl;
      return -1;
    }
  TFile *outputFile = new TFile("./out/outputFile.root", "RECREATE");
  while (inputFile.good())
    {
      inputFile.getline(fileList, 256);
      cout << "\033[32m" << fileList << "\033[0m" << endl;
      inputEpsilonFile.getline(fileEpsilon, 256);
      if (inputFile.fail() || inputEpsilonFile.fail()) break;
      ifstream inputData(fileList);
      if (inputData.fail())
	{
	  cerr << "open error." << endl;
	  return -1;
	}
      ifstream inputEpsilon(fileEpsilon);
      if (inputEpsilon.fail())
	{
	  cerr << "open error." << endl;
	  return -1;
	}

      while (inputData.good())
	{
	  inputData >> EventNum >> RunNum >> Multi >> bimp >> Nparp
		    >> Npart >> NelP >> NinP >> NelT >> NinT >> passhead;
	  inputEpsilon >> epsilon;
	  // cout << epsilon << endl;
	  if (inputData.fail() || inputEpsilon.fail()) break;
	  int *idList = new int[Multi];
	  double *pxList = new double[Multi];
	  double *pyList = new double[Multi];
	  double *pzList = new double[Multi];
	  double *massList = new double[Multi];
	  double *xList = new double[Multi];
	  double *yList = new double[Multi];
	  double *zList = new double[Multi];
	  double *timeList = new double[Multi];
	  for (int i = 0; i != Multi; ++i)
	    {
	      inputData >> ID >> PX >> PY >> PZ >> MASS >> X >> Y >> Z >> TIME;
	      idList[i] = ID;
	      pxList[i] = PX;
	      pyList[i] = PY;
	      pzList[i] = PZ;
	      massList[i] = MASS;
	      xList[i] = X;
	      yList[i] = Y;
	      zList[i] = Z;
	      timeList[i] = TIME;
	    }
	  /**
	   * do something
	   *
	   */
	  int totalChargeNum = GetChargeNum(idList, pxList, pyList, pzList, massList,
					 xList, yList, zList, timeList, Multi);
	  double averageFlow = GetFlow(idList, pxList, pyList, pzList, massList,
	  			       xList, yList, zList, timeList, Multi, 2);
	  // cout << totalChargeNum << endl;
	  // cout << averageFlow << endl;
	  delete idList;
	  delete pxList;
	  delete pyList;
	  delete pzList;
	  delete massList;
	  delete xList;
	  delete yList;
	  delete zList;
	  delete timeList;
	  /// for fill data
	  for (int i = 0; i != MAX; ++i)
	    {
	      ProfileFile[i]->Fill(totalChargeNum/0.9, epsilon);
	      V2_dNdEta[i]->Fill(totalChargeNum, averageFlow);
	      V2DivEpsilon[i]->Fill(totalChargeNum, averageFlow/epsilon);
	    }
	}
      inputData.close();
      inputEpsilon.close();
    }

  inputFile.close();
  inputEpsilonFile.close();
  outputFile->cd();
  /// write and delete
  for (int i = 0; i != MAX; ++i)
    {
      ProfileFile[i]->Write();
      delete ProfileFile[i];

      V2_dNdEta[i]->Write();
      delete V2_dNdEta[i];

      V2DivEpsilon[i]->Write();
      delete V2DivEpsilon[i];
    }
  outputFile->Close();
  return 0;
}
