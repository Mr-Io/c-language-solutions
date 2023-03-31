#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELIMIT 80

int main()
{
	long unsigned n;
	int len;
	char *s;

	s = NULL;
	n = 0;
	while ((len = getline(&s, &n, stdin)) > 0){
		if (len > LINELIMIT) {
			printf("%d:%s", len, s);
		}
	}
	free(s);
	return 0;
}
