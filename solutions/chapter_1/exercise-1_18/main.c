#include <stdio.h>
#include <stdlib.h>

int stripline(char s[]);

int main()
{
	char *s;
	long unsigned n;
	int len;

	s = NULL;
	n = 0;
	while ((len = getline(&s, &n, stdin)) > 0){
		if ((len = stripline(s)) > 0) {
			printf("%d:%s\n", len, s);
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