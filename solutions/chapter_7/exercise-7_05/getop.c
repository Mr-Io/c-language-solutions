#include "getop.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getkey(char s[]);

int getop(char s[], double *num)
{
	int c;
	// capture 1st char, if EOF or enter -> return
	if ((c = getchar()) == '\n') {
		s = "\n";
		return getkey(s);
	}
	else if (c == EOF) {
		return EOF;
	}
	else {
		ungetc(c, stdin);
	}
	// get string
	scanf("%s", s);
	// check if it is a number
	if (sscanf(s, "%lf", num)==1)
		return NUMBER;
	// if not, get the key
	return getkey(s);
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