// Name: Luka Ivicevic
// Section: E
// File: x_rayer.h
// Desc: Defines the x_rayer class that respresents an x ray machine

#include <iostream>
#include "patient.h"

using namespace std;

#ifndef X_RAYER_H
#define X_RAYER_H

class X_Rayer
{
  public:
    X_Rayer();
    // Desc: Default constructor sets m_Num_uses to 0 and m_Cost_per_use to 550
    // Pre: None
    // Post: m_Num_uses = 0, m_Cost_per_use 550
    void charge_patient(Patient &victim);
    // Desc: Charges a patient the cost to use the machine
    // Pre: A patient type with enough enough money to use the machine
    // Post: Subtracts the cost of the machine from the patient
    void apply(Patient &victim);
    // Desc: 10% of the time it halves the patient's condition
    // the patients condition
    // Pre: None
    // Post: Halves  patient's health 10% of the time
        
    friend ostream& operator << (ostream &out, const X_Rayer &XR);
    // Desc: Allows cout of the X_Rayer class
    
  private:
    float m_cost_per_use;
    short m_num_uses;
};

#endif
