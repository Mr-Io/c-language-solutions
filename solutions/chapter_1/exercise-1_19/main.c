#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int stripline(char s[]);
void reverse(char s[]);

int main()
{
	char line[MAXLINE];
	int len;

	while ((len = mygetline(line, MAXLINE)) != 0) {
		if (stripline(line) > 0){
			reverse(line);
			printf("%s\n", line);
		}
	}
	return 0;
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

int stripline(char s[]) 
{
	int len;

	for(len = 0; s[len] != '\0'; ++len);
	--len;
	while (len >= 0 && (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')) {
		s[len] = '\0';
		--len;
	}
	return len + 1;
}

void reverse(char s[]) 
{
	int i, j;
	char c;

	for (j = 0; s[j] != '\0'; ++j);
	--j;
	for (i = 0; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
