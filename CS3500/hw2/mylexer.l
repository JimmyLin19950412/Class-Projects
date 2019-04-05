/* Jimmy Lin */
					   /* ---- PROLOGUE ---- */
%{
#include <iostream>
using namespace std;

int no_lines = 1;
int num = 0;
%}
		              /* ---- DEFINITIONS ---- */
%option noyywrap
DIGIT		[0-9]
SIGNS 		[+-]
HEXA		[ABCDEF]
UPLETTERS	[A-Z]
LOWLETTERS	[a-z]
IDENT		({UPLETTERS}|{LOWLETTERS})({UPLETTERS}|{DIGIT}|{LOWLETTERS})*
EMAILSUF	(.com|.edu|.net)
WHITESPACE	[ \t\r]

%%  		              /* ---- REGULAR EXPRESSIONS ---- */

[ \t]													;
\n														{ no_lines++; }
{SIGNS}?{DIGIT}+ 										{ cout << "#" << num << ": TOKEN: INTCONST	LEXME: " << yytext << endl; num++; }
{SIGNS}?{DIGIT}+\.{DIGIT}+								{ cout << "#" << num << ": TOKEN: DECCONST	LEXME: " << yytext << endl; num++; }
{SIGNS}?{DIGIT}+\.{DIGIT}+E[-]?[1-9]+					{ cout << "#" << num << ": TOKEN: SCICONST	LEXME: " << yytext <<endl; num++; }
({HEXA}|{DIGIT})+H										{ cout << "#" << num << ": TOKEN: HEXCONST	LEXME: " << yytext <<endl; num++; }
[01]+B													{ cout << "#" << num << ": TOKEN: BINCONST	LEXME: " << yytext <<endl; num++; }
({IDENT}.)+@({IDENT}.)+{EMAILSUF}						{ cout << "#" << num << ": TOKEN: EMCONST	LEXME: " << yytext <<endl; num++; }
(if|then|else|while|end|banana)							{ cout << "#" << num << ": TOKEN: KEYWORD	LEXME: " << yytext << endl; num++; }
{IDENT}													{ cout << "#" << num << ": TOKEN: IDENT	LEXME: " << yytext <<endl; num++; }
\"({DIGIT}|{UPLETTERS}|{LOWLETTERS}|{WHITESPACE})*\"	{ cout << "#" << num << ": TOKEN: STRCONST	LEXME: " << yytext <<endl; num++; }
[\+\-\*\/\<\>\&]										{ cout << "#" << num << ": TOKEN: OPERATOR	LEXME: " << yytext <<endl; num++; }
.														{ cout << "#" << num << ": TOKEN: ?		LEXME: " << yytext <<endl; num++; }
%.*														;

%%  		              /* ---- EPILOGUE ---- */

int main()
{
	int x = 0;
    yylex();
    cout << no_lines << " lines processed." <<endl;
    return 0;
	
}