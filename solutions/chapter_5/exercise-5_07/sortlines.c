#include "sortlines.h"
#include "utils.h"
#include "alloc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 1000

static void swap(char** x, char** y);

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

int readlines2(char** lineptr, int nlines, char* s, int maxs)
{
	int i, len;
	for (i = 0;i<nlines && maxs > 0 && (len = getline(s, maxs)) != EOF; ++i) {
		if (len > maxs)
			return -1;
		lineptr[i] = s;
		s += len;
		maxs -= len;
	}
	return i;
}

void writelines(char** lineptr, int nlines)
{
	while (nlines-- > 0) 
		printf("%s\n", *lineptr++);
}

void sortlines(char** lineptr, int start, int end)
{
	//base case
	if (start >= end)
		return;
	//recursion
	int piv_end = start;
	swap(&lineptr[start], &lineptr[(start + end)/2]);// swap(lineptr + start, lineptr + (start+end)/2);
	int i;
	for (i = start + 1; i <= end; ++i)
		if (strcmp(lineptr[i], lineptr[start]) < 0) 
			swap(&lineptr[i], &lineptr[++piv_end]); 
	swap(&lineptr[start], &lineptr[piv_end]);
	sortlines(lineptr, start, piv_end - 1);
	sortlines(lineptr, piv_end + 1, end);
}

//auxiliar internal function
static void swap(char** x, char** y)
{
	char* tmp = *x;
	*x = *y;
	*y = tmp;
}
