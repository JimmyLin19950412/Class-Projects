#include <iostream>
#include <fstream>

using namespace std;

class Rectangle
{
 private:
  int length;
  int width;

 public:
  Rectangle();
  Rectangle(int rect_length, int rect_width);
     
  void operator !();
  Rectangle & operator *= (const Rectangle & rec);

  friend Rectangle operator + (const Rectangle &rec1 , const Rectangle &rec2);
  friend ostream & operator << (ostream & stream, const Rectangle & rec);
};

int main()
{
 Rectangle A(3, 2);
 Rectangle B(9,5);
 Rectangle C;
 cout <<"A: " << A;
 cout <<"B: " << B;
 cout <<"C: " << C;
 C = A + B;
 cout <<"C = A + B ==> C: " << C;
 C *= A;
 cout <<"C *= A    ==> C: " << C;
 !C;
 cout <<"!C        ==> C: " << C;

 return 0;
}
//// here Define your functions
//Description: default constructor that initilizes length and widt of any object
//with one
//Pre:none
//Post: sets lenght and width to 1
Rectangle::Rectangle()
{
 length = 1;
 width = 1;
}

//Description: constructor that takes lenght and width as parameters
//Pre: requires two integeters
//Post: sets length and width to a value equal to the 2 parameters
Rectangle::Rectangle(int rect_length, int rect_width)
{
 length = rect_length;
 width = rect_width;
}

//Description: subtracts 2 from both length and width, if eitehr are equal to
//or less than 0 then sets them to 1
//Pre: requires length and one to be populated
//Post: changes the value of length and width by -2 or sets them to 1
void Rectangle::operator !()
{
 length -= 2;
 width -= 2;
 
 //if length is equal to or less than one then sets length to 1
 if(length < 1) {
  length = 1;
 }
 //if width is qual to or less than one then sets width to 1
 if(width < 1) {
  width = 1;
 } 
}

//Description: multiplies the length of the current rectangle with the length
//of the called rectangle
//Pre: requires lenght and width of the main rectangle class to be filled
//Post: changes the lenght and width of the main rectangle class
Rectangle & Rectangle::operator *= (const Rectangle & rec)
{
 length *= rec.length;
 width *= rec.width;
 return (*this); 
}

//Description: Adds rectangle length 1 and rectangle length 2
//Adds rectangle width 1 and rectangle width 2
//Pre: reqiuires two populated rectangle classes
//Post: returns the value of both length and width
Rectangle operator + (const Rectangle & rec1, const Rectangle & rec2)
{ 
 Rectangle temp;
 temp.length = rec1.length + rec2.length;
 temp.width = rec1.width + rec2.width;
 return temp;   
}

//Description: posts rectangle width and length on screen
//Pre: requires ostrean to be defined and a filled class
//Post: posts rectangle length and width onto screen
ostream & operator <<(ostream & stream, const Rectangle & rec)
{
 return (stream<<"["<<rec.length<<" , "<<rec.width<<"]"<<endl);
}
