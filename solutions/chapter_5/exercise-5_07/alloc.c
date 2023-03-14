//dynamic memory simulation . c
#include "alloc.h"
#include "stdio.h"
#define ALLOCSIZE 100000

static char allocbuff[ALLOCSIZE];
static char* palloc = allocbuff;

char* alloc(int n)
{
	if (allocbuff + ALLOCSIZE - palloc > n) {
		palloc += n;
		return palloc - n;
	}
	else {
		return NULL;
	}
}

void afree(char* p)
{
	if (p >= allocbuff && p < palloc)
		palloc = p;
}