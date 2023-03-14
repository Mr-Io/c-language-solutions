#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int max);

int main()
{
	char line[MAXLINE];
	int len;

	while ((len = getline(line, MAXLINE)) != 0)
		if (len > 80) {
			printf("%3d:", len);
			printf("%s", line);
		}
	return 0;
}

int getline(char s[], int lim) {
	int c, i;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1) {
			s[i] = c;
		}
	}
	if (c == '\n' && i < lim-1) {
		s[i] = c;
		++i;
	}
	if (i < lim - 1)
		s[i] = '\0';
	else {
		s[lim - 2] = '\n';
		s[lim - 1] = '\0';
	}
	return i;
}