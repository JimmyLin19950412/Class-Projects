  void getInput()
  {
	//variables
	//max size for each word is assumed to be 20
	const it MAXWORDSIZE = 20;
	//max words
	const int MAXWORDS = 100;
	//2100 is assuming no words are more then 20 characters in length
	//100 words max and spaces along with a null characters
	const int MAXSIZE = MAXWORDSIZE * MAXWORDS;
	//max words is set to 99 because assuming that one space is used
	//per word then only 99 spaces will be entered
	const int MAXWORDS = 99; 
	int amtSpaces = 0; //holds the number of spaces entered
	int count = 0; //counter or while loop
	//determines if the keywords head, torso, hand, nose, or leg is fputc
	bool keyword = false;

	//NTCA array
	char inputArray[MAXSIZE];
	
	//only loops if the amount of words are more then 100
	do {
	  //gets user input
      cout<<"What is your Issue: ";
	  cin>>inputArray;  
	   
	  //sets amtWords to 0
	  amtSpaces = 0;
	  
	  //checks how many words are in the array
	  //loops until NTCA character is found
	  while(inputArray[count] != '\0') {
		//if a space is detected
	    if(inputArray[count] == ' ') {
		  //increases amtSpace by 1
		  amtSpaces++;
		}
		//increases count counter by 1
		count++;
	  }
	  
	  //loop that checks for keywords: head, torso, hand, nose, or leg
	  keyword = keywordCheck(count, inputArray);
	  
	}while(amtWords > MAXWORDS || keyword == false);  
  }
  bool keywordCheck(int count, const char inputArray[])
  {
    //variables
	
	//checks for keyword head
	if(inputArray[count] == 'h' || inputArray[count] == 'H') {
      if(inputArray[count+1] == 'e' || inputArray[count+1] == 'E') {
		if(inputArray[count+2] == 'a' || inputArray[count+2] == 'A') {
		  if(inputArray[count+3] == 'd' || inputArray[count+3] == 'D') {
			return true;
		  }	
		}
	  }
	}
	
	//checks keyword for torso
	if(inputArray[count] == 't' || inputArray[count] == 'T') {
      if(inputArray[count+1] == 'o' || inputArray[count+1] == 'O') {
		if(inputArray[count+2] == 'r' || inputArray[count+2] == 'R') {
		  if(inputArray[count+3] == 's' || inputArray[count+3] == 'S') {
			if(inputArray[count+4] == 'o' || inputArray[count+4] == 'O') {
			  return true;
			}
		  }	
		}
	  }
	}
	
	//checks keyword for hand
	if(inputArray[count] == 'h' || inputArray[count] == 'H') {
      if(inputArray[count+1] == 'a' || inputArray[count+1] == 'A') {
		if(inputArray[count+2] == 'n' || inputArray[count+2] == 'N') {
		  if(inputArray[count+3] == 'd' || inputArray[count+3] == 'D') {
			return true;
		  }	
		}
	  }
	}
	
	//checks keyword for nose
	if(inputArray[count] == 'n' || inputArray[count] == 'N') {
      if(inputArray[count+1] == 'o' || inputArray[count+1] == 'O') {
		if(inputArray[count+2] == 's' || inputArray[count+2] == 'S') {
		  if(inputArray[count+3] == 'e' || inputArray[count+3] == 'E') {
			return true;
		  }	
		}
	  }
	}
	
	//checks keyword for leg
	if(inputArray[count] == 'l' || inputArray[count] == 'L') {
      if(inputArray[count+1] == 'e' || inputArray[count+1] == 'E') {
		if(inputArray[count+2] == 'g' || inputArray[count+2] == 'G') {
		  return true;
		}
	  }
	}
  }  