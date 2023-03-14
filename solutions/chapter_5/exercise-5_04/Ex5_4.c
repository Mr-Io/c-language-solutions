#include <stdio.h>

int strend(char* s, char* t) 
{
	char *sstart = s;
	char *tstart = t;

	// get pointer to the end
	while (*s++ != '\0');
	while (*t++ != '\0');
	--s;
	--t;
	// iterate from back to end
	while (*s == *t && s >= sstart && t >= tstart) {
		--t; 
		--s;
	}
	return (t < tstart) ? 1 : 0;
}

int main()
{
	char s[] = "Hello, ";
	char t[] = "lo, ";

	printf("%d", strend(s, t));
	

	return 0;
}
