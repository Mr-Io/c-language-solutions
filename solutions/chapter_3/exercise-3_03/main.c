#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 100

int expand(const char s1[], char s2[], int n);

int main()
{
	char *in;
	char out[MAXLINE];
	long unsigned n;

	in = NULL;
	n = 0;
	while (getline(&in, &n, stdin) > 0){
		if (expand(in, out, MAXLINE) == -1){
			printf("error expand: insufficient length for s2 (max. size: %d)\n", MAXLINE);
			return -1;
		}
		printf("%s", out);
	};
	free(in);
	return 0;
}

int expand(const char s1[], char s2[], int n)
{
	int i, j;
	int start, mid, end;
	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		start = s1[i];
		mid = s1[i + 1];
		end = mid != '\0' ? s1[i + 2] : '\0';
		if (mid == '-' && end > start && ((isdigit(start) && isdigit(end)) || 
										  (isupper(start) && isupper(end)) || 
										  (islower(start) && islower(end))    )) {
			while (end != start){
				s2[j++] = start++;
				if (j >= n){
					return -1;
				}
			}
			++i;
		}else{
			s2[j++] = s1[i];
			if (j >= n){
				return -1;
			}
		}
	}
	s2[j] = '\0';
	return j;
}
