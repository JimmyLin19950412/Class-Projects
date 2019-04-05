//Name: Jimmy Lin
//Date: 4/21/2015
//File: robotcalc.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "abstractstack.h"
#include "abstractstack.hpp"

using namespace std;

int main()
{
  stack<string> obj;
  stack<string> tempStack;
  stack<string> tempStack2;
  string input = "";
  int a;
  int b;
  int total;
  
  while(input != "@") {
    //gets input
    cin>>input;
    //adding, subtracting, multiplying, dividing, or module of last 2 number inputed
    if(input == "+" || input == "-" || input == "*" || input == "/" || input == "%") {  
      a = atoi(obj.top().c_str());
      obj.pop();
      b = atoi(obj.top().c_str());
      obj.pop();  
      if(input == "+") {
        total = b + a;
      }
      else if(input == "-") {
        total = b - a;
      }
      else if(input == "*") {
        total = b * a;
      }
      else if(input == "/") {
        total = b / a;
      }
      else if(input == "%") {
        total = b % a;
      }
      obj.push(to_string(total));
    }
    else if(input == "!") {
      total = atoi(obj.top().c_str());
      obj.pop();
      total = -1 * total;
      obj.push(to_string(total));
    }
    else if(input == "SUM") {
      total = 0;
      while(!obj.isEmpty()) {
        total = total + atoi(obj.top().c_str());
        obj.pop();
      }
      obj.push(to_string(total));
    }
    //prints current stack
    else if(input == "#") {
      obj.print();
    }
    //reverses the stack
    else if(input == "R") {
      while(!obj.isEmpty()) {
        tempStack.push(obj.top());
        obj.pop();
      }
      obj = tempStack;  
      tempStack = tempStack2;
    }
    //clears stack
    else if(input == "$") {
      obj.clear();
    }
    //else number
    else {
      obj.push(input);
    }
  }
  return 0;
}
