//Jimmy Lin
//hw3 section b

#include <iostream>
#include <string>
#include <vector>
using namespace std;


//fuinction prototype
string getToken(vector<string> &input, int &pos);
bool expression(string token, vector<string> &input, int &pos);
bool simpleExpression(string token, vector<string> &input, int &pos);
bool term(string token, vector<string> &input, int &pos);
bool factor(string token, vector<string> &input, int &pos);
bool assignment(string token, vector<string> &input, int &pos);
bool printStatement(string token, vector<string> &input, int &pos);
bool retStatement(string token, vector<string> &input, int &pos);
bool ifStatement(string token, vector<string> &input, int &pos);
bool loopStatement(string token, vector<string> &input, int &pos);
bool statement(string token, vector<string> &input, int &pos);
bool statementSequence(string token, vector<string> &input, int &pos);
bool paramSequence(string token, vector<string> &input, int &pos);
bool functionDeclaration(string token, vector<string> &input, int &pos);
bool functionSequence(string token, vector<string> &input, int &pos);
bool isRelation(string token);
bool isAddOperator(string token);
bool isMulOperator(string token);
bool isInteger(string token);
bool isDecimal(string token);
bool isString(string token);
bool isKeyword(string token);
bool isIdentifier(string token);

int main()
{
	//holds user input
	string userInput;
	//holds number of characters in user input
	int numInput = 1;
	//holds number of position in array token is at
	int pos = 0;
	//creating a vector to hold user input
	vector<string> input;
	//holds token
	string token;
	
	//gets user input
	while(cin>>userInput) {
		//ressize array and assigns user input to that position
		input.resize(numInput++, userInput);
	}
	
	//gets token
	token = getToken(input, pos);
	
	//start of test
	if(functionSequence(token, input, pos) == true) {
		cout<<"CORRECT"<<endl;
	}
	else {
		cout<<"INVALID!"<<endl;
	}

	return 0;
}

//returns a token to be tested
string getToken(vector<string> &input, int &pos)
{
	pos++;
	return input[pos-1];
}

//determines if token is a relation
bool isRelation(string token)
{
	//if relation is < > - #
	if(token == "<" || token == ">" || token == "-" || token == "#") {
		return true;
	}
	return false;
}

//determins if token is an add operator
bool isAddOperator(string token)
{
	//if relation is + - OR &
	if(token == "+" || token == " -" || token == "OR" || token == "&") {
		return true;
	}
	return false;
}

//determine token is a mul operator
bool isMulOperator(string token) 
{
	//if relation is * / AND
	if(token == "*" || token == " /" || token == "AND") {
		return true;
	}
	return false;
}

//determine if token is an integer
bool isInteger(string token) {
	//holds variable for for loop count
	int i = 0;
	
	//if first char in token is a + or - increase position of for loop by 1
	if(token[i] == '+' || token[i] == '-') {
		i++;
	}
	
	//for loop poisition is 0 if first char is not + or -. otherwise starts at 1
	for( ; i < token.length() - 1; i++) {
		if(isdigit(token[i]) == false) {
			return false;
		}
	}
	return true;
}

//determine if token is decimal
bool isDecimal(string token)
{
	//if decimal is found
	int foundDecimal = false;
	//holds number of decimals found
	int decimalsFound = 0;
	
	//if last char in token is a . then it cant be a decimal
	if(token[token.length()-1] == '.') {
		return false;
	}
	
	//parses entire string
	for(int i = 0; i < token.length() - 1; i++) {
		//if decimal is found
		if(token[i] == '.') {
			foundDecimal = true;
			decimalsFound++;
			//if more then 1 decimal is found then it cant be a decimal number
			if(decimalsFound > 1) {
				return false;
			}
		}
		//if a non digit is found then it cant be a decimal number
		else if(isdigit(token[i]) == false) {
			return false;
		}
	}
	//if decimal is not found then it cant be a decimal number
	if(foundDecimal == false) {
		return false;
	}
	
	return true;
}

//determinee if token is a string
bool isString(string token)
{
	//if first char in token is not a quote, cant be a string
	if(token[0] != '"') {
		return false;
	}
	//if last char in token is not a quote, cant be a string
	if(token[token.length()-1] != '"') {
		return false;
	}
	
	//parses string for spaces
	for(int i = 0; i < token.length() - 1; i++) {
		//if a space is found then it cant be a string
		if(token[i] == ' ') {
			return false;
		}
	}
	
	return true;
}

//determine if token is a keyword
bool isKeyword(string token)
{
	if(token == ":=") {
		return true;
	}
	else if(token == "+") {
		return true;
	}
	else if(token == "-") {
		return true;
	}
	else if(token == "*") {
		return true;
	}
	else if(token == "/") {
		return true;
	}
	else if(token == "OR") {
		return true;
	}
	else if(token == "AND") {
		return true;
	}
	else if(token == "~") {
		return true;
	}
	else if(token == "(") {
		return true;
	}
	else if(token == ")") {
		return true;
	}
	else if(token == "<") {
		return true;
	}
	else if(token == ">") {
		return true;
	}
	else if(token == "=") {
		return true;
	}
	else if(token == "#") {
		return true;
	}
	else if(token == "&") {
		return true;
	}
	else if(token == "!") {
		return true;
	}
	else if(token == "PRINT") {
		return true;
	}
	else if(token == "IF") {
		return true;
	}
	else if(token == "ELSE") {
		return true;
	}
	else if(token == "FI") {
		return true;
	}
	else if(token == "LOOP") {
		return true;
	}
	else if(token == "POOL") {
		return true;
	}
	else if(token == "FUNC") {
		return true;
	}
	else if(token == "RET") {
		return true;
	}
	else if(token == "BEGIN") {
		return true;
	}
	else if(token == "END.") {
		return true;
	}
	
	return false;
}

//determine if identifier is found
bool isIdentifier(string token)
{
	//if token is a keyword then it cant be an identifier
	if(isKeyword(token) == true) {
		return false;
	}
	
	//if first char is a digit then it cant be an identifier
	if(isdigit(token[0]) == true) {
		return false;
	}

	return true;
}

//parse input to see if it is an expression
bool expression(string token, vector<string> &input, int &pos)
{
	//holds token obtained in expression
	string tokenExpression;
	
	//parses token for simple expression
	if(simpleExpression(token, input, pos) == true) {
		//gets a new token to test for relation
		tokenExpression = getToken(input, pos);
		//optional relation simpleExpression
		if(isRelation(tokenExpression) == true) {
			//gets a new token
			tokenExpression = getToken(input, pos);
			if(simpleExpression(tokenExpression, input, pos) == true) {
				return true;
			}
			else {
				return false;
			}
		}
		//token is not an add operator need to move back to previous token
		else {
			pos--;
		}
		return true;
	}
	
	return false;
}

//parse input to see if its a simple expression
bool simpleExpression(string token, vector<string> &input, int &pos)
{
	//holds token obtained in simple expression
	string tokenSimpleExpression;

	//parses token for term
	if(term(token, input, pos) == true) {
		//gets token
		tokenSimpleExpression = getToken(input, pos);
		//if token add operator
		if(isAddOperator(tokenSimpleExpression) == true) {
			//while token is an add operator
			while(isAddOperator(tokenSimpleExpression) == true) {
				//gets new token
				tokenSimpleExpression = getToken(input, pos);
				//if next token is not a term
				if(term(tokenSimpleExpression, input, pos) == false) {
					return false;
				}
				//gets new token to determine if its an add operator
				tokenSimpleExpression = getToken(input, pos);
			}
			pos--;
		}
		//token is not an add operator need to move back to previous token
		else {
			pos--;
		}
		return true;
	}
	
	return false;
}

//parse input to see if its a term
bool term(string token, vector<string> &input, int &pos)
{
	
	//holds token obtained in term
	string tokenTerm;
	
	//parse token for factor
	if(factor(token, input, pos) == true) {
		//gets token
		tokenTerm = getToken(input, pos);
		//if token mul operator
		if(isMulOperator(tokenTerm) == true) {
			//while token is a mul operator
			while(isMulOperator(tokenTerm) == true) {
				//gets new token
				tokenTerm = getToken(input, pos);
				//if next token is not a factor
				if(factor(tokenTerm, input, pos) == false) {
					return false;
				}
				//gets new token to determine if its an add operator
				tokenTerm = getToken(input, pos);
			}
			pos--;
		}
		//token is not a mul operator need to move back to previous token
		else {
			pos--;
		}
		return true;
	}
	
	return false;
}

//parse input to see if its a factor
bool factor(string token, vector<string> &input, int &pos)
{
	//holds token obtained in factor
	string tokenFactor;
	
	if(isInteger(token) == true) {
		return true;
	}
	if(isDecimal(token) == true) {
		return true;
	}
	if(isString(token) == true) {
		return true;
	}
	if(isIdentifier(token) == true) {
		return true;
	}
	if(token == "(") {
		//gets token to parse for expression
		tokenFactor = getToken(input, pos);
		if(expression(tokenFactor, input, pos) == false) {
			return false;
		}
		//gets next token to parse of for )
		tokenFactor = getToken(input, pos);
		if(tokenFactor == ")") {
			return true;
		}
		else {
			return false;
		}
	}
	if(token == "~") {
		//gets new token to parse factor
		tokenFactor = getToken(input, pos);
		if(factor(tokenFactor, input, pos) == true) {
			return true;
		}
	}
	return false;
}

//determine if token is an assignment
bool assignment(string token, vector<string> &input, int &pos)
{
	//holds token obtained in assignment
	string tokenAssignment;
	
	//parses token for identifier
	if(isIdentifier(token) == true) {
		//get new token to test for :=
		tokenAssignment = getToken(input, pos);
		if(tokenAssignment == ":=") {
			//get new token to test for expression
			tokenAssignment = getToken(input, pos);
			if(expression(tokenAssignment, input, pos) == true) {
				//get new token to test for !
				tokenAssignment = getToken(input, pos);
				if(tokenAssignment == "!") {
					return true;
				}
			}
		}
	}
	
	return false;
}

//determine if token is a print statement
bool printStatement(string token, vector<string> &input, int &pos)
{
	//holds token obtained in printStatement
	string tokenPrintStatement;
	
	//if token is PRINT
	if(token == "PRINT") {
		//get new token to test for (
		tokenPrintStatement = getToken(input, pos);
		if(tokenPrintStatement == "(") {
			//get new token to test for expression
			tokenPrintStatement = getToken(input, pos);
			if(expression(tokenPrintStatement, input, pos) == true) {
				//get new token to test for )
				tokenPrintStatement = getToken(input, pos);
				if(tokenPrintStatement == ")") {
					//get new token to test for !
					tokenPrintStatement = getToken(input, pos);
					if(tokenPrintStatement == "!") {
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

//determine if token s a retStatement
bool retStatement(string token, vector<string> &input, int &pos) 
{
	//holds token for retStatement
	string tokenRetStatement;
	
	if(token == "RET") {
		//get new token to test for identifier
		tokenRetStatement = getToken(input, pos);
		if(isIdentifier(tokenRetStatement) == true) {
			//get new token to test for !
			tokenRetStatement = getToken(input, pos);
			if(tokenRetStatement == "!") {
				return true;
			}
		}
	}
	
	return false;
}

//determine if tokne is a if statement
bool ifStatement(string token, vector<string> &input, int &pos)
{
	//stores token for ifStatement
	string tokenIfStatement;
	
	if(token == "IF") {
		//get new token to test for (
		tokenIfStatement = getToken(input, pos);
		if(tokenIfStatement == "(") {
			//get new token to test for expression
			tokenIfStatement = getToken(input, pos);
			if(expression(tokenIfStatement, input, pos) == true) {
				//get new token to test for )
				tokenIfStatement = getToken(input, pos);
				if(tokenIfStatement == ")") {
					//get new token for statement sequence
					tokenIfStatement = getToken(input, pos);
					if(statementSequence(tokenIfStatement, input, pos) == false) {
						return false;
					}
					//get new token to test for else
					tokenIfStatement = getToken(input, pos);
					if(tokenIfStatement == "ELSE") {
						//get new token to test for statement sequence
						tokenIfStatement = getToken(input, pos);
						if(statementSequence(tokenIfStatement, input, pos) == false) {
							return false;
						}
					}
					else {
						pos--;
					}
					//get new token to test for end of if
					tokenIfStatement = getToken(input, pos);
					if(tokenIfStatement == "FI") {
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

//determine if token is a loop statement
bool loopStatement(string token, vector<string> &input, int &pos)
{
	//stores token for loopStatement
	string tokenLoopStatement;
	
	if(token == "LOOP") {
		//get new token to test for (
		tokenLoopStatement = getToken(input, pos);
		if(tokenLoopStatement == "(") {
				//get new token to test for expression
				tokenLoopStatement = getToken(input, pos);
				if(expression(tokenLoopStatement, input, pos) == true) {
					//get new token to test for )
					tokenLoopStatement = getToken(input, pos);
					if(tokenLoopStatement == ")") {
						//get new token to test for statement sequence
						tokenLoopStatement = getToken(input, pos);
						if(statementSequence(tokenLoopStatement, input, pos) == false) {
							return false;
						}
						//get new token to test for end of loop
						tokenLoopStatement = getToken(input, pos);
						if(tokenLoopStatement == "POOL") {
							return true;
						}
					}
				}
		}
	}
	return false;
}

//determine if token is a statement
bool statement(string token, vector<string> &input, int &pos)
{
	if(assignment(token, input, pos) == true) {
		return true;
	}
	else if(printStatement(token, input, pos) == true) {
		return true;
	}
	else if(retStatement(token, input, pos) == true) {
		return true;
	}
	else if(ifStatement(token, input, pos) == true) {
		return true;
	}
	else if(loopStatement(token, input, pos) == true) {
		return true;
	}
	
	return false;
}

//determine if token is a statement sequence
bool statementSequence(string token, vector<string> &input, int &pos)
{
	//stores token for statementSequence
	string tokenStatementSequence;
	
	if(statement(token, input, pos) == true) {
		//get token to test for additional statements
		tokenStatementSequence = getToken(input, pos);
		while(statement(tokenStatementSequence, input, pos) == true) {
			//gets token to test for additional statement
			tokenStatementSequence = getToken(input, pos);
		}
		pos--;
		return true;
	}
	
	return false;
}

//determine if tokne is a param sequence
bool paramSequence(string token, vector<string> &input, int &pos)
{
	//stores token for paramSequence
	string tokenParamSequence;
	
	if(isIdentifier(token) == true) {
		//get token to test for , 
		tokenParamSequence = getToken(input, pos);
		while(tokenParamSequence == ".") {
			//get token to test for identifier
			tokenParamSequence = getToken(input, pos);
			if(isIdentifier(token) == false) {
				return false;
			}
			//get new token to test for , 
			tokenParamSequence = getToken(input, pos);
		}
		pos--;
		return true;
	}
	
	return false;
}

//determine if token is a fucntion delcaration
bool functionDeclaration(string token, vector<string> &input, int &pos)
{
	//stores token for functionDeclaration
	string tokenFunctionDeclaration;
	
	if(token == "FUNC") {
		//gets new token to test for identifer
		tokenFunctionDeclaration = getToken(input, pos);
		if(isIdentifier(tokenFunctionDeclaration) == true) {
			//gets new token to test for (
			tokenFunctionDeclaration = getToken(input, pos);
			if(tokenFunctionDeclaration == "(") {
				//gets new token to test for param sequence
				tokenFunctionDeclaration = getToken(input, pos);
				while(paramSequence(tokenFunctionDeclaration, input, pos) == true) {
					//gets new token to test for param sequence
					tokenFunctionDeclaration = getToken(input, pos);
				}
				pos--;
				//gets new token to test for )
				tokenFunctionDeclaration = getToken(input, pos);
				if(tokenFunctionDeclaration == ")") {
					//gets new token to test for begin
					tokenFunctionDeclaration = getToken(input, pos);
					if(tokenFunctionDeclaration == "BEGIN") {
						//gets new token to test for sttaement sequence
						tokenFunctionDeclaration = getToken(input, pos);
						if(statementSequence(tokenFunctionDeclaration, input, pos) == false) {
							return false;
						}
						//gets new token to test for END.
						tokenFunctionDeclaration = getToken(input, pos);
						if(tokenFunctionDeclaration == "END.") {
							return true;
						}
					}
				}
			}
		}
	}
	
	return false;
}

//determine if token is a function sequence
bool functionSequence(string token, vector<string> &input, int &pos)
{
	//stores token for function sequence
	string tokenFunctionSequence;
	
	if(functionDeclaration(token, input, pos) == true) {
		//gets new token to test for function declaration
		tokenFunctionSequence = getToken(input, pos);
		while(functionDeclaration(tokenFunctionSequence, input, pos) == true) {
			//gets new token to test for function declaration
			tokenFunctionSequence = getToken(input, pos);
		}
		return true;
	}
	
	return false;
}