#include <stdio.h>

// dynamic memory simulation .h
#ifndef DYNAMIC_MEMORY_SIM
#define DYNAMIC_MEMORY_SIM
char* alloc(int n);
void afree(char* p);
int freesize(void);
#endif 

//getline
int getline(char* s, int lim);

//Ex5_7
#define MAXLINES 5000
char* lineptr[MAXLINES];

int readlines(char** lineptr, int nlines);
void writelines(char** lineptr, int nlines);

// main program
int main()
{
	int nlines;
	nlines = readlines(lineptr, MAXLINES);
	writelines(lineptr, nlines);
	return 0;
}

//readlines
#include <string.h>
#define MAXLEN 1000
int readlines(char** lineptr, int nlines)
{
	int i, len;
	char s[MAXLEN];
	for (i = 0;i<nlines && (len = getline(s, MAXLEN)) != EOF; ++i) {
		if((lineptr[i] = alloc(len))==NULL)
			return -1;
		strcpy(lineptr[i], s);
	}
	return i;
}

//writelines
void writelines(char** lineptr, int nlines)
{
	while (nlines-- > 0) 
		printf("%s\n", *lineptr++);
}


//dynamic memory simulation . c
#define ALLOCSIZE 10000

static char allocbuff[ALLOCSIZE];
static char* palloc = allocbuff;

char* alloc(int n)
{
	if (allocbuff + ALLOCSIZE - palloc > n) {
		palloc += n;
		return palloc-n;
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

int freesize()
{
	return allocbuff + ALLOCSIZE - palloc;
}

// getline
int getline(char* s, int lim)
{
	int c=0, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	s[i++] = '\0';
	if (c == EOF)
		return EOF;
//	printf(">>> %s\n", s);
	return i;
}
