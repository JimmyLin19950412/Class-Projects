//Name: Jimmy Lin
//Date: 11/18/2014
//Section: E
//File: hospital_room_class.cpp
//Description: cpp file that contains the function definitions

#include <iostream>
#include "x_ray_class.h"
#include "patient_class.h"
#include "hospital_room_class.h"

using namespace std;

//oz of schraut
const float ozSchraut = 10.0;

//default constructor
hospital_room::hospital_room()
{
	//sets schraut to 10.0
	schraut = ozSchraut;
}

//calls charge_patient and apply from the_machine object and
//passes the patient's info to them
void hospital_room::admit(patient & pat)
{
	//passes the patient's info to the_machine
	the_machine.charge_patient(pat);
	//passes the patient's info to the_machine
	the_machine.apply(pat);
}

//prints patient variables onto the screen
ostream & operator << (ostream & stream, const hospital_room & room)
{
	stream<<"Oz of Schraut!: "<<room.schraut<<endl;
	stream<<room.the_machine<<endl<<endl;
	
	return stream;
}