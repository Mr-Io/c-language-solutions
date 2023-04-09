#include "stack.h"
#include <stdio.h>
#include <math.h>

#define MAXSTACK 16

double stack[MAXSTACK];
int rsp = 0; /* next free position of the stack */

double pop(void)
{
	if (rsp == 0){
		return NAN;
	}
	return stack[--rsp];
}

int push(double x)
{
	if (rsp >= MAXSTACK){
		return -1;
	}
	stack[rsp++] = x;
	return 0;
}

void clearstack(void)
{
	rsp = 0;
}

double peek(void)
{
	if (rsp == 0){
		return NAN;
	}
	return stack[rsp];
}

int swap(void)
{
	if (rsp < 2){
		return -1;
	}
	double tmp;
	tmp = stack[rsp-2];
	stack[rsp-2] = stack[rsp-1];
	stack[rsp-1] = tmp;
	return 0;
}

int dup(void)
{
	if (rsp < 1 || rsp + 1 >= MAXSTACK ){
		return -1;
	}
	double tmp = stack[rsp-1];
	stack[rsp++] = tmp;
	return 0;
}

void printstack(void)
{
	int i;
	for(i = 0 ; i < rsp ; ++i){
		printf("%d: %f\n", rsp-i-1, stack[i]);
	}
}