//Name:	Jimmy Lin
//Date:	10/14/2014
//File:	area.cpp
/*Section: Calculate right-triangles, right-diamonds, rectangle, and circles
height base and or width*/

#include <iostream>
#include "area.h"

using namespace std;

int main()
{
  //accessing structures
  rightTriangle rightT; //accessing rightTriangle structure
  rightDiamond rightD; //accessing rightDiamond structure
  rectangle rect; //accessing rectangle structure
  circle circ; //accessing circle structure
  
  //variables
  float areaRightT; //area of right triangle
  float areaRightD; //area of right diamond
  float areaRect; //area of rectangle
  float areaCirc; //area of circle 
  //greeting for the user
  greet();
  
  //asks for base of triangle
  cout<<"Enter the Base of a Triangle: ";
  rightT.m_base = read();
  
  //asks for height of a triangle
  cout<<"Enter the Height of a Triangle: ";
  rightT.m_height = read();
  cout<<endl;
  
  //asks user for height of diamond
  cout<<"Enter the Height of a Diamond: ";
  rightD.m_height = read();
  
  //asks user for base of diamond
  cout<<"Enter the Base of a Diamond: ";
  rightD.m_base = read();
  cout<<endl;	
  
  //asks user for height of rectangle
  cout<<"Enter the Height of a Rectangle: ";
  rect.m_height = read();
    
  //asks user for width of rectangle
  cout<<"Enter the Width of a Rectangle: ";
  rect.m_width = read();
  cout<<endl;
  
  //asks user for radius of circle
  cout<<"enter the Radius of a Circle: ";
  circ.m_radius = read();
  cout<<endl;
  
  //prints area of triangle
  areaRightT = area(rightT);
  cout<<"Area of Triangle is: "<<areaRightT<<endl;
  
  //prints area of diamond
  areaRightD = area(rightD);
  cout<<"Area of Diamond is: "<<areaRightD<<endl;
  
  //prints area of rectangle
  areaRect = area(rect);
  cout<<"Area of Rectangle is: "<<areaRect<<endl;
  
  //prints area of circle
  areaCirc = area(circ);
  cout<<"Area of Circle is: "<<areaCirc<<endl;
  
  //sign off message
  signoff();
}
