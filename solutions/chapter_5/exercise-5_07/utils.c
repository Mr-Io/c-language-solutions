#include <stdio.h>

int getline(char* s, int lim)
{
	int c=0, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	s[i++] = '\0';
	if (c == EOF && i==1)
		return EOF;
	printf(">>> %s\n", s);
	return i; // return strlen(s) + 1, the true size needed to save the line
}