#include <stdio.h>

int strrindex(char s[], char t);


int main()
{
	printf("%d", strrindex("lloelo", "ell"));
	return 0;
}

int strrindex(char s[], char t[])
{
	/* Compute end positions for s and t*/
	int end_s, end_t;
	for (end_s = 0; s[end_s] != '\0'; ++end_s);
	--end_s;
	for (end_t = 0; t[end_t] != '\0'; ++end_t);
	--end_t;

	/* and simply run the algorithm from back*/
	int i, j, k;
	for (i = end_s; i >= 0; --i) {
		for (k = i, j = end_t; j >= 0 && s[k] == t[j]; --k, --j);
		if (j < 0)
			return k+1;
	}
	return -1;
}
