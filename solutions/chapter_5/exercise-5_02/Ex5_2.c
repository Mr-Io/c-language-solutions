#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch();

int getfloat(float* pn)
{
	int c, sign;
	int isnum = 0;

	// remove trailing spaces
	while (isspace(c = getch()));
	// return if end of file
	if (c == EOF) {
		ungetch();
		return EOF;	
	}
	// return if not a number
	if (!isdigit(c) && c != '+' && c != '-' && c != '.') {
		ungetch();
		return 0;
	}
	// capture sign
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();
	// return if not a number
	if (!isdigit(c) && c!='.') {
		ungetch();
		return 0;
	}
	//capture number value before '.'
	*pn = 0;
	while(isdigit(c)){
		isnum = 1;
		*pn = *pn * 10 + c - '0';
		c = getch();
	} 
	//capture numbervalue after '.'
	if (c == '.') {
		int power = 1;
		c = getch();
		while (isdigit(c)) {
			isnum = 1;
			power *= 10;
			*pn = *pn * 10 + c - '0';
			c = getch();
		}
		*pn /= power;
	}
	*pn *= sign;
	ungetch();
	return isnum;
}

int main()
{
	int res;
	float x;
	res = getfloat(&x);

	printf("%d %f", res, x);

	return 0;
}

//READ WITH BUFFER
#include <ctype.h>
#include <limits.h>
#define MAXLINE 100
char line[MAXLINE] = "";
int i = 0;

int getline(char s[], int lim);

int getch() 
{
	int res;
	if (line[i] != '\0')
		return line[i++];
	else {
		i = 0;
		res = getline(line, MAXLINE);
		printf(">>> ");
		printf(line);
		return line[i++];
	}
}

void ungetch() 
{
	--i;
	if (i < 0)
		i = 0;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
