#include "tab.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define MAXLINE 100
#define TABDEFAULT 4
static char tab[MAXLINE];

static int alldigit(char* s) 
{
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (!isdigit(s[i]))
			return 0;
	}
	return 1;
}

int settab(int argc, char* argv[])
{
	int i;
	if (argc == 1) {
		for (i = 0; i < MAXLINE; ++i) {
			if (i % TABDEFAULT == 0)
				tab[i] = 1;
		}
	}
	else if (alldigit(argv[1])){
		int n;
		for (i = 1; i < argc; ++i) {
			if (!alldigit(argv[i])) {
				printf("error: invalid tabstop position '%s'\n", argv[i]);
				return 0;
			}
			n = atoi(argv[i]);
			if (n > 0 && n < MAXLINE)
				tab[n] = 1;
		}
	}
	else {
		int m = 4, n = 4; //default values if one of them is not set
		for (i = 1; i < argc; ++i) {
			if (argv[i][0] == '-') {
				m = atoi(argv[i] + 1);
			}
			else if (argv[i][0] == '+') {
				n = atoi(argv[i] + 1);
			}else{
				printf("error: invalid command '%s'\n", argv[i]);
				return 0;
			}
			if (!alldigit(argv[i] + 1)) {
				printf("error: number '%s'\n", argv[i]);
				return 0;
			}
		}
		tab[m] = 1;
		for (i = m+1; i < MAXLINE; ++i) {
			if ((i - m) % n == 0)
				tab[i] = 1;
		}
	}
	return 1;
}


static int tabstop(int i)
{
	if (i >= MAXLINE)
		return 1;
	else
		return tab[i];
}

static int tabstop(int j);

void detab()
{
	int c;
	int j = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			do {
				putchar(' ');
				++j;
			} while (!tabstop(j));
		}
		else {
			putchar(c);
			++j;
		}
		if (c == '\n') {
			j = 0;
		}
	}
}

void entab()
{
	int c;
	int i = 0, nspaces = 0; 
	while ((c = getchar()) != EOF) {
		if (tabstop(i) && nspaces>0){
			putchar('\t');
			nspaces = 0;
		}
		if (c == ' ') {
			++nspaces;
		}
		else {
			while (nspaces > 0) {
				putchar(' ');
				--nspaces;
			}
			putchar(c);
		}
		++i;
		if (c == '\n') {
			nspaces = 0;
			i = 0;
		}
	}
}
