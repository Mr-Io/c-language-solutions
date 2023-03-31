#include <stdio.h>

#define MAXLINE 100

int cins(const char s[], char c);
int any(const char s[], const char e[]);

int main() 
{
	char *s = NULL;
	char *e = NULL;
	long unsigned ls = 0;
	long unsigned le = 0;

	if (getline(&s, &ls, stdin) == -1){
		printf("error getline: possible EOF\n");
		return 1;
	}
	if (getline(&e, &le, stdin) == -1){
		printf("error getline: possible EOF\n");
		return 1;
	}
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