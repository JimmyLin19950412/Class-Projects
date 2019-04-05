//Name:	Jimmy Lin
//Date:	10/7/2014
//Section: C
//File: randomzer.h
//Description: contains function prototypes

#include<iostream>

using namespace std;

#ifndef RANDOMIZER_H
#define RANDOMIZER_H
//Description: greets the user
//Pre: none
//Post: prints out a greeting for the user
//return: none
void greet();

//Description: read two numbers from the user
//Pre: requires 2 integers from the user
//Post: changes the value of number1 and number 2
//return: nonr
void readNumbers(int & number1, int & number2);

//Description: generates and prints five random numbers 
//Pre: requires two integers from the user
//Post: prints out five random numbers
//return: none
void randomGenerator(int num1, int num2);

//Description: prints signoff message to the user
//Pre: none
//Post: prints out signoff message
//return: none
void signoff();

#endif
