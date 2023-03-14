#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000
#define V_LEN 6

void itoa(int n, char s[]);
void reverse(char s[]);


int main()
{
	char s[1000];
	int v[V_LEN] = {INT_MIN, INT_MIN + 1, -2341095, 2341095, INT_MAX, -0};
	
	int i;
	for (i = 0; i < V_LEN; ++i) {
		itoa(v[i], s);
		printf("%d\n", v[i]);
		printf("%s\n", s);

	}

	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;
	if (n == INT_MIN) {
		s[0] = '8';
		n /= 10;
		i = 1;
	}else {
		i = 0;
	}
	if ((sign = n) < 0) 
		n = -n;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i++] = '\0';
	reverse(s);
}

void reverse(char s[]) 
{
	int i, j;
	char t;
	for (j = 0; s[j] != '\0'; ++j);
	--j;
	for (i = 0; i < j; ++i, --j) {
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
