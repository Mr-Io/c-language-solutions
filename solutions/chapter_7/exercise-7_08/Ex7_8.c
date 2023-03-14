#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define MAXLINES 60

void printfile(char* fname);

int main(int argc, char* argv[])
{
	// check good form
	if (argc < 2) {
		printf("Usage: Ex7_8 file 1 [file2 file3 ...]\n");
		return 0;
	}
	// retrieve and print lines of the files one by one
	int i;
	for (i = 1; i < argc; ++i)
		printfile(argv[i]);
}

int printfheader(char* fname, int pagenum) 
{
	putchar('\n');
	printf("-------------------------\n");
	printf("%-20s -%d-\n", fname, pagenum);
	printf("-------------------------\n");
	return 3;
}

void printfile(char* fname)
{
	FILE* fp;
	static int linenum = MAXLINES;
	static int pagenum = 0;
	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "error: unable to open '%s'\n", fname);
		exit(1);
	}
	char line[MAXLINE];
	while (fgets(line, MAXLINE, fp)) {
		++linenum;
		if (linenum > MAXLINES) {
			++pagenum;
			linenum = printfheader(fname, pagenum);
		}
		printf("%s", line);
	}
	fclose(fp);
}