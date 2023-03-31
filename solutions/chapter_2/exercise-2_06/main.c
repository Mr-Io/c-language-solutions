#include <stdio.h>

unsigned getmask(unsigned p, unsigned n);
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main() 
{
	unsigned x, p, n, y;

	while(scanf("%x %u %u %x", &x, &p, &n, &y) == 4){
		printf("0x%0*X\n", (int) sizeof(unsigned)*2, 
				setbits(x, p, n, y));
	}
	return 0;
}

/* a mask to put ON n bits starting at position p */
unsigned getmask(unsigned p, unsigned n) 
{
	return ~(~0 << n) << (p+1-n);
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) 
{
	unsigned mask = getmask(p, n);
	return (x & ~mask) | ((y << (p+1-n)) & mask) ;
}
