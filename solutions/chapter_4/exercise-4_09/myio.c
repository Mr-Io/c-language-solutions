#include "myio.h"
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 16

int buffchar;
int ibuf = 0;	/* 0 not saved and 1 saved */

int getch(void) 
{
	if(ibuf){
		ibuf = 0;
		return buffchar;
	}
	return getchar();
}

int ungetch(int c) 
{
	if (ibuf) {
		return -1;
	}
	buffchar = c;
	ibuf = 1;
	return 0;
}
