#include "readutils.h"
#include <stdio.h>
#include <ctype.h>

int getline(char s[], int lim)
{
	int c, i;
	int j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1)
			s[j++] = (char)c;
	}
	s[j++] = '\0';
	if (c == EOF && j == 1)
		return EOF;
	//printf(">>> %s\n", s);
	return j; // return strlen(s) + 1, the size needed to save the line
}

int getword(char* s, int lim)
{
	int c;
	s[0] = '\0';
	// return -1 if end of file
	if ((c = getch()) == EOF) 
		return EOF;
	// not a word, handle it
	if (!isalpha(c) && c != '_' && c != '#') {				
		int lastc = '\0';
		switch (c) {
		case '"':		// string constant, handle it
			while (((c = getch()) != '"' || lastc =='\\') && c!= EOF)
				lastc = c;
			return getword(s, lim);
			break;
		case '/':		// check if comment, ignore them
			if ((c=getch()) == '/') {		// ignore it until next new line
				while ((c = getch()) != '\n' && c != EOF);
				return getword(s, lim);
			}
			else if (c == '*') {			// ignore it until next "*/"
				while (((c = getch()) != '/' || lastc != '*') && c != EOF)
					lastc = c;
				return getword(s, lim);
			}
			else {
				ungetch(c);
				c = '/';
			}
			break;
		}
	}

	// return 0 if it is not a word
	int i = 0;
	s[i++] = (char)c;
	if (!isalpha(c) && c != '_' && c!='#') {
		s[i] = '\0';
		return 0;
	}
	// return 1 if it is a word
	while ((isalnum(c = getch()) || c == '_') && i < lim - 1) 
		s[i++] = (char)c;
	ungetch(c);
	s[i] = '\0';
	return 1;
}

#define MAXLINE 100
static int buffc = EOF;


int getch() 
{
	int res;
	if (buffc != EOF) {
		res = buffc;
		buffc = EOF;
	}
	else {
		res = getchar();
	}
	return res;
}

void ungetch(int c) 
{
	if (buffc != EOF)
		printf("error: unable to ungetch the character\n");
	buffc = c;
}

