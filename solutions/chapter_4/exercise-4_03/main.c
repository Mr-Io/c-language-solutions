#include <stdio.h>
#include <stdlib.h>

#define MAXOP 32
#define NUMBER '0' 
#define ERROR '!'

int getop(char s[], int n);
void push(double x);
double pop(void);

/* reverse Polish calculator */
int main() 
{
	int type;
	char s[MAXOP];
	char s2[10];
	double op2;
	int iop2;
	while ((type = getop(s, MAXOP)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0){
				push(pop() / op2);
			}else{
				printf("error: division by 0\n");
			}
			break;
		case '%':
			iop2 = (int) pop();
			if (iop2 != 0){
				push((int)pop() % iop2);
			}else{
				printf("error: division by 0\n");
			}
			break;
		case '\n':
			printf("%lf\n", pop());
			break;
		case ERROR:
			printf("Input ignored. Too long.\n");
			break;
		default:
			printf("error: Invalid token '%c'\n", type);
			break;
		}
	}
}

/* PUSH-POP */
#define MAXSTACK 16
double stack[MAXSTACK];
int istack=0; /* next free position of the stack */

double pop()
{
	if (istack > 0){
		return stack[--istack];
	}else{
		printf("error: stack empty\n");
	}
	return 0;
}

void push(double x)
{
	if (istack < MAXSTACK){
		stack[istack++] = x;
	}else{
		printf("error: stack full, cant push %lf\n", x);
	}
}

//GETOP
#include <ctype.h>

int getch(void);
void ungetch(int c);

int getop(char s[], int n)
{
	/* remove trailing blank lines and make it 1 char long */
	while(isblank(s[0] = getch()));
	s[1] = '\0';
	/* return character if not a number */ 
	if (!isdigit(s[0]) && s[0] != '.' && s[0] != '+' && s[0] != '-'){
		return s[0];
	}
	/* get all digits before '.' */
	char c;
	int i = 1;
	do{
		c = getch();
		if (i < n){
			s[i] = c;
		}
		++i;
	}while (isdigit(c));
	/* get all digits after '.' */
	if (s[i] == '.') {
		do{
			c = getch();
			if (i < n){
				s[i] = c;
			}
			++i;
		}while (isdigit(c));
	}
	/* ungetch the last character (not a digit) */
	ungetch(c);
	s[i < n ? i : n-1] = '\0';
	/* check for too long string */
	if (i > n){
		return ERROR;
	}
	/* check if it was just the '-' or '+' operators */
	if ((s[0] == '-' || s[0] == '+') && s[1] == '\0'){
		return s[0];
	}
	return NUMBER;
}


//READ WITH BUFFER
#define BUFSIZE 16
int buff[BUFSIZE];
int ibuf = 0;	// next free position in buff

int getch(void) 
{
	return (ibuf > 0) ? buff[--ibuf] : getchar();
}

void ungetch(int c) 
{
	if (ibuf >= BUFSIZE) {
		printf("ungetch: too many characters \n");
	}else{
		buff[ibuf++] = c;
	}
}