//Programmer: Jimmy Lin, Luka LastNameThatNoOneCanPronounce
//Date: 12/8/2014
//File: organ_donor.cpp
//Description: contains the function definitions for class organ_donor

#include <iostream>
#include <cstdlib>
#include "patient.h"
#include "organ_donor.h"

using namespace std;

//default constructor
organ_donor::organ_donor()
{
  //sets num_uses to 0
  m_num_uses = 0;
	
  //sets cost of use to 100
  m_cost_of_use = 100;
}

//charges patient
void organ_donor::charge_patient(const Patient & p) const
{
  //calls the function pay_out from patient and charges
  //him/her the amount m_cost_of_use
  p.pay_out(m_cost_of_use);
}

//increase patient's mental health by 10
//decrease patient's physical health by 0-20
//2% chance of setting patient's physical health to 0
//decrease patient's weight by 10
void apply(const Patient & p)
{
  int const WEIGHTCHANGE = 10;
  int const MENTALCHANGE = 10;
  int randomKill = rand() % 101;
  int randomHealth = rand() % 21;
	
  //increases patient's mental health
  p.increaseMH(MENTALCHANGE);
	
  //decreases patient's health if randomKill is equal to or above 3
  if(randomKill >= 3) {
    p.decreaseC(randomHealth);
  }
  else {
    //sets patient's health to 0
    p.setZeroC();
  }
	
  //decreases patient's weight
  p.decreaseWOP(WEIGHTCHANGE);
}

//prints the state of the machine		
ostream & operator << (ostream & stream, const organ_donor & od)
{
  stream<<"Cost of use: "<<od.m_cost_of_use;
  stream<<"Number of uses: "<<od.m_num_uses;
  return stream;
}