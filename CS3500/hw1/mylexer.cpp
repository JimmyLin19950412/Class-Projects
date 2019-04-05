//Name: Jimmy Lin
//Date: 09/10/2017
//Section: 1B
//File: mylexer.cpp
//Description: Homework # 1 note: I hate myself for coding this...monster...so much redundency

#include<iostream>
#include <string>

using namespace std;

//function prototypes
//detects if string is a number
bool detectInteger(string userInput, int length);
//detects if string is a decimal
bool detectDecimal(string userInput, int length);
//detects for scientific
bool detectScientific(string userInput, int length);
//detects hexadecimals
bool detectHexadecimal(string userInput, int length);
//detects email
bool detectEmail(string userInput, int length);
//detects identifiers
bool detectIdentifier(string userInput, int length);

int main()
{
	//stores number of lines
	int numberOfLines;
	//stores user input
	string userInput;
	//holds length of string
	int length;
	
	//return values
	string integer = "Integer.";
	string decimal = "Decimal.";
	string scientific = "Scientific.";
	string hexadecimal = "Hexadecimal.";
	string keywords = "Keyword.";
	string identifiers = "Identifier.";
	string email = "Email.";
	string error = "INVALID!";
	
	//gets number of lines from user
	cin>>numberOfLines;
	cout<<numberOfLines<<endl;
	
	//for loop that gets input from user until i = numberOfLines
	for(int i = 0; i < numberOfLines; i++) {
		//obtain user input
		cin>>userInput;
		//assign the length of users input to length
		length = userInput.length();
		
		//detects empty input. No valid input is empty
		if(length == 0) {
			cout<<i+1<<". "<<error<<endl;
		}
		//detects space as first input. No valid input has a space as first character
		if(isspace(userInput[0]) == true) {
			cout<<i+1<<". "<<error<<endl;	
		}
		//detect keywords
		if(userInput == "while" || userInput == "else" || userInput == "if" || userInput == "print") {
			//if user input is while, else, if, or print then cout keywords
			cout<<i+1<<". "<<keywords<<endl;
		}
		//detect integer
		else if(detectInteger(userInput, length) == true) {
			cout<<i+1<<". "<<integer<<endl;
		}
		//detect decimal
		else if(detectDecimal(userInput, length) == true) {
			cout<<i+1<<". "<<decimal<<endl;
		}
		//detect scientific
		else if(detectScientific(userInput, length) == true) {
			cout<<i+1<<". "<<scientific<<endl;
		}
		//detect hexadecimal
		else if(detectHexadecimal(userInput, length) == true) {
			cout<<i+1<<". "<<hexadecimal<<endl;
		}
		//detect identifiers
		else if(detectIdentifier(userInput, length) == true) {
			cout<<i+1<<". "<<identifiers<<endl;
		}
		//detect email
		else if(detectEmail(userInput, length) == true) {
			cout<<i+1<<". "<<email<<endl;
		}
		//no matches
		else {
			cout<<i+1<<". "<<error<<endl;
		}	
	}
	
	return 0;
}

//detects for numbers
bool detectInteger(string userInput, int length) {
	//holds a character in userInput
	char character;
	//holds true if first character is a + or -. otherwise false
	bool firstChar = false;
	
	//for loop that goes up to the length of userInput
	for(int i = 0; i < length; i++) {
		//assigns a character from userInput to variable character
		character = userInput[i];
		
		//if this is the first character
		if(i == 0) {
			//if first character is not a number, + or - then it cannot be an integer
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0' && character != '+' && character != '-') {
				return false;
			}
			else {
				//if first character is a + or -
				if(character == '+' || character == '-') {
					firstChar = true;
				}
			}
		}
		//if it is not the first character
		else {
			//if the following characters after the first one is not a number then it cannot be an integer
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0') {
				return false;
			}
		}
	}
	
	//if first character is a + or - and the length of the string is 1 then it is not an integer
	if(firstChar == true) {
		if(length == 1) {
			return false;
		}
	}
	return true;
}

//detects for decimals
bool detectDecimal(string userInput, int length) {
	//holds a character in userInput
	char character;
	//number of decimals found
	int decimalsFound = 0;
	//stores location of the decimal
	int decimalLocation;
	
	//if length of userInput is 1 then it cannot be a decimal
	if(length == 1) {
		return false;
	}
	
	//loops to find a decimal, if no decimal is found then it cannot be a decimal
	for(int i = 0; i < length; i++) {
		if(userInput[i] == '.') {
			decimalsFound++;
			decimalLocation = i;
		}
	}
	
	//if there are 0 decimal points, more then 1 decimal points, more then 1 E's, or no E's then it cannot be a scientific
	if(decimalsFound > 1 || decimalsFound == 0) {
		return false;
	}
	
	//if decimal point is the last character in a string then it cannot be a decimal
	if(decimalLocation+1 == length) {
		return false;
	}
	
	//if a decimal point does not have a number before it then it cannot be a decimal
	if(userInput[decimalLocation-1] != '1' && userInput[decimalLocation-1] != '2' && userInput[decimalLocation-1] != '3' && userInput[decimalLocation-1] != '4' &&
	userInput[decimalLocation-1] != '5' && userInput[decimalLocation-1] != '6' && userInput[decimalLocation-1] != '7' && userInput[decimalLocation-1] != '8' &&
	userInput[decimalLocation-1] != '9' && userInput[decimalLocation-1] != '0') {
		return false;
	}
	
	//for loop that goes up to the length of userInput and determines if userInput is a decimal or not
	for(int i = 0; i < length; i++) {
		//assigns a character from userInput to variable character
		character = userInput[i];

		//if this is the first character
		if(i == 0) {
			//if first character is not a number, + or - then it cannot be a decimal
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0' && character != '+' && character != '-') {
				return false;
			}
		}
		//if it is not the first character
		else {
			//if the following characters after the first one is not a number or a decimal point then it cannot be a decimal
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0' && character != '.') {
				return false;
			}
		}
	}
	return true;
}

//detects for scientific
bool detectScientific(string userInput, int length) {
	//holds a character in userInput
	char character;
	//number of decimals found
	int decimalsFound = 0;
	//stores location of the decimal
	int decimalLocation;
	//number of E's foound
	int eFound = 0;
	//stores location of Email
	int eLocation;
	
	//if length of userInput is 1 then it cannot be a scientific
	if(length == 1) {
		return false;
	}
	
	//loops to find a decimal and E, if no decimal or E is found then it cannot be a scientific
	for(int i = 0; i < length; i++) {
		if(userInput[i] == '.') {
			decimalsFound++;
			decimalLocation = i;
		}
		if(userInput[i] == 'E') {
			eFound++;
			eLocation = i;
		}
	}
	
	//if there are 0 decimal points, more then 1 decimal points, more then 1 E's, or no E's then it cannot be a scientific
	if(decimalsFound > 1 || decimalsFound == 0 || eFound > 1 || eFound == 0) {
		return false;
	}
	
	//if decimal point, E, or - is the last character in a string then it cannot be a scientific
	if(decimalLocation == length || eLocation == length || userInput[length-1] == '-') {
		return false;
	}
	
	//if last character in userInput is a 0 then check chracter before
	//if character before is a - then it cannot be scientific
	if(userInput[length-1] == '0') {
		if(userInput[length-2] == '-') {
			return false;
		}
	}
	
	//if a decimal point does not have a number before it then it cannot be scientific
	if(userInput[decimalLocation-1] != '1' && userInput[decimalLocation-1] != '2' && userInput[decimalLocation-1] != '3' && userInput[decimalLocation-1] != '4' &&
	userInput[decimalLocation-1] != '5' && userInput[decimalLocation-1] != '6' && userInput[decimalLocation-1] != '7' && userInput[decimalLocation-1] != '8' &&
	userInput[decimalLocation-1] != '9' && userInput[decimalLocation-1] != '0') {
		return false;
	}
	
	//if a E does not have a number before it then it cannot be scientific
	if(userInput[eLocation-1] != '1' && userInput[eLocation-1] != '2' && userInput[eLocation-1] != '3' && userInput[eLocation-1] != '4' &&
	userInput[eLocation-1] != '5' && userInput[eLocation-1] != '6' && userInput[eLocation-1] != '7' && userInput[eLocation-1] != '8' &&
	userInput[eLocation-1] != '9' && userInput[eLocation-1] != '0') {
		return false;
	}
	
	//if a E does not have a number or a - after it then it cannot be scientific
	if(userInput[eLocation+1] != '1' && userInput[eLocation+1] != '2' && userInput[eLocation+1] != '3' && userInput[eLocation+1] != '4' &&
	userInput[eLocation+1] != '5' && userInput[eLocation+1] != '6' && userInput[eLocation+1] != '7' && userInput[eLocation+1] != '8' &&
	userInput[eLocation+1] != '9' && userInput[eLocation+1] != '0' && userInput[eLocation+1] != '-') {
		return false;
	}
	
	//for loop that goes up to the length of userInput and determines if userInput is a scientific or not
	for(int i = 0; i < length; i++) {
		//assigns a character from userInput to variable character
		character = userInput[i];

		//if this is the first character
		if(i == 0) {
			//if first character is not a number, + or - then it cannot be scientific
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0' && character != '+' && character != '-') {
				return false;
			}
		}
		//if it is not the first character
		else {
			//if the following characters after the first one is not a number, a decimal point, a E, or a - then it cannot be scientific
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0' && character != '.' && character != 'E' && character != '-') {
				return false;
			}
		}
	}
	
	//for loop starting from 1 after E's location. If anything after E (excluding the first character after E as it can be -) is not a number then it is not scientific
	for(int i = eLocation+1; i < length; i++) {
		//assigns a character from userInput to variable character
		character = userInput[i];

		//if this is the first character after E
		if(i == eLocation+1) {
			//if first character is not a number or - then it cannot be scientific. First character can not be 0 either
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '-') {
				return false;
			}
			//if first character is a - then check to see if the following character is a 0, if it is then it cannot be scientific
			else if(character == '-') {
				if(userInput[i+1] == '0') {
					return false;
				}
				//checks to see if - is last character
				if(i+1 == length) {
					return false;
				}
			}
		}
		//if it is not the first character
		else {
			//if the following characters after the first one is not a number then it cannot be scientific
			if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0') {
				return false;
			}
		}
	}
	return true;
}

//detects hexadecimals
bool detectHexadecimal(string userInput, int length) {
	//holds a character from userInput
	char character;
	
	//if last character is not an H then it cannot be a hexadecimals
	if(userInput[length-1] != 'H') {
		return false;
	}
	
	//if length is 1, only 1 character, then it cannot be a hexadecimal
	if(length == 1) {
		return false;
	}
	
	//for loop that goes through entire userInput. if a character is not A B C D E F or a number then it cannot be a hexadecimal
	for(int i = 0; i < length-1; i++) {
		//character is a character of userInput
		character = userInput[i];
		
		if(character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' 
			&& character != '9' && character != '0' && character != 'A' && character != 'B' && character != 'C' && character != 'D' && character != 'E' && character != 'F') {
				return false;
			}
	}
	return true;
}

//detects identifiers
bool detectIdentifier(string userInput, int length) {
	//if identifier is a hexadecimal then it cannot be an identifier
	if(detectHexadecimal(userInput, length) == true) {
		return false;
	}
	
	//if first character is not a letter then it cannot be an identifier
	if(isalpha(userInput[0]) == false) {
		return false;
	}
	
	//checks the rest of the string, if a character is not a letter, number, or _ then it cannot be an identifier
	for(int i = 0; i < length; i++) {
		if(isalpha(userInput[i]) == false && isdigit(userInput[i]) == false && userInput[i] != '_') {
			return false;
		}
	}
	
	return true;
}

//detects email
bool detectEmail(string userInput, int length) {
	//variable to hold amount of . found
	int periodFound = 0;
	//variable to hold amount of @ found
	int atFound = 0;
	//string variable to hold subsections of userInput
	string subSec = "";
	//length of subSec
	int subSecLength;
	
	for(int i = 0; i < length; i++) {
		if(userInput[i] == '.') {
			periodFound++;
		}
		if(userInput[i] == '@') {
			atFound++;
		}
	}
	
	//if no periods are found then it cannot be an email
	//if 0, or more then 1 @ is found then it cannot be an email
	if(periodFound == 0 || atFound == 0 || atFound > 1) {
		cout<<"boo1"<<endl;
		return false;
	}
	
	//if the ending of userInput is not.com .edu or .net then it cannot be an email
	if(userInput.substr(length-4, 4) != ".com" && userInput.substr(length-4, 4) != ".edu" && userInput.substr(length-4, 4) != ".net") {
		cout<<"boo2"<<endl;
		return false;
	}
	
	//loops through entire userInput length
	for(int i = 0; i < length-3; i++) {
		//if a . or @ is found test subSec to see if it is an identifier
		if(userInput[i] == '.' || userInput[i] == '@') {
			subSecLength = subSec.length();
			//test subsec to determine if it is an ideentifier or not
			if(detectIdentifier(subSec, subSecLength) == false) {
				return false;
			}
			//reset subsec
			subSec = "";
		}
		//if neither a . or @ is found, add character to subSec
		else {
			subSec += userInput[i];
		}
	}
	return true;
}