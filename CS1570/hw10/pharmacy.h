//Programmer: Jimmy Lin, Luka Ivicevic
//Date: 12/8/2014
//File: pharmacy.h
//Description: contains the class pharmacy

#include <iostream>
#include "patient.h"

using namespace std;

#ifndef PHARMACY_H
#define PHARMACY_H

class pharmacy
{
  private:
    float m_cost_per_use;
    short m_num_uses;
    short m_num_pills;

  public:
    // Desc: default constructor
	  // Pre: needs private member variables to change
	  // Post: changes private member variables
    pharmacy();
		
    // Desc: default constructor
	  // Pre: needs private member variables to change
	  // Post: changes private member variables
    void charge_patient(const Patient & p);
		
    // Desc: default constructor
	  // Pre: needs private member variables to change
	  // Post: changes private member variables
    void apply(const Patient & p);
		
    // Desc: default constructor
	  // Pre: needs private member variables to change
	  // Post: changes private member variables
    friend ostream & operator << (ostream & stream, const pharmacy & p);
};

#endif