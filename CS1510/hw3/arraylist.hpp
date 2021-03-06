//Name: Jimmy Lin
//Date: 3/4/2015
//File: arraylist.hpp
//Description: functions for arraylist.h

#include <iostream>
#include "arraylist.h"

using namespace std;

//destructor
template <typename T>
ArrayList<T>::~ArrayList()
{
  delete [] m_data;
  m_data = NULL;
}

//operator =
template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> & rhs)
{
  //prevents self copy
  if (this == &rhs) {
    return (*this);
  }  
  //if the size of the 2 array lists are not equal
  if (m_max != rhs.m_max || m_size != rhs.m_size) {
    //makes both the size equal
    m_max = rhs.m_max;
    m_size = rhs.m_size;
    delete m_data;
    m_data = new T[m_max];
  }
  //coppies elements from rhs to lhs
  for (int i = 0; i < m_size; i++) {
    m_data[i] = rhs.m_data[i];
  }
  
  return (*this); 
}

//copy constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> & cpy)
{
  //copies max size
  m_max = cpy.m_max;
  //copies the number of elements in array
  m_size = cpy.m_size;
  //creates array list with new size
  m_data = new T[m_max];
  //copies the elements from rhs to the lhs
  for (int i = 0; i < m_size; i++) {
    m_data[i] = cpy.m_data[i];
  }
}

//accessor function for the number of elements in the list
template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

//accessor function for the first element of the list
template <typename T>
const T & ArrayList<T>::first() const
{
  if(m_size == 0) {
    cout<<"!-- ERROR : PANIC in ARRAYLIST.first()!!  (list is empty)"
    <<endl;
  }
  return m_data[0];
}

//return a read-and-write reference to the element at the specified position
template <typename T>
T & ArrayList<T>::operator[](int i)
{
  if(i > m_size || i < 0) {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)"
    <<endl;
  }
  return m_data[i];
}

//finds an element in the ArrayList
template <typename T>
int ArrayList<T>::find(const T  & x)
{
  //return -1 if value isnt found
  int retVal = -1;
  
  //loops through array to find the value
  for (int i = 0; i < m_size; i++) {
    //if value is found
    if (m_data[i] == x) {
      //returns the position of where x was first found
      return i;
    }  
  }
  
  //x was not found
  return retVal;
}

//clears the arraylist
template <typename T>
void ArrayList<T>::clear()
{
  delete [] m_data;
  m_data = NULL;
  m_max = 0;
  m_size = 0;
}

//puts the value x at the end of an arraaylist
template <typename T>
void ArrayList<T>::insert_back(const T & x)
{
  //if m_max is zero, add 1 so it 
  //CAN AT LEAST STORE SOMETHING, STUPID DEFAULT CONSTRUCTOR
  if(m_max == 0) {
    m_max = 1;
  }
  //if array is full
  if((m_size+1) >= m_max) {
    //doubles max size
    m_max *= 2;
    //new array with enlarged max size
    T * newData = new T[m_max];
    //copies data to newData
    for(int i = 0; i < m_size; i++) {
      newData[i] = m_data[i];
    }
    delete [] m_data;
    //makes m_data point to newData's pointer
    m_data = newData; 
  }
  //data position temp is = to x
  m_data[m_size] = x;
  //m_size + 1
  m_size++;
}

//puts the value x at the position i in the arraylist
template <typename T>
void ArrayList<T>::insert(const T & x, int i)
{
  //if trying to add to an unexisting cell, error
  if(i < 0 || i > m_size) {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)"
    <<endl;
  }
  //if max size is reached, enlarge array
  if(m_size == m_max) {
    //doubles max size
    m_max *= 2;
    //new array with enlarged max size
    T * newData = new T[m_max];
    //copies data to newData
    for(int j = 0; j < m_size; j++) {
      newData[j] = m_data[j];
    }
    delete [] m_data;
    //makes m_data point to newData's pointer
    m_data = newData;
  }
  //loops through whole array until posiiton i is reached
  //loops backwards
  for(int j = m_size; j > i; j--) {
    //moves every elementm up to i, back by 1
    m_data[j] = m_data[j-1];
  }
  m_data[i] = x;
  m_size++;
}

//removes element at index i in the array
template <typename T>
void ArrayList<T>::remove(int i)
{
  //if trying to remove an unexisting cell, error
  if(i < 0 || i > m_size) {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)"
    <<endl;
  }
  //removing the last element
  if(i == m_size) {
    m_size--;;
  }
  else {
    //loops through whole array until position i is reached
    for(int j = i; j < m_size; j++) {
      m_data[j] = m_data[j+1];  
    }
    m_size--;
  }
  //if size of the list is less than 1/4 of the max size, decrease max size by half
  if(m_size < (m_max / 4)) {
    //reduce max size by half
    m_max = m_max / 2;
    //new array with smaller max size
    T * newData = new T[m_max];
    //copies dataa to newData
    for(int j = 0; j < m_size; j++) {
      newData[j] = m_data[j];
    }
    delete [] m_data;
    //makes m_data point to newData's pointer
    m_data = newData;
  } 
}

//*-------------------------small tester done

//swaps two elements of the array
template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if(i > m_size || i < 0 || k > m_size || k < 0) {
    cout<<"!! ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)"
    <<endl;
  }
  
  T temp1 = m_data[i];
  T temp2 = m_data[k];
  
  //swaps the elements
  m_data[i] = temp2;
  m_data[k] = temp1;  
}

//appends two lists
template <typename T>
void ArrayList<T>::append(const ArrayList<T> & alist)
{
  //if the 2 appended lists are greater than 'this' m_max then
  //remake 'this' with greater max size
  if((m_size + alist.m_size) >= m_max) {
    m_max = m_size + alist.m_size;
    T * newData = new T[m_max];
    //copies the values
    for(int i = 0; i < m_size; i++) {
      newData[i] = m_data[i];  
    }
    delete [] m_data;
    m_data = newData;
  }
  //appends alist to end of 'this' array 
  for(int i = m_size; i < m_max; i++) {
    m_data[i] = alist.m_data[i-m_size];
  }
  m_size = m_max;
}

//removes duplicates from an arraylist
template <typename T>
void ArrayList<T>::purge()
{
  for(int i = 0; i < m_size; i++) {
    for(int j = i+1; j < m_size; j++) {
      //if duplicate is found
      if(m_data[i] == m_data[j]) {
        remove(j);
      }
    }
  }
}
