//Name: Jimmy Lin
//Date: 11/11/2014
//Section: C
//File: main.cpp
//Description: 

#include <iostream>
#include "time.h"

using namespace std;

int main()
{
  //calls time clss
  Time times;
  
  //reads in user hour, minute, and seconds
  times.read_in();
  
  //prints out user entered hour, minute, and seconds
  times.print_out();
  
  //prints out the user entered hour, minute, and seconds
  //but with +1 seconds
  times.nextSecond();
  
  return 0;
}
