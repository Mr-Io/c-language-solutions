#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch();

int getint(int* pn)
{
	int c, sign;

	while (isspace(c = getch()));
	if (c == EOF) {
		ungetch();
		return EOF;	// End of file
	}
	if (!isdigit(c) && c != '+' && c != '-') {
		ungetch();
		return 0;	// not a number
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();
	if (!isdigit(c)) {
		ungetch();
		return 0;	// not a number
	}
	//number
	*pn = 0;
	do {
		*pn = *pn * 10 + c - '0';
	} while (isdigit(c = getch()));
	*pn *= sign;
	ungetch();
	return 1;
}

int main()
{
	int res, n;
	res = getint(&n);

	printf("%d %d", res, n );

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
