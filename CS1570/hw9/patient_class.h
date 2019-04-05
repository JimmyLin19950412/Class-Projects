//Name: Jimmy Lin
//Date: 11/18/2014
//Section: E
//File: patient.h
//Description: header file containing the class patient

#include <iostream>

using namespace std;

#ifndef PATIENT_H
#define PATIENT_H
	//patient
	class patient
	{
		public:
			//Description: default constructor that randomly assigns patient's
			//amtMoney, is_alive, health, and name value
			//Pre: requires a file ready with names
			//Post: changes the patient's amtMoney, is_alive, health,
			//and name values
			patient();
			
			//Description: reduce monetary asset by amount passed
			//Pre: patient's amtMoney needs to be populated and an
			//integer needs to be passed
			//Post: reduce the patient's amtMoney by the amount passed
			void payout(int money);
			
			//Description: modifies the patient's health based off of the
			//passed health
			//Pre: requires an integer that can be passed
			//Post: changes the user's health
			void modify_health(int changeHealth);
			
			//Description: prints out the patients private variables
			//Pre: needs ostream operator and patient class to be passed
			//Post: prints out amtMoney, is_alive health, and name
			friend ostream & operator << (ostream & stream, const patient & pat);
			
		private:
			//amount of money the patient has
			float amtMoney;
			//determines if user is dead or alive
			bool is_alive;
			//condition of the patient's health
			int health;
			//patient's name
			string name;
			//Description: changes the patient's is_alive variable based off
			//of health
			//Pre: none
			//Post: if patient's health is 0 then change is_alive to dead
			//else keep to alive
			void kill();
	};
#endif