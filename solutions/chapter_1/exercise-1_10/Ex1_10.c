#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int blanck = OUT;
	int c = -1;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar('\\');
			putchar('b');
		}
		else if (c == '\t') {
			putchar('\\');
			putchar('t');
		}
		else if (c == '\n') {
			putchar('\\');
			putchar('n');
		}
		else {
			putchar(c);
		}
	}
}