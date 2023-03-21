#include <stdio.h>
#include <ctype.h>

#define MAX_CHAR 256

int main()
{
	int lengths[MAX_CHAR];
	int c;
	for (c = 0; c < MAX_CHAR; ++c)
		lengths[c] = 0;

	while ((c = getchar()) != EOF){
		++lengths[c]; /* implicit cast from signed to unsigned */
	}
	printf("Vertical Histogram\n");
	printf("------------------\n");
	for (c = 0; c < MAX_CHAR; ++c) {
		if (lengths[c] > 0 && isprint(c) && c != ' '){
			printf("%c:", c);
			while (lengths[c]-- > 0) {
				putchar('|');
			}
			putchar('\n');
		}
	}
}