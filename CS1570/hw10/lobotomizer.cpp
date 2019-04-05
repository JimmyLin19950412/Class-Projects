//Programmer: Jimmy Lin, Luka Ivicevic
//Date: 12/8/2014
//File: lobotomizer.cpp
//Description: contains the function definition for the class lobotomizer

#include <iostream>
#include <cstdlib>
#include "lobotomizer.h"
#include "patient.h"

using namespace std;

//default constructor for lobotomizer
lobotomizer::lobotomizer()
{
	//sets num_uses to 0
	m_num_uses = 0;
	
	//sets cost of use to 200
	m_cost_per_use = 200;
}

//increases patient's mental health by 10 and physical health by 3
//3% chance to put patient's mental health to 0
//10% chance that the patient's name is randomized
void lobotomizer::apply(const Patient & p)
{
	//constant for regular mental health change
	int const MENTALCHANGE = 10;
	//constant for regular physical health change
	int const PHYSICALCHANGE = 3;
	//generates a random number between 0 and 100
	int random = rand() % 101;
	
	//if random number is greater than 3, 3%
	if (random >= 4) {
		//increases patient's mental health
		p.increaseMH(MENTALCHANGE);
	}
	else {
		//if random is less than or equal to 3%
		//sets patients mental health to 0
		p.setZeroMH();
	}
	
	//increases the patients physical health 
	p.increaseC(PHYSICALCHANGE);
	
	//if random is less than or equal to 10, 10%
	if(random <= 10) {
		//------------------------------changes name to a new random name
	}
}

//gets cost per use of the machine
int lobotomizer::getCostPerUse() const
{
	//returns cost per use of the machine
	return m_cost_per_use;
}

//outputs the state of the machine
ostream & operator << (ostream & stream, const lobotomizer & lobo)
{
	//prints the cost per use
	stream<<"Cost per use: "<<lobo.m_cost_per_use<<endl;
	
	//prints the num of uses
	stream<<"Number of uses: "<<lobo.m_num_uses<<endl;
	
	//outputs the stream
	return stream;
}