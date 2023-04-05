#include <stdio.h>
#include <limits.h>

#define CINTLEN 20
#define V_LEN 6

enum {POSITIVE, NEGATIVE};

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	char s[CINTLEN];
	int n;
	while (scanf("%d", &n) == 1){
		itoa(n, s);
		printf("%s\n", s);
	}
	return 0;
}

void itoa(int n, char s[])
{
	int i; 
	int sign;
	unsigned un;

	un = (unsigned) n;
	sign = n < 0 ? NEGATIVE : POSITIVE;
	if (n < 0){
		un = ~un + 1;
	}
	i = 0;
	do{
		s[i++] = un % 10 + '0';
	} while ((un /= 10) > 0);
	if (sign == NEGATIVE){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) 
{
    int i, j;
    char c;

    for (j = 0; s[j] != '\0'; ++j);
    --j;
    for (i = 0; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}