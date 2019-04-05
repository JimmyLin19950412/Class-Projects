//Name: Jimmy Lin
//ID: 12434423
//Date: 9/16/2014
//Section: C
//File NameL lab4.cpp
/*Description: Asks user to see if they would like to enter a number, if yes
then user enters a number, if number is not between 0 and 50 then the number
is not accepted, and the number has to be divisible by 5 or 3. Program asks
user to enter a number until they say no. */

#include<iostream>

using namespace std;

int main()
{
  //variables
  int number = 0; //the current number the user has entered
  int totalNumber = 0; //sum of user entered numbers
  float finalNumber; //the average sum of numbers 
  int amtInput = 0; //Total amount of times the user inputed a number
  char response; //contains the answer for if the user wants to continue or not
  bool endLoop = false; //boolean to determine if loop stops or continues
  
  //loop to ask user to determine if they would like to enter a number
  do
  {
    //asks user if they would like to enter a number and stores response in variable response
    cout<<"Would you like to enter a number? (y/n)"<<endl;
    cin>>response;
    
    //if user enters y then asks them for a number
    if (response == 'y' || response == 'Y')
    {
      //asks user to enter a number and stores it in variable number
      cout<<"Please enter a number: ";
      cin>>number;
      
      //determines if the entered number is between 0 and 50
      if (number >= 0 && number <= 50)
      {
        //determines if the number entered is divisible by 5 or 3
        if (number % 5 == 0 || number % 3 == 0)
        {
          //increases variable amtInput by 1
          amtInput++;
      
          //adds variable number to variable totalNumber
          totalNumber += number;
        }
      }
    }
    //if user enters no then sets variable endLoop to false
    else if (response == 'n' || response == 'N')
    {
      //sets enloop to false since the user no longer wants to enter in numbers
      endLoop = true;
    }
  }while(endLoop == false);
  
  //determines if the user has entered a number yet, if not does not execute
  if (amtInput >= 1)
  {
   /*calculates the average of those numbers that are entered by the user that are divisble   
   by 5 or 3 and is greater than or equal to 0 and less than or equal to 50 */
   finalNumber = totalNumber / static_cast<float>(amtInput);
   
   //displays the averaged number
   cout<<"The average is: "<<finalNumber<<endl;
  }
  return 0;
} 
