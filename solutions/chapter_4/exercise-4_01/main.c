#include <stdio.h>
#include <string.h>

int strrindex(const char s[], const char t[]);


int main()
{
	char *s;
	char *t;
	long unsigned ns, nt;

	s = t = NULL;
	ns = nt = 0;
	while (getline(&s, &ns, stdin) > 0){
		if (getline(&t, &nt, stdin) <= 0){
			printf("getline: error reading 2nd line\n");
			return 1;
		}
		printf("position of last occurence: %d\n", strrindex(s, t));
	}

	return 0;
}

int strrindex(const char s[], const char t[])
{
	int i_start; /* initial position to start comparing*/
	int i, j, k;
	
	i_start = strlen(s) - strlen(t);
	for (i = i_start; i >= 0; --i) {
		for (k = i, j = 0; s[k] == t[j] && t[j] != '\n' && t[j] != '\0' ; ++k, ++j);
		if (t[j] == '\n' || t[j] == '\0'){
			return i;
		}
	}
	return -1;
}
