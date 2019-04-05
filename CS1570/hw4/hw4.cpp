//Name: Jimmy Lin
//Date: 9/24/2014
//Sectoin: e
//File: hw4.cpp
/*Description: Lets user select what pills they want, user pays,
user pays and gets an appropriate bottle to store pills that are
dispensed */

#include<iostream>

using namespace std;

int main()
{
  //code i was told to add for the program
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  //variables
  //menu option one
  const string MENU_ONE = "Naprosyn"; //menu 1 
  const int MENU_ONE_AMT = 15; //amount of pills dispensed for menu 1
  const float MENU_ONE_COST = 10.00; //cost of menu one
  const string MENU_ONE_DESCRIPTION = "(pain relief)";
  //menu option two
  const string MENU_TWO = "Krystexxa"; //menu 2
  const int MENU_TWO_AMT = 30; //amount of pills dispensed for menu 2
  const float MENU_TWO_COST = 3.50; //cost of menu two
  const string MENU_TWO_DESCRIPTION = "(relief from gout - I think)";
  //menu opttion three
  const string MENU_THREE = "Schraut!"; //menu 3
  const int MENU_THREE_AMT = 20; //amount of pills dispensed for menu 3
  const float MENU_THREE_COST = 4.00; //cost of menu three
  const string MENU_THREE_DESCRIPTION = "(for relief from diarrhea)";
  //menu option 4
  const string MENU_FOUR = "Xeljanz"; //menu 4 option
  const int MENU_FOUR_AMT = 5; //amount of pills dispensed for menu 4
  const float MENU_FOUR_COST = 6.75; //cost of menu four
  const string MENU_FOUR_DESCRIPTION = 
  "(relif from Hippopotomonstrosesquipedaliophobia)";
  //menu option 5
  const string MENU_FIVE = "Qnsl Dipropionate"; //menu 5 opetions
  const int MENU_FIVE_AMT = 40; //amount of pills dispensed for menu 5
  const float MENU_FIVE_COST = 12.25; //cost of menu five
  const string MENU_FIVE_DESCRIPTION = "(for treatment of nasally fitted Q-tips)";
  //menu option 6
  const string MENU_SIX = "GoLytely"; //menu 6 option
  const int MENU_SIX_AMT = 1; //amount of pills dispensed for menu 6
  const float MENU_SIX_COST = 14.33; //cost of menu six
  const string MENU_SIX_DESCRIPTION = "(to treat gluttony)"; 
  
  int option; //user entered options
  float payment; //user entered payment
  float change; //change the user gets
  int totalPills; //total pills being dispensed
  
  //greets the user
  cout<<"Welcome to Dr. Eloe's INSTY-MEDS"<<endl;
  
  //shows menu and lets user pick from menu
  do {
    cout<<"\t INSTY-MEDS"<<endl;
    cout<<"\t ----------"<<endl;
    cout<<"1. "<<MENU_ONE<<" \t\t$"<<MENU_ONE_COST<<" \t"<<MENU_ONE_DESCRIPTION<<endl;
    cout<<"2. "<<MENU_TWO<<" \t\t$"<<MENU_TWO_COST<<" \t"<<MENU_TWO_DESCRIPTION<<endl;
    cout<<"3. "<<MENU_THREE<<" \t\t$"<<MENU_THREE_COST<<" \t"<<MENU_THREE_DESCRIPTION<<endl;
    cout<<"4. "<<MENU_FOUR<<" \t\t$"<<MENU_FOUR_COST<<" \t"<<MENU_FOUR_DESCRIPTION<<endl;
    cout<<"5. "<<MENU_FIVE<<" \t$"<<MENU_FIVE_COST<<" \t"<<MENU_FIVE_DESCRIPTION<<endl;
    cout<<"6. "<<MENU_SIX<<" \t\t$"<<MENU_SIX_COST<<" \t"<<MENU_SIX_DESCRIPTION<<endl;
    cout<<"7. Quit"<<endl;
    cout<<"Option: ";
    cin>>option;
    
    //determines what the user choice
    switch(option) {
      case 1: //menu option 1
        cout<<"You chose "<<MENU_ONE<<endl;
        //loop till user enters suffcient amount of money
        do {
          //user enters payment
          cout<<"Cost: $"<<MENU_ONE_COST<<endl;
          cout<<"Pay: ";
          cin>>payment;
          //if user entered less then what was asked for
          if(payment < MENU_ONE_COST) {
            cout<<"Please enter at least the given cost"<<endl;
          }
        }while(payment < MENU_ONE_COST);
        //if user enters in to much money it calculates the change
        if(payment > MENU_ONE_COST) {
          change = payment - MENU_ONE_COST; //calculates user's change
          cout<<"You entered $"<<payment<<", your change is $"<<change<<endl;
        }
        //tells user how many pills will be dispensed
        totalPills = MENU_ONE_AMT;
        cout<<"Please prepare a pill container that can hold "<<totalPills<<endl; 
        break;
      case 2: //menu option 2
        cout<<"You chose "<<MENU_TWO<<endl;
        //loop till user enters suffcient amount of money or quits
        do {
          //user enters payment
          cout<<"Cost: $"<<MENU_TWO_COST<<endl;
          cout<<"Pay: ";
          cin>>payment;
          //if user entered less then what was asked for
          if(payment < MENU_TWO_COST) {
            cout<<"Please enter at least the given cost"<<endl;
          }
        }while(payment < MENU_TWO_COST);
        //if user enters in to much money it calculates the change
        if(payment > MENU_TWO_COST) {
          change = payment - MENU_TWO_COST; //calculates user's change
          cout<<"You entered $"<<payment<<", your change is $"<<change<<endl;
        }
        //tells user how many pills will be dispensed
        totalPills = MENU_TWO_AMT;
        cout<<"Please prepare a pill container that can hold "<<totalPills<<endl;                
        break;
      case 3: //menu option 3
	cout<<"You chose "<<MENU_THREE<<endl;
        //loop till user enters suffcient amount of money or quits
        do {
          //user enters payment
          cout<<"Cost: $"<<MENU_THREE_COST<<endl;
          cout<<"Pay: ";
          cin>>payment;
          //if user entered less then what was asked for
          if(payment < MENU_THREE_COST) {
            cout<<"Please enter at least the given cost"<<endl;
          }
        }while(payment < MENU_THREE_COST);
        //if user enters in to much money it calculates the change
        if(payment > MENU_THREE_COST) {
          change = payment - MENU_THREE_COST; //calculates user's change
          cout<<"You entered $"<<payment<<", your change is $"<<change<<endl;
        }
	//tells user how many pills will be dispensed
        totalPills = MENU_THREE_AMT;
        cout<<"Please prepare a pill container that can hold "<<totalPills<<endl;
        break;
      case 4: //menu option 4 NOTE: only gets menu option 5 and 6
	cout<<"You chose "<<MENU_FOUR<<endl;
        //loop till user enters suffcient amount of money or quits
        do {
          //user enters payment
          cout<<"Cost: $"<<MENU_SIX_COST<<endl; //-----BROKEN!
          cout<<"Pay: ";
          cin>>payment;
          //if user entered less then what was asked for
          if(payment < MENU_SIX_COST) { //-----BROKEN!
            cout<<"Please enter at least the given cost"<<endl;
          }
        }while(payment < MENU_SIX_COST); //-----BROKEN!
        //if user enters in to much money it calculates the change
        if(payment > MENU_SIX_COST) { //-----BROKEN!
          change = payment - MENU_SIX_COST; //calculates user's change BROKEN!
          cout<<"You entered $"<<payment<<", your change is $"<<change<<endl;
        }
	//tells user how many pills will be dispensed
        totalPills = MENU_FIVE_AMT + MENU_SIX_AMT;
        cout<<"Please prepare a pill container that can hold "<<totalPills<<endl;
        break;
      case 5: //menu option 5 NOTE: Also recieves menu option 6
	cout<<"You chose "<<MENU_FIVE<<endl;
        //loop till user enters suffcient amount of money or quits
        do {
          //user enters payment
          cout<<"Cost: $"<<MENU_SIX_COST<<endl; //-----BROKEN!
          cout<<"Pay: ";
          cin>>payment;
          //if user entered less then what was asked for
          if(payment < MENU_SIX_COST) { //-----BROKEN!
            cout<<"Please enter at least the given cost"<<endl;
          }
        }while(payment < MENU_SIX_COST); //-----BROKEN!
        //if user enters in to much money it calculates the change
        if(payment > MENU_SIX_COST) { //-----BROKEN!
          change = payment - MENU_SIX_COST; //calculates user's change BROKEN!
          cout<<"You entered $"<<payment<<", your change is $"<<change<<endl;
        }
        //tells user how many pills will be dispensed
        totalPills = MENU_FIVE_AMT + MENU_SIX_AMT;
        cout<<"Please prepare a pill container that can hold "<<totalPills<<endl;
        break;
      case 6: //menu option 6
	cout<<"You chose "<<MENU_SIX<<endl;
        //loop till user enters suffcient amount of money or quits
        do {
          //user enters payment
          cout<<"Cost: $"<<MENU_SIX_COST<<endl;
          cout<<"Pay: ";
          cin>>payment;
          //if user entered less then what was asked for
          if(payment < MENU_SIX_COST) {
            cout<<"Please enter at least the given cost"<<endl;
          }
        }while(payment < MENU_SIX_COST);
        //if user enters in to much money it calculates the change
        if(payment > MENU_SIX_COST) {
          change = payment - MENU_SIX_COST; //calculates user's change BROKEN!
          cout<<"You entered $"<<payment<<", your change is $"<<change<<endl;
        }
	//tells user how many pills will be dispensed
        totalPills = MENU_SIX_AMT;
        cout<<"Please prepare a pill container that can hold "<<totalPills<<endl;
        break;
      case 7: //menu option 7
        break;
      default: //invalud input
        cout<<"Invalid input."<<endl;
    }
  }while(option != 7);
  
  //signs the user off
  cout<<"Thank you for using Dr. Eloe's INSTY-MENDS"<<endl;
  cout<<"Have a good day!"<<endl;	  
  return 0;
}
