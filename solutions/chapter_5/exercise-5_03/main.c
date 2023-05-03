#include <stdio.h>

void mystrcat(char* s, const char* t) 
{
	while (*s++ != '\0');
	s--;
	while (*s++ = *t++);
}

int main()
{
	char *s, *t;
	long unsigned ns, nt;
	int ls, lt;
	
	s = t = NULL;
	ns = nt = 0;
	while ((ls = getline(&s, &ns, stdin)) > 0){
		s[ls-1] = '\0'; /* remove trailing '\n' from string s */
		if ((lt = getline(&t, &nt, stdin)) <= 0){
			return 0;
		}
		if (ns < ls + lt +1){
			printf("error: %ld characters allocated for s, we need %d \n", ns, ls + lt + 1);
			return 1;
		}
		mystrcat(s, t);
		printf("%s\n", s);
	}

	return 0;
}
