#include <stdio.h>
#define N 4

int main()
{
	int c;
	int k = 0;

	while ((c=getchar()) != EOF) {
		if (c == '\t') {
			while (k < N) {
				putchar(' ');
				++k;
			}
		}
		else {
			putchar(c);
			++k;
		}
		if (k >= N || c == '\n') {
			k = 0;
		}
	}
	return 0;
}