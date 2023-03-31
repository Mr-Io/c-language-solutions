#include <stdio.h>
#include <stdlib.h>

#define SOMESIZE 4

int lower(int c);

int main() 
{
	char *s;
	long unsigned n;
	int i;

	s = NULL;
	n = 0;
	while(getline(&s, &n, stdin) > 0){
		for (i = 0; s[i] != '\0'; ++i){
			putchar(lower(s[i]));
		}
	}
	free(s);
	return 0;
}

int lower(int c) {
	return (c < 'A' || c > 'Z') ? c : c + 'a' - 'A';
}
