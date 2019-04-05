//Name: Jimmy Lin
//Date: 4/21/2015
//File: abstractstack.hpp

#include <iostream>
#include "abstractstack.h"

using namespace std;

template <typename N>
struct Node
{
  N data;
  Node * next;
  Node();
};

template <typename T>
class stack : public AbstractStack<T>
{
  Node<T> * head;
  int size = 0;
  
  public:
    bool isEmpty() const;
    const T& top() const throw(Oops);
    void push(const T& x);
    void pop();
    void clear();
    void print();
    stack();
    ~stack();
};

template <typename T>
stack<T>::stack()
{
  head = NULL;
}

template <typename T>
stack<T>::~stack()
{
  clear();
}

template <typename N>
Node<N>::Node()
{
  next = NULL;
}

template <typename T>
bool stack<T>::isEmpty() const
{
  if (head == NULL) {
    return true;
  }
  else {
    return false;
  }
}

template <typename T>
const T& stack<T>::top() const throw (Oops)
{
  if(isEmpty()) {
    throw Oops("Error stack is empty");
  }
  else {
    Node<T> * temp = head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    return temp->data;
  }
}

template <typename T>
void stack<T>::push(const T& x)
{
  Node<T> * newNode = new Node<T>;
  newNode->data = x;
  if(head == NULL) {
    head = newNode;
    return;
  }
  Node<T> * temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  size++;
}

template <typename T>
void stack<T>::pop()
{
  if(head == NULL) {
    return;
  }
  
  if(head->next == NULL) {
    delete head;
    head = NULL;
    return;
  }
  
  Node<T> * temp = head;
  Node<T> * temp2 = head;
  
  while(temp->next != NULL) {
    temp = temp->next;
  }
  
  while(temp2->next->next != NULL) {
    temp2 = temp2->next;
  }
  
  delete temp;
  temp2->next = NULL;
  temp = NULL;
  size--;
}

template <typename T>
void stack<T>::clear()
{
  if(head == NULL) {
    return;
  }
  
  Node<T> * temp = head;
  
  while(head->next != NULL) {
    head = head->next;
    delete temp;
    temp = head;
  }
  
  delete head;
  head = NULL;
  temp = NULL;
  size = 0;
}    

template <typename T>
void stack<T>::print()
{
  if(head == NULL) {
    cout<<"[ ]"<<endl;
    return;
  }
  
  Node<T> * temp = head;
  
  cout<<"[ ";
  
  for(int i = size; i >= 0; i--) {  
    for(int j = 0; j < i; j++) {
      temp = temp->next;
    }  
    cout<<temp->data<<", ";  
    temp = head;
  }
  
  cout<<"]"<<endl;
}
