//Programmer: Jimmy Lin, Luka LastNameThatNoOneCanPronounce
//Date: 12/8/2014
//File: liposuctionizer.cp
//Description: contains the definitions for the class liposuctionizer

#include <iostream>
#include "liposuctionizer.h"
#include "patient.h"
#include "patient.cpp"

using namespace std;

//default constructor 
//sets num_uses to 0, cost_per_use to 750
liposuctionizer::liposuctionizer()
{
	m_cost_per_use = 750;
	m_num_uses = 0;
}

//charges patient for using the machine
void liposuctionizer::charge_patient(const Patient & p)
{
  //charges patient
  p.pay_out(m_cost_per_use);
}

//changes the patient's weight and mental state
//after every 61 uses it will kill a patient
void liposuctionizer::apply(const Patient & p)
{
  int const MENTAL = 20;
	
  //gets the patients weight
  int patientWeight = p.getWOP();

  //gets 10% of patients weight
  patientWeight *= .1;

  //decrease patients weight
  p.decreaseWOP(patientWeight);
  
  //increase mental health
  p.increaseMH(MENTAL);
	
  //if machine is used 61 times then it kills the patient (set physical health to 0)
  if((m_num_uses % 61) == 0) {
    p.setZero();
  }
}

//prints out the state of the machine
ostream & operator << (ostream & stream, const liposuctionizer & l)
{
  stream<<"Cost per use: "<<l.m_cost_per_use<<endl;
  stream<<"Number of uses: "<<l.m_num_uses<<endl;
  return stream;
}