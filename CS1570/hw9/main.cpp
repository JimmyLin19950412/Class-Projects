//Name: Jimmy Lin
//Date: 11/18/2014
//Section: E
//File: main.cpp
//Description:

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "x_ray_class.h"
#include "hospital_room_class.h"
#include "patient_class.h"

using namespace std;

int main()
{
	//initializes random seed
	srand(time(NULL));
	
	//variables
	//amount of time to pass a patient through the hospital room
	const int PASS = 5;
	
	//declaring classes
	hospital_room room;
	patient patOne;
	patient patTwo;
	patient patThree;
	
	//Before room of death designed by Clayton Price
	cout<<"Initial Records: "<<endl;
	cout<<patOne;
	cout<<patTwo;
	cout<<patThree;
	
	//displays hospital room info
	cout<<"Hospital Room Info:"<<endl;
	cout<<room;
	
	//admit patients to hospital room
	cout<<"Admitting patients one, two, and three to hospital room!"<<endl;
	room.admit(patOne);
	room.admit(patTwo);
	room.admit(patThree);
	
	//after hospital room
	cout<<"After hospital room"<<endl;	
	cout<<patOne;
	cout<<patTwo;
	cout<<patThree;
	
	
	//passes one poor soul to the hospital room 5 times
	cout<<endl<<"Admitting one poor soul the Hospital Room "<<
	PASS - 1<<" more times!"<<endl;
	
	for(int i = 1; i <= PASS - 1; i++) {
		cout<<i+1<<" Hospital Room visit:"<<endl;
		room.admit(patOne);
		cout<<patOne;
	}
	
	//displays hospital room info
	cout<<"Hospital Room Info:"<<endl;
	cout<<room;
	
	return 0;
}