//Name: Jimmy Lin
//Date: 2/12/2014
//Section: 1C cs1510
//Description: creating and using 2D arrays

#include <iostream>

using namespace std;

int main()
{
  
  //variables
  int gridMapNum; //holds the number of grid maps
  int height; //holds the height of the grid map
  int width; //holds the width of the grid map
  int smallNum; //holds the smallest number of flowers crushed
  int temp; //holds the new calculated number of flowers crushed
  bool firstTime = true; //checks to see if it is the first time 
                        //comparing smallNum and temp
  int xcoord; //holds the x coordinate
  int ycoord; //holds the y coordinate
                        
  //asks the user to input the number of grid maps
  cout<<"Please enter the number of grid maps: ";
  cin>>gridMapNum;
  
  //loops through all 3 grid maps to assign them a height and width
  for (int i = 0; i < gridMapNum; i++) {
    //resets all variables
    height = 0;
    width = 0;
    smallNum = 0;
    temp = 0;
    firstTime = true;
    xcoord = 0;
    ycoord = 0;
    
    //while loop to ensure that the user enteres in a number >3
    while (width < 3) {
      //asks the user for the width
      cout<<"What is the width of the "<<i+1<<" grid map? ";
      cin>>width;
      //if width is < 3 then error message is displayed
      if (width < 3) {
        //error message
        cout<<"Please enter a width greater than or equal to 3"<<endl;
      }
    }
    
    //while loop to ensure that the user enters in a number >3
    while (height < 3) {
      //asks the user for width
      cout<<"What is the height of the "<<i+1<<" grid map? ";
      cin>>height;
      //if width is < 3 then error message is displayed
      if (height < 3) {
        //error message
        cout<<"Please enter a height greater than or equal to 3"<<endl;
      }
    }
    
    //creates a 2D array
    //first creates an array with the size of height
    int ** array = new int*[height];
    //loops through all cells of the height array to create the width
    for (int j = 0; j < height; j++) {
      array[j] = new int[width];
    }
    
    //loop through each cell of the array
    //for loop to loop through the height first
    for (int j = 0; j < height; j++) {
      //for loop to loop through the width
      for (int x = 0; x < width; x++) {
        //asks the user to enter a number
        cout<<"Please enter a number for coordinate "<<"("<<j<<", "<<x<<"): ";
        //assigns the user inputed number to array
        cin>>array[j][x];
      }
    }
    
    /*-------------------------------------------------*/
    //loops through the width
    for (int w = 0; w < width; w++) {
      //checks width to make sure there is enough space for 3x3 cell
      if (w + 2 <= width - 1) {
        //loops through the height
        for (int h = 0; h < height; h++) {
          //checks height to make sure there is enough height for 3x3 cell
          if (h + 2 <= height - 1) {
            //loops through the height of the chosen 3x3 cell from w and h
            for (int x = 0; x < 3; x++) {
              //loops through the width of the choen 3x3 cell from w and h
              for (int y = 0; y < 3; y++) {
                //adds the number in cell to smallNum
                temp += array[x+h][y+w];
              } 
            }
            if (firstTime == true) {
              firstTime = false;
              smallNum = temp;
              temp = 0;
              xcoord = h;
              ycoord = w;
            }
            else if (smallNum > temp) {
              smallNum = temp;
              temp = 0;
              xcoord = h;
              ycoord = w;
            }
          }
          else {
            //ends height loop if there is not enough room for 3x3 cell
            h = height;
          }
        }
            
      }
      else {
        //ends width loop if there is not enough room for 3x3 cell
        w = width;
      }
    }
    /*--------------------------------------------*/
     
    //prints the gridmap number, top left most cell of a 3x3 coordinate with the least amount
    //of flowers crushed, and amount of flowers crushed
    cout<<"#"<<i<<": "<<"("<<ycoord<<", "<<xcoord<<")"<<smallNum<<endl;
    
    //deconstructs the 2D array that was created
    for (int j = 0; j < height; j++) {
      delete [] array[j];
      array[j] = NULL;
    }
    delete [] array;
    array = NULL;
  }
  return 0;
}

