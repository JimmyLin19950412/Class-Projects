// Name: Luka Ivicevic
// Section: E
// File: x_rayer.cpp
// Desc: Definitions for the x_rayer class

#include <iostream>
#include <cstdlib>
#include "x_rayer.h"

using namespace std;

const int PROB = 10; // 10/100 = 10%

X_Rayer::X_Rayer()
{
  m_num_uses = 0;
  m_cost_per_use = 550;
}

void X_Rayer::charge_patient(Patient &victim)
{
  victim.pay_out(m_cost_per_use);
  return;
}

void X_Rayer::apply(Patient &victim)
{
  int randNum = rand() % 99; // 0 - 100
  if (randNum < PROB)
  {
    victim.modify_health(); // halves condition
  }
  m_num_uses++;
  return;
}

ostream& operator << (ostream &out, const X_Rayer &XR)
{
  out<<"Machine"<<endl;
  out<<"{"<<endl;
  out<<"  Number of Uses: "<<XR.m_num_uses<<endl;
  out<<"  Cost Per Use: "<<XR.m_cost_per_use<<endl;
  out<<"}"<<endl;
  return out;
}

