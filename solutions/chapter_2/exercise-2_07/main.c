#include <stdio.h>

unsigned getmask(unsigned p, unsigned n);
unsigned invert(unsigned x, int p, int n);

int main() 
{
	unsigned x, p, n, y;

	while(scanf("%x %u %u", &x, &p, &n) == 3){
		printf("0x%0*X\n", (int) sizeof(unsigned)*2, invert(x, p, n));
	}
	return 0;
}

/* a mask to put ON n bits starting at position p */
unsigned getmask(unsigned p, unsigned n) 
{
	return ~(~0 << n) << (p+1-n);
}

unsigned invert(unsigned x, int p, int n) 
{
	return x ^ getmask(p, n);
}
