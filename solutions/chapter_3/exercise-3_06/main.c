#include <stdio.h>
#include <limits.h>
#include <string.h>

#define CINTLEN 100
#define V_LEN 6

enum {POSITIVE, NEGATIVE};

int itoa_v2(int n, char s[], int blanks);
void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	char s[CINTLEN];
	int n;
	int width;
	while (scanf("%d %d", &n, &width) == 2){
		if(itoa_v2(n, s, width) != 0){
			printf("error itoa: %d too big (max. width: %d)\n", width, CINTLEN);
			return 1;
		}
		printf("%s\n", s);
	}
	return 0;
}

/* return 0 if success and -1 on error */
int itoa_v2(int n, char s[], int blanks)
{
	itoa(n, s);
	int len = strlen(s);

	if (blanks > CINTLEN){
		return -1;
	}else if (blanks > len){
		int i, j;
		for (i = blanks, j = len; i >= 0 ; --i, --j){
			s[i] = j >= 0 ? s[j] : ' ';
		}
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