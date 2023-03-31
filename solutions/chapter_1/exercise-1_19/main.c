#include <stdio.h>
#include <stdlib.h>

int stripline(char s[]);
void reverse(char s[]);

int main()
{
	char *s;
	long unsigned n;
	int len;

	s = NULL;
	n = 0;
	while ((len = getline(&s, &n, stdin)) > 0) {
		if (stripline(s) > 0){
			reverse(s);
			printf("%s\n", s);
		}
	}
	free(s);
	return 0;
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
