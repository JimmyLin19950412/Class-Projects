//Programmer: Jimmy Lin, Luka LastNameThatNoOneCanPronounce
//Date: 12/8/2014
//File: organ_donor.h
//Description: contains the class organ_donor

#include <iostream>
#include "patient.h"

using namespace std;

#ifndef ORGAN_DONOR_H
#define ORGAN_DONOR_H

class organ_donor
{
  private:
    float m_cost_of_use;
    short m_num_uses;
		
  public:
    //default constructor that sets num_uses to 0, cost_per_use to 100
    organ_donor();
		
    //charges the patient
    void charge_patient(const Patient & p) const;
		
    //increase patient's mental health by 10
    //decrease patient's physical health by 0-20
    //2% chance of setting patient's physical health to 0
    //decrease patient's weight by 10
    void apply(const Patient & p);
		
    //prints out the state of the class
    friend ostream & operator << (ostream & stream, const organ_donor & od);
};

#endif