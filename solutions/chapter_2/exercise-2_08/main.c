#include <stdio.h>

/* position p starts in 0 for this program */
unsigned rightrot(unsigned x, unsigned n);

int main() 
{
	unsigned x, n;

	while(scanf("%x %u", &x, &n) == 2){
		printf("0x%0*X\n", (int) sizeof(unsigned)*2, rightrot(x, n));
	}
	return 0;
}

unsigned rightrot(unsigned x, unsigned n) 
{
	unsigned leftmost;

	n %= sizeof(unsigned) * 8;
	leftmost = x & ~(~0 << n);
	leftmost <<= sizeof(unsigned)*8 - n;
	return x >> n | leftmost;
}
