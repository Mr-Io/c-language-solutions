#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stack.h"
#include "getop.h"

#define MAXOP 100

int isvar[27];
double var[27];
#define INDEX_LAST 26

void printvar() {
	int i;
	for (i = 0; i < INDEX_LAST; ++i) {
		if (isvar[i]){
			printf("  | %c = %lf\n", i + 'a', var[i]);
		}
	}
}

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
			isvar[INDEX_LAST] = 1;
			var[INDEX_LAST] = pop();
			printstack();
			printf("RETURN:");
			printf("\t%lf\n\n", var[INDEX_LAST]);
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
			printvar();
			printstack();
			printf("\n");
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
			if (isvar[INDEX_LAST])
				push(var[INDEX_LAST]);
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


