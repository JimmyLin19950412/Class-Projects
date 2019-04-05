// Name: Luka Ivicevic
// Section: E
// File: main.cpp
// Desc: Simulation of a doctor

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "hospital_room.h"
#include "patient.h"
#include "x_rayer.h"
#include "lobotomizer.h"
#include "organ_donor.h"
#include "placeboizer.h"
#include "pharmacy.h"
#include "liposuctionizer.h"

using namespace std;

// global const
const int NUM_PAT = 10;

int main()
{
  srand(time(NULL)); // Random seed
  
	//declaring classes
	lobotomizer lobo;
	organ_donor od;
	placeboizer pb;
	pharmacy pharm;
	liposuctionizer lip;
	hospital_room<lobotomizer> roomlobo;
	hospital_room<organ_donor> roomod;
	hospital_room<placeboizer> roompd;
	hospital_room<pharmacy> roompharm;
	hospital_room<liposuctionizer> roomlip;
	hospital_room<X_Rayer> roomxray;
	patient p1;
	patient p2;
	patient p3;
	patient p4;
	patient p5;
	patient p6;
	patient p7;
	patient p8;
	patient p9;
	patient p10;
	patient p[NUM_PAT] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10}
	doctor d;
	
	for (int i = 0; i < 10; i++)
	{
	  if(p[i].getMoney() >= lobo.getCostPerUse() && p[i].isAlive == true) {
		  roomlobo.admit(p[i],d);
			// output patient and number of times the machine was used on them
			// and if the doctor vomits
			cout<<p[i];
			
	  }
	
	  if(p[i].getMoney() >= od.getCostPerUSe() && p[i].isAlive == true) {
		  roomod.admit(p[i],d);
			// output patient and number of times the machine was used on them
			// and if the doctor vomits
			cout<<endl<<p[i];
			cout<<//NUM USES<<endl;
			if (doctor puked)
			  cout<<"The doctor has puked."<<endl;
	  }
	
	  if(p[i].getMoney() >= pb.getCostPerUSe() && p[i].isAlive == true) {
		  roompb.admit(p[i],d);
			// output patient and number of times the machine was used on them
			// and if the doctor vomits
			cout<<endl<<p[i];
	  }
	
	  if(p[i].getMoney() >= pharm.getCostPerUSe() && p[i].isAlive == true) {
		  roompharm.admit(p[i],d);
			// output patient and number of times the machine was used on them
			// and if the doctor vomits
			cout<<endl<<p[i];
	  }
	
	  if(p[i].getMoney() >= lip.getCostPerUSe() && p[i].isAlive == true) {
	  	roomlip.admit(p[i],d);
			// output patient and number of times the machine was used on them
			// and if the doctor vomits
			cout<<endl<<p[i];
	  }
		// output doctor, number of patients who died, how much money the doctor
		// made
		
	}
  return 0;
}
