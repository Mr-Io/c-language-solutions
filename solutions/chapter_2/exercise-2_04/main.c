#include <stdio.h>

#define MAXLINE 100


int cins(const char s[], char c);
void squeeze(char s[], const char e[]);

int mygetline(char s[], int lim);

int main() 
{
	char s[MAXLINE];
	char e[MAXLINE];

	mygetline(s, MAXLINE);
	mygetline(e, MAXLINE);
	squeeze(s, e);
	printf("%s\n", s);
	return 0;
}

/* return 1 if string s contains char c and 0 if not */
int cins(const char s[], char c) 
{
	int i;
	for (i = 0; s[i] != '\0'; ++i){
		if (s[i] == c) {
			return 1;
		}
	}
	return 0;
}

/* delete all character in s that matches any character in e */
void squeeze(char s[], const char e[])
{
	int i;
	int j;
	for (i = 0, j = 0; s[i] != '\0'; ++i){
		if (!cins(e, s[i])){
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

int mygetline(char s[], int lim) 
{
	int c, i;

	for (i = 0; i<lim-1 &&  (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (i == lim-1){
		s[i-1] = '\n';
	}else if (c == '\n' || (c == EOF && i > 0)){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	while (c != EOF && c != '\n'){
		c = getchar();
		++i;
	}
	return i;
}