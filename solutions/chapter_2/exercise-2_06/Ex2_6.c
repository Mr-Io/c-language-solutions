#include <stdio.h>

/* position p starts in 0 for this program */
unsigned getmask(unsigned p, unsigned n);
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main() 
{
	printf("%d\n", setbits(0, 28, 3, -1));
	return 0;
}

/* a mask to put off n bits starting at position p*/
unsigned getmask(int p, int n) 
{
	return ~(~0u >> (unsigned) p) | (~0u >> (unsigned)(p + n));
}

unsigned setbits(unsigned x, int p, int n, unsigned y) 
{
	unsigned mask = getmask(p, n);
	return (x & mask) | (y & ~mask);
}