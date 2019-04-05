//Name: Jimmy Lin
//Date: 11/18/2014
//Section: E
//File: patient_class.cpp
//Description: cpp file that contains the function definitions

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "patient_class.h"

//contains the maximum amount of names in the file
const int MAXNAMES = 20;

using namespace std;

//default constructor that randomly assigns patient's
//amtMoney, is_alive, health, and name value
patient::patient()
{
	//contains the random number that will be used to loop through file
	//to get name
	int random = rand() % MAXNAMES;
	
	//randomly picks a number between 0 and 4000 and assigns it to patient's
	//amtMoney
	amtMoney = rand() % 4001;
	
	//randomly picks a number between 0 and 100 and assigns it to the patient's
	//health
	health = rand() % 101;
	
	//if patient's health is 0 then they are dead, else they are alive
	if(health == 0) {
		//sets patient to being dead
		is_alive = false;
	}
	else {
		//sets patient to being alive
		is_alive = true;
	}
	
	//opens file
	ifstream fin;
	fin.open("names.dat.txt");
	//randomly selects a name for the patient
	//loops through file till it reaches the random number
	//and gets the name and sets it to the patient
	for(int i = 0; i <= random; i++) {
			fin>>name;
	}
	//closes file
	fin.close();
}

//reduces the patient's amtMoney by money
void patient::payout(int money)
{
	//reduces the patient;s amtMoney by money
 amtMoney -= money;
}

//modifies the patient's health based off of the passed health
void patient::modify_health(int changeHealth)
{
	//changes the patient's health based off of changeHealth
	health /= changeHealth;
	kill();
}

//modifies the patient;s is_alive variable
void patient::kill()
{
	//if health > 0 then patient is alive, else they are dead
	if(health > 0) {
		//patient is alive
		is_alive = true;
	}
	else {
		//patient is dead
		is_alive = false;
	}
}

//prints patient variables onto the screen
ostream & operator << (ostream & stream, const patient & pat)
{
	stream<<"Amount of money: "<<pat.amtMoney<<endl;
	//determines if prints dead or alive
	if(pat.is_alive) {
		stream<<"Is alive: Alive"<<endl;
	}
	else {
		stream<<"Is alive: Dead"<<endl;
	}
	stream<<"Health: "<<pat.health<<endl;
	stream<<"Name: "<<pat.name<<endl<<endl;
	
	return stream;
}