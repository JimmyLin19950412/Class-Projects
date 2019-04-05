//Name: Jimmy Lin
//Date: 10/27/2014
//Section: E
//File: hw7.h
//Description: contains hw7 function prototypes

#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef HW7_H
#define HW7_H

//constants
const int dnaSize = 128; //variable size for dna array 
const int MAXPEOPLE = 5000; //maximum amount if people
const int MINPEOPLE = 1; //minimum amount of people

//structure for people that will be generated in the study
struct person {
  char m_dna[dnaSize]; //array of characters that holds person's dna
  int m_bo; //contains the smell of the person
            //1 = pleasant, 2 = neutral, 3 = slight putrification, 4 = rotton
  bool m_desireBrain; //true if person desires brain, if not false
  int m_gait; //1 = normal, 2 = shuffle, 3 = crawling
};

//Description: displays a greeting message to the user
//Pre: none
//Post: couts a string containing a greeting message to the user
//Return: none
void greeting();

//Description: assigns a string of dna to each person
//Pre: requires a structure array and assigns randomly
//generated dna in a string of 128 characters. 
//Will only generate a G, T, A, C
//Post: populates the m_dna array in structure array with 
// a G. T. C. or an A. These 4 characters will make up a
//128 character array
//Return:
void assignDNA(person people[], const int maxSize);

//Description: asks user for number of people to test
//Pre: none
/*Post: user entered number (1-5000) will be stored in a pass by reference
variable called peopleTest that will determine how many people will be tested
*/
//Return: none
void userNumber(int &peopleTest);

//Description: determines how many people want to eat brains
//Pre: requires a pass by reference structure array named people[]
//and a number (maxSize) that will represent how many people will be tested
//for wanting to eat brains or not. Also requires an integer to be used
//for pass by reference that will determine how many people want brains
//Post: m_desireBrain in the structure will be populated by a random number
//1 = true, want brains. 2 = false, does not want brains
//the number of people who want brains will be held and passed to numBrains
//Return: none
void desireToEatBrains(person people[], const int maxSize, int &numBrains);

//Description: determines the smell of the person
//Pre: requires a pass by reference structure array
//requires an integer that will hold the maximum amount of people to be tested
//requires a pass by reference integer to hold how many people 
//smell slightly ripe or rotton
//Post: m_bo in the structure will be populated by a number between 1 and 4
//1 = pleasant, 2 = neutralm 3 = slight putrification, 4 = rotton
//pass by reference integer numSmell will be increased to hold the amount
//of people that smell either rottom or slight putrification
//Return: none
void smell(person people[], const int maxSize, int &numSmell);

//Description: determines if person is walking normally or not
//Pre: requires a pass by reference structure array
//requires an integer that holds the maximum amount of people to be tested
//requires a pass by reference integer that holds how many people do not walk 
//normally
//Post: numWalk, a pass by reference integer will increase by 1 when 
//someone is tested to not walk normally.
//person array that is being passed will have its m_gait changed 
//accordingly on how the person walkts
//Return: none
void walk(person people[], const int maxSize, int &numWalk);

//Description: calculates the percentage of people who want are
//considered zombies based off of their desires to eat brains
//Pre: requires the number of people who want brains and the number
//of people in the test
//Post: changes a variable's value to the number that is calculated
//Return: returns the percentage (a float) of the amount of people who are 
//zombies based off of their desires to eat brains
float calculateEatBrains(int numBrains, int peopleTest);

//Description: calculates the number of people who are considered
//zombies based off of their smell
//Pre: requires an integer that of people who smell slightly ripe
//or rotton and the amount of people in the test
//Post: changes a variable assigned to the function to a percentage
//(float) of the amount of people who are considered zombies
//based off of their smell
//Return: returns a percentage (float) of the amount of poeple who are
//considered zombies based off of their smell
float calculateSmell(int numSmell, int peopleTest);

//Description: calculates the percentage of people who are considered
//zombies based off of how they walk
//Pre: requires an integer with the amount of people who do not
//walk normally and an integer with the amount of people in the test
//Post: changes the value of a variable to the calculated percentage
//Return: returns a value based off of the calculated percentage
float calculateWalk(int numWalk, int peopleTest);

//Description: calculates the percentage of people who are considered
//zombies based off of how they smell, walk and eat
//Pre: requires a structure with their m_bo, m_gait, and m_desireBrain
//populated
//Post: changes the value of an integer this function is assinged to
//to the value that is calculated
//Return: returns the value that is calculated
float calculateSmellWalkEat(person people[], int peopleTest);

//Description: calculates the percentage of people who are considered
//zombies based off of how they smell, walk. and eat
//Pre: requires a structure that has a populated m_dna
//Post: changes the value of an integer this function is assigned to
//to the value that is calculated 
//Return: returns the value that is calculated
float calculateDNA(person people[], int peopleTest);

//Description: calculates the percentage of people who are considered
//zombies based off their dna test, smell, walk, and eat
//Pre: requires a fully populated structure of how many people
//that are being tested, and an integer indicating how manu people
//that are being tested
//Post: populates a float value that holds the percentage of people
//who are considereed zombies
//Return: returns a float
float calculateDNASmellWalkEat(person people[], int peopleTest);

//Description: displays a signoff message to the user
//Pre: none
//Post: couts a string containing a signoff message to the user
//Return: none
void signoff();

#endif
