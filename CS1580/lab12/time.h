//Name: Jimmy Lin
//Date: 11/11/2014
//Section: C
//File: time.h
//Description: contains the function prototypes and classes

#include <iostream>

using namespace std;

#ifndef TIME_H
#define TIME_H

//class called time
class Time
{
  public:
    //Description: gets user input of hours, minutes, and seconds
    //Pre: none
    //Post: changes the private variable hour, minute, and second
    //to what the user entered
    //Return: none
    void read_in();
    //Description: //prints out the time the user entered
    //Pre: none
    //Post: prints out the time the user entered in this format
    //HH:MM:SS
    //Return: none
    void print_out();
    //Description: prints out the time the user entered with +1 seconds
    //Pre: none
    //Post: prints out the the time the user entered with +1 seconds
    //Return: none 
    void nextSecond();
  private:
    //holds hours
    int hour;
    //holds minutes
    int minute;
    //holds seconds
    int second;
};

#endif
