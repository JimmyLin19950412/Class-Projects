//Name: Jimmy Lin
//Date: 2/26/2015
//File: realbox.cpp
//Definition: contains the functions for realbox.h

#include <iostream>
#include "realbox.h"

using namespace std;

//constructor for RealBox class
RealBox::RealBox(int s, float a)
{
  //sets m_boxsize equal to s
  m_boxsize = s;
  //creates a dynamic array with size of s
  m_reals = new float[m_boxsize];
  //fills the array m_reals with a value
  for(int i = 0; i < m_boxsize; i++) {
    m_reals[i] = a;
  }
}

//destructor
RealBox::~RealBox()
{
  //deletes the pointer m_reals;
  delete [] m_reals;
}

//overloaded operator =
const RealBox& RealBox::operator=(const RealBox& rhs)
{
  //prevents self copy
  if(this == &rhs) {
    return (*this);
  }
  //if the size of the 2 classes are not equal
  if(m_boxsize != rhs.m_boxsize) {
    //deletes the pointer array m_reals
    delete [] m_reals;
    //creates a new array and with same side as rhs
    m_reals = new float[rhs.m_boxsize];
  }
  //makes both the size equal
  m_boxsize = rhs.m_boxsize;
  //copies elements from rhs to lhs
  for(int i = 0; i < m_boxsize; i++) {
    m_reals[i] = rhs.m_reals[i];
  }
  //allows cascading assignment
  return (*this);      
}

//copy constructor 
RealBox::RealBox(const RealBox & rhs)
{
  //copies the size
  m_boxsize = rhs.m_boxsize;
  //uses the copied size to make a new array with the size
  m_reals = new float[m_boxsize];
  //copies every element from old array into new array
  for(int i = 0; i < m_boxsize; i++) {
    m_reals[i] = rhs.m_reals[i];
  }  
}

//sets a value in the RealBox
void RealBox::set(int i, float x) 
{
  //checks to see if it would go out of bounds
  //if it goes out of bounds
  if(i > m_boxsize) {
    cout<<"Error! Out of bounds!"<<endl;
    return;
  }
  
  //sets the position i to the value of x
  m_reals[i] = x;  
}

//prints the RealBox
ostream & operator<<(ostream & out, const RealBox & box)
{
  out<<"[ ";
  //loops through RealBox and prints its content
  for(int i = 0; i < box.m_boxsize; i++) {
    out<<box.m_reals[i]<<", ";
  }
  out<<"]";
  return out;
}
