#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void recitoa(char s[], int n, int i);

int main()
{

	char s[MAXLINE];
	recitoa(s, 12345, 0);
	printf("%s", s);
	return 0;
}

void wrapreverse(char s[]);

void recitoa(char s[], int n, int i) 
{
	// base case
	if (n < 10) {
		s[i] = n + '0';
		s[i + 1] = '\0';
		wrapreverse(s);
		return;
	}
	// recursion
	s[i] = (n % 10) + '0';
	recitoa(s, n / 10, i + 1);
}

void recreverse(char s[], int start, int end)
{
	// base case
	if (start >= end)
		return;
	// recursion
	char tmp;
	tmp = s[start];
	s[start] = s[end];
	s[end] = tmp;
	recreverse(s, ++start, --end);
}

void wrapreverse(char s[])
{
	recreverse(s, 0, strlen(s)-1);
}
