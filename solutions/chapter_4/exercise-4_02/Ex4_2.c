#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
double pow(double b, int e);

int main()
{
	printf("%lf\n", atof("1234"));
	printf("%lf\n", atof("0.1234"));
	printf("%lf\n", atof("1234.0"));
	printf("%lf\n", atof("1234."));
	printf("%lf\n", atof("1234.543"));
	printf("%lf\n", atof("1234.2e4"));
	printf("%lf\n", atof("1234.432e+4"));
	printf("%lf\n", atof("1234.123e-3"));
	printf("%lf\n", atof("-1234"));
	printf("%lf\n", atof("-1234.0"));
	printf("%lf\n", atof("-1234."));
	printf("%lf\n", atof("-1234.543"));
	printf("%lf\n", atof("-1234.2e4"));
	printf("%lf\n", atof("-1234.432e+4"));
	printf("%lf\n", atof("-1234.123e-3"));
	return 0; 
}

double atof(char s[])
{
	// get sign
	int i, sign;
	for (i = 0; s[i] == ' '; ++i);
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+') 
		++i;
	// get absolute integer value
	double val = 0;
	while (isdigit(s[i])){
		val = 10 * val + (s[i] - '0');
		++i;
	}
	// add decimals
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
	// add exponents
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

double pow(double b, int e)
{
	//base cases
	if (e == 0)
		return 1;
	else if (e == 1)
		return b;
	else if (e == -1)
		return 1 / b;
	// recursive cases
	if (e%2==0) 
		return pow(b, e / 2)*pow(b, e/2);
	else
		return b * pow(b, e - 1);
}