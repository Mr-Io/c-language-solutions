#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

#define MAXLINES 100
#define MAXLEN  100

char* ptrlines[MAXLINES];

int getline(char s[], int lim);
void printlines(int start, int n, int maxn);

int main(int argc, char* argv[]) 
{

	char buffer[MAXLINES*MAXLEN];					// queue type buffer
	char* palloc = buffer;							// next place in memory available
	char* pend = buffer + MAXLINES * MAXLEN - 1;	// last place in memory available

	char line[MAXLEN];
	int n = (argc == 2) ? atoi(argv[1] + 1) : N;
	if (n<1 || n>MAXLINES)
		n = N;
	int len, i=0;
	int ptrlines_full = 0;
	while ((len = getline(line, MAXLEN))!=EOF) {
		if (pend < palloc) {
			if (buffer + MAXLEN * MAXLINES - 1 - palloc >= len-1) {
				pend = buffer + MAXLEN * MAXLINES - 1;
			}
			else {
				palloc = buffer; // wrap around the memory buffer
			}
		}
		if (pend - palloc < len-1) {
			printf("error: no more lines can be stored in buffer");
			return;
		}
		// copy line
		strcpy(palloc, line);
		//save palloc and update i
		ptrlines[i++] = palloc;
		if (i >= n) {	// wrap around the array of pointers
			ptrlines_full = 1;
			i = 0;	
		}
		//update palloc
		palloc += len; 
		// update pend
		if (ptrlines_full) {
			pend = ptrlines[((i + 1) < n) ? (i + 1) : 0];
			pend = (pend != buffer) ? pend - 1 : buffer + MAXLEN * MAXLINES - 1;
		}
	}
	if (ptrlines_full)
		printlines(i, n, n);
	else
		printlines(0, i, i);
    
    return 0;
}


void printlines(int start, int n, int maxn)
{
	int i,c;
	for (i = start, c = 0; c < n; ++i, ++c) {
		if (i >= maxn)
			i = 0;
		printf("%s\n", ptrlines[i]);
	}
}

int getline(char s[], int lim)
{
	int c, i;
	int j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1) 
			s[j++] = c;
	}
	s[j++] = '\0';
	if (c == EOF && j==1)
		return EOF;
	//	printf(">>> %s\n", s);
	return j; // return strlen(s) + 1, the true size needed to save the line
}
