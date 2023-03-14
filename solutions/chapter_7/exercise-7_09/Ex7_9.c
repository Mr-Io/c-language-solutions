#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define isupper_macro(c) ('A' <= c && c <= 'Z')? 1 : 0

int isupper_function(int c) {
	if ('A' <= c && c <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	int c;
	for (c = CHAR_MIN ; c <= CHAR_MAX; ++c) {
		printf("char: [%c] ", c);
		printf("%d", isupper_function(c));
		printf("%d", isupper_macro(c));
		printf("\n");
	}
}