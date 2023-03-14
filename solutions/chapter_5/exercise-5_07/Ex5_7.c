#include "sortlines.h"
#include <stdio.h>
#include <time.h>

#define MAXLINES 5000
char* lineptr[MAXLINES];

#define MAXMEM 100000
char smem[MAXMEM];

// main program
int main()
{
	int nlines;
	clock_t start, end;

	start = clock();
	//nlines = readlines(lineptr, MAXLINES);
	nlines = readlines2(lineptr, MAXLINES, smem, MAXMEM);
	end = clock();
	sortlines(lineptr, 0, nlines - 1);
	writelines(lineptr, nlines);
	
	printf("Performance: %d", end - start);
	return 0;
}
