#include "utils.h"
#include <stdio.h>
#include <string.h>

#define MAXWORD 100
#define NKEY (sizeof keytabs / sizeof keytabs[0])

struct key {
	char* word;
	int count;
};

struct key keytabs[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
	};

void printkeys(void);
int binsearch(char* w);

int main()
{

	int isword;
	char word[MAXWORD];
	int n;
	while ((isword = getword(word, MAXWORD)) != EOF) {
		if (isword) {
			n = binsearch(word);
			if (n != -1)
				++keytabs[n].count;
		}
	}
	printkeys();
	return 0;
}

int binsearch(char* w)
{
	int left=0, right=NKEY-1;
	int med;
	int cmp;
	while (left < right) {
		med = (left + right) / 2;
		if ((cmp = strcmp(w, keytabs[med].word)) < 0) 
			right = med - 1;
		else if (cmp > 0) 
			left = med + 1;
		else 
			return med;
	}
	if (strcmp(w, keytabs[left].word) == 0)
		return left;
	else if (strcmp(w, keytabs[right].word) == 0)
		return right;
	else
		return -1; // not found
}

void printkeys() 
{
	int i;
	for (i = 0; i < NKEY; ++i) {
		if (keytabs[i].count>0)
			printf("%8s %3d\n", keytabs[i].word, keytabs[i].count);
	}
}
