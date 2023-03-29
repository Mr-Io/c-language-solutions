#include <stdio.h>

#define MAXLINE 100

int cins(const char s[], char c);
int any(const char s[], const char e[]);

int mygetline(char s[], int lim); 

int main() 
{
	char s[MAXLINE];
	char e[MAXLINE];

	mygetline(s, MAXLINE);
	mygetline(e, MAXLINE);

	printf("position: %d\n", any(s, e));
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

/* 
* return the first location in the string s1 where 
* any character of string s2 occurs (starting from 0)
* return -1 if s1 contains no characters from s2
*/
int any(const char s1[], const char s2[])
{
	int i;
	for (i = 0; s1[i] != '\0'; ++i) {
		if (cins(s2, s1[i])){
			return i;
		}
	}
	return -1;
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
