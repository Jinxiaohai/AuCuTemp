#include "Head.h"
#include <cmath>
#include "TLorentzVector.h"

double GetFlow(int *idlist,
	       double *pxlist, double *pylist, double *pzlist, double *masslist,
	       double *xlist, double *ylist, double *zlist, double *timelist,
	       int Multi, int N)
{
  double phiAngle = 0.;
  double sumFlow = 0;
  int COUNT = 0;
  for (int i = 0; i != Multi; ++i)
    {
      if (pzlist[i] > 0)
	{
	  if (abs(idlist[i]) == 2212 || abs(idlist[i]) == 2112
	      || abs(idlist[i]) == 111 || abs(idlist[i]) == 211
	      || abs(idlist[i]) == 321)
	    {
	      double Energy = pxlist[i]*pxlist[i] + pylist[i]*pylist[i]
		+ pzlist[i]*pzlist[i] + masslist[i]*masslist[i];
	      TLorentzVector *lor = new TLorentzVector(pxlist[i], pylist[i], pzlist[i], Energy);
	      double pt = lor->Pt();
	      if (pt > 1e-7)
		{
		  double pseudoRapidity = lor->PseudoRapidity();
		  if (abs(pseudoRapidity) > 3 && abs(pseudoRapidity) < 3.9)
		    {
		      phiAngle = atan2f(pylist[i], pxlist[i]);
		      sumFlow += cos(N*phiAngle);
		      COUNT += 1;
		    }
		}
	    }
	}
    }
  return sumFlow / COUNT;
}
