//Programmer: Jimmy Lin, Luka Ivicevic
//Date: 12/8/2014
//File: lobotomizer.h
//Description: contains the class lobotomizer

#include <iostream>
#include "patient.h"

using namespace std;

#ifndef LOBOTOMIZER_H
#define LOBOTOMIZER_H

class lobotomizer
{
	private:
		float m_cost_per_use;
		short m_num_uses;
		
	public:
		//default constructor that sets num_uses to 0 and cost of use to 200
		lobotomizer();
		
		//increases patient's mental health by 10 and physical health by 3
		//3% chance to put patient's mental health to 0
		//10% chance that the patient's name is randomized
		void apply(const Patient & p);
		
		//gets the cost per use of the machine
		int getCostPerUse() const;
		
		//gets number of schraut
		//insertion operator that outputs the state of the machine
		friend ostream & operator << (ostream & stream, const lobotomizer & lobo);
};

#endif