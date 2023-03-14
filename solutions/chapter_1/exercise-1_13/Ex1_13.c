#include <stdio.h>

#define IN 1
#define OUT 0

#define LONGEST_WORD 45

int main()
{
	int lengths[LONGEST_WORD + 1];
	int i;
	for (i = 0; i <= LONGEST_WORD; ++i)
		lengths[i] = 0;

	int state = OUT;
	int wc=0;
	int c;

	while ((c = getchar()) != EOF){
		if (c != ' ' && c != '\t' && c != '\n') {
			state = IN;
			++wc;
		}
		else if (state==IN) {
			state = OUT;
			++lengths[wc];
			wc = 0;
		}
	}

	for (i = 0; i <= LONGEST_WORD; ++i) {
		printf("%2d:", i);
		while (lengths[i] > 0) {
			putchar('|');
			--lengths[i];
		}
		putchar('\n');
	}
}