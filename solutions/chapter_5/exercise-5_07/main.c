#include <stdio.h>
#include <time.h>

#define MAXLINES 32768
#define LINESIZE 128

int readlines_dynamic(char **lineptr, int maxlines);
int readlines_static(char (*lines)[LINESIZE], int maxlines);

int mygetline(char *s, int n);

int main(int argn, char **argv)
{
	char mode;
	int nlines;
	clock_t tic, toc;
	char* lineptr[MAXLINES];
	char  lines[MAXLINES][LINESIZE];

	printf("mode 	clocktics 	nº lines\n");
	printf("---- 	--------- 	--------\n");

	tic = clock();
	nlines = readlines_static(lines, MAXLINES);
	toc = clock();
	printf(" sta 	%9ld 	%8d\n", toc - tic, nlines);

	tic = clock();
	nlines = readlines_dynamic(lineptr, MAXLINES);
	toc = clock();
	printf(" dyn 	%9ld 	%8d\n", toc - tic, nlines);

	return 0;
}

int readlines_dynamic(char **lineptr, int maxlines)
{
	char *line;
	int len, linecount;
	long unsigned n;

	linecount = 0;
	while(maxlines-- > 0){
		n = 0;
		line = NULL;
		if (len = getline(&line, &n, stdin) < 1){
			break;
		}
		*lineptr++ = line;
		++linecount;
	}

	return linecount;
}

int readlines_static(char (*lines)[LINESIZE], int maxlines)
{
	int len, n, linecount;

	linecount = 0;
	while(maxlines-- > 0 && (len = mygetline(*lines++, LINESIZE)) > 0){
		++linecount;
	}

	return linecount;
}

/* 
* NON STANDARD
* read a line from stdin and store it in buffer `s` (whitout '\n')
* The total line is readed but at most `n` characters 
* are stored in `s` including the terminating '\0'.
* The total length of the line readed is returned. 
*/
int mygetline(char *s, int n) 
{
    int c, res;
    char *save_s = s;
    char *send = s + n;

    while(s < send - 2 &&  (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    *s++ = '\0';

    res = s - save_s - 1;
    while (c != EOF && c != '\n'){
        c = getchar();
        ++res;
    }
    return res;
}