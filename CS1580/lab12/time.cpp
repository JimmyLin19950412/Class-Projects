//Name: Jimmy Lin
//Date: 11/11/2014
//Section: C
//File: time.cpp
//Description: contains function definitions

#include <iostream>
#include "time.h"

using namespace std;

//reads in the time of the user
void Time::read_in()
{
  //variables
  int hours = 0; //contains user entered hours
  int minutes = 0; //contains user entered minutes
  int seconds = 0; //contains user entered seconds
  
  //asks user to enter hours and repeats if user entered hour
  //is greater than 24 or lower than 0
  do { 
    cout<<"Enter hour: ";
    cin>>hours;
    
    //outputs error if user entered invalid hours
    if(hours > 23 || hours < 0) {
      cout<<"Invalid hour!"<<endl;
    }
  }while(hours > 23 || hours < 0);
  
  //asks user to enter minutes and repeats if user entered minute
  //is greater than 60 or lower than 0
  do {
    cout<<"Enter minute: ";
    cin>>minutes;
    
    //outputs error if user entered invalid minutes
    if(minutes > 60 || minutes < 0) {
      cout<<"Invalid minute!"<<endl;
    }
  }while(minutes > 60 || minutes < 0);
  
  //asks user to enter seconds and repeats if user entered seconds is
  //greater than 60 or lower than 0
  do {
    cout<<"Enter second: ";  
    cin>>seconds;
    
    //outputs error if user entered invalid seconds
    if(seconds > 60 || seconds < 0) {
      cout<<"Invalid second!"<<endl;
    }
  }while(seconds > 60 || seconds < 0);
  
  //assigns user entered hours, minutes, and seconds to private variables
  hour = hours;
  minute = minutes;
  second = seconds;    
}

//prints out the user's inputed hours, minutes, and seconds
void Time::print_out()
{
  cout<<"Time is: "<<hour<<":"<<minute<<":"<<second<<endl;
}

//prints out the time the user entered with +1 seconds
void Time::nextSecond()
{
  //adds 1 to second
  second++;
  
  //if second is >=60 then minute +1 and second reset to 0
  if(second >= 60) {
    second = 0;
    minute++;
  }
  
  //if minute is >= 60 then minute + 1 and minute resets to 0
  if(minute >= 60) {
    minute = 0;
    hour++;
  }
  
  //if hours is > 23 then hour = 1
  if(hour > 23) {
    hour = 0;
  }
  
  //printts out next second
  cout<<"Next Second is: "<<hour<<":"<<minute<<":"<<second<<endl;
}

