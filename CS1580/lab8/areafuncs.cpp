//Name:	Jimmy Lin
//Date:	10/14/2014
//File: areafuncs.cpp
//Section: C
/*Description: Holds the function defintions for area.cpp*/

#include <iostream>
#include "area.h"

using namespace std;

//greeting message for the user
void greet()
{
  //greeting message to the user
  cout<<"~*~ Welcome to Area Calculator ~*~"<<endl;
}

//reads and returns the number the user entered
float read()
{
  //variables
  float userInput; //user input
  
  cin>>userInput; //puts user's input into userInput
  
  //return's user's input
  return userInput;
}

//calculates the area of a circle
float area(const circle & circ)
{
  float radius = circ.m_radius; //radius of the circle
  const float pi = 3.14; //constant number, pi
  
  //calculates and returns area of a circle
  return pi*(radius*radius);
}

//calculates the area of a rectangle
float area(const rectangle & rect)
{
  //variables
  float height = rect.m_height; //height of rectangle
  float width = rect.m_width; //width of rectangle  

  //calculates and returns the area of a rectangle
  return height*width;
}

//sign off message for the user
void signoff()
{
  //sign off message
  cout<<"Have a Good Day!";
  return;
}
