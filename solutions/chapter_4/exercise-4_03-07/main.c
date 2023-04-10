#include "tokenizer.h"
#include "stack.h"
#include "variables.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 32

/* reverse Polish calculator */
int main() 
{
	int type;
	char s[MAXOP];
	double op1, op2;
	int iop2;
	char var;
	double vprinted;
	int mssg;

	mssg = 0;
	initvar();

	while ((type = gettoken(s, MAXOP)) != EOF) {
		switch (type) {
		case NUM:
			op1 = atof(s);
			if (push(op1) == -1){
				printf("error: full stack, can't push %f \n", op1);
				mssg = 1;
			}
			break;
		case VAR:
			var = s[0];
			if (hasvalue(var)){
				if (push(getvar(var)) == -1){
					printf("error: full stack, can't push %f \n", op1);
					mssg = 1;
				}
			}else{
				setvar(var, pop());
			}
			break;
		case '_':
			op1 = vprinted;
			if (push(op1) == -1){
				printf("error: full stack, can't push %f \n", op1);
				mssg = 1;
			}
			break;
		case '\n':
			if (!mssg){
				printvar();
				printstack();
			}else{
				mssg = 0;
			}
			printf("> ");
			vprinted = peek();
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
				mssg = 1;
			}
			break;
		case '%':
			iop2 = (int) pop();
			if (iop2 != 0){
				push((int)pop() % iop2);
			}else{
				printf("error: division by 0\n");
				mssg = 1;
			}
			break;
		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case EXP:
			push(exp(pop()));
			break;
		case SIN:
			push(sin(pop()));
			break;
		case SWP:
			swap();
			break;
		case DUP:
			dup();
			break;
		case DEL:
			pop();
			break;
		case CLR:
			clearstack();	
			break;
		case ERR:
			printf("error: input ignored\n");
			mssg = 1;
			break;
		default:
			printf("error: Invalid input '%s'\n", s);
			mssg = 1;
			break;
		}
	}
	/* we should free memory allocated with getline in myio.c here */
}