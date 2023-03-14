#include <stdio.h>

#define N 4
#define MAXLINE 1000

int getline(char line[], int max);

int main()
{
	char s[MAXLINE]; 
	int len;

	while ((len=getline(s, MAXLINE))!= 0) {
		int pos = 0;
		int count_blanck = 0;
		int i;
		for (i = 0; i < len; ++i) {
			if (s[i] == ' ') {
				if (pos == N-1) {
					count_blanck = 0;
					putchar('\t');
				}
				else {
					++count_blanck;
				}
			}
			else {
				if (count_blanck > 0) {
					while (count_blanck > 0) {
						putchar(' ');
						--count_blanck;
					}
				}
				putchar(s[i]);
			}
			/*Update pos*/
			++pos;
			if (pos >= N || s[i] =='\t')  
				pos = 0;
		}
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