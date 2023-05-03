#include <stdio.h>

int strend(char* s, char* t) 
{
	char *sstart = s;
	char *tstart = t;

	/* get pointer to the end */
	while (*s++ != '\0');
	while (*t++ != '\0');
	--s;
	--t;

	/* iterate from back to end */
	while (*s-- == *t-- && s >= sstart && t >= tstart);

	return (t < tstart) ? 1 : 0;
}

int main()
{
	char *s, *t;
	long unsigned ns, nt;
	int ls, lt;
	
	s = t = NULL;
	ns = nt = 0;
	while ((ls = getline(&s, &ns, stdin)) > 0){
		if ((lt = getline(&t, &nt, stdin)) <= 0){
			return 0;
		}
		printf("match: %d\n", strend(s, t));
	}

	return 0;
}
