//Name:	Jimmy Lin
//Date:	10/14/2014
//File:	area.h
//Section: C
//Description: holds function prototypes for areafuncs.cpp and area.cpp

#include <iostream>

using namespace std;

#ifndef AREAFUNCS_H
#define AREAFUNCS_H

//structure to hold information for triangle
struct rightTriangle
{
  float m_height; //height of the triangle
  float m_base; //base of the trianle
};

//structure to hold information for diamond
struct rightDiamond
{
  float m_height; //height of the diamond
  float m_base; //base of the diamond
};

//structure to hold information for rectangle
struct rectangle
{
  float m_height; //height of the rectangle
  float m_width; //width of the rectangle 
};

//structure to hold information for circle
struct circle
{
  float m_radius; //radius of the circle
};

//Description: reads in user input
//Pre: a number 
//Post: none
//Return: a number that the user entered
float read();

//Description: calculates area of a right-triangle or right-diamond
//Pre: requires a number to be inputed
//Post: none
//Return: returns the area
template<typename T>
float area(const T & shape)
{
  //variables
  float height =  shape.m_height; //height of the shape
  float base = shape.m_base; //base of the shape
  const float num = .5; //constant multipled to the shape
  
  //calculates and returns the area of the shape
  return height*base*num;     
}

//Description: calculates area of a circle
//Pre:	requires two floats in structure circle
//Post:	none
//Return: area of circle
float area(const circle & circ);

//Description: calculates area of rectangle
//Pre: requires two floats in structure rectangle
//Post: none
//Return: area of rectangle
float area(const rectangle & rect);

//Description: greeting message
//Pre: none
//Post: greeting message for the user
//Return: none
void greet();

//Description: sign off message
//Pre: none
//Post: signs off the user
//Returin: none
void signoff();

#endif
