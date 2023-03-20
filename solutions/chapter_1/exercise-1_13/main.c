#include <stdio.h>

#define IN 1
#define OUT 0

#define LONGEST_WORD 45

int main()
{
	int lengths[LONGEST_WORD];
	int i;
	for (i = 0; i < LONGEST_WORD; ++i)
		lengths[i] = 0;
	int state = OUT;
	int wc=0, maxwc=0;

	int c;
	while ((c = getchar()) != EOF){
		if (c != ' ' && c != '\t' && c != '\n') {
			state = IN;
			++wc;
		}else if (state==IN) {
			state = OUT;
			maxwc = wc > maxwc ? wc : maxwc;
			if (wc < LONGEST_WORD){
				++lengths[wc];
			}
			wc = 0;
		}
	}
	printf("Vertical histogram\n");
	printf("------------------\n");
	int k;
	for (i = 0; i <= maxwc && i < LONGEST_WORD; ++i) {
		printf("%2d:", i);
		for (k = 0; k < lengths [i]; ++k){
			putchar('|');
		}
		putchar('\n');
	}
	printf("Horizontal Histogram\n");
	printf("--------------------\n");
	int height = 0;
	for (i = 0; i <= maxwc && i < LONGEST_WORD; ++i) {
		height = lengths[i] > height ? lengths[i] : height;
	}
	for ( ; height > 0 ; --height){
		for (i = 0; i <= maxwc && i < LONGEST_WORD; ++i) {
			if (lengths[i] >= height){
				printf(" | ");
			}else{
				printf("   ");
			}
		}
		putchar('\n');
	}
	for (i = 0; i <= maxwc && i < LONGEST_WORD; ++i) {
		printf(" %d ", i);
	}
	putchar('\n');
	return 0;
}