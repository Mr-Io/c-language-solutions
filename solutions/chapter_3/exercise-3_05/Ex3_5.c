#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000
#define V_LEN 6

void itob(int n, char s[], int b);
void reverse(char s[]);


int main()
{
	char s[1000];
	int i, j;
	int v[6] = {15, 255, 512, INT_MAX, 0, 123145015};
	for (i = 0; i < 6; ++i) {
		printf("%d\n", v[i]);
		itob(v[i], s, 2);
		printf("\t%2d: %35s\n", 2, s);
		itob(v[i], s, 8);
		printf("\t%2d: %35s\n", 8, s);
		itob(v[i], s, 16);
		printf("\t%2d: %35s\n", 16, s);
		itob(v[i], s, 10);
		printf("\t%2d: %35s\n", 10, s);
		putchar('\n');
	}
	return 0;
}

// only positive quantities
void itob(int n, char s[], int b)
{
	int i = 0;
	int next;
	do {
		next = n % b;
		s[i++] = (next <= 9) ? next + '0' : next - 10 + 'a';
	} while ((n /= b) > 0);
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
