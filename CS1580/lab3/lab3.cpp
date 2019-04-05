//Name: Jimmy Lin
//ID: 12434423
//Section: C
//Date: September 9, 2014
//File Name: lab3.cpp
//Description: Body Mass Index (BMI) Calculator

#include<iostream>

using namespace std;

int main()
{
  //variables
  int mass;	//int variable holding user's weight
  int height;	//int variable holding user's height
  float BMI;	//float variable holding the user's bmi
  const int CONVERSION_FACTOR = 703; // holding the value of conversion factor
 
  //introduction
  cout<<"Welcome to the BMI calculator"<<endl;
  
  //asks user to enter their mass in pounds
  cout<<"Please enter your weight in pounds: ";
  //inputs users weight into mass variable
  cin>>mass;
  
  //asks user for their height in inches
  cout<<"Please enter your height in inches: ";
  //inputs users height into height variable
  cin>>height;
  
  //calculates the user's BMI with their given mass and height
  BMI =( static_cast<float>(mass) * CONVERSION_FACTOR)/(height * height);
  
  //outpus users BMI
  cout<<"The BMI value for "<<height<<" "<<"inches and "<<mass<<" "<<"pounds is "<<BMI <<endl;
  
  return 0;
}
