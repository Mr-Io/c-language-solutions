#include <stdio.h>

unsigned bitcount(unsigned x);

int main() 
{
	unsigned x;

	while(scanf("%x", &x) == 1){
		printf("%u\n",  bitcount(x));
	}
	return 0;
}

unsigned bitcount(unsigned x) 
{
	unsigned n=0;
	while (x != 0) {
		++n;
		x &= x - 1;
	}
	return n;
}
