#ifndef GETOP_FILE
#define GETOP_FILE

enum boolean{FALSE, TRUE};
enum types{ENTER, SUM, MULT, MINUS, DIV, MOD, NUMBER, PRINT, DUPLICATE, SWAP, CLEAR, 
	SIN, EXP, POW, VARIABLE, LASTVALUE, OTHER};
int getop(const char s[]);

#endif
