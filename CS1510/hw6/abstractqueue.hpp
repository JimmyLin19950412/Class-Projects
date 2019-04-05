//Name:	Jimmy Lin
//Date:	May 4, 2015
//Class: C
//File: abstractqueue.hpp

#include <iostream>
#include <vector>
#include "abstractqueue.h"

using namespace std;

template <typename T>
class fuelsim : public AbstractQueue<T>
{  
  public:
    vector<T> ships;
    ~fuelsim();
    bool isEmpty() const;
    const T& front() const throw (Oops);
    const T& back() const throw (Oops);
    void enqueue(const T& x);
    void dequeue();
    void clear();
};

template <typename T>
fuelsim<T>::~fuelsim()
{
  clear();
}

template <typename T>
bool fuelsim<T>::isEmpty() const
{
  if (ships.size() == 0) {
    return true;    
  }
  else {
    return false;
  }
}

template <typename T>
const T& fuelsim<T>::front() const throw (Oops)
{
  if(isEmpty()) {
    throw Oops("Error que is empty");
  }
  else {
    return ships.front();  
  }
}

template <typename T>
const T& fuelsim<T>::back() const throw (Oops)
{
  if(isEmpty()) {
    throw Oops("Error que is empty");
  }
  else {
    return ships.back();
  }
}

template <typename T>
void fuelsim<T>::enqueue(const T& x)
{
  ships.push_back(x);  
}

template <typename T>
void fuelsim<T>::dequeue()
{
  ships.erase(ships.begin());
}

template <typename T>
void fuelsim<T>::clear()
{
  while(!isEmpty()) {
    dequeue();
  }
} 
