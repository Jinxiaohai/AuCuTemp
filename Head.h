#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <fstream>
#include "TProfile.h"

using namespace std;

extern int GetCharge(int);
/**
 * Get the total charge number
 *
 * @param idlist
 * @param pxlist
 * @param pylist
 * @param pzlist
 * @param masslist
 * @param xlist
 * @param ylist
 * @param zlist
 * @param timelist
 * @param Multi
 *
 * @return total charge number
 */
extern int GetChargeNum(int* idlist,
			double* pxlist, double* pylist, double* pzlist, double* masslist,
			double* xlist, double* ylist, double* zlist, double* timelist,
			int Multi);
/**
 * Get flow
 *
 * @param idlist
 * @param pxlist
 * @param pylist##
 * @param pzlist
 * @param masslist
 * @param xlist
 * @param ylist
 * @param zlist
 * @param timelist
 * @param Multi
 * @param N
 *
 * @return return the flow of an event.
 */
extern double GetFlow(int* idlist,
		      double* pxlist, double* pylist, double* pzlist, double* masslist,
		      double* xlist, double* ylist, double* zlist, double* timelist,
		      int Multi, int N);
/**
 * define some root file and histogram
 *
 */
extern void DefineRoot();

class AMPT
{
  friend istream& operator>>(istream &is, const AMPT &ampt);
  friend ostream& operator<<(ostream &os, const AMPT &ampt);
 public:
  /// constructor and copy constructor
  AMPT(istream &is);
  AMPT(const AMPT &ampt);

  /// Get
  int GetAMPTEventNum();
  int GetAMPTRunNum();
  int GetAMPTMulti();
  double GetAMPTImpactpar();
  int GetAMPTNparp();
  int GetAMPTNpart();
  int GetAMPTNelp();
  int GetAMPTNinp();
  int GetAMPTNelt();
  int GetAMPTNint();
  double GetAMPTPasshead();

 private:
  int AMPTEventNum, AMPTRunNum, AMPTMulti;
  int AMPTNparp, AMPTNpart;
  int AMPTNelp, AMPTNinp;
  int AMPTNelt, AMPTNint;
  double AMPTImpactpar, AMPTPasshead;
  int *AMPTIdlist;
  double *AMPTPseudoMomentum[4];
  double *AMPTCoordinate[4];
};

///_____________________________________________________________________________
/**
 * for root file.
 *
 */

const int MAX = 8;
extern TProfile *ProfileFile[MAX];
extern TProfile *V2_dNdEta[MAX];
extern TProfile *V2DivEpsilon[MAX];

///_____________________________________________________________________________

#endif /* HEAD_H */
