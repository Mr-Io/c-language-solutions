#include "getop.h"
#include <ctype.h>
#include <string.h>

int getop(const char s[]) 
{
	// CHECK NUMBER 
	int	i = 0;
	int digit = 0;
	//capture the sign or the + - operator
	if ((s[0] == '-' || s[0] == '+') && isdigit(s[1]))
		++i;
	//get all digits before '.'
	if (isdigit(s[i])) {
		digit = 1;
		while (isdigit(s[i++]));
	}
	// get all digits after .
	if (s[i] == '.' && isdigit(s[++i])) {
		digit = 1;
		while (isdigit(s[i++]));
	}
	if (digit == 1)
		return NUMBER;
	// CHECK OTHER KEYS;
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
