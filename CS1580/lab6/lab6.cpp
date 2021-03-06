//Name: Jimmy Lin
//Date: 9/30/2014
//ID: 12434423
//Section: C
//File: lab6.cpp
/*Description: Takes 3 numbers from user and calculates
 arithmetic and harmonic mean */
#include<iostream>

using namespace std;
//----prototypes
void greet(); //greeting message
/*read a user input for a number and make sure it is positive,
if it is negative, keep asking until it is positive*/
float readNumber();
//calculate and return the arithmetic mean of three positive numbers
float arithmeticMean(float number1, float number2, float number3);
//calculate and retun the harmonic mean of three positive numbers
float harmonicMean(float number1, float number2, float number3);
//print results on screen
void printResult(float harmoninc, float arithmetic);
//a signoff message is output on screen
void signoff();

int main()
{
  //variables
  float numOne; //first number
  float numTwo; //second number
  float numThree; //third number
  float arithMean; //arithmetic number
  float harmMean; //harmonic number
  
  //greeting message
  greet();
  
  /*read a user input for a number and make sure it is positive,
  if it is negative, keep asking until it is positive*/
  numOne = readNumber();
  numTwo = readNumber();
  numThree = readNumber();
  
  //calculate and return the arithmetic mean of three positive numbers
  arithMean = arithmeticMean(numOne, numTwo, numThree);
  
  //calculate and return the harmonic mean of three positive numbers
  harmMean = harmonicMean(numOne, numTwo, numThree);
  
  //print results on screen
  printResult(harmMean, arithMean);
  
  //a sign off message is output on the screen
  signoff();
  
  return 0;
}

void greet()
{
  cout<<"~*~Welcome to Arithmetic Mean and Harmonic Mean Calculator~*~"<<endl;
}

float readNumber()
{
  //variable
  float number; //user inputed number
  bool exit = false; //exits loop
  
  //loop asking for number until user enters a positive non zero number
  do {
    cout<<"Enter a positive Number: ";
    cin>>number;
    
    //invalid input
    if(number <= 0) {
      cout<<"Invalid Number! Try again"<<endl;
    }
    else {
      exit = true; //exits loop
    }
  }while(!exit);
  
  //returns number
  return number;
}

float arithmeticMean(float number1, float number2, float number3)
{
  //variable
  float mean; //mean value of three numbers
  
  //calculates arithmetic mean
  mean = (number1 + number2 + number3)/3;
  
  //returns mean
  return mean;
}

float harmonicMean(float number1, float number2, float number3)
{
  //variables
  float mean; //mean value of three numbers
  
  mean = 3/((1/number1)+(1/number2)+(1/number3));
  
  //returns mean
  return mean;
}

void printResult(float harmonic, float arithmetic)
{
  //prints the arithemtic and harmonic mean
  cout<<"Arithmetic Mean: "<<arithmetic<<endl;
  cout<<"Harmonic Mean: "<<harmonic<<endl;
}

void signoff()
{
  cout<<"Have a Good Day!"<<endl;
}
