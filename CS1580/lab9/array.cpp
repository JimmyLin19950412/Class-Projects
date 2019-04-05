//Name:	Jimmy Lin
//Date:	10/21/2014
//Section: C
//File:	array.cpp
//Description: Calculates the lowest and higest mid term scores for 3 students

#include <iostream>
#include "array.h"

using namespace std;

int main()
{
  //variables
  const int STUDENT_ARRAY = 3; //array max size
  int studentNumber; //student's number in array
  
  //call structure
  student students[STUDENT_ARRAY]; //student structure array
  
  //GET ALL information for each student as input from user
  read_in(students, STUDENT_ARRAY);
  
  //calculates the highest score for course 1
  studentNumber = max_index(students, STUDENT_ARRAY, 0);
  cout<<students[studentNumber].m_name<<" gained the Maximum grade in course "<<
  "#1 which is "<<students[studentNumber].m_grade[0]<<endl;
  
  //calculate the lowest score for course 1
  studentNumber = min_index(students, STUDENT_ARRAY, 0);
  cout<<students[studentNumber].m_name<<" gained the Minimum grade in course "<<
  "#1 which is "<<students[studentNumber].m_grade[0]<<endl;
  
  //calculates the higehst score for course 2
  studentNumber = max_index(students, STUDENT_ARRAY, 1);
  cout<<students[studentNumber].m_name<<" gained the Maximum grade in course "<<
  "#2 which is "<<students[studentNumber].m_grade[1]<<endl;
  
  //calculate the lowest score for course 2
  studentNumber = min_index(students, STUDENT_ARRAY, 1);
  cout<<students[studentNumber].m_name<<" gained the Minimum grade in course "<<
  "#2 which is "<<students[studentNumber].m_grade[1]<<endl;
  
  //calculates the highest score for course 3
  studentNumber = max_index(students, STUDENT_ARRAY, 2);
  cout<<students[studentNumber].m_name<<" gained the Maximum grade in course "<<
  "#3 which is "<<students[studentNumber].m_grade[2]<<endl;
  
  //calculates the lowest score for course 3
  studentNumber = min_index(students, STUDENT_ARRAY, 2); 
  cout<<students[studentNumber].m_name<<" gained the Minimum grade in course "<<
  "#3 which is "<<students[studentNumber].m_grade[2]<<endl;
  
  return 0;
}
