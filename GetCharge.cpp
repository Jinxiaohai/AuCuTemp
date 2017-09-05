#include "Head.h"
/**
 * get the charge number of particle.
 *
 * @param id
 *
 * @return charge
 */
int GetCharge(int id)
{
  int charge = 0;

  if (id==11) charge=-1;   // e-
  else if (id==-11) charge=1;   // e+
  else if (id==211) charge=1;   // π+
  else if (id==-211) charge=-1;   // π-
  else if (id==213) charge=1;   // ρ(770)+
  else if (id==321) charge=1;   // Κ+
  else if (id==-321) charge=1;   // Κ-
  else if (id==323) charge=1;   // Κ*(892)+
  else if (id==411) charge=1;   // D+
  else if (id==413) charge=1;   // D*(2010)+
  else if (id==431) charge=1;   // Ds+
  else if (id==433) charge=1;   // Ds*+
  else if (id==521) charge=1;   // B+
  else if (id==523) charge=1;   // B*+
  else if (id==1114) charge=-1; // Δ-
  else if (id==2212) charge=1;  // p+
  else if (id==-2212) charge=1;  // p-
  else if (id==2214) charge=1;  // Δ+
  else if (id==2224) charge=2;  // Δ++
  else if (id==3112) charge=-1; // Σ-
  else if (id==3114) charge=-1; // Σ*-
  else if (id==3222) charge=1;  // Σ+
  else if (id==3224) charge=1;  // Σ*+
  else if (id==3312) charge=-1; // Ξ-
  else if (id==3314) charge=-1; // Ξ*-
  else if (id==3334) charge=-1; // Ω-
  else if (id==4122) charge=1;  // Λc+
  else if (id==4222) charge=2;  // Σc++
  else if (id==4212) charge=1;  // Σc+
  else if (id==4224) charge=2;  // Σc*++
  else if (id==4232) charge=1;  // Ξc+
  else if (id==4322) charge=1;  // Ξ'c+
  else if (id==4324) charge=1;  // Ξc*+

  return charge;
}
