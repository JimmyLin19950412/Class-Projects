//Name:	Jimmy Lin
//Date:	10/15/2014
//Section: E
//File: functions.cpp
//Description: function definitions for main.cpp

#include <iostream>
#include <cstdlib>
#include "functions.h"

using namespace std;

//reads name of the three patients
void readName(patientOne & name1, patientTwo & name2, patientThree & name3)
{
  //asks for the first patient's name
  cout<<"What is the first patient's name? ";
  cin>>name1.m_name;
  
  //asks for the second patient's name
  cout<<"What is the second patient's name? ";
  cin>>name2.m_name;
  
  //asks for the third patient's name
  cout<<"What is the third patient's name? ";
  cin>>name3.m_name;
}

//generates random number
float randomNumber(int minNum, int maxNum, int decimal)
{
  //variable
  //generates random number from minNum to maxNum
  float randomNumber = (rand() % (maxNum + 1) + minNum) / static_cast<float>(decimal);
  
  //returns the generated random number
  return randomNumber;
}

//greets the user
void greeting()
{
  //greeting message
  cout<<"Welcome to Dr. Eloe's Jejunal Hemorrhage Syndrome diagnosis"<<endl;
}

//signs the user off
void signOff()
{
  //sign off message
  cout<<"Thank you for using Dr. Eloe's Jejunal Hemorrhage Syundrom!"<<endl;
  cout<<"Have a good day!"<<endl;
}
