//Name: Jimmy Lin
//Date: 12/2/2014
//Section: C
//File: lab14.cpp
//Description: lab14.cpp

#include <iostream>

using namespace std;

//templated class
template<class T>
class Array_Class
{
  private:
    T m[4]; //array with 4 spots
  public:
    //gets 4 variables as input to initialie m[4]
    Array_Class(T m_0, T m_1, T m_2, T m_3);
    Array_Class(T _m[]); //gets an array as input to initialize m[0]
    Array_Class(); //initializes all members of m[4] with zero
    
    //multiplying elements of array pair-wisely
    Array_Class<T> & operator *=(const Array_Class<T> & arr);
    
    //summation of elements of array pair-wisely
    template<class u>
    friend Array_Class<u> operator+(const Array_Class<u> & lhs, 
    const Array_Class<u> & rhs); 
        
    //print out the element of array
    template<class u>
    friend ostream & operator<<(ostream & stream, 
    const Array_Class<u> & array); 
};
          
int main()
{
  //creates a populated array
  int arr[4] = {3,2,3,5};
  
  Array_Class<int> A(1,2,3,4); //initializes Array_Class, calling it A
  Array_Class<int> B(arr); //initializes Array_Class, calling it B
  Array_Class<int> C; //initializes Array_Class, calling it C

  cout<<"A: "<<A<<"B: "<<B<<"C: "<<C;
  B *= A;
  C = A + B;
  cout<<"A: "<<A<<"B: "<<B<<"C: "<<C;
   
  return 0;
}

//gets 4 variables as input to initialize m[4]
template<class T>
Array_Class<T>::Array_Class(T m_0, T m_1, T m_2, T m_3) 
{
  //populates array
  m[0] = m_0;
  m[1] = m_1;
  m[2] = m_2;
  m[3] = m_3;
}

//gets an array as input to initialize m[0]
template<class T>
Array_Class<T>::Array_Class(T _m[])
{
  //sets m[] array's value to equal the passed in array's value
  for(int i = 0; i <= 3; i++) {
    m[i] = _m[i];
  }   
}

//initialize all members of m[4] with 0
template<class T>
Array_Class<T>::Array_Class() 
{
  //loops thrugh whole array and popualtes m[4] to 0
  for(int i = 0; i <= 3; i++) {
    m[i] = 0;
  }
} 

//multipling elements of array pair-wisely
template<class T>
Array_Class<T> & Array_Class<T>::operator *=(const Array_Class<T> & arr)
{
  //multiplys the array values pair-wisely
  for(int i = 0; i <= 3; i++) {
    m[i] *= arr.m[i];
  }
  
  return *this;
}

template<class T>
//summation of elements of array pair-wisely
Array_Class<T> operator+(const Array_Class<T> & lhs, const Array_Class<T> & rhs)
{
  Array_Class<T> temp;
  //summation of the elements of array pair-wisely
  for(int i = 0; i <= 3; i++) {
    temp.m[i] = lhs.m[i] + rhs.m[i];
  }
  
  //returns temp
  return temp; 
}

template<class T>
//print out element of array
ostream & operator<<(ostream & stream, const Array_Class<T> & array)
{
  //prints out the array
  stream<<"|"<<array.m[0]<<","<<array.m[1]<<","<<array.m[2]<<","<<array.m[3]<<"|"<<endl;
  
  //returns stream
  return stream;  
}
