// Name: Luka Ivicevic and Jimmy Lin
// Section: E
// Date: 12/8/2014
// Desc: A doctor class to store info on a doctor like name, money, oz of
// Schraut.

#include <iostream>

using namespace std;

#ifndef DOCTOR_H
#define DOCTOR_H

class doctor
{
  public:
    // Constructor for doctor class that sets m_name to name and
	// m_oz_of_schraut/m_money to 0
    doctor(string name);
	// Desc: The doctor pukes his guts out
	// Pre: None
	// Post: m_oz_of_schraut is reset to 0
	void puke();
	// Desc: The doctor take schraut
	// Pre: Amount needs to be a positive integer
	// Post: Adds amount to m_oz_of_schraut
	bool takeSchraut(const int &amount);
	// Desc: Returns m_oz_of_schraut
	// Pre: None
	// Post: None
	short getSchraut();
  private:
    string m_name;
	short m_oz_of_schraut;
	float m_money;
};

#endif