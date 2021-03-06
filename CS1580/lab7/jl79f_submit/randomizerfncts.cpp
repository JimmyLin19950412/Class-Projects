//Name:	Jimmy Lin
//Date:	10/7/2014
//Section: C
//File:	randomizerfncts.cpp
//Description: contains function definitions

#include<iostream>
#include<cstdlib>

using namespace std;

//prints a greeting message to the user
void greet()
{
  //greeting message
  cout<<"~*~Welcome to Random Number Generator~*~"<<endl;
}

//reads two numbers from the user
void readNumbers(int & number1, int & number2)
{
  //asks user to enter a lower limit that is greater than 0
  do {
    cout<<"Enter the lower limit [>0]: ";
    cin>>number1;
  }while(number1 <= 0); 
  
  /*asks user to enter a upper limit that is greater than 9
  and 2 times greater then the first number */
  do {
    cout<<"Enter the uper limit [>9]: ";
    cin>>number2;
  }while(number2 <= 9 || number2 < (number1*2));
}

//generates amd prints five random numbers
void randomGenerator(int num1, int num2)
{
  //variable  
  int random1; //generated random number 1
  int random2; //generated random number 2
  int random3; //generated random number 3
  int random4; //generated random number 4
  int random5; //generated random number 5
  
  //generates 5 random numbers
  random1 = num1 + rand() % (num2 + 1 - num1);
  random2 = num1 + rand() % (num2 + 1 - num1);
  random3 = num1 + rand() % (num2 + 1 - num1);
  random4 = num1 + rand() % (num2 + 1 - num1);
  random5 = num1 + rand() % (num2 + 1 - num1);
  
  //prints out the 5 random numbers
  cout<<"1. Random Number between "<<num1<<" and "<<num2
  <<", inclusively, is: "<<random1<<endl;
  
  cout<<"2. Random Number between "<<num1<<" and "<<num2
  <<", inclusively, is: "<<random2<<endl;
  
  cout<<"3. Random Number between "<<num1<<" and "<<num2
  <<", inclusively, is: "<<random3<<endl;
  
  cout<<"4. Random Number between "<<num1<<" and "<<num2
  <<", inclusively, is: "<<random4<<endl;
  
  cout<<"5. Random Number between "<<num1<<" and "<<num2
  <<", inclusively, is: "<<random5<<endl; 
}

//prints a signoff message to the user
void signoff()
{
  //signoff message
  cout<<"Have a Good Day!"<<endl;
}
