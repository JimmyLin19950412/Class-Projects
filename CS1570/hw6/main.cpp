//Name: Jimmy Lim
//Date:	10/15/2014
//File:	main.cpp
//Section: E
//Description: Helps determine the presence of Jejunal Hemorrhage Syndrome

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;

int main()
{
  //accessing structures
  patientOne patient1; //accessing patient one's structure
  patientTwo patient2; //accessing patient two's structure
  patientThree patient3; //access patient three's structure
  
  //variables
  bool fail = false; //determines if loop continues or stops
  int failChance; //holds percent chance to fail
  bool patient1Fail = false; //if patient 1 failed test or not
  bool patient2Fail = false; //if patient 2 failed test or not
  bool patient3Fail = false; //if patient 3 failed test or not
  bool patient1Disease = false; //if patient 1 has disease or not
  bool patient2Disease = false; //if patient 2 has disease or not
  bool patient3Disease = false; //if patient 3 has disease or not
  
  //generates a random seed
  srand(time(NULL));
  
  //greeting message
  greeting();
  
  //asks for name of the patients
  readName(patient1, patient2, patient3);
  
  //patient1-------------------------------------
  //generates number to see if patient failed test
  failChance = randomNumber(0, 100, 1);
  //if fail is higher then 5 then test is successful
  if(failChance > 5 && fail == false) {
    //assigns toneA to patient1
    toneA(patient1);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient1.m_name<<" Insufficient data collected - proteins p1, p2, "<<
    "and p3 not represented"<<endl;
    //failed test
    patient1Fail = true;
  }
  
  //generates number to see if pateient failed test
  failChance = randomNumber(0, 100, 1);
  //if fail is higher then 5 then test is successful
  if(failChance > 5 && fail == false) {
    //assigns toneG to patient1
    toneG(patient1);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected  
    cout<<patient1.m_name<<" Insufficient data collected - proteins p2 and p4 "<<
    "not represented"<<endl;
    //failed test
    patient1Fail = true;        
  }
  
  //generates number to see if patient failed test
  failChance = randomNumber(0, 100, 1);  
  if(failChance > 5 && fail == false) {
    //assigns toneH to patient1
    toneH(patient1);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient1.m_name<<" Insufficient data collected - proteins p1, p4, and p5 "<<
    "not represented"<<endl;
    //failed test
    patient1Fail = true;	    
  }
  
  //resets fail
  fail = false;

  //patient2 ------------------------------------
  //generates number to see if patient failed test
  failChance = randomNumber(0, 100, 1);
  //if fail is higher then 5 then test is successful
  if(failChance > 5 && fail == false) {
    //assigns toneA to patient1
    toneA(patient2);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient2.m_name<<" Insufficient data collected - proteins p1, p2, "<<
    "and p3 not represented"<<endl;
    //failed test
    patient2Fail = true;    
  }
                                           
  //generates number to see if pateient failed test
  failChance = randomNumber(0, 100, 1);
  //if fail is higher then 5 then test is successful
  if(failChance > 5 && fail == false) {
    //assigns toneG to patient1
    toneG(patient2);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient2.m_name<<" Insufficient data collected - proteins p2 and p4 "<<
    "not represented"<<endl;
    //failed test
    patient2Fail = true;    
  }
                                                                                     
  //generates number to see if patient failed test
  failChance = randomNumber(0, 100, 1);
  if(failChance > 5 && fail == false) {
    //assigns toneH to patient1
    toneH(patient2);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient2.m_name<<" Insufficient data collected - proteins p1, p4, and p5 "<<
    "not represented"<<endl;
    //failed test
    patient2Fail = true;     
  }
                                                                                                                             
  //resets fail
  fail = false;
                                                                                                                                
  //patient3 ------------------------------------
   //generates number to see if patient failed test
  failChance = randomNumber(0, 100, 1);
  //if fail is higher then 5 then test is successful
  if(failChance > 5 && fail == false) {
    //assigns toneA to patient1
    toneA(patient3);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient3.m_name<<" Insufficient data collected - proteins p1, p2, "<<
    "and p3 not represented"<<endl;
    //failed test
    patient3Fail = true;
  }

  //generates number to see if pateient failed test
  failChance = randomNumber(0, 100, 1);
  //if fail is higher then 5 then test is successful
  if(failChance > 5 && fail == false) {
    //assigns toneG to patient1
    toneG(patient3);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient3.m_name<<" Insufficient data collected - proteins p2 and p4 "<<
    "not represented"<<endl;
    //failed test
    patient3Fail = true;    
  }

  //generates number to see if patient failed test
  failChance = randomNumber(0, 100, 1);
  if(failChance > 5 && fail == false) {
    //assigns toneH to patient1
    toneH(patient3);
  }
  else {
    //sets fail to true so that the rest of the test for the patient is skipped
    fail = true;
    //displays which proteins where not collected
    cout<<patient3.m_name<<" Insufficient data collected - proteins p1, p4, and p5 "<<
    "not represented"<<endl;
    //failed test
    patient3Fail = true;    
  }

  //RESULTS-====================================
  //if patient 1 did not fail test then will determine if they have the disease
  if(patient1Fail == false) {
    //determines if patient 1 has disease
    patient1Disease = diseaseDetermine(patient1);    
    
    //prints out the results of patient 3
    if (patient1Disease == true) {
      //has disease
      cout<<patient1.m_name<<" HAS Jejunal Hemorrhage Syndrome"<<endl;
    }
    else {
      //no disease
      cout<<patient1.m_name<<" does NOT have Jejunal Hemorrhage Syndrome"<<endl;
    }
                                             
    //prints protein levels
    cout<<"Protein 1 level "<<patient1.m_p1<<endl;
    cout<<"Protein 2 level "<<patient1.m_p2<<endl;
    cout<<"Protein 3 level "<<patient1.m_p3<<endl;
    cout<<"Protein 4 level "<<patient1.m_p4<<endl;
    cout<<"Protein 5 level "<<patient1.m_p5<<endl;
                                                                     
  }
  else {
    //prints out patient 1 failed the test
    cout<<patient1.m_name<<" failed the test"<<endl;
  }
            
  //if patient 2 did not fail test then will determine if they have the disease
  if(patient2Fail == false) {
    //determines if patient 2 has disease
    patient2Disease = diseaseDetermine(patient2);

    //prints out the results of patient 2
    if (patient2Disease == true) {
      //has disease
      cout<<patient2.m_name<<" HAS Jejunal Hemorrhage Syndrome"<<endl;
    }
    else {
      //no disease
      cout<<patient2.m_name<<" does NOT have Jejunal Hemorrhage Syndrome"<<endl;
    }

    //prints protein levels
    cout<<"Protein 1 level "<<patient2.m_p1<<endl;
    cout<<"Protein 2 level "<<patient2.m_p2<<endl;
    cout<<"Protein 3 level "<<patient2.m_p3<<endl;
    cout<<"Protein 4 level "<<patient2.m_p4<<endl;
    cout<<"Protein 5 level "<<patient2.m_p5<<endl;   
  }
  else {
    //prints out patient 2 failed the test
    cout<<patient2.m_name<<" failed the test"<<endl;
  }
  
  //if patient 3 did not fail test then will determine if they have the disease
  if(patient3Fail == false) {
    //determines if patienr 3 has disease
    patient3Disease = diseaseDetermine(patient3);
    
    //prints out the results of patient 3
    if (patient3Disease == true) {
      //has disease
      cout<<patient3.m_name<<" HAS Jejunal Hemorrhage Syndrome"<<endl;
    }
    else {
      //no disease
      cout<<patient3.m_name<<" does NOT have Jejunal Hemorrhage Syndrome"<<endl;
    }
    
    //prints protein levels
    cout<<"Protein 1 level "<<patient3.m_p1<<endl;
    cout<<"Protein 2 level "<<patient3.m_p2<<endl;
    cout<<"Protein 3 level "<<patient3.m_p3<<endl;
    cout<<"Protein 4 level "<<patient3.m_p4<<endl;
    cout<<"Protein 5 level "<<patient3.m_p5<<endl;
  }
  else {
    //prints out patient 3 failed the test
    cout<<patient3.m_name<<" failed the test"<<endl;
  }
       
      
  //signoff message
  signOff();
    
  return 0;
}
