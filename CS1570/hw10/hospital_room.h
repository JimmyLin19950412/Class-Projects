// Name: Luka Ivicevic
// Section: E
// File: hospital_room.h
// Desc: Simulates a hospital room
#include <iostream>
#include "patient.h"
#include "doctor.h"
#include "x_rayer.h"
#include "lobotomizer.h"
#include "organ_donor.h"
#include "placeboizer.h"
#include "pharmacy.h"
#include "liposuctionizer.h"

using namespace std;

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

template <class T_machine>
class Hospital_Room
{
  public:
    Hospital_Room();
    // Desc: Default constructor for Hospital_Room
    // Pre: None
    // Post: Makes m_num_schraut = 10.0
    void admit(Patient & victim, doctor &dr);
    // Desc: Admits the patient to the hospital
    // Pre: None
    // Post: Uses m_the_machine's functions on the patient to simulate a visit
    friend ostream &operator << <T_machine>(ostream &out, const Hospital_Room<T_machine> &HR);
    // Desc: Easy output for Hospital_Room class
  private:
    T_machine m_the_machine;
    float m_num_schraut;  
};

#endif
