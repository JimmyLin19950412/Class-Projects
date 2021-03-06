//Name:	Jimmy Lin
//Date:	10/7/2014
//File:	hw5.cpp
//Section A1
/*Description: */

#include<iostream>

using namespace std;

//function prototypes

//Description: displays a greeting for the user
//Precondition: none
//Postcondition: displays a greeting
//Return: none
void greeting();

//Description: Displays a menu for the user to pick
//Precondition: none
//Postcondition: diplays a menu
//Return: a number that the user picked
int menu();

//Description: calculates body mass index
//Precondition: requires two integers from the user
//Postcondition: none
//Return: float body mass index
float BodyMassIndex(int weight, int height);

//Description: calculates the creatinine clearance
//Precondition: requires two integers and one float from the user
//Postcondition: none
//Return: float creatinine clearance
float creatinineClearance(int age, int weight, float serumValue);

//Description: calculates coronary risk
//Precondition: requires one float, one bool, and one short
//Postcondition: none
//Return: int coronary risk
int coronaryRisk(float BMI, bool heartDisease, short lbsBacon);

//Description: calculates totter index
//Precondition: requires two floats from the user
//Postcondition: none
//Returns: float totter index
float totterIndex(float leftLeg, float rightLeg);

//Description: Displays a goodbye message
//Preconditions: none
//Postconditions: displays a goodbye message
//Return: none
void goodbye();

int main()
{
  //variables
  char userAnswer; //user's answer to some questions
  int menuChoice; //holds the choice the user entered for menu
  int weight; //weight of the user
  int height; //height of the user
  int age; //age of the user
  float serumValue; //serium creatine value
  bool heartDisease; //predisposition to heart disease
  short lbsBacon; //lb of bacon eaten for breakfast
  float leftLeg; //length of left leg
  float rightLeg; //length of right leg
  float BMI; //body mass index
  float CC; //creatine clearance
  int CR; //coronary risk
  float TI; //totter index
  
  //displays a greeting to the user
  greeting();
  
  //displays menu until the user enters 5
  do {
    //displays menu and assigns the number the user picked to a variable
    menuChoice = menu();
    
    //determines which function to display depending on the choice of the user
    //if user entered 1
    if(menuChoice == 1){
      //asks user for weight
      cout<<"What is your weight? ";
      cin>>weight;
      
      //asks user for height
      cout<<"What is your height? ";
      cin>>height;
      
      /*calls function BodyMassIndex with weight
      and height of the user and calculates
      the body mass index of the user */
      BMI =  BodyMassIndex(weight, height);
    
      //displays the user's body mass index
      cout<<"Your Body Mass Index is "<<BMI<<endl;
    }
    //if user entered 2
    else if(menuChoice == 2){
      //asks user for age
      cout<<"What is your age? ";
      cin>>age;
      
      //asks user for weight
      cout<<"What is your weight? ";
      cin>>weight;
      
      //asks user for serum creatine value
      cout<<"What is the serum creatine value? ";
      cin>>serumValue;
      
      //calculates creatinine clearance
      CC = creatinineClearance(age, weight, serumValue);
      
      //displays user's creatinine clearance
      cout<<"your creatinine clearance is "<<CC<<endl;
    }
    //if user entered 3
    else if(menuChoice == 3) {
      //asks user for BMI
      cout<<"What is your BMI? ";
      cin>>BMI;
      
      //asks user if they have predisposition to heart disease
      do {
        cout<<"Do you have a predisposition to heart disease? (y/n): ";
        cin>>userAnswer;
        //loops till user enters a y or n
      }while(userAnswer != 'y' && userAnswer != 'n');
      
      //determines wether if the user has a predisposition to heart disease
      if(userAnswer == 'y') {
        heartDisease = true;
      }
      else {
        heartDisease = false;
      }
      
      //asks user for pounds of bacon eaten for breakfast
      cout<<"How many pounds(lb) of bacon did you eat for breakfast? ";
      cin>>lbsBacon;
      
      //calculates coronary risk
      CR = coronaryRisk(BMI, heartDisease, lbsBacon);
      
      //displays user's coronary risk
      cout<<"Your coronary risk is "<<CR<<endl;
    }
    //if user entered 4
    else if(menuChoice == 4) {
      //asks user for length of left leg
      cout<<"Length of left leg? ";
      cin>>leftLeg;
      
      //asks user for length of right leg
      cout<<"Length of right leg? ";
      cin>>rightLeg;
      
      //calculates totter index
      TI = totterIndex(leftLeg, rightLeg);
      
      //displays totter index
      cout<<"Your totter index is "<<TI<<endl;
    }
    //if user entered 5
    else if(menuChoice == 5) {
      //displays goodbye message
      goodbye();
    }
    //if user enteres an invalid input
    else {
    
    }
  }while(menuChoice != 5); //loops until user enteres 5
}

//displays a greeting to the user
void greeting()
{
  //welcome message
  cout<<"Welcome to Dr. Eloe's Health-o-matic!"<<endl;
}

//displays a menu for the user
int menu()
{
  //variables
  int userChoice; //user's choice on the menu
  
  //displays menu
  cout<<"1. Body Mass Index (BMI)"<<endl;
  cout<<"2. Creatinine Clearance (CC)"<<endl;
  cout<<"3. Coronary Risk (CR)"<<endl;
  cout<<"4. Totter Index (TI)"<<endl;
  cout<<"5. Quit"<<endl;
  cout<<"Enter a choice: ";
  cin>>userChoice;
  
  //returns userChoice
  return userChoice;
}

//calculates BodyMassIndex
float BodyMassIndex(int weight, int height)
{
  //variable
  float BMI; //holds the body mass index
  
  /*calculates the body mass index based off of
  the users weight and height */
  BMI = (static_cast<float>(weight)/(static_cast<float>(height)*height))
   * static_cast<float>(703);
  
  //returns BMI
  return BMI;
}

//calculates creatinine clearance
float creatinineClearance(int age, int weight, float serumValue)
{
  //variables
  float CC; //creatinine clearance
  
  //calculates creatinine clearance
  CC = ((140-age)*weight*serumValue)/72;
  
  //returns creatinine clearance
  return CC;
}

//calculates coronary risk
int coronaryRisk(float BMI, bool heartDisease, short lbsBacon)
{
  //variables
  int CR = 0; //coronary risk
  
  //calculates coronary risk
  //if user's BMI is greater then 30 then add 2 to CR
  if(BMI > 30) {
    CR += 2;
  }
  
  //if either parent have heart disease then add 1 to CR
  if(heartDisease == true){
    CR++;
  }
  
  //for every 1 pound of bacon eaten for breakfast add 1 point to CR
  CR += lbsBacon;
  
  //returns coronary risk
  return CR;
}

//calculates totter index
float totterIndex(float leftLeg, float rightLeg)
{
  //variables
  float TI; //totter index
  
  //if either leg's length is 0 then TI is 0
  if(leftLeg == 0 || rightLeg == 0) {
    TI = 0;
  }
  else {
    TI = leftLeg/rightLeg;
  }
  //returns totter index
  return TI;
}

//displays a goodbye message
void goodbye()
{
  //goodbye message
  cout<<"Thank you for using Dr. Eloe's Health-o-matic. Have a nice day!"
  <<endl;
}
