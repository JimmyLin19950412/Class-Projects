//Programmer: Jimmy Lin, Luka Ivicevic
//Date: 12/8/2014
//File: pharmacy.cpp
//Description: contains the function definition for the class pharmacy

#include <iostream>
#include <cstdlib>
#include "pharmacy.h"
#include "patient.h"

using namespace std;

//default constructor for pharmacy
pharmacy::pharmacy()
{
  m_cost_per_use = 150;
  m_num_uses = 0;
  m_num_pills = rand() % 50 + 50; //random between 50 - 100
}

//charges patient
void pharmacy::charge_patient(const Patient & p)
{
  //charges patient
  p.charge_patient(m_cost_per_use);
}

//decrements the pills by 1
//random effect will occur from the pills
//if pills run out then patient loses a lot of stats
void pharmacy::apply(const Patient & p)
{
  //pill effect one
  int const EFFECT1C = 10; //physical condition
  int const EFFECT1MH = 10; //mental condition
  //pill effect two
  int const EFFECT2C = 20; //physical condition
  //pill effect 3
  int const EFFECT3C = 50; //physical condition
  //pill effect 4
  int const EFFECT4MH = 100; //mental condition
  int const EFFECT4W = 100; //weight
  //run out of pills, cotton balls
  int const COTTONBALLMH = 23; //mental condition
  int const COTTONBALLW = 44; //weight
	
  //holds the random number that determines which pill effect to use
  int random = rand() % 100;
	
	//if there is at least 1 pill left 
	if(m_num_pills > 0) {
    //effect 1, random between 0 and 24
    if(random >= 0 && random <= 24) {
      //increases patient's physical health
		  p.increaseC(EFFECT1C);
      //increases patient's mental health
      p.decreaseMH(EFFECT1MH);
    }
    //effect 2, random between 25 and 49
    else if(random >= 25 && random <= 49) {
      //increases patient's physical health
      p.increaseC(EFFECT2C);
      //sets patient's mental health to 0
      p.setZeroMH();
	  }
    //effect 3, random between 50 and 74
    else if(random >= 50 && random <= 74) {
      //physical health set to a number
      p.setC(EFFECT3C);
    }
    else if(random >= 75 && random <= 99) {
      //mental health set to a number
      p.setMH(EFFECT4MH);
      //increases weight
      p.increaseWOP(EFFECT4W);
    }
    
    //decreases the amount of pills there are left by 1
    m_num_pills--;
  }
  //if there are no pills left
  else {
    //decreases mental health
    p.decreaseMH(COTTONBALLMH);
    //increase weight
    p.increaseWOP(COTTONBALLW);
  }
}

//prints out the state of the machine
ostream & operator << (ostream & stream, const pharmacy & p)
{
  stream<<"Cost per use: "<<p.m_cost_per_use<<endl;
  stream<<"Number of uses?: "<<p.m_num_uses<<endl;
  stream<<"Number of pills: "<<p.m_num_pills<<endl;
  return stream;
}