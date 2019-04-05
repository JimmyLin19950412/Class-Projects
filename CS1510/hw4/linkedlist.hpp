//Name:	Jimmy Lin
//Date:	3/17/2015
//Section: C
//File: linkedlist.hpp
//Description: functions of linkedlist.h

#include <iostream>
#include "linkedlist.h"

using namespace std;

//performs a deep copy of the data from rhs into this linked list
template <class T>
const LinkedList<T> &  LinkedList<T>::operator=(const LinkedList<T> & rhs) ////////////////////////////////
{
  clear();
  
  Node<T> * rhs_temp = rhs.head;
  Node<T> * temp;
  int size = rhs.size();
  
  head = new Node<T>(rhs_temp->m_data, NULL);
  
  temp = head;
  
  rhs_temp = rhs_temp->m_next;
  
  for(int i = 1; i < size; i++) {
    temp->m_next = new Node<T>(rhs_temp->m_data, NULL);
    temp = temp->m_next;
    rhs_temp = rhs_temp->m_next;
  }
  
  return (*this);
}    
  
//copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & rhs) 
{  
  Node<T> * rhs_temp = rhs.head;
  Node<T> * temp;
  int size = rhs.size();
  
  head = new Node<T>(rhs_temp->m_data, NULL);
  
  temp = head;
  
  rhs_temp = rhs_temp->m_next;
  
  for(int i = 1; i < size; i++) {
    temp->m_next = new Node<T>(rhs_temp->m_data, NULL);
    temp = temp->m_next;
    rhs_temp = rhs_temp->m_next;
  }  
}

//------------Basic Accessor Operations

//accessor funciton for the current # data values in the list
template <class T>
int LinkedList<T>::size() const 
{
  //list is empty
  if (head == NULL) {
    return 0;
  }
  
  //holds the size
  int size = 1;
  Node<T> * temp = head;
  
  //loops through the entire array
  while(temp->m_next != NULL) {
    size++;
    temp = temp->m_next;
  }
  return size;
}

//determines whether the list is empty
template <class T>
bool LinkedList<T>::isEmpty() const
{
  //is empty
  if(head == NULL) {
    return true;
  }
  
  //not empty
  return false;
}

//get a pointer to the first element node
template <class T>
Node<T>* LinkedList<T>::getFirstPtr()
{
  //list is empty
  if (head == NULL) {
    cout<<"!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list"<<endl;
    return NULL;
  }
  
  return head;
}

//accessor function for last element node
template <class T>
Node<T>* LinkedList<T>::getLastPtr()
{
  if (head == NULL) {
    cout<<"!! -- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list"<<endl;
    return NULL;
  }
  
  Node<T> * temp = head;
  
  //loops till last node
  while(temp->m_next != NULL) {
    temp = temp->m_next;
  }
  
  return temp;
  
}

//accessor function for a node in the list
template <class T>
Node<T>* LinkedList<T>::getAtPtr(int i)
{
  if(i <= 0 || i > size()) {
    cout<<"!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index"<<endl;
    return NULL;
  }
  
  Node<T> * temp = head;
  
  //loops till i position
  for(int j = 0; j < i; j++) {
    temp = temp->m_next;  
  }
  
  return temp;
}

//-------Basic Mutator Operations

//effectively empties the list
template <class T>
void LinkedList<T>::clear()
{ 
  //if element is empty
  if(head == NULL) {
    return;
  }
   
  while(head != NULL) {
    Node<T> * temp = head;
    head = head->m_next;
    delete temp;
    temp = NULL;
  }
  
  head = NULL;
}

//puts the data x in the front of the list
template <class T>
void LinkedList<T>::insert_front(const T & x)
{
  //if lsit is empty
  if(head == NULL) {
    Node<T> * newNode = new Node<T>(x, NULL);
    head = newNode;
  }
  else {
    Node<T> * newNode = new Node<T>(x, head);
    head = newNode; 
  }
}

//outs the data value at the position pointed by pos
template <class T>
void LinkedList<T>::insert(const T & x, Node<T> * pos) 
{
  Node<T> * temp = head;
  
  while(temp->m_next != pos) {
    temp = temp->m_next;
  }
  
  Node<T> * newNode = new Node<T>(x, pos);
  
  temp->m_next = newNode;      
}

//removed the elemtn in the position pointed by pos
template <class T>
void LinkedList<T>::remove(Node<T> * pos)
{
  //if list is empty
  if (head == NULL) {
    return;
  }
  
  Node<T> * temp = head;
  
  //while temp does not = pos
  while (temp->m_next != pos) {
    temp = temp->m_next;
  }
  
  temp->m_next = pos->m_next;
  delete pos;
  pos = NULL;
  
}

//------complex operations

//determines whether this list is identical to rhs list in terms of data
//values and their order of the list
template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> & rhs) const
{	
  //not same size
  if(size() != rhs.size()) {
    return false;
  }
  
  Node<T> * temp = head;
  Node<T> * rhs_temp = rhs.head;
  
  while(temp->m_next != NULL) {
    if(temp->m_data == rhs_temp->m_data) {
      temp = temp->m_next;
      rhs_temp = rhs_temp->m_next; 
    }
    else {
      return false;
    }
  }
  
  return true;
}

//determines whether x is in the list
template <class T>
Node<T>* LinkedList<T>::find(const T & x)
{
  Node<T> * temp = head;
  while(temp->m_next != NULL) {
    if(temp->m_data == x) {
      return temp;
    }
    temp = temp->m_next;
  }
  
  return NULL;
}

//reverses the elements from the list
template <class T>
void LinkedList<T>::reverse()
{
  Node<T> * temp = head;
  Node<T> * temp2;
  Node<T> * temp3;
  int sizes = size() - 1;
  
  while(temp->m_next != NULL) {;
    temp = temp->m_next;
  }
  
  temp3 = temp;
  
  while(sizes >= 0) {
    temp2 = head;
    for(int i = 1; i < sizes; i++) {
      temp2 = temp2->m_next; 
    }
    sizes--;
    temp->m_next = temp2;
    temp = temp->m_next;
    temp2->m_next = NULL;
  }
  
  head = temp3;
  
}

//appends two lists
template <class T>
void LinkedList<T>::append(const LinkedList<T> & xlist)
{
  Node<T> * temp = head;
  
  while(temp->m_next != NULL) {
    temp = temp->m_next;
  }
  
  temp->m_next = xlist.head;
}
