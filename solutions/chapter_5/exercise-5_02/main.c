#include <stdio.h>
#include <ctype.h>

int getfloat(float* pn);

int main()
{
	int res;
	float n;

	do{
		printf("> ");
		res = getfloat(&n);
		switch (res){
		case 0:
			printf("Not a number!\n");
			break;
		case 1:
			printf("Number: %f\n", n);
			break;
		case EOF:
			printf("End Of File!\n");
			break;
		}
	}while (res > 0);

	return 0;
}

int getfloat(float* pn)
{
	int c, sign;

	/* remove trailing spaces */
	while (isspace(c = getc(stdin)));

	/* return if end of file  or not a number */
	if (c == EOF) {
		return EOF;	
	}
	if (!isdigit(c) && c != '+' && c != '-' && c != '.') {
		ungetc(c, stdin);
		return 0;
	}

	/* sign handling */
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+'){
		c = getc(stdin);
	}
	if (!isdigit(c) && c!='.') {
		ungetc(c, stdin);
		return 0;
	}

	/* capture number value before '.' */
	int isnum = 0;
	*pn = 0;
	while(isdigit(c)){
		isnum = 1;
		*pn = *pn * 10 + c - '0';
		c = getc(stdin);
	} 
	/*capture numbervalue after '.' */
	if (c == '.') {
		int power = 1;
		c = getc(stdin);
		while (isdigit(c)) {
			isnum = 1;
			power *= 10;
			*pn = *pn * 10 + c - '0';
			c = getc(stdin);
		}
		*pn /= power;
	}
	*pn *= sign;
	ungetc(c, stdin);
	return isnum;
}
