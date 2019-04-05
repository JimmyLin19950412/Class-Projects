//Name: Jimmy Lin
//ID: 12434423
//Date:	9/19/2014
//File: hw3.cpp
//Description: 

#include<iostream>

using namespace std;

int main()
{
  //variables
  //constants for region (menu)
  const string menuOptionOne = "Head & Neck"; //(1) contains the first option in the menu
  const string menuOptionTwo = "Torso"; //(2) conains the second option in the menu
  const string menuOptionThree = "Extremity"; //(3) contains the third option in the menu
  const string menuOptionFour = "Not Listed"; //(4) contains the fourth option in the menu
  //constants for subregion
  const string menuOneOne = "Head"; //1 1
  const string menuOneTwo = "Neck"; //1 2
  const string menuOneThree = "Face"; //1 3
  const string menuTwoOne = "Back" ; //2 1
  const string menuTwoTwo = "Abdomen"; //2 2
  const string menuTwoThree = "Chest"; //2 3
  const string menuThreeOne = "Arm"; //3 1
  const string menuThreeTwo = "Leg"; //3 2
  //constants for injury
  const string menuOneOneOne = "Cerebral Contusion"; //1 1 1
  const string menuOneOneTwo = "Earlobe gastrophilogy"; //1 1 2
  const string menuOneOneThree = "Altered Ego"; //1 1 3
  const string menuOneTwoOne = "Broken"; //1 2 1
  const string menuOneThreeOne = "Permanent Smiley Face"; //1 3 1
  const string menuOneThreeTwo = "Deformed Plastic Surgery (melting)"; //1 3 2 
  const string menuTwoOneOne = "Disk Rupture"; //2 1 1
  const string menuTwoOneTwo = "BBQd Ribs"; //2 1 2
  const string menuTwoTwoOne = "Intestinal Distress"; //2 2 1
  const string menuTwoTwoTwo = "Alcohol Poisoning"; //2 2 2
  const string menuTwoThreeOne = "Flail Chest"; //2 3 1
  const string menuTwoThreeTwo = "Alien Implantation"; //2 3 2
  const string menuThreeOneOne = "Broken Radius"; //3 1 1
  const string menuThreeOneTwo = "Finger (nail fungus)"; //3 1 2
  const string menuThreeTwoOne = "Toe (burned toe hair)"; //3 2 1
  const string menuThreeTwoTwo = "Fractured femur"; //3 2 2
  
  //constants for severity
  const int menuOneOneOneS = 9; //1 1 1 S
  const int menuOneOneTwoS = 5; //1 1 2 S
  const int menuOneOneThreeS = 4; //1 1 3 S
  const int menuOneTwoOneS = 6; //1 2 1 S
  const int menuOneThreeOneS = 3; //1 3 1 S
  const int menuOneThreeTwoS = 1; //1 3 2 S
  const int menuTwoOneOneS = 7; //2 1 1 S
  const int menuTwoOneTwoS = 7; //2 1 2 S
  const int menuTwoTwoOneS = 2; //2 2 1 S
  const int menuTwoTwoTwoS = 2; //2 2 2 S
  const int menuTwoThreeOneS = 4; // 2 3 1 S
  const int menuTwoThreeTwoS = 8; //2 3 2 S
  const int menuThreeOneOneS = 3; //3 1 1 S
  const int menuThreeOneTwoS = 0; //3 1 2 S
  const int menuThreeTwoOneS = 1; //3 2 1 S
  const int menuThreeTwoTwoS = 3; //3 2 2 S
  
  //patient one
  string patientOne; //contains the name of the first patient
  string patientOneMenu; //patient one's region
  string patientOneSubregion; //patient one's subregion
  string patientOneInjury; //patient one's injury
  int patientOneSeverity; //patient one's severity scale
  
  //patient two
  string patientTwo; //contains the name of the second patient
  string patientTwoMenu; //patient two's region
  string patientTwoSubregion; //patient two's subregion
  string patientTwoInjury; //patient two's injury
  int patientTwoSeverity; //patient two's severity
  
  int userChoice; //holds the users decisions throughout the program 
  
  //greets the user
  cout<<"Greetings Dr. Eloe"<<endl;
  
  //asks the user to enter the name of the patients
  cout<<"Please enter the name of the first patient: ";
  cin>>patientOne;
  cout<<endl;
  cout<<"Please enter the name of the second patient: ";
  cin>>patientTwo; 
  cout<<endl;
  
  //do while loop to show the user a menu
  //loop repeats until 1, 2, 3, or 4 is inputed
  do
  {
    cout<<"         "<<patientOne<<endl;
    cout<<" 	     Menu"<<endl;
    cout<<"	     ----"<<endl;
    cout<<"1. "<<menuOptionOne<<endl;
    cout<<"2. "<<menuOptionTwo<<endl;
    cout<<"3. "<<menuOptionThree<<endl;
    cout<<"4. "<<menuOptionFour<<endl;
    cout<<"Please enter a number: ";
    cin>>userChoice;
  }while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4);
  
  //-----------------------------determines patient one's menu choice
  //menu choice 1
  if(userChoice == 1)
  {
    //sets the first patients region
    patientOneMenu = menuOptionOne;
    //do while loop to show and determine the subregion
    do
    {
      //show user the subregion regarding menu's option 1
      cout<<"          "<<patientOne<<endl;
      cout<<"		Subregion"<<endl;
      cout<<"		---------"<<endl;
      cout<<"1. "<<menuOneOne<<endl; //1 1
      cout<<"2. "<<menuOneTwo<<endl; //1 2
      cout<<"3. "<<menuOneThree<<endl; //1 3
      cout<<"Please enter a number: ";
      cin>>userChoice;        
    }while(userChoice != 1 && userChoice != 2 && userChoice != 3 );
    
    //determines patient one's injury then assigns it a severity scale
    //menu 1 1 
    if(userChoice == 1)
    {
     //sets the first patients subregion
     patientOneSubregion = menuOneOne;
     
     //loop to determine injury
     do
     {
       cout<<"         "<<patientOne<<endl;	
       cout<<"		Injury"<<endl;
       cout<<"		------"<<endl;
       cout<<"1. "<<menuOneOneOne<<endl; //1 1 1
       cout<<"2. "<<menuOneOneTwo<<endl; //1 1 2
       cout<<"3. "<<menuOneOneThree<<endl; //1 1 3
       cout<<"Please enter a number: ";   
       cin>>userChoice;
     }while(userChoice != 1 && userChoice != 2 && userChoice != 3);
     
     //determines the severity
     if(userChoice == 1)
     {
       patientOneInjury = menuOneOneOne; 
       patientOneSeverity = menuOneOneOneS; //1 1 1 S
     }
     else if(userChoice == 2)
     {
       patientOneInjury = menuOneOneTwo;
       patientOneSeverity = menuOneOneTwoS; //1 1 2 S
     }
     else if(userChoice == 3)
     {
       patientOneInjury = menuOneOneThree;
       patientOneInjury = menuOneOneThreeS; //1 1 3 S
     }
    
    }
    //menu 1 2
    else if(userChoice == 2)
    {
      patientOneSubregion = menuOneTwo;
      
      //determines the injury
      do
      {
        cout<<"        "<<patientOne<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuOneTwoOne<<endl; //1 2 1
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1);
      
      //determines the severity
      if(userChoice == 1)
      {
        patientOneInjury = menuOneTwoOne;
        patientOneSeverity = menuOneTwoOneS; //1 2 1 S
      }
    }
    //menu 1 3
    else if(userChoice == 3)
    {
      patientOneSubregion = menuOneThree;
      
      //determines injury
      do
      {
        cout<<"        "<<patientOne<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuOneThreeOne<<endl; //1 3 1
        cout<<"2. "<<menuOneThreeTwo<<endl; //1 3 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientOneInjury = menuOneThreeOne;
        patientOneSeverity = menuOneThreeOneS; //1 3 1 S
      }
      else if(userChoice == 2)
      {
        patientOneInjury = menuOneThreeTwo;
        patientOneSeverity = menuOneThreeTwoS; //1 3 2 S
      }
    }
  }
  //menu choice 2
  else if(userChoice == 2)
  {
    patientOneMenu = menuOptionTwo;
    
    //determines subregion
    do
    {
      cout<<"          "<<patientOne<<endl;
      cout<<"		Subregion"<<endl;
      cout<<"		---------"<<endl;
      cout<<"1. "<<menuTwoOne<<endl; //2 1
      cout<<"2. "<<menuTwoTwo<<endl; //2 2
      cout<<"3. "<<menuTwoThree<<endl; //2 3
      cout<<"Please enter a number: ";
      cin>>userChoice;
    }while(userChoice != 1 && userChoice != 2 && userChoice != 3);
    
    //determines injury
    //2 1 
    if(userChoice == 1)
    {
      patientOneSubregion = menuTwoOne;
      
      //determines injury
      do
      {
        cout<<"        "<<patientOne<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuTwoOneOne<<endl; //2 1 1
        cout<<"2. "<<menuTwoOneTwo<<endl; //2 1 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientOneInjury = menuTwoOneOne;
        patientOneSeverity = menuTwoOneOneS; //2 1 1 S
      }
      else if(userChoice == 2)
      {
        patientOneInjury = menuTwoOneTwo;
        patientOneInjury = menuTwoOneTwoS; //2 1 2 S
      }
    }
    //2 2
    else if(userChoice == 2)
    {
      patientOneSubregion = menuTwoTwo;
      
      //determines injury
      do
      {
        cout<<"        "<<patientOne<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuTwoTwoOne<<endl; //2 2 1
        cout<<"2. "<<menuTwoTwoTwo<<endl; //2 2 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientOneInjury = menuTwoTwoOne;
        patientOneSeverity = menuTwoTwoOneS; //2 2 1 S
      }
      else if(userChoice == 2)
      {
        patientOneInjury = menuTwoTwoTwo;
        patientOneSeverity = menuTwoTwoTwoS; //2 2 2 s
      }
    }
    //2 3 
    else if(userChoice == 3)
    {
      patientOneSubregion = menuTwoThree;
      
      //determines injury
      do
      {
        cout<<"        "<<patientOne<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuTwoThreeOne; //2 3 2
        cout<<"2. "<<menuTwoThreeTwo; //2 3 1
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientOneInjury = menuTwoThreeOne;
        patientOneSeverity = menuTwoThreeOneS; //2 3 1 S
      }
      else if(userChoice == 2)
      {
        patientOneInjury = menuTwoThreeTwo;
        patientOneSeverity = menuTwoThreeTwoS; //2 3 2 S
      }
    }
  }
  //menu choice 3
  else if (userChoice == 3)
  {
    patientOneMenu = menuOptionThree;
    
    //determines subregion
    do
    {
      cout<<"          "<<patientOne<<endl;
      cout<<"		Subregion"<<endl;
      cout<<"		------"<<endl;
      cout<<"1. "<<menuThreeOne<<endl; //3 1
      cout<<"2. "<<menuThreeTwo<<endl; //3 2
      cout<<"please enter a number: ";
      cin>>userChoice;
    }while(userChoice != 1 && userChoice != 2);
    
    if(userChoice == 1)
    {
      patientOneSubregion = menuThreeOne;
      
      //determines injury
      do
      {
        cout<<""<<patientOne<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuThreeOneOne<<endl; //3 1 1
        cout<<"2. "<<menuThreeOneTwo<<endl; //3 1 2
        cout<<"Please enter a number: "<<endl;
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
     
      //determines severity
      if(userChoice == 1)
      {
        patientOneInjury = menuThreeOneOne;
        patientOneSeverity = menuThreeOneOneS; //3 1 1 S
      }
      else if(userChoice == 2)
      {
        patientOneInjury = menuThreeOneTwo;
        patientOneSeverity = menuThreeOneTwoS;
      }
    }
    else if(userChoice == 2)
    {
      patientOneSubregion = menuThreeTwo;
      
      //determines injury
      do
      {
        cout<<"        "<<patientOne<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuThreeTwoOne<<endl; //3 2 1
        cout<<"2. "<<menuThreeTwoTwo<<endl; //3 2 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientOneInjury = menuThreeTwoOne;
        patientOneSeverity = menuThreeTwoOneS; //3 2 1 S
      }
      else if(userChoice == 2)
      {
        patientOneInjury = menuThreeTwoTwo;
        patientOneSeverity = menuThreeTwoTwoS; //3 2 2 S
      }
    }
  }
  //menu choice 4
  else if(userChoice == 4)
  {
    patientOneMenu = menuOptionFour;
    patientOneSeverity = -1;
  }

  //----------------------------------------patient two's menu choice  
  //do loop to show menu
  do
  {
    cout<<"            "<<patientTwo<<endl;
    cout<<"		Menu"<<endl;
    cout<<"		----"<<endl;
    cout<<"1. "<<menuOptionOne<<endl; //1
    cout<<"2. "<<menuOptionTwo<<endl; //2
    cout<<"3. "<<menuOptionThree<<endl; //3
    cout<<"4. "<<menuOptionFour<<endl; //4
    cout<<"Please enter a number: ";
    cin>>userChoice;
  }while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4);
 
  //determines subregion
  //menu choice 1
  if(userChoice == 1)
  {
    patientTwoMenu = menuOptionOne;
    
    //determines subregion
    do
    {
      cout<<"          "<<patientTwo<<endl;
      cout<<"		Subregion"<<endl;
      cout<<"		---------"<<endl;
      cout<<"1. "<<menuOneOne<<endl; //1 1
      cout<<"2. "<<menuOneTwo<<endl; //1 2
      cout<<"3. "<<menuOneThree<<endl; //1 3
      cout<<"Please enter a number: ";
      cin>>userChoice;
    }while(userChoice != 1 && userChoice != 2 && userChoice != 3);
    
    //determines injury
    //1 1
    if(userChoice == 1)
    {
      patientTwoSubregion = menuOneOne;
    
      //determins injury
      do
      {
        cout<<"        "<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuOneOneOne<<endl; //1 1 1
        cout<<"2. "<<menuOneOneTwo<<endl; //1 1 2
        cout<<"3. "<<menuOneOneThree<<endl; //1 1 3
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2 && userChoice != 3);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuOneOneOne;
        patientTwoSeverity = menuOneOneOneS; //1 1 1 S
      }
      else if(userChoice == 2)
      {
        patientTwoInjury = menuOneOneTwo;
        patientTwoSeverity = menuOneOneTwoS; //1 1 2 S
      }
      else if(userChoice == 3)
      {
        patientTwoInjury = menuOneOneThree;
        patientTwoSeverity = menuOneOneThreeS; //1 1 3 S
      }
    }
    //1 2
    else if(userChoice == 2)
    {
      patientTwoSubregion = menuOneTwo;
      
      //determines injury
      do
      {
        cout<<"        "<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuOneTwoOne<<endl; //1 2 1
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuOneTwoOne;
        patientTwoSeverity = menuOneTwoOneS; //1 2 1 S
      }
    }
    //1 3
    else if(userChoice == 3)
    {
      patientTwoSubregion = menuOneThree;
      
      //determines injury
      do
      {
        cout<<""<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuOneThreeOne; //1 3 1
        cout<<"2. "<<menuOneThreeTwo; //1 3 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuOneThreeOne;
        patientTwoSeverity = menuOneThreeOneS; //1 3 1 S
      }
      else if(userChoice == 2)
      {
        patientTwoInjury = menuOneThreeTwo;
        patientTwoSeverity = menuOneThreeTwoS; //1 3 2 S
      }
    }
  }
  //menu choice 2
  else if(userChoice == 2)
  {
    patientTwoMenu = menuOptionTwo;
    
    //determines subregion
    do
    {
      cout<<"          "<<patientTwo<<endl;
      cout<<"		Subregion"<<endl;
      cout<<"		---------"<<endl;
      cout<<"1. "<<menuTwoOne<<endl; //2 1
      cout<<"2. "<<menuTwoTwo<<endl; //2 2
      cout<<"3. "<<menuTwoThree<<endl; //2 3
      cout<<"Please enter a number: ";
      cin>>userChoice;
    }while(userChoice != 1 && userChoice != 2 && userChoice != 3);
    
    //determines injury
    //2 1
    if(userChoice == 1)
    {
      patientTwoSubregion = menuTwoOne;
      
      //determines injury
      do
      {
        cout<<"        "<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuTwoOneOne<<endl; //2 1 1
        cout<<"2. "<<menuTwoOneTwo<<endl; //2 1 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuTwoOneOne;
        patientTwoSeverity = menuTwoOneOneS; //2 1 1 S 
      }
      else if(userChoice == 2)
      {
        patientTwoInjury = menuTwoOneTwo;
        patientTwoSeverity = menuTwoOneTwoS; //2 1 2 S
      }
    }
    //2 2
    else if(userChoice == 2)
    {
      patientTwoSubregion = menuTwoTwo;
      
      //determines injury
      do
      {
        cout<<"        "<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuTwoTwoOne<<endl; //2 2 1
        cout<<"2. "<<menuTwoTwoTwo<<endl; //2 2 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuTwoTwoOne;
        patientTwoSeverity = menuTwoTwoOneS; //2 2 1 S
      }
      else if(userChoice == 2)
      {
        patientTwoInjury = menuTwoTwoTwo;
        patientTwoInjury = menuTwoTwoTwoS; //2 2 2 S
      }
    }
    //2 3
    else if(userChoice == 3)
    {
      patientTwoSubregion = menuTwoThree;
      
      //determines injury
      do
      {
        cout<<"        "<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuTwoThreeOne<<endl; //2 3 1
        cout<<"2. "<<menuTwoThreeTwo<<endl; //2 3 2
        cout<<"Please enter a number: ";
        cin>>userChoice;  
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuTwoThreeOne;
        patientTwoSeverity = menuTwoThreeOneS; //2 3 1 S
      }
      else if(userChoice == 2)
      {
        patientTwoInjury = menuTwoThreeTwo;
        patientTwoSeverity = menuTwoThreeTwoS; //2 3 2 S
      }
    }
  }
  //menu choice 3
  else if(userChoice == 3)
  {
    patientTwoMenu = menuOptionThree;
    
    //determines subregion
    do
    {
      cout<<"          "<<patientTwo<<endl;
      cout<<"		Subregion"<<endl;
      cout<<"		---------"<<endl;
      cout<<"1. "<<menuThreeOne<<endl; //3 1
      cout<<"2. "<<menuThreeTwo<<endl; //3 2
      cout<<"Please select a number: ";
      cin>>userChoice;
    }while(userChoice != 1 && userChoice != 2);
    
    //determines injury
    //3 1
    if(userChoice == 1)
    {
      patientTwoSubregion = menuThreeOne;
      
      //determines injury
      do
      {
        cout<<"        "<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuThreeOneOne<<endl; //3 1 1 
        cout<<"2. "<<menuThreeOneTwo<<endl; //3 1 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuThreeOneOne;
        patientTwoSeverity = menuThreeOneOneS; //3 1 1 S
      }
      else if(userChoice == 2)
      {
        patientTwoInjury = menuThreeOneTwo;
        patientTwoSeverity = menuThreeOneTwoS; //3 1 2 S
      }
    }
    //3 2
    else if(userChoice == 2)
    {
      patientTwoSubregion = menuThreeTwo;
      
      //determines injury
      do
      {
        cout<<"        "<<patientTwo<<endl;
        cout<<"		Injury"<<endl;
        cout<<"		------"<<endl;
        cout<<"1. "<<menuThreeTwoOne<<endl; //3 2 1
        cout<<"2. "<<menuThreeTwoTwo<<endl; //3 2 2
        cout<<"Please enter a number: ";
        cin>>userChoice;
      }while(userChoice != 1 && userChoice != 2);
      
      //determines severity
      if(userChoice == 1)
      {
        patientTwoInjury = menuThreeTwoOne;
        patientTwoSeverity = menuThreeTwoOneS; //3 2 1 S
      }
      else if(userChoice == 2)
      {
        patientTwoInjury = menuThreeTwoTwo;
        patientTwoSeverity = menuThreeTwoTwoS; //3 2 2 S
      }
    }
  }
  //menu choice 4
  else if(userChoice == 4)
  {
    patientTwoMenu = menuOptionFour;
    patientTwoSeverity = -1;
  }
  
  //-----------------compares patient based on severity or name
  //if patientOnes severity is higher then patienttwos then display patientOne
  
  cout<<endl;
  cout<<endl;
 
  if(patientOneSeverity > patientTwoSeverity)
  {
    cout<<"Patient:	"<<patientOne<<endl;
    cout<<"Region:	"<<patientOneMenu<<endl;
    cout<<"Subregion:	"<<patientOneSubregion<<endl;
    cout<<"Injury:	"<<patientOneInjury<<endl;
    cout<<"Severity:	"<<patientOneSeverity<<endl;
  
  }
  //if patientTwos severity is higher than patientOnes then display patientTwo
  if(patientOneSeverity < patientTwoSeverity)
  {
    cout<<"Patient:	"<<patientTwo<<endl;
    cout<<"Region:	"<<patientTwoMenu<<endl;
    cout<<"Subregion:	"<<patientTwoSubregion<<endl;
    cout<<"Injury:	"<<patientTwoInjury<<endl;
    cout<<"Severity:	"<<patientTwoSeverity<<endl;
  }
  //if patientTwos and PatientOnes severity are the same then compare name size
  if(patientOneSeverity == patientTwoSeverity)
  {
    if(patientOne > patientTwo)
    {
      cout<<"Patient:	"<<patientOne<<endl;
      cout<<"Region:	"<<patientOneMenu<<endl;
      cout<<"Subregion: "<<patientOneSubregion<<endl;
      cout<<"Injury:	"<<patientOneInjury<<endl;
      cout<<"Severity: "<<patientOneSeverity<<endl;
    }
    else if(patientOne < patientTwo)
    {
      cout<<"Patient:	"<<patientTwo<<endl;
      cout<<"Region:	"<<patientTwoMenu<<endl;
      cout<<"Subregion: "<<patientTwoSubregion<<endl;
      cout<<"Injury:	"<<patientTwoInjury<<endl;
      cout<<"Severity:	"<<patientTwoSeverity<<endl;
    }
    //if patientOnes and PatientTwos name have same amount of characters then
    //display patientOne
    else
    {
      cout<<"Patient:	"<<patientOne<<endl;
      cout<<"Region:	"<<patientOneMenu<<endl;
      cout<<"Subregion: "<<patientOneSubregion<<endl;
      cout<<"Injury:	"<<patientOneInjury<<endl;
      cout<<"Severity:	"<<patientOneSeverity<<endl;
    }  
  }
  return 0;
}
