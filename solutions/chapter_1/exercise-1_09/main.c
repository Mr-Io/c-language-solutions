#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int blank = OUT;
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			blank = IN;
		}else{
			if (blank == IN) {
				putchar(' ');
				blank = OUT;
			}
			putchar(c);
		}
	}
}