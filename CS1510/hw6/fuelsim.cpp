//Name: Jimmy Lin
//Date: May 4, 2015
//Class: C
//File: fuelsim.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "abstractqueue.h"
#include "abstractqueue.hpp"

using namespace std;

int main()
{
  vector<int> arrival;
  vector<string> name;
  vector<int> units;
  
  fuelsim<int> APortArrival;
  fuelsim<string> APortName;
  fuelsim<int> APortUnits;
  
  fuelsim<int> BPortArrival;
  fuelsim<string> BPortName;
  fuelsim<int> BPortUnits;
  
  fuelsim<int> CPortArrival;
  fuelsim<string> CPortName;
  fuelsim<int> CPortUnits;
  
  int arrivalTime = 0;
  string shipName = "";
  int fuelUnits = 0;
  
  string shipInfo = "";
  int numShips = 0;
  int maxWait = 0;
  int minWait = 100000000;
  string maxName;
  string minName;
 
  int counter = 1; 
  int A = 0;
  int B = 0;
  int C = 0;
  
  cin>>numShips;
  cin.ignore();
  for(int i = 0; i < numShips; i++) {
    getline(cin,shipInfo);
    arrivalTime = atoi(shipInfo.substr(0, shipInfo.find(" ")).c_str());
    shipInfo.erase(0, shipInfo.find(" ") + 1);
    shipName = shipInfo.substr(0, shipInfo.find(" "));
    shipInfo.erase(0, shipInfo.find(" ") + 1);
    fuelUnits = atoi(shipInfo.substr(0).c_str());
    
    arrival.push_back(arrivalTime);
    name.push_back(shipName);
    units.push_back(fuelUnits*3);
  }
  
  while(name.size() != 0 || APortName.ships.size() != 0 || BPortName.ships.size() != 0
  || CPortName.ships.size() != 0) {
    for(int x = 0; x < numShips; x++) {
      if(arrival[x] == counter) {
        if(APortName.ships.size() <= BPortName.ships.size() && 
        APortName.ships.size() <= CPortName.ships.size()) {
          cout<<"At time "<<counter<<" "<<name.front()<<" joins port A."<<endl;
          APortArrival.enqueue(arrival[x]);
          APortName.enqueue(name.front());
          APortUnits.enqueue(units[x]);
          name.erase(name.begin());
        }
        else if(BPortName.ships.size() <= CPortName.ships.size()) {
          cout<<"At time "<<counter<<" "<<name.front()<<" joins port B."<<endl;
          BPortArrival.enqueue(arrival[x]);
          BPortName.enqueue(name.front());
          BPortUnits.enqueue(units[x]);
          name.erase(name.begin());
        }
        else {
          cout<<"At time "<<counter<<" "<<name.front()<<" joins port C."<<endl;
          CPortArrival.enqueue(arrival[x]);
          CPortName.enqueue(name.front());
          CPortUnits.enqueue(units[x]);
          name.erase(name.begin());
        }
      }
    }
    
    if(APortName.ships.size() != 0) {
      if(A == APortUnits.front()) {
        cout<<"At time "<<counter<<" "<<APortName.front()<<" is done fueling."<<endl;
        if((counter - APortArrival.front()) > maxWait) {
          maxWait = counter - APortArrival.front();
          maxName = APortName.front();
        }
        if((counter - APortArrival.front()) < minWait) {
          minWait = counter - APortArrival.front();
          minName = APortName.front();
        }                                                      
        APortArrival.dequeue();
        APortName.dequeue();
        APortUnits.dequeue();
        A = 0;
      }
      A++;
    }
    
    if(BPortName.ships.size() != 0) {
      if(B == BPortUnits.front()) {
        cout<<"At time "<<counter<<" "<<BPortName.front()<<" is done fueling."<<endl;
        if((counter - BPortArrival.front()) > maxWait) {
          maxWait = counter - BPortArrival.front();
          maxName = BPortName.front();
        }
        if((counter - BPortArrival.front()) < minWait) {
          minWait = counter - BPortArrival.front();
          minName = BPortName.front();
        }                                                  
        BPortArrival.dequeue();
        BPortName.dequeue();
        BPortUnits.dequeue();
        B = -1;
      }
      B++;
    }
    
    if(CPortName.ships.size() != 0) {
      if(C == CPortUnits.front()) {
        cout<<"At time "<<counter<<" "<<CPortName.front()<<" is done fueling."<<endl;
        if((counter - CPortArrival.front()) > maxWait) {
          maxWait = counter - CPortArrival.front();
          maxName = CPortName.front();
        }
        if((counter - CPortArrival.front()) < minWait) {
          minWait = counter - CPortArrival.front();
          minName = CPortName.front();
        }
        CPortArrival.dequeue();
        CPortName.dequeue();
        CPortUnits.dequeue();
        C = 0;
      }
      C++;
    }
    counter++;
  }
  
  
  cout<<"Longest wait: "<<maxName<<", "<<maxWait<<" mins."<<endl;
  cout<<"Shortest wait: "<<minName<<", "<<minWait<<" mins."<<endl;
  return 0;
}
