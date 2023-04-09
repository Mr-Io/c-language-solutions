#include "myio.h"
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 16

char buff[BUFSIZE];
int ibuf = 0;	/* next free position in buff */

int getch(void) 
{
	return (ibuf > 0) ? buff[--ibuf] : getchar();
}

int ungetch(int c) 
{
	if (ibuf >= BUFSIZE || c == EOF) {
		return -1;
	}
	buff[ibuf++] = c;
	return 0;
}


/* push s string into the input, return 0 on success and -1 on error */
int ungets(char s[])
{
	/* check if there is space*/
	int i, len;
	for (len = 0; s[len] != 0 ; ++i);
	if (len > BUFSIZE - ibuf){
		return -1;
	}

	/* push s in the correct order , ungetch should not fail */
	for (i = len -1 ; i >= 0 ; --i){
		if (ungetch(s[i]) == -1){
			return -1;
		}
	}
	return 0;
}