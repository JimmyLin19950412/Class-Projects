//Name:	Jimmy Lin
//Date: 10/21/2014
//Section: C
//File: array.h
//Description: contains function prototypes and structures for array.cpp

#include <iostream>

using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

//structures ================================================
const int ARRAYSIZE = 3;

struct student
{
  string m_name;
  int m_grade[ARRAYSIZE];
};

//function prototypes =========================================
//Description: GET ALL information for each student as input from user
//Pre: needs an array and integer
//Post: none
//Return: none
void read_in(student students[], const int size);

/*Description: calculate the index of student who got the maximum 
grade in each course*/
//Pre: needs an array and 2 integers
//Post: none
//Return: highest grade
int max_index(student students[], const int size, const int course_number);

/*Description: calculate the index of student who got the minimum 
grade in each course*/
//Pre: needs an array and 2 integers
//Post: none
//Return: lowest grade
int min_index(student students[], const int size, const int course_number);

#endif
