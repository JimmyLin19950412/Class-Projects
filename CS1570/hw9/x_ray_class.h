//Name: Jimmy Lin
//Date: 11/18/2014
//Section: E
//File: x_ray_class.h
//Description: header file containing the class x_ray

#include <iostream>
#include "patient_class.h"

using namespace std;

#ifndef X_RAY_CLASS_H
#define X_RAY_CLASS_H
	//x_ray class
	class x_ray
	{
		public:
			//Description: default constructor
			//Pre: none
			//Post: changes the value of the private members in the class
			x_ray();
			
			//Description: charges the patient
			//Pre: requires a patient class
			//Post: changes the patient's amtMoney by the charge_per_use
			void charge_patient(patient & pat);
			
			//Description: changes the health of the patient
			//Pre: requires a patient class
			//Post: .1 chance of halving the patient's health
			void apply(patient & pat);
			
			//Description: prints x_ray variables onto the screen
			//Pre: requires a populated class and a ostream to be passed
			//Post: prints out x_ray variables onto the screen
			friend ostream & operator << (ostream & stream, const x_ray & ray);
			
		private:
			//represents the cost for each use
			float cost_per_use;
			//number of times the particular machine has been used
			short num_uses;
	};
#endif