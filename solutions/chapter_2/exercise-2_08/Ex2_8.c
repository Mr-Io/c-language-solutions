#include <stdio.h>

/* position p starts in 0 for this program */
unsigned rightrot(unsigned x, int n);

int main() 
{
	printf("%u", rightrot(0xff000001,24));
	return 0;
}

unsigned rightrot(unsigned x, int n) {
	unsigned leftmost = ~(~0u >> 1);
	int i;
	for (i = 0; i < n; ++i) {
		x = (x & 1u) == 0 ? x >> 1 : (x >> 1) | leftmost;
	}
	return x;
}
