//Name: Jimmy Lin
//Date: 11/18/2014
//Section: E
//File: x_ray_class.cpp
//Description: cpp file that contains the function definitions

#include <iostream>
#include <stdlib.h>
#include "x_ray_class.h"
#include "patient_class.h"

using namespace std;

//contains the cost_per_use number
const int MONEY = 550;
//contains the amount that will be divided off of
//the patients current health
const int DIVIDEHEALTH = 2;
//contains the percent chance that the x-ray will reduce
//the patient's health
const int PERCENT = 10;

//default constructor
x_ray::x_ray()
{
	//sets cost_per_use to $550
	cost_per_use = MONEY;
	//sets num_uses to 0s
	num_uses = 0;
}

//charges the patient
void x_ray::charge_patient(patient & pat)
{
	//calls patient class to access payout function
	//passes cost_per_use as integer value
	pat.payout(cost_per_use);
}

//changes the patient's health
void x_ray::apply(patient & pat)
{
	//contains a randomly generated number between 1 and 10
	int number = rand() % PERCENT + 1;
	
	//if number is 1 (.1 chance of happening) then patient's health is halved
	if(number == 1) {
		//halves the patient's health
		pat.modify_health(DIVIDEHEALTH);
	}
	
	//increases num_uses by 1
	num_uses++;
}

//prints x_ray variables onto the screen
ostream & operator << (ostream & stream, const x_ray & ray)
{
	stream<<"Cost per use: "<<ray.cost_per_use<<endl;
	stream<<"Number of uses: "<<ray.num_uses<<endl;
	
	return stream;
}
