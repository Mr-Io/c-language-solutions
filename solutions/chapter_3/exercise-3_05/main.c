#include <stdio.h>
#include <limits.h>

#define CINTLEN 64

enum {POSITIVE, NEGATIVE};

int itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[CINTLEN];
	int n, b;
	while (scanf("%d %d", &n, &b) == 2){
		if (itob(n, s, b) != 0){
			printf("error itob: invalid base (%d)\n", b);
			return 1;
		}
		printf("%s\n", s);
	}
	return 0;
}

/* return 0 on sucess an -1 on error */
int itob(int n, char s[], int b)
{
	int i; 
	int sign;
	unsigned un;

	if (b < 2 || b > (26+10)){
		return -1;
	}

	un = (unsigned) n;
	sign = n < 0 ? NEGATIVE : POSITIVE;
	if (n < 0){
		un = ~un + 1;
	}

	unsigned next;
	i = 0;
	do {
		next = un % b;
		s[i++] = (next <= 9) ? next + '0' : next - 10 + 'A';
	} while ((un /= b) != 0);
	if (sign == NEGATIVE){
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s);

	return 0;
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
