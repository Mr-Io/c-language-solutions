#include "getop.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getkey(char s[]);

int getop(char s[])
{
	int digit = FALSE;
	// recover last character not used
	static int c = ' ';
	s[0] = c;
	//trailing blank lines
	while(s[0] == ' ' || s[0] == '\t')
		s[0]=getchar();
	s[1] = '\0';
	// EOF
	if (s[0] == EOF)
		return EOF;
	//operators: *, /, \n, ^ ...
	if (!isalnum(s[0]) && s[0]!='-' && s[0]!='+') {
		c = ' ';
		return getkey(s);
	}
	// comand operators: swap, clear, print...
	int i=0;
	if (isalpha(s[i])) {
		while (isalpha(s[i])) 
			s[++i] = getchar();
		c = s[i];
		s[i] = '\0';
		return getkey(s);
	}
	//capture the sign or the + - operator
	if (s[0] == '-' || s[0] == '+')
		s[++i] = getchar();
	//get all digits before '.'
	if (isdigit(s[i])) {
		digit = TRUE;
		while (isdigit(s[i]))
			s[++i] = getchar();
	}
	// get all digits after .
	if (s[i] == '.') {
		s[++i] = getchar();
		if (isdigit(s[i])) {
			digit = TRUE;
			while (isdigit(s[i])) 
				s[++i] = getchar();
		}
	}
	// return it.
	c = s[i];
	s[i] = '\0';
	if (digit == TRUE) {
		return NUMBER;
	}
	else {
		return getkey(s);
	}
}


int getkey(char s[]) 
{
	if (!strcmp(s, "\n")) {
		return ENTER;
	}
	else if (!strcmp(s, "_")) {
		return LASTVALUE;
	}
	else if (!strcmp(s,"+")) {
		return SUM;
	}
	else if(!strcmp(s, "*")){
		return MULT;
	}
	else if(!strcmp(s, "-")){
		return MINUS;
	}
	else if(!strcmp(s, "/")){
		return DIV;
	}
	else if(!strcmp(s, "%")){
		return MOD;
	}
	else if(!strcmp(s, "print")){
		return PRINT;
	}
	else if(!strcmp(s, "dupl")){
		return DUPLICATE;
	}
	else if(!strcmp(s, "swap")){
		return SWAP;
	}
	else if(!strcmp(s, "clear")){
		return CLEAR;
	}
	else if(!strcmp(s, "sin")){
		return SIN;
	}
	else if(!strcmp(s, "exp")){
		return EXP;
	}
	else if(!strcmp(s, "^")){
		return POW;
	}
	else if (strlen(s)==1 && isalpha(s[0])){
		return VARIABLE;
	}
	else {
		return OTHER;
	}
}