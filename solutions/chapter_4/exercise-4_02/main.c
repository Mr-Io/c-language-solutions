#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(const char s[]);

int main()
{
	char *s;
	long unsigned n;

	s = NULL;
	n = 0;
	while (getline(&s, &n, stdin) > 0){
		printf("%f\n", atof(s));
	}
	return 0; 
}

double atof(const char s[])
{
	/* ignore trailing whitespaces and get sign */
	int i, sign;
	for (i = 0; s[i] == ' '; ++i);
	sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '-' || s[i] == '+'){
		++i;
	}

	/* get absolute integer value */
	double val = 0;
	while (isdigit(s[i])){
		val = 10 * val + (s[i] - '0');
		++i;
	}

	/* add decimals */
	if (s[i] == '.') {
		int dec = 1;
		++i;
		while (isdigit(s[i])) {
			val = 10 * val + (s[i] - '0');
			dec *= 10;
			++i;
		}
		val /= dec;
	}

	/* add exponents */
	if (s[i] == 'e' || s[i] == 'E') {
		int expsign, exp=0;
		++i;
		expsign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+') 
			++i;
		while (isdigit(s[i])) {
			exp = 10 * exp + (s[i] - '0');
			++i;
		}
		val = val * pow(10.0, expsign * exp);
	}
	return  sign * val;
}