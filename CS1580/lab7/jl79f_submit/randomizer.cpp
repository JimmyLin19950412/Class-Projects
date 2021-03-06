//Name:	Jimmy Lin
//Date:	10/7/2014
//Section: C
//File:	randomizer.cpp
//Description: generates five random numbers between 2 bounds

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"randomizer.h"

using namespace std;

int main()
{
  //variables
  int number1 = 0; //first number the user enters
  int number2 = 0; //second number the user enters
  
  //generates a random seed
  srand(time(NULL));
  
  //greets the user
  greet();
  
  //reads two numbers from the user
  readNumbers(number1, number2);
  
  //generates and prints five random numbers
  randomGenerator(number1, number2);
  
  //signoff message
  signoff();
}
