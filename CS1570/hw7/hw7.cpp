//Name: Jimmy Lin
//Date: 10/27/2014
//Section: E
//File: hw7.cpp
//Description: helps diagnose the patient on zombie like symptoms

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hw7.h"

using namespace std;

int main()
{
  //structure
  person people[MAXPEOPLE];
  
  //variables
  int peopleTest; //holds the number of people that will be tested
  int numBrains = 0; //holds the amount of people that want to eat brains
  int numSmell = 0; //holds the number of people who smell slightly ripe or 
                    //rotton
  int numWalk = 0; //holds the amount of people who do not walk normally
  float percentBrains; //holds the percentage of people who are zombies based 
                       //off of their desires to eat brains
  float percentSmell; //holds the percentage of people who are zombies based
                      //off of their smell
  float percentWalk; //holds the percentage of people who are zombies based
                     //off of how they walk
  
  float percentSmellWalkEat; //holds the percentate of people who are zombies
                             //based off of how they smell, walk, and eat
  
  float percentDNA; //holds the percentage of people who are zombies
                     //off of their DNA sequance, which is GTAC
  
  float percentDNASmellWalkEat; //holds the percentage of people who are
                                //zombies based off of their dna sequence,
                                //smell, walk, and eat
                                                                                                   
  //initializes random seed
  srand(time(NULL));
  
  //greets the user
  greeting();
    
  //collects the number of people that will be tested from user
  userNumber(peopleTest);
 
  //assigns dna to subjects
  assignDNA(people, peopleTest);
   
  //determines how many people want to eat brains
  desireToEatBrains(people, peopleTest, numBrains);
  
  //determines who has a slightly ripe or rotting smell
  smell(people, peopleTest, numSmell);
  
  //determines who cannot walk normally
  walk(people, peopleTest, numWalk);
  
  //calculates the percentage of people that are zombies
  //based off of their desire to eat brains
  percentBrains = calculateEatBrains(numBrains, peopleTest);
  
  //calculates the percentage of people that are zombies
  //based off their smell
  percentSmell = calculateSmell(numSmell, peopleTest);
  
  //calculates the percentage of people that are zombies
  //based off of their walking
  percentWalk = calculateWalk(numWalk, peopleTest);
  
  //calculates the percentage of people that are zombies
  //based off of their smell, walk, and wat
  percentSmellWalkEat = calculateSmellWalkEat(people, peopleTest);
  
  //calculates the percentage of people that are zombies
  //based off of their dna sequance, which is GTAC
  percentDNA = calculateDNA(people, peopleTest);
  
  //calculates the percentage of people that are zombies
  //based off of their dna sequence, smell, walk, and eat
  percentDNASmellWalkEat = calculateDNASmellWalkEat(people, peopleTest);
  
  //displays results
  cout<<"Out of a total of "<<peopleTest<<" people tested: "<<endl;
  cout<<percentBrains<<"% want to eat brains."<<endl;
  cout<<percentSmell<<"% have a slightly ripe or rotting stench smell."<<endl;
  cout<<percentWalk<<"% do not walk normally"<<endl;
  cout<<percentSmellWalkEat<<"% qualify as zombies only by how they smell, "<<
  "how they walk, and what they want to eat."<<endl;  
  cout<<percentDNA<<"% qualify as zombies only by the DNA test."<<endl;
  cout<<percentDNASmellWalkEat<<"% qualify as zombies by both the DNA test "<<
  "and how they walk, how they smell, and what they want to eat."<<endl;
  
  //signs off the user
  signoff(); 
  
  return 0;
}
