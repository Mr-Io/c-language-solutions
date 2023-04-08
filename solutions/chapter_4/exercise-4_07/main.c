#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100

enum boolean{FALSE, TRUE};
enum types{ENTER, SUM, MULT, MINUS, DIV, MOD, NUMBER, PRINT, DUPLICATE, SWAP, CLEAR, 
	SIN, EXP, POW, VARIABLE, LASTVALUE, OTHER};

int getop(char s[]);

int getch(void);
void ungetch(int c);
void ungets(char s[]);

double pop(void);
void push(double x);
void clearstack(void);

int isvar[27];
double var[27];

int main() 
{
	int c;
	int ivar;
	char s[MAXOP];
	double op2, op1;
	int iop2;
	while ((c = getop(s)) != EOF) {
		switch (c) {
		case ENTER:
			isvar[26] = 1;
			printf("%lf\n\n", var[26]=pop());
			break;
		case NUMBER:
			push(atof(s));
			break;
		case SUM:
			push(pop() + pop());
			break;
		case MULT:
			push(pop() * pop());
			break;
		case MINUS:
			op2 = pop();
			push(pop() - op2);
			break;
		case DIV:
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else{
				printf("error: division by 0\n");
				return 0;
			}
			break;
		case MOD:
			iop2 = (int) pop();
			if (iop2 != 0)
				push((int)pop() % iop2);
			else{
				printf("error: division by 0\n");
				return 0;
			}
			break;
		case PRINT:	// print value without deleting it from the stack
			printf("%lf\n", op2=pop());
			push(op2);
			break;
		case DUPLICATE:  // duplicate last values from the stack;
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case SWAP:  // swap last 2 values from the stack;
			op2 = pop();
			op1 = pop();
			push(op2);
			push(op1);
			break;
		case CLEAR:	// clear stack
			clearstack();
			break;
		case SIN:
			push(sin(pop()));
			break;
		case EXP:
			push(exp(pop()));
			break;
		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case VARIABLE:
			ivar = s[0] - 'a';
			if (isvar[ivar])
				push(var[ivar]);
			else {
				isvar[ivar] = 1;
				var[ivar] = pop();
			}
			break;
		case LASTVALUE:
			if (isvar[26])
				push(var[26]);
			else{
				printf("error: there are no previous values\n");
				return 0;
			}
			break;
		case OTHER: default: 
			printf("error: Invalid token '%s'\n", s);
			return 0;
			break;
		}
	}
	return 0;
}

//READ WITH BUFFER
#include <ctype.h>
#define BUFSIZE 10
int buff[BUFSIZE];
int ibuf = 0;	// next free position in buff

int getch() 
{
	return (ibuf > 0) ? buff[--ibuf] : tolower(getchar());
}

void ungetch(int c) 
{

	if (ibuf >= BUFSIZE) {
		printf("warning: no more space in buffer for '%c'\n", c);
	}
	else {
		buff[ibuf++] = c;
	}
}

void ungets(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		ungetch(s[i]);
}

//GETOP
#include <ctype.h>
#include <string.h>
int getkey(char s[]);

int getop(char s[])
{
	int digit = FALSE;
	//trailing blank lines
	while((s[0] = getch()) == ' ' || s[0] == '\t');
	s[1] = '\0';
	// EOF
	if (s[0] == EOF)
		return EOF;
	//operators: *, /, \n, ^ ...
	if (!isalnum(s[0]) && s[0]!='-' && s[0]!='+') {
		return getkey(s);
	}
	// comand operators: swap, clear, print...
	int i=0;
	if (isalpha(s[i])) {
		while (isalpha(s[i])) 
			s[++i] = getch();
		ungetch(s[i]);
		s[i] = '\0';
		return getkey(s);
	}
	//capture the sign or the + - operator
	if (s[0] == '-' || s[0] == '+')
		s[++i] = getch();
	//get all digits before '.'
	if (isdigit(s[i])) {
		digit = TRUE;
		while (isdigit(s[i]))
			s[++i] = getch();
	}
	// get all digits after .
	if (s[i] == '.') {
		s[++i] = getch();
		if (isdigit(s[i])) {
			digit = TRUE;
			while (isdigit(s[i])) 
				s[++i] = getch();
		}
	}
	// return it.
	ungetch(s[i]);
	s[i] = '\0';
	if (digit == TRUE) {
		return NUMBER;
	}
	else {
		return getkey(s);
	}
}


int getkey(char s[]) {
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

//PUSH-POP
#define MAXSTACK 100
double stack[MAXSTACK];
int istack=0;			// next free position of the stack 

double pop()
{
	if (istack > 0)
		return stack[--istack];
	else
		printf("warning: stack empty \n");
	return 0;
}

void push(double x)
{
	if (istack < MAXSTACK)
		stack[istack++] = x;
	else
		printf("warning: no more space in stack for value %lf\n", x);
}

void clearstack()
{
	istack = 0;
}
