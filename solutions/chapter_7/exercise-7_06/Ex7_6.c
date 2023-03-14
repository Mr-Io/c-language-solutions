#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100 

void printesc(char s[]);

int main(int argc, char* argv[])
{
	// check arguments
	if (argc != 3) {
		printf("Usage: Ex7_6 file1 file2\n");
		return;
	}
	// open files
	FILE *f1, *f2;
	if ((f1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "error: unable to open '%s'", argv[1]);
		exit(1);
	}
	if ((f2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "error: unable to open '%s'", argv[2]);
		exit(1);
	}
	// compare them line by line
	int countline = 0;
	char* res1;
	char* res2;
	char line1[MAXLINE];
	char line2[MAXLINE];
	do {
		res1 = fgets(line1, MAXLINE, f1);
		res2 = fgets(line2, MAXLINE, f2);
		countline++;
	} while (res1 != NULL && res2 != NULL && !strcmp(line1, line2));
	if (res1 != NULL || res2 != NULL) {
		printf("%9.9s[%d]:", argv[1], countline);
		printesc((res1) ? res1 : "[\\EOF]");
		putchar('\n');
		printf("%9.9s[%d]:", argv[2], countline);
		printesc((res2) ? res2 : "[\\EOF]");
		putchar('\n');
	}
	// close files
	fclose(f1);
	fclose(f2);
}

void printesc(char s[])
{
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; ++i) {
		switch (s[i]) {
		case '\n':
			printf("[\\n]");
			break;
		case '\t':
			printf("[\\t]");
			break;
		case '\r':
			printf("[\\r]");
			break;
		default:
			putchar(s[i]);
			break;
		}
	}
}