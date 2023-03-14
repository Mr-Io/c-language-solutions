#include <stdio.h>
#define MAXLINE 1000


int main()
{
	char s[MAXLINE];
	int len;

	len = getline(s, MAXLINE);
	printf("%s", s);

	len = getline_equivalent(s, MAXLINE);
	printf("%s", s);
} 

int getline(char s[], int lim) {
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

int getline_equivalent(char s[], int lim) {
	int c, i;
	
	//equivalent for without && or ||
	for (i = 0; i < lim - 1 ; ++i) {
		if ((c = getchar()) != EOF){
			if (c != '\n') {
				s[i] = c;
			}
			else {
				lim = i + 1;
			}
		}
		else {
			lim = i + 1;
		}
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}