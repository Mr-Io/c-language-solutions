#include "tab.h"
#include "stdio.h"
#include "stdlib.h"

#define MAXLINE 100
#define TABDEFAULT 4
static char tab[MAXLINE];

void settab(int argc, char* argv[])
{
	int i;
	if (argc == 1) {
		for (i = 0; i < MAXLINE; ++i) {
			if (i % TABDEFAULT == 0)
				tab[i] = 1;
		}
	}
	else {
		int n;
		for (i = 1; i < argc; ++i) {
			n = atoi(argv[i]);
			if (n > 0 && n < MAXLINE)
				tab[n] = 1;
		}
	}
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
