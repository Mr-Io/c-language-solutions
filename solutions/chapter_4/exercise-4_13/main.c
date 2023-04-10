#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]);

int main()
{

	char *s;
	int len;
	long unsigned n;

	s = NULL;	
	n = 0;
	while((len = getline(&s, &n, stdin)) > 0){
		reverse(s);
		printf("%s\n", s);
	}
	free(s);
	return 0;
}

void reverse_rec(char s[], int start, int end);

void reverse(char s[])
{
	int len = strlen(s);
	if (len > 0 && s[len - 1] == '\n'){
		s[--len] = '\0';
	}
	reverse_rec(s, 0, strlen(s)-1);
}

void reverse_rec(char s[], int start, int end)
{
	// base case
	if (start >= end)
		return;
	// recursion
	char tmp;
	tmp = s[start];
	s[start] = s[end];
	s[end] = tmp;
	reverse_rec(s, ++start, --end);
}