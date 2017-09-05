#include "Head.h"


AMPT::AMPT(istream &is)
{
  is >> *this;
}

AMPT::AMPT(const AMPT &ampt)
{
  this->AMPTEventNum = ampt.GetAMPTEventNum();
  this->AMPTRunNum = ampt.GetAMPTRunNum();
  this->AMPTMulti = ampt.GetAMPTMulti();
  this->AMPTImpactpar = ampt.GetAMPTImpactpar();
  this->AMPTNparp = ampt.GetAMPTNparp();
  this->AMPTNpart = ampt.GetAMPTNpart();
  this->AMPTNelp = ampt.GetAMPTNelp();
  this->AMPTNinp = ampt.GetAMPTNinp();
  this->AMPTNelt = ampt.GetAMPTNelt();
  this->AMPTNint = ampt.GetAMPTNint();
  this->AMPTPasshead = ampt.GetAMPTPasshead();
}


/// Get
int AMPT::GetAMPTEventNum()
{
  return this->AMPTEventNum;
}

int AMPT::GetAMPTRunNum()
{
  return this->AMPTRunNum;
}

int AMPT::GetAMPTMulti()
{
  return this->AMPTMulti;
}

double AMPT::GetAMPTImpactpar()
{
  return this->AMPTImpactpar;
}

int AMPT::AMPTNparp()
{
  return this->AMPTNparp;
}

int AMPT::GetAMPTNpart()
{
  return this->AMPTNpart;
}

int AMPT::GetAMPTNelp()
{
  return this->AMPTNelp;
}

int AMPT::GetAMPTNinp()
{
  return this->AMPTNinp;
}

int AMPT::GetAMPTNelt()
{
  return this->AMPTNelt;
}

int AMPT::GetAMPTNint()
{
  return this->AMPTNint;
}

double AMPT::GetAMPTPasshead()
{
  return this->AMPTPasshead;
}
