#include <stdio.h>
#include <stdlib.h>


#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);

int getch(void);
void ungetch(int c);

double pop(void);
void push(double x);

int main() 
{
	int c;
	char s[MAXOP];
	double op2;
	int iop2;
	while ((c = getop(s)) != EOF) {
		switch (c) {
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
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: division by 0\n");
			break;
		case '%':
			iop2 = (int) pop();
			if (iop2 != 0)
				push((int)pop() % iop2);
			else
				printf("error: division by 0\n");
			break;
		case '\n':
			printf("%lf\n", pop());
			break;
		default:
			printf("error: Invalid token '%c'\n", c);
			break;
		}
	}
}

//READ WITH BUFFER
#define BUFSIZE 100
int buff[100];
int ibuf = 0;	// next free position in buff

int getch() 
{
	return (ibuf > 0) ? buff[--ibuf] : getchar();
}

void ungetch(int c) 
{
	if (ibuf >= BUFSIZE) {
		printf("error: no more space in buffer\n");
	}
	else {
		buff[ibuf++] = c;
	}
}

//GETOP
#include <ctype.h>

int getop(char s[])
{
	//trailing blank lines
	while((s[0] = getch()) == ' ' || s[0] == '\t');
	s[1] = '\0';
	// no numbers
	if (!isdigit(s[0]) && s[0] != '.' && s[0] != '+' && s[0] != '-')
		return s[0];
	//capture the sign or return the plus or minus symbol
	int i=0;
	if (s[0] == '-' || s[0] == '+')
		s[++i] = getchar();
	//get all digits before '.'
	while (isdigit(s[i]))
		s[++i] = getch();
	// get all digits after .
	if (s[i] == '.') {
		s[++i] = getch();
		while (isdigit(s[i]))
			s[++i] = getch();
	}
	// return it.
	ungetch(s[i]);
	s[i] = '\0';
	if ((s[0] == '-' || s[0] == '+') && s[1] == '\0')
		return s[0];
	else
		return NUMBER;
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
		printf("error: stack empty\n");
	return 0;
}

void push(double x)
{
	if (istack < MAXSTACK)
		stack[istack++] = x;
	else
		printf("error: full stack for value %lf\n", x);
}
