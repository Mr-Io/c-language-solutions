#include <stdio.h>

#define MAX_CHAR 122-32+1

int main()
{
	int lengths[MAX_CHAR];
	int i;
	for (i = 0; i < MAX_CHAR; ++i)
		lengths[i] = 0;

	int cc=0;
	int c;

	while ((c = getchar()) != EOF){
		if (c>=32 && c<=122)
			++lengths[c-32];
	}

	for (i = 0; i < MAX_CHAR; ++i) {
		printf("%c %3d:", i+32, i+32);
		while (lengths[i] > 0) {
			putchar('|');
			--lengths[i];
		}
		putchar('\n');
	}
}