// Name: Luka Ivicevic
// Section: E
// File: hospital_room.cpp
// Desc: Definitions for the hospital_room class

#include <iostream>
#include <cstdlib>
#include "hospital_room.h"
#include "patient.h"
#include "doctor.h"

using namespace std;

template <class T_machine>
Hospital_Room<T_machine>::Hospital_Room()
{
  m_num_schraut = 10.0;
}

template <class T_machine>
void Hospital_Room<T_machine>::admit(Patient &victim, doctor &dr)
{
  if (victim.isAlive() == false || victim.getMoney() < m_the_machine.getCost())
  {
    return;
  }
  else
  {
    // variable to choose how much schraut the dr takes
	int num = rand() % 4 + 1; // 0 - 3
	// variable to check if schraut was consumed
	bool consumed;
	// number of times victim is put through the machine
	int loops;
    // Charge patient
    m_the_machine.charge_patient(victim);
	// Doctor takes schraut(1, 2, or 3), if there's not enough in the room
    // he will finish off what's in the room.	
	if (m_num_schraut < num)
	  consumed = dr.takeSchraut(m_num_schraut);
	else
	  consumed = dr.takeSchraut(num);
	if (consumed)
	{
	  loops = dr.getSchraut() - 5;
	  if (loops < 0)
	    loops = 0;
	  // put victim through the machine loops amount of times
	  for (int i = 0; i <= loops; i++)
	  {
	    m_the_machine.apply(victim);
	  }
	}
	else 
	{
	  // double the amount of loops from the last one
	  loops = (dr.getSchraut() - 5) * 2;
	  if (loops < 0)
	    loops = 0;
	  // put victim through the machine loops amount of times
	  for (int i = 0; i <= loops; i++)
	  {
	    m_the_machine.apply(victim);
	  }
	}
    return;
  }
}

template <class T_machine>
ostream &operator << (ostream &out, const Hospital_Room<T_machine> &HR)
{
  out<<"Hospital Room"<<endl;
  out<<"{"<<endl;
  out<<"  Schraut: "<<HR.m_num_schraut<<endl;
  out<<HR.m_the_machine;
  out<<"}"<<endl;
  return out;
}
