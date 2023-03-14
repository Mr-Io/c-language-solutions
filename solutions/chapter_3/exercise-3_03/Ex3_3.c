#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int expand(char s1[], char s2[]);

int main()
{
	char in[] = "Hola todos las letras:    a-z\n"
				"y también en mayúscula:   A-Z\n"
				"y los números:            0-9\n"
				"y unas cuantas cosas que no deberían funcionar:\n"
				"	                       a-d-c a-0-Z -a-9 1-J a\n"
				"así como algunos casos interesantes:\n"
				"                          a-z0-9\n"
				"                          -a-z -4-5- a-b-c-d\n";
	char out[MAXLINE];

	expand(in, out);
	printf("%s", out);

}

int expand(char s1[], char s2[])
{
	int i, j;
	int start, mid, end;
	for (i = 0, j = 0; s1[i + 2] != '\0'; i++) {
		start = s1[i];
		mid = s1[i + 1];
		end = s1[i + 2];
		if (mid == '-' && end > start && ((isdigit(start) && isdigit(end)) || (isupper(start) && isupper(end)) || (islower(start) && islower(end)))) {
			char c;
			for (c = start; c <= end; ++c)
				s2[j++] = c;
			i += 2;
		}else{
			s2[j++] = s1[i];
		}
	}
	s2[j++] = s1[i];
	s2[j++] = s1[i+1];
	s2[j++] = '\0';
	return j;
}
