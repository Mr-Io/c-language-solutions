#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int state = OUT;
	int c;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			putchar(c);
			state = IN;
		}
		else if (state == IN) {
			putchar('\n');
			state = OUT;
		}

	}
}