//Programmer: Jimmy Lin, Luka Ivicevic
//Date: 12/8/2014
//File: placeboizer.h
//Description: contains the class placeboizer

#include <iostream>
#include "patient.h"

using namespace std;

#ifndef PLACEBOIZER_H
#define PLACEBOIZER_H

class placeboizer
{
  private:
	  float m_cost_per_use;
		short m_num_uses;

  public:
	  // Desc: default constructor
	  // Pre: needs private member variables to change
	  // Post: changes private member variables
    placeboizer();
		
    // Desc: charges the patient based off of the cost per use variable
	  // Pre: requires cost per use variable to be filled in
    // and a patient class to call
	  // Post: charges the patient's money pockets
	  void charge_patient(const Patient & p);
		
    // Desc: changes the variables in patient class
	  // Pre: requires a patient class called
	  // Post: changes some variables in patient class
    void apply(const Patient & p);

    // Desc: prints out the state of the machine
	  // Pre: requires the member variables to be filled in
		// needs an ostream to be referenced in order to call function
	  // Post: prints out the state of the machine
    friend ostream & operator << (ostream & stream, const placeboizer & p);
};

#endif