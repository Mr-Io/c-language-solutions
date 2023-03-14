#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

void printfpattern(char* pattern, char* f);

int main(int argc, char* argv[])
{
	// check good form
	if (argc < 2) {
		printf("Usage: Ex7_7 pattern [file1 file2 ...]\n");
		return 0;
	}
	// retrieve and print lines of the files one by one
	int i;
	for (i = 2; i < argc; ++i) {
		printfpattern(argv[1], argv[i]);
	}
	printfpattern(argv[1], "stdin");
}

void printfpattern(char* pattern, char* fname)
{
	int linecount = 0;
	FILE* fp;
	if (!strcmp(fname, "stdin")) {
		fp = stdin;
	}
	else {
		if ((fp = fopen(fname, "r")) == NULL) {
			fprintf(stderr, "error: unable to open '%s'\n", fname);
			exit(1);
		}
	}
	char line[MAXLINE];
	while (fgets(line, MAXLINE, fp)) {
		++linecount;
		if (strstr(line, pattern))
			printf("%s[%d]: %s", fname, linecount, line);
	}
	if (fp!=stdin)
		fclose(fp);
}