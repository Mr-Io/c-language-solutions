#include "stack.h"
#include <stdio.h>

#define MAXSTACK 100
static double stack[MAXSTACK];
static int istack = 0;				// next free position of the stack 

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

void printstack()
{
	int i;
	for (i = 0;  i < istack; ++i) {
		printf("%d:\t%lf\n", istack-i-1, stack[i]);
	}
}