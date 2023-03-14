#include <stdio.h>

/* position p starts in 0 for this program */
unsigned getmask(unsigned p, unsigned n);
unsigned invert(unsigned x, int p, int n);

int main() 
{
	printf("%d\n", invert(0, 28, 3));
	return 0;
}

/* a mask to put off n bits starting at position p*/
unsigned getmask(int p, int n) 
{
	return ~(~0u >> (unsigned) p) | (~0u >> (unsigned)(p + n));
}

unsigned invert(unsigned x, int p, int n) 
{
	return x ^ ~getmask(p, n);
}
