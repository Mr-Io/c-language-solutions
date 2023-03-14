#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int blanck = OUT;
	int c = -1;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			blanck = IN;
		}
		else{
			if (blanck == IN) {
				putchar(' ');
				blanck = OUT;
			}
			putchar(c);
		}
	}
}