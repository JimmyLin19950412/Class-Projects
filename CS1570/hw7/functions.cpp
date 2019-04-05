//Name: Jimmy Lin
//Date: 10/27/2014
//Section: E
//File: functions.cpp
//Description: contains the functions for hw7

#include <iostream>
#include <cstdlib>
#include <math.h>
#include "hw7.h"

using namespace std;

//greeting message for the user
void greeting()
{
  cout<<"============= Welcome to Dr. Eloe's research study on Zombie-ism!"<<
  "============="<<endl;
}

//asks user to enter a number between 1-5000 and this will determine how many
//people will be tested
void userNumber(int &peopleTest) 
{
  //variables
  int number; //a number entered by the user
  
  //loops until user enters a number between MINPEOPLE and MAXPEOPLE
  do {
    //asks user to enter a number between MINPEOPLE and MAXPEOPLE
    cout<<"Enter the number of people in the test ("<<MINPEOPLE<<"-"<<MAXPEOPLE
    <<"): ";
    cin>>number;
    //if the number is not between MAXPEOPLE and MINPEOPLE then error message
    //is displayed
    if (number > MAXPEOPLE || number < MINPEOPLE) {
      //error message
      cout<<"Error! Please enter a valid number"<<endl;	
    }
  }while(number > MAXPEOPLE || number < MINPEOPLE);
  
  //assigns number to peopleTest
  peopleTest = number;
}

//assigns DNA to each person
void assignDNA(person people[], const int maxSize)
{
  //variables
  int number; //holds the numbner that determines dna
              //G = 0-29 
              //T = 30-53
              //A = 54-81
              //C = 82-102
  //loops through each person in array
  for (int i = 0; i <= maxSize - 1; i++) {
    //loops through each dna
    for (int j = 0; j <= dnaSize - 1; j++) {
      //generates a random number between 0-102
      number = rand() % 103;
      
      //G = 0-29
      if (number >= 0 && number <= 29) {
        people[i].m_dna[j] = 'G';
      }
      //T = 30-53
      else if (number >= 30 && number <= 53) {
        people[i].m_dna[j] = 'T';
      }
      //A = 54-81
      else if (number >= 54 && number <= 81) {
        people[i].m_dna[j] = 'A';
      }
      //C = 82-102    
      else if (number >= 82 && number <= 102) {
        people[i].m_dna[j] = 'C';
      }
    }    
  }
}

//determines if people want to eat brains or not and pass back how many
//people that want brains
void desireToEatBrains(person people[], const int maxSize, int &numBrains)
{
  //variables
  int number; //holds a number between 1 and 2, 1 = true, 2 = false
  
  //loops through everyone in structure and determines if that person
  //has a desire to eat brains or not
  for (int i = 0; i <= maxSize - 1; i++) {
    //generates a 1 or 2
    number = rand() % 2 + 1;    
    
    //1 = true, desire for brains
    if (number == 1) {
      people[i].m_desireBrain = true;
      //increases the amount of people who want brains by 1
      numBrains += 1;
    }
    //2 = false, no desire for brains
    else if (number == 2) {
      people[i].m_desireBrain = false;
    } 
  } 
}

//determines the smell of the person
void smell(person people[], const int maxSize, int &numSmell)
{
  //variables
  int number; //holds the number between 1-4
          //1 = pleasant, 2 = neutral, 3 = slight putrification, 4 = rotton
  
  //loops through everyone in structure and determins the smell of person
  for (int i = 0; i <= maxSize - 1; i++) {
    //generates random number between 1-4	
    number = rand() % 4 + 1;
    
    //if 1 = pleasant
    if (number == 1) {
      people[i].m_bo = 1;
    }
    //if 2 = neutral
    else if (number == 2) {
      people[i].m_bo = 2;
    }
    //if 3 = slight putrification
    else if (number == 3) {
      people[i].m_bo = 3;
      //increases the number of people who smell slightly ripe or rotton by 1
      numSmell += 1;
    }
    //if 4 = rottom
    else if (number == 4) {
      people[i].m_bo = 4;
      //increases the number of people who smell slightly ripe or rotton by 1
      numSmell += 1;	
    }
  }
}

//determines if person is walking normally or not
//1 = normal, 2 = shuffle, 3 = crawling
void walk(person people[], const int maxSize, int &numWalk)
{
  //variables  
  int number; //holds the number determining if the person is walking normally
              //or not, 1 = normal, 2 = shuffle, 3 = crawling
  
  //loops through everyone that is being tested and determins if person
  //is walking normally or not
  for (int i = 0; i <= maxSize - 1; i++) {
    //generates a random number between 1-3
    number = rand() % 3 + 1;
    
    //1 = normal
    if (number == 1) {
      people[i].m_gait = 1;
    }
    //2 = shuffle
    else if (number == 2) {
      people[i].m_gait = 2;
      //increases the amount of people who do not walk normally by 1
      numWalk += 1;
    }
    //3 = crawling
    else if (number == 3) {
      people[i].m_gait = 3;
      //increases the amount of people who do not walk normally by 1
      numWalk += 1;
    }
  }
}

//calculates the percentage of people who want to eat brains
//based off of their desire to eat brains
float calculateEatBrains(int numBrains, int peopleTest)
{
  //variables
  float number;
  
  //rounds to 2 decimal places
  number = (static_cast<float>(numBrains) / peopleTest) * 100;
  
  //returns round_up
  return number;
}

//calculates the percentage of people who smell slightly ripe or rotton
float calculateSmell(int numSmell, int peopleTest)
{
  //variables
  float number;
  
  //rounds to 2 decimal places
  number = (static_cast<float>(numSmell) / peopleTest) * 100;
  
  //returns round_up
  return number;               
}

//calculates the percentage of people who do not walk normally
float calculateWalk(int numWalk, int peopleTest)
{
  //variables
  float number; 
                  
  //rounds to 2 decimal places
  number = (static_cast<float>(numWalk) / peopleTest) * 100;
  
  //returns round_up
  return number;
}

//calculates the percentage of people who are zombies
//based off of their walk, smell, and eat
float calculateSmellWalkEat(person people[], int peopleTest)
{
  //variables
  int num = 0; //holds the value of people who are considered zombies
  
  //loops through everyone who is being tested
  for(int i = 0; i <= peopleTest - 1; i++) {
    //if person has a desire for brains
    if(people[i].m_desireBrain == true) {
      //if person has a slightly ripe or rotton smell
      if(people[i].m_bo == 3 || people[i].m_bo == 4) {
        //if person is crawling or shuffling
        if(people[i].m_gait == 2 || people[i].m_gait == 3) {
          //increases number of people who meet all those requirements by 1
          num += 1;
        }
      }
    }
  }
  
  //calculates the percentage of people who are considered zombies
  //based off of their walk, smell, and eat
  return (static_cast<float>(num) / peopleTest) * 100;
}

//calculates the percentage of people who are considered zombies
//based off of their dna test
float calculateDNA(person people[], int peopleTest)
{
  //variable
  int num = 0; //number of people considered a zombie
               //based off of their dna
               
  //loops through everyone being tested
  for(int i = 0; i <= peopleTest - 1; i++) {
    //loops through all dna sequance
    for(int j = 0; j <= dnaSize - 5; j++) {
      //tests to see if dna is G
      if(people[i].m_dna[j] == 'G') {
        //then tests if next dna is T
        if(people[i].m_dna[j+1] == 'T') {
          //then tests if next dna is A
          if(people[i].m_dna[j+2] == 'A') {
            //then tests if next dna is C
            if(people[i].m_dna[j+3] == 'C') {
              //if dna is GTAC then number of people considered
              //a zombie +1
              num += 1;
              //exits loop
              j = 124;
            }
          }
        }
      }
    }
  }
  
  //calculates the percentage of people who are considered a zombie
  //based off of their dna
  return (static_cast<float>(num) / peopleTest) * 100;
}

//calculates the percentage of people who are considered zombies
//based off of their dna test, smell, walk, and eat
float calculateDNASmellWalkEat(person people[], int peopleTest)
{
  //variables
  int num = 0; //holds the number of people who are considered zombies
  
  //loops through everyone being tested
  for(int i = 0; i <= peopleTest - 1; i++) {
    //loops through all dna sequences
    for(int j = 0; j <= dnaSize - 5; j++) {
      //tests to see if dna is g
      if(people[i].m_dna[j] == 'G') {
        //tests to see if dna is T
        if(people[i].m_dna[j+1] == 'T') {
          //tests to see if dna is A
          if(people[i].m_dna[j+2] == 'A') {
            //tests to see if dna is C
            if(people[i].m_dna[j+3] == 'C') {
              //if a person has a desire for brains
              if(people[i].m_desireBrain == true) {
                //if person has a slightly ripe or rotton smell
                if(people[i].m_bo == 3 || people[i].m_bo == 4) {
                  //if person is crawling or shuffling
                  if(people[i].m_gait == 2 || people[i].m_gait == 3) {
                    //person meets all the requirements to be considered
                    //a zombie
                    num += 1;
                  }
                }
              }  
            }
          }
        }
      }  
    }
  }

  //calculates the percentage of people who are considered zombies
  //based off of their DNA, smell, walk, and eat
  //returns the calculated value back
  return (static_cast<float>(num) / peopleTest) * 100;
}

//signoff message for the user
void signoff()
{
  cout<<"We hope you found this research study interesting."<<endl;
}
