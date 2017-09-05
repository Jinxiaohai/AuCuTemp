#include "Head.h"
#include "TProfile.h"

TProfile *ProfileFile[MAX] = {nullptr};
TProfile *V2_dNdEta[MAX] = {nullptr};
TProfile *V2DivEpsilon[MAX] = {nullptr};

void DefineRoot()
{
  /// define
  char ProName[256];
  for (int i = 0; i != MAX; ++i)
    {
      sprintf(ProName, "epsilonCharge%d", i);
      ProfileFile[i] = new TProfile(ProName, ProName, 15+i*5, 0, 500, 0, 0.8);
    }
  /// for v2
  char V2_dNdEtaName[256];
  for (int i = 0; i != MAX; ++i)
    {
      sprintf(V2_dNdEtaName, "V2_dNdEta%d", i);
      V2_dNdEta[i] = new TProfile(V2_dNdEtaName, V2_dNdEtaName, 15+5*i, 0, 500, 0, 0.1);
    }
  /// for v2divepsilon
  char V2DivEpsilonName[256];
  for (int i = 0; i != MAX; ++i)
    {
      sprintf(V2DivEpsilonName, "V2DivEpsilon%i", i);
      V2DivEpsilon[i] = new TProfile(V2DivEpsilonName, V2DivEpsilonName, 15+5*i, 0, 500, 0, 0.2);
    }
}
