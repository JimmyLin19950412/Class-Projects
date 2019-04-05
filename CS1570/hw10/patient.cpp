// Name: Luka Ivicevic
// Section: E
// File: patient.hpp
// Desc: Definitions for the patient class

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "patient.h"

using namespace std;

const int DIVIDE_BY = 2;

Patient::Patient()
{
  int randNum = rand() % 4001; // 0 - 4000
  m_money = randNum;
  randNum = rand() % 100; // 0 - 99
  m_condition = randNum;
  if (m_condition == 0)
  {
    m_is_alive = false;
  } 
  else
  {
    m_is_alive = true;
  }
  // Get name from file
  randNum = rand() % 20; // 0 - 19
  
  ifstream fin;
  
  fin.open("names.dat");
  for (int i = 0; i <= randNum; i++)
  {
    fin>>m_name;
  }
  fin.close();
  // set mental health and weight
  randNum = rand() % 101; // 0 - 100
  m_mental_health = randNum;
  randNum = rand() % 101 + 120; // 120 - 220
  m_wop = randNum;
}

void Patient::pay_out(float amount)
{
  m_money -= amount;
  return;
}

void Patient::modify_health()
{
  m_condition /= DIVIDE_BY;
  kill();
  return;
}

void Patient::kill()
{
  if (m_condition == 0)
  {
    m_is_alive = false;
  }
}

bool Patient::isAlive() const
{
  if (m_condition != 0)
    return true;
  else
    return false;
}

int Patient::getMoney() const
{
  return m_money;
}

void Patient::increaseMH(const int &num)
{
  m_mental_health += num;
  return;
}

void Patient::decreaseMH(const int &num)
{
  m_mental_health -= num;
  if (m_mental_health < 0)
    m_mental_health = 0;
  return;
}

void Patient::setMH(const int &num)
{
  m_mental_health = num;
  return;
}

void Patient::setZeroMH()
{
  m_mental_health = 0;
  return;
}

void Patient::increaseC(const int &num)
{
  m_condition += num;
  return;
}

void Patient::decreaseC(const int &num)
{
  m_condition -= num;
  if (m_condition < 0)
    m_condition = 0;
  return;
}

void Patient::setC(const int &num)
{
  m_condition = num;
  return;
}

void Patient::setZeroC()
{
  m_condition = 0;
  return;
}

void Patient::increaseWOP(const int &num)
{
  m_wop += num;
  return;
}

void Patient::decreaseWOP(const int &num)
{
  m_wop -= num;
  if (m_wop < 0)
    m_wop = 0;
  return;
}

int Patient::getWOP() const
{
  return m_wop;
}

void Patient::changeName()
{
  // Get name from file
  int randNum = rand() % 20; // 0 - 19
  
  ifstream fin;
  
  fin.open("names.dat");
  for (int i = 0; i <= randNum; i++)
  {
    fin>>m_name;
  }
  fin.close();
  return;
}

int Patient::getMH()
{
  return m_mental_health;
}

ostream &operator<<(ostream &out, const Patient &victim)
{
  out<<victim.m_name<<" weighs "<<victim.m_wop<<" lbs w/ MH = ";
	out<<victim.m_mental_health<<" and PH = "<<victim.m_condition;
	out<<" and has $"<<victim.m_money<<endl;
  return out;
}
