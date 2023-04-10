#include <stdio.h>

#define CINTLEN 20

int itoa(char s[], int n);

int main()
{
	char s[CINTLEN];
	int n;

	while (scanf("%d", &n) == 1){
		itoa(s, n);
		printf("%s\n", s);
	}
	return 0;
}

int itoa_rec(char s[], unsigned n);

int itoa(char s[], int n)
{
	/* handle negative numbers */
	unsigned un;
	un = (unsigned) n;
	if (n < 0){
        un = ~un + 1;
		s[0] = '-';
		++s;
    }

	/* recursive logic */
	int total_digits;
	total_digits = itoa_rec(s, un);

	/* finish s with null character '\0' */
	s[total_digits] = '\0';
}

/* 
* convert a integert n into a string s 
* (it only works for positive numbers and it does not add '\0' to end)
* it returns the number of digits of n 
*/
int itoa_rec(char s[], unsigned n)
{
	int n_digits;

	/* case base */
	if (n == 0){
		return 0;
	}
	/* recursive case */	
	n_digits = itoa_rec(s, n/10) + 1;
	s[n_digits-1] = n % 10 + '0';
	if (n < 10){
		s[n_digits] = '\0';
	}
	return n_digits;
}
