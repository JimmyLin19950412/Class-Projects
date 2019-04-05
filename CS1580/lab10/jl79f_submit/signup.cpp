//Name:	Jimmy Lin
//Date:	10/28/2014
//Section: C
//File: signup.cpp
//Description: simulates a user sign-up process for an e-mail account

#include <iostream>
#include <string.h>

using namespace std;

//structure
struct account
{
  char m_firstName[15]; //NTCA array that contains first name
  char m_lastName[15]; //NTCA array that contains last name
  char m_userID[15]; //NTCA array that contains the user ID
  char m_password[15]; //NTCA array that contains the password
};

//function prototypes
//Description: greets the user
//Pre: none
//Post: outputs a string that contains a greeting message
//Resturn: none
void greeting();

//Description: reads in the user's info and puts them in a struct
//Pre: requires a struct to put user info in
//Post: first name, last name, and password are populated in struct
//userID is then generated
//Return: none
void read_in(account &user);

//Description: prints user's first name, last name, and user id
//Pre: requires a structure containing the user's first name, last name
//and user ID
//Post: prints severl strings that contains the user's last name
//first name and user ID
//Return: none
void print_out(account &user);

//Description: reprints the user with asterisks
//Pre: requires an array that contains the original password
//Post: outputs a string that contains the same number of characters in
//in asterisks as the user's password
//Return: none
void printPassword(char password[]);

//Description: signs off the suer
//Pre: none
//Post: outputs a string that contains a sign off message
//Return: none
void signoff();
int main()
{
  //calls stucture
  account user;
  
  //variables
  
  //greets the user
  greeting();
  
  //asks the user for input
  read_in(user);
  
  //prints out all user info but password
  print_out(user);
  
  //prints password
  printPassword(user.m_password);
  
  //signs the user off
  signoff();
  
  return 0;
}

//greets the user
void greeting()
{
  cout<<"Wecleom! Please enter your information to sign up"<<endl;
}

//reads in user info
void read_in(account &user)
{
  //variables
  bool exit = false; //determines to exit loop or not
  char confirmPassword[15]; //holds confirmation password
  int i = 0; //counter that determines size of password
  
  //asks user to enter first name
  cout<<"Enter your First Name: ";
  cin>>user.m_firstName;
  
  //asks user to enter last name
  cout<<"Enter your Last Name: ";
  cin>>user.m_lastName;
  
  //asks user for a password between 7-15 char
  //loops until user enters a password between 7-15 char
  do {
    //asks user for password
    cout<<"Enter your Password (7-15 characters): ";
    cin>>user.m_password;
    
    //determines the size of the password
    while(user.m_password[i] != '\0') {
      //increases counter that determines the size of password
      i++;
    }
    
    //determines if password is of right size
    //password is of right size
    if(i >= 7 && i <= 14) {
      //asks user for a confirmation password
      cout<<"Confirm your password: ";
      cin>>confirmPassword;
      
      //compares password
      if(strncmp(user.m_password, confirmPassword, 15) == 0) {
       exit = true;
     }
    }
    else {
      i = 0;
    }
  }while(exit == false);

  //generates userID
  strncat(user.m_userID, user.m_firstName, 15);
  strncat(user.m_userID, user.m_lastName, 15);
}

//prints out user info in struct
void print_out(account &user)
{
  cout<<"*********************************"<<endl;
  cout<<"Account information Summary:"<<endl;
  cout<<"First Name: "<<user.m_firstName<<endl;
  cout<<"Last Name: "<<user.m_lastName<<endl;
  cout<<"User ID: "<<user.m_userID<<endl;
}

//prints out password
void printPassword(char password[])
{
  //variable
  int i = 0; //contains the amount of characters inside password
  string asterisk; //string consisting of only asterisks
  
  while(password[i] != '\0') {
    //adds 1 to i
    i++;
  }
  
  //adds asterisks to asterisk string
  for (int j = 0; j <= i-1; j++) {
    asterisk = asterisk + "*";
  } 
  
  //prints password
  cout<<"Password: "<<asterisk<<endl; 
}

//signs off the user
void signoff()
{
  cout<<"Thanks!"<<endl;
}
