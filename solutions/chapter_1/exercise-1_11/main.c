#include <stdio.h>

#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

/* count lines, words, and characters in input */
int main()
{
	int state = OUT;
	int c, nc, nl, nw;

	nc = nl = nw = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n'){
			++nl;
		}
		if (c != ' ' && c != '\t' && c != '\n'){
			if (state == OUT){
				++nw;
			}
			state = IN;
		}else{
			state = OUT;
		}
	}
	printf("characters: %d\n", nc);
	printf("lines:      %d\n", nl);
	printf("words:      %d\n", nw);
}