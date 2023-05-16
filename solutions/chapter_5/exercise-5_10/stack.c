#include "stack.h"
#include <math.h>

#define MAXSTACK 128

static double stack[MAXSTACK];
static int rsp = 0; /* next free position of the stack */

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