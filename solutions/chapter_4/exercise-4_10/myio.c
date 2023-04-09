#include "myio.h"
#include <stdio.h>
#include <ctype.h>

unsigned long nb = 0;	
char *buff = NULL;
int len = 0; /* number of character readed by getline */
int pos = 0; /* current buffer position */

/* return 0 success and -1 on error */
int fillbuff(void)
{
	if ((len = getline(&buff, &nb, stdin)) < 0){
		return -1;
	}
	pos = 0;
	return 0;
}

int getch(void) 
{
	/* fill buffer if it is empty */
	if (len - pos == 0){
		if(fillbuff() == -1){
			return -1;
		}
	}
	return buff[pos++];
}

/* push s string into the input, return 0 on success and -1 on error */
int ungetch(int c) 
{
	if (pos == 0) {
		return -1;
	}
	buff[--pos] = c;
	return 0;
}