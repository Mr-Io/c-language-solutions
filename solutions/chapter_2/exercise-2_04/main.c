#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int cins(const char s[], char c);
void squeeze(char s[], const char e[]);

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