//Name:	Jimmy Lin
//Date:	10/21/2014
//Section: C
//File:	arrayFuncs.cpp
//Description: functions for array.cpp

#include <iostream>
#include "array.h"

using namespace std;

//GET ALL information for each student as input from user
void read_in(student students[], const int size)
{
  //asks for student name and enters it into array
  for(int i = 0; i <= size - 1; i++) {
    cout<<"Student Name: ";
    cin>>students[i].m_name;
   
    //asks for students grade and enters it into array
    for(int j = 0; j <= size -1; j++) {
      cout<<"Enter the grade for course #"<<j+1<<" ? ";
      cin>>students[i].m_grade[j];
    }  
    cout<<endl;
  } 
}

//calculate the index of student who got the maximum grade in each course
int max_index(student students[], const int size, const int course_number)
{
  //variables
  //assumes the first student in course has the highest grade
  int studentNumber = 0;
  
  //loops through each student
  for(int i = 0; i <= size - 1; i++) {
    //compares grade in the course
    if(students[i].m_grade[course_number] > 
    students[studentNumber].m_grade[course_number]) {
      studentNumber = i;
    } 
  }
  
  //returns the highest grade
  return studentNumber;
}

//calculate the index of student who got the minimum grade in each course
int min_index(student students[], const int size, const int course_number)
{
  //variables
  //assumes the first student in course has the lowest grade
  int studentNumber = 0;
  
  //loops through each student
  for(int i = 0; i <= size - 1; i++) {
    //compares grade in the course
    if(students[i].m_grade[course_number] <
    students[studentNumber].m_grade[course_number]) {
      studentNumber = i;
    }
  }
  
  return studentNumber;
}
