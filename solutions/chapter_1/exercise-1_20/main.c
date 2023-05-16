#include <stdio.h>
#define TABLEN 8

int main()
{
	int c;
	int pos = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			while (pos < TABLEN) {
				putchar(' ');
				++pos;
			}
		}else{
			putchar(c);
			++pos;
		}
		if (pos >= TABLEN || c == '\n') {
			pos = 0;
		}
	}
	return 0;
}