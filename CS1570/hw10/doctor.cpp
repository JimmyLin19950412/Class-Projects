// Name: Luka Ivicevic
// Section: E
// Date: 12/8/2014
// Desc: Function definitions for the doctor class

#include <iostream>
#include "doctor.h"

using namespace std;

doctor::doctor(string name)
{
  m_name = name;
  m_oz_of_schraut = 0;
  m_money = 0;
}

void doctor::puke()
{
  m_oz_of_schraut = 0;
  return;
}

bool doctor::takeSchraut(const int &amount)
{
  if (amount == 0)
    return false;
  m_oz_of_schraut += amount;
  if (m_oz_of_schraut >= 25)
    puke();
  return true;
}

short doctor::getSchraut()
{
  return m_oz_of_schraut;
}