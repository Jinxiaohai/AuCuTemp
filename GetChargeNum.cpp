#include "TLorentzVector.h"
#include "Head.h"
#include <iostream>

using namespace std;

/**
 * deal with the event.
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
 * @return totalchargenumber
 */
int GetChargeNum(int *idlist,
	      double *pxlist, double *pylist, double *pzlist, double *masslist,
	      double *xlist, double *ylist, double *zlist, double *timelist,
	      int Multi)
{
  int totalChargeNumber = 0;
  for (int i = 0; i != Multi; ++i)
    {
      double px = pxlist[i], py = pylist[i], pz = pzlist[i];
      double Energy = (px*px + py*py + pz*pz + masslist[i]*masslist[i]);
      TLorentzVector *lor = new TLorentzVector(px, py, pz, Energy);
      double pt = lor->Pt();
      if (pz > 0)
	{
	  if (GetCharge(idlist[i]) != 0)
	    {
	      if (pt > 1e-7)
		{
		  // double rapidity = lor->Rapidity();
		  double pseudoRapidity = lor->PseudoRapidity();
		  if (abs(pseudoRapidity) > 3 && abs(pseudoRapidity) < 3.9)
		    {
		      totalChargeNumber += 1;
		    }
		}
	    }
	}
    }
  return totalChargeNumber;
}
