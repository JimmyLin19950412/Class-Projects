//Name: Jimmy Lin
//ID: 12434423
//Date: 3/16/2016
//File: heapsort.cpp
//Description: Performs a min or max heap on an array of values

#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

void maxHeapsort(int array[], int n, int & tires);
void minHeapsort(int array[], int n, int & tries);
int isSortedMax(int array[], int p, int n);
int isSortedMin(int array[], int p, int n);
void exchange(int array[], int p, int p2);

int main()
{
  int n;
  int answer = 3;
  int * array;
  int tries = 0;
  
  //asks for how many elements are in the array
  cout<<"How many elements are in the array?"<<endl;
  cin>>n;
  array = new int [n];
  
  //asks for the elements in the array
  for(int i = 0; i < n; i++) {
    cout<<"What is your "<<i+1<<" number?"<<endl;
    cin>>array[i];
  }
  
  //loops until the user enters a valid input of 1 or 2
  while(answer != 1 && answer != 2) { 
    cout<<"1) Max Heapsort"<<endl;
    cout<<"2) Min Heapsort"<<endl;
    cin>>answer;
  }
  
  //max heapsort
  if(answer == 1) {
    cout<<"You have chosen Max Heapsort."<<endl;
    maxHeapsort(array, n, tries);
  }
  //minheapsort
  else {
    cout<<"You have chosen Min Heapsort."<<endl;
    minHeapsort(array, n, tries);
  }
  
  //prints array
  for(int i = 0; i < n; i++) {
    cout<<array[i]<<", ";
  }
    cout<<"Took "<<tries<<" comparisons to make the proper heap!"<<endl;
}

//Pre-Condition: Array contains random integers
//Post-Condition: Array is sorted were the parents are larger than the childeren
void maxHeapsort(int array[], int n, int & tries)
{
  int parents = floor(n/2); //finds the number of parent nodes
  int p = parents; //adjustable value that starts out with the same value as parents
  
  //loops through entire array
  for(int i = 0; i < parents; i++) {
    //invariant: array(p...parents) satisfies max heap property
    if(i != 0) {
      assert(isSortedMax(array, p, n));
    }
    if((p-1) == -1) {
      //do nothing. at top of heap
  
    }
    //chjecks to see if the parent node has 2 children
    else if((2*p+1) > n) {
      if(array[2*p-1] > array[p-1]) {
        //exchange nodes
        exchange(array, p-1, 2*p-1);
        //recurrsian loop to ensure the node is in the correct position
        maxHeapsort(array, parents, tries);
      }
      else {
        p--;
        i--;
      }
    }
    //compare the child nodes to the parent node
    else if(array[2*p+1-1] > array[2*p-1]) {
      if(array[2*p+1-1] > array[p-1]) {
        //exchange nodes
        exchange(array, p-1, 2*p+1-1);
        //recursian loop to ensure the node is  in the correct position
        maxHeapsort(array, parents, tries);
      }
    }
    //compares the child node to the parent node
    else if(array[2*p-1] > array[p-1]) {
      //exchange nodes
      exchange(array, p-1, 2*p-1);
      //recursian loop to ensure the node is in the correct position
      maxHeapsort(array, parents, tries);
    }
    else {
      p--;
      i--;
    }
    tries++;
    //invariant:array(p...parents) satifies max heap property
    assert(isSortedMax(array, p, n)); 
  }
}

//Pre-Condition: Array contains random integers
//Post-Condition: Array is sorted were the parents are smaller than the children
void minHeapsort(int array[], int n, int & tries)
{
  int parents = floor(n/2); //finds the number of parent nodes
  int p = parents; //adjustable value that starts out with the same value as parents
  
  //loops through entire array
  for(int i = 0; i < parents; i++) {
    //invariant: array(p...parents) satisfies min heap property
    //assert(isSortedMin(array, p, n));
    if((p-1) == -1) {
      //do nothing. at top of heap
    }
    //checks to see if parent node has 2 children
    else if((2*p+1) > n) {
      if(array[2*p-1] < array[p-1]) {
        //exchange nodes
        exchange(array, p-1, 2*p-1);
        //recurrsian loop to ensure node is in correct position
        minHeapsort(array, parents, tries);
      }
      else {
        p--;
        i--;
      }
    }
    //compares the child nodes of the parent node
    else if(array[2*p+1-1] < array[2*p-1]) {
      if(array[2*p+1-1] < array[p-1]) {
        //exchange nodes
        exchange(array, p-1, 2*p+1-1);
        //recurrsian loop to ensure node is in correct positions
        minHeapsort(array, parents, tries);
      }
    }
    //compares parent node with child node
    else if(array[2*p-1] < array[p-1]) {
      //exchange nodes
      exchange(array, p-1, 2*p-1);
      //recurrsian loop to ensure node is in the correct positions
      minHeapsort(array, parents, tries);
    }
    else {
      p--;
      i--;
    }
    tries++;
    //invariant: array(p...parents) satifies min heap property
    //assert(isSortedMin(array, p, n));
  }
}

int isSortedMax(int array[], int p, int n)
{
  cout<<"hi"<<endl;
  //checks to see if parent node has 2 children
   if((2*p+1) > n) {
    //checks if child node is bigger than parent node
    if(array[2*p] > array[p]) {
      return false;
    }
    else {
      return true;
    }
  }
  //checks if child node is bigger than parent node
  else if(array[2*p+1] > array[p]) {
    return false;
  }
  //checks if child node is bigger then parent node
  else if(array[2*p] > array[p]) {
    return false;
  }
  else {
    return true;
  }
}

int isSortedMin(int array[], int p, int n)
{
  //checks to see if parent node has 2 children
  if((2*p+1) > n) {
    //checks if child node is bigger than parent node
    if(array[2*p] < array[p]) {
      return false;
    }
    else {
      return true;
    }
  }
  //checks if child node is bigger than parent node
  else if(array[2*p+1] < array[p]) {
    return false;
  }
  //checks if child node is bigger than parent node
  else if(array[2*p] < array[p]) {
    return false;
  }
  else {
    return true;
  }
}

//exchanges the position of two nodes
void exchange(int array[], int p, int p2) {
  int temp = array[p];
  array[p] = array[p2];
  array[p2] = temp;
}
