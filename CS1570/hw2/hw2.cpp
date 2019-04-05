//Name:  Jimmy Lin
//ID:	 12434423
//Date:  September 11, 2014
//File:  hw2.cpp
/*Description: Asks user for age, weight, gender, IQ, and number of pills
taken each day. Then it will use that information to calculate the
recommended dosage of tablets to take */

#include<iostream>

using namespace std;

int main()
{
  //variables
  int age; //stores user's age
  int iq; //stores user's iq
  float weight; //stores the user's weight
  int freq; //stores the frequncy at which the user takes their pills per day
  int gender; //stores the user's gender. 0 for female 1 for male
  const int TS = 250; //stores the constant tablet strenght
  const int DEC = 20; //stores Doctor Eloe's constant
  int recDosage; //recommended dosage to take
  
  //greeting message
  cout<<"Welcome to Dr. Eloes prescription dosage. Please enter in the"<<
  " following information!"<<endl;
  
  //asks user for their age
  cout<<"What is your age? ";
  cin>>age;
  
  //asks user for their IQ
  cout<<"What is your IQ? ";
  cin>>iq;
  
  //asks user for their weight
  cout<<"What is your weight in kg? ";
  cin>>weight;
  
  //asks user for the frequency at which they thake their pills
  cout<<"How many pills do you take per day? ";
  cin>>freq;
  
  //asks user for their gender
  cout<<"Are you a female or male? (0 for female, 1 for male) ";
  cin>>gender;
  
  /*calculates the user's recommended dosage from the informatio that they
  entered */ 
  recDosage = ((static_cast<float>(age)/iq) * ((static_cast<float>(weight)/freq)
  + 1) * ((TS/static_cast<float>(1000)) + gender) + DEC) + .5;
  
  /* outputs the user's informtion that they entered along with the
  recommended dosage that they should tale */
  cout<<"Your information was: "<<endl;
  cout<<"Age = "<<age<<endl;
  cout<<"Weight = "<<weight<<" kg"<<endl;
  cout<<"IQ = "<<iq<<endl;
  cout<<"Frequencey = "<<freq<<endl<<endl;
  cout<<"Tablet Strength of "<<TS<<" mg"<<endl;
  cout<<"Your recommended dosage is "<<recDosage<<" tablets."<<endl;
  
  //says good-bye to the user and thanks them for using the program
  cout<<"Thank you for using Dr. Eloes program to determine how many"<<
  " tablets you should take. Please come again and have a nice day."<<endl;
  
  return 0;
}	
