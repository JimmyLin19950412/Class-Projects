//Programmer: Jimmy Lin, Luka Ivicevic
//Date: 12/8/2014
//File: placeboizer.cpp
//Description: contains the function definition for the class placeboizer

#include <iostream>
#include <cstdlib>
#include "placeboizer.h"
#include "patient.h"

using namespace std;

//default constructor for placeboizer
placeboizer::placeboizer()
{
  //sets number of uses to 0
  m_num_uses = 0;
	
  //sets cost per use to 500
  m_cost_per_use = 500;
}

//charges the patient based off of the cost per use of the machine
void placeboizer::charge_patient(const Patient & p)
{
  //charges the patient money based off of the cost of use of the machine
  p.charge_patient(m_cost_per_use);
}

//changes patient's mental health along with their weight
void placeboizer::apply(const Patient & p)
{
  //variables
  int const WEIGHTGAIN = 50;
  int patientMentalHealth;
  int increase;
	
  //gets the user's mental health and sets it to a variables
  patientMentalHealth = p.getMH();
	
  //determines how much to increase the patient's mental health by
  increase = (100 - patientMentalHealth) / 2;	
	
	//increases patient's mental health
  p.increaseMH(increase);

  //increases the patient's weight
  p.increaseWOP(WEIGHTGAIN);
}

//prints out the state of the machine
ostream & operator << (ostream & stream, const placeboizer & p)
{
  stream<<"Cost per use: "<<p.m_cost_per_use<<endl;
  stream<<"Number of uses: "<<p.m_num_uses;
  return stream;
}