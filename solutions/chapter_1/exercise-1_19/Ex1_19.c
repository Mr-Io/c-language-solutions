#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int max);
void reverse(char s[]);

int main()
{
	char line[MAXLINE];
	int len;

	while ((len = getline(line, MAXLINE)) != 0) {
		reverse(line);
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
	if (i < lim - 1) {
		s[i] = '\0';
	}else {
		s[i - 1] = '\0';
		--i;
	}
	return i;
}

void reverse(char s[]) 
{
	int i, j;
	char t;
	for (j = 0; s[j] != '\0'; ++j);
	--j;
	for (i = 0; i < j; ++i, --j) {
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
