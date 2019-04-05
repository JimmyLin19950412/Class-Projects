//Name: Jimmy Lin
//Student ID: 12434423
//Date: 12/01/17
//Class: CS3600

#include<iostream>
#include<gmp.h>
#include<fstream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

//compile using g++ file.cpp -o fileName -lgmp

using namespace std;

main()
{
	//holds bit size. User provides
	int bitSize;
	//holds the number generated from urandomb
	mpz_t generatedNum;
	//holds p, a prime number
	mpz_t p;
	//holds temp p when subtracting 1 for totient
	mpz_t tmpp;
	//holds q, a prime number 
	mpz_t q;
	//holds temp q when subtracting 1 for totient
	mpz_t tmpq;
	//holds N for public and private key. N = p * q
	mpz_t N;
	//holds the totient of N. Were totient = (p-1)(q-1)
	mpz_t totient;
	//holds e for public key
	mpz_t e;
	//holds d for private key
	mpz_t d;
	//holds c for ciphertext
	mpz_t c;
	//holds m for plaintext
	mpz_t m;
	//holds temporary number
	mpz_t tmp;
	//holds tmp pointer string
	char tmpStr[8100];
	//holds the plain text from inxFile
	char plainText[8100];
	//holds cipher text from file
	char cipherText[8100];
	//holds text to be decrypted
	//holds int for counting in while loop
	int counter = 0;
	//holds message as a hex number
	string messageAsHex = "";
	//holds temporary string values
	char tmpString[10];
	//holds name of files. User provides
	string userInput;
	
	//allocate all mpz_t
	mpz_init(generatedNum);
	mpz_init(p);
	mpz_init(tmpp);
	mpz_init(q);
	mpz_init(tmpq);
	mpz_init(N);
	mpz_init(totient);
	mpz_init(e);
	mpz_init(d);
	mpz_init(c);
	mpz_init(m);
	mpz_init(tmp);
	
	//asking for K value
	cout<<"Enter the bit size: "<<endl;
	cin>>bitSize;

	//contains random number
	gmp_randstate_t RNG;
	gmp_randinit_mt(RNG);
	//set initial seed value into RNG
	gmp_randseed_ui(RNG, time(NULL));
	do {
		//generates a random number of length bitSize/2 and places it into generatedNum using RNG as seed
		mpz_urandomb(generatedNum, RNG, bitSize/2);
		
		//generates a the next prime number after generated num and places it into p
		mpz_nextprime(p, generatedNum);
		
		//generates a random number of length bitSize/2 and places it into generatedNum using RNG as seed
		mpz_urandomb(generatedNum, RNG, bitSize/2);
		
		//generates a the next prime number after generated num and places it into q
		mpz_nextprime(q, generatedNum);
		
		//multiples p and q together and places it into N
		mpz_mul(N, p, q);
	}
	//compares the bit length of n to bitSize, if not the same then regenerate p and q to get new N
	while(bitSize != mpz_sizeinbase(N, 2));
	
	//subtracts 1 from both p and q-1
	mpz_sub_ui(tmpp, p, 1);
	mpz_sub_ui(tmpq, q, 1);
	//computes the totient
	mpz_lcm(totient, tmpp, tmpq);
	
	//generates a random e
	do {
		//generates random number between 0 and totient, places it into e
		mpz_urandomm(e, RNG, totient);
		//gets the gcd of e and totient, places it into tmp
		mpz_gcd(tmp, e, totient);
	}
	//compares e and totient, if they are the same then 0
	while(mpz_cmp_ui(tmp, 1) != 0);
	
	//generates a d from e and totient
	mpz_invert(d, e, totient);
	
	//asking user for the name of the public key output file to save to
	cout<<"Enter the name of the public key output file to save: "<<endl;
	cin>>userInput;
	
	//initializes output file to place N and e
	ofstream neFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(neFile.is_open()) {
		//writes to file
		//converts N to a string
		mpz_get_str(tmpStr, 10, N);
		neFile<<tmpStr<<"\n";
		//converts e to a string
		mpz_get_str(tmpStr, 10, e);
		neFile<<tmpStr;
		//closes file
		neFile.close();
	}
	//file could not be opened
	else {
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}
	
	//asking user for the name of the private key output file to save to
	cout<<"Enter the name of the private key output file to save: "<<endl;
	cin>>userInput;
	
	//initializes output file to place N and d
	ofstream ndFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(ndFile.is_open()) {
		//writes to file
		//converts N to a string
		mpz_get_str(tmpStr, 10, N);
		ndFile<<tmpStr<<"\n";
		//converts d to a string
		mpz_get_str(tmpStr, 10, d);
		ndFile<<tmpStr;
		//closes file
		ndFile.close();
	}
	//file could not be opened
	else{
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}

	//asking user for the name of the file to output p and q to
	cout<<"Enter the name of the p q output file to save: "<<endl;
	cin>>userInput;
	
	//intializes output file to place p and q
	ofstream pqFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(pqFile.is_open()) {
		//converts p to a string
		mpz_get_str(tmpStr, 10, p);
		pqFile<<tmpStr<<"\n";
		//converts q to a string
		mpz_get_str(tmpStr, 10, q);
		pqFile<<tmpStr;
		//closes file
		pqFile.close();
	}
	//file could not be opened 
	else {
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}
	
	//asking user for the file that contains x to be encrypted using (N, e)
	cout<<"Enter the name of the file that contains x to be encrypted using (N,e): "<<endl;
	cin>>userInput;
	
	//initializes input file containing message x
	ifstream xFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(xFile.is_open()) {
		//reads from file character by character
		while(xFile.get(plainText[counter])) {
			//converts the character at plainText[counter] to a number
			sprintf(tmpString, "%x", plainText[counter]);
			//counter ++ to keep track of how many elements are in plainText character array
			counter++;
			//adds the number converted to messageAsHex
			messageAsHex = messageAsHex + tmpString;
		}
		//converts messageAsHex into a mpz_t value
		mpz_set_str(tmp, messageAsHex.c_str(), 16);
		//closes file
		xFile.close();
	}
	//file could not be openened
	else {
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}
	
	//asking user for the name of the file to output E(x) to
	cout<<"Enter the output file name to store E(x), which is c: "<<endl;
	cin>>userInput;
	
	//initialize output file containing E(x)
	ofstream exFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(exFile.is_open()) {
		//(tmp^e) mod N and store it into c
		mpz_powm(c, tmp, e, N);
		//converts tmp to a string
		mpz_get_str(tmpStr, 16, c);
		//converts char arraay tmpStr to string and places it into str
		string str(tmpStr);
		//holds length of str
		int length = str.length();
		//holds cracked text
		string crackedText = "";
		//for loop that loops through str and converts hex to ASCII
		for(int i = 0; i < length; i+=2) {
			string byte = str.substr(i,2);
			char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
			crackedText.push_back(chr);
		}
		exFile<<crackedText;
		//closes file
		exFile.close();
	}
	//file is not open
	else{
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}
	
	//asking user for the name of private key file to import
	cout<<"Enter the name of the private key file to import: "<<endl;
	cin>>userInput;
	
	//initializes input file containing private key to import
	ifstream inputKeyFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(inputKeyFile.is_open()) {
		//gets the first line from file, should be N
		getline(inputKeyFile, userInput);
		mpz_set_str(N, userInput.c_str(), 10);
		//gets the second line from file, should be d
		getline(inputKeyFile, userInput);
		mpz_set_str(d, userInput.c_str(), 10);
		//closes file
		inputKeyFile.close();
	}
	//if file is not open
	else {
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}
	
	//asking user for the name of file that contains c to be decrypted using d
	cout<<"Enter the name of the file that contains c to be decrypted using d: "<<endl;
	cin>>userInput;
	
	//initializes input file containing c to be decrypted using d
	ifstream inputCFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(inputCFile.is_open()) {
		//resets counter
		counter = 0;
		//resets messageAsHex
		messageAsHex = "";
		while(inputCFile.get(cipherText[counter])) {
			//converts the character at cipherText[counter] to a number
			sprintf(tmpString, "%x", cipherText[counter]);
			//counter ++ to keep track of how many elements are in cipherText character array
			counter++;
			//adds the number converted to messageAsHex
			messageAsHex = messageAsHex + tmpString;
		}
		//converts messageAsHex into a mpz_t value
		mpz_set_str(tmp, messageAsHex.c_str(), 16);
		//closes file
		inputCFile.close();
	}
	//if file is not open
	else {
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}
	
	//asking user for the name of file to output D(c)
	cout<<"Enter the output file name to store D(c): "<<endl;
	cin>>userInput;
	
	//initializes input file containing c to be decrypted using d
	ofstream outputDFile((userInput+".txt").c_str());
	//checks to see if file is open
	if(outputDFile.is_open()) {
		//(tmp^d) mod n and store it into m
		mpz_powm(m, tmp, d, N);
		//converts m to a hex string and places into tmpStr
		mpz_get_str(tmpStr, 16, m);
		//converts char arraay tmpStr to string and places it into str
		string str(tmpStr);
		//holds length of str
		int length = str.length();
		//holds cracked text
		string crackedText = "";
		//for loop that loops through str and converts hex to ASCII
		for(int i = 0; i < length; i+=2) {
			string byte = str.substr(i,2);
			char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
			crackedText.push_back(chr);
		}
		//cout<<crackedText<<endl;
		outputDFile<<crackedText;
		//closes file
		outputDFile.close();
	}
	//if file is not open
	else {
		cout<<"Unable to open file "<<userInput<<endl;
		return 0;
	}

	return 0;	
}