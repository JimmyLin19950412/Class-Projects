//Name: Jimmy Lin
//Date: 11/18/2014
//Section: E
//File: hospital_room_class.h
//Description: header file containing class hospital_room

#include <iostream>
#include "patient_class.h"
#include "x_ray_class.h"

using namespace std;

#ifndef HOSPITAL_ROOM_CLASS_H
#define HOSPITAL_ROOM_CLASS_H
	//hospital_room class
	class hospital_room
	{
		public:
			//Description: default constructor
			//Pre: non
			//Post: changes value of variables
			hospital_room();
			
			//Description: calls charge_patient and apply from the_machine
			//object and passes the patient's info to them
			//Pre: patient class
			//Post: changes the patient's amtMoney and health of patient
			void admit(patient & pat);
			
			//Description: prints out private variables
			//Pre: ostream operator and hospital room class
			//Post: prints out private variables
			friend ostream & operator << 
			(ostream & stream, const hospital_room & room);
		private:
			//calls the x_ray class
			x_ray the_machine;
			//contains the oz of schraut
			float schraut;
	};
#endif