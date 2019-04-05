//Programmer: Jimmy Lin, Luka LastNameThatNoOneCanPronounce
//Date: 12/8/2014
//File: liposuctionizer.h
//Description: contains the class liposuctionizer

#include <iostream>
#include "patient.h"

using namespace std;

#ifndef LIPOSUCTIONIZER_H
#define LIPOSUCTIONIZER_H

class liposuctionizer
{
  private:
   float m_cost_per_use;
   short m_num_uses;
		
  public:
    //default constructor that will set num_uses to 0
    //cost_of_use to 750
    liposuctionizer();
		
    //charges patient
    void charge_patient(const Patient & p);

    //changes patient's weight and mental state
    //after every 61 uses it will kill a patient
    void apply(const Patient & p);
		
    //prints out the state of the machine
    friend ostream & operator << (ostream & stream, const liposuctionizer & l);
};

#endif