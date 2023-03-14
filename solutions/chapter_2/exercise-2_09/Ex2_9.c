#include <stdio.h>

int bitcount(unsigned x);

int main() 
{
	printf("%d", bitcount(0xff000001));
	return 0;
}

int bitcount(unsigned x) {
	int n=0;
	while (x != 0) {
		++n;
		x &= x - 1;
	}
	return n;
}
