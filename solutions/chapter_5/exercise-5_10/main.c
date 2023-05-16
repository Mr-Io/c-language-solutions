#include "stack.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

static void usage_error(void);
static int isnumber(const char *s);

int main(int argc, char* argv[]) 
{
	if(argc < 2){
		usage_error();
	}

	double op1, op2;
	while (--argc > 0){
		if (isnumber(*++argv)){	// number
			push(atof(*argv));
		}else{					// operator
			if (strlen(*argv) != 1){
				usage_error();
			}	
			op2 = pop();
			op1 = pop();
			switch(**argv){
			case('+'):
				push(op1 + op2);
			break;
			case('-'):
				push(op1 - op2);
			break;
			case('*'):
				push(op1 * op2);
			break;
			case('/'):
				push(op1 / op2);
			break;
			}
		}
	}

	//  only one number must remain on stack
	double res;
	res = pop();
	if (!isnan(pop())){
		usage_error();
	}
	printf("%.2f\n", res);
	
	return 0;
}

/* error function helper */
static void usage_error(void)
{
	fprintf(stderr, "error. Usage: expr <numbers and operators>\n");
	exit(-1);
}

/* return 1 if s represent a number or 0 if not */
static int isnumber(const char *s)
{
	int i;
	/* get sign */
	i = 0;
	if ((s[0] == '+' || s[0] == '-') && s[1] != '\0'){
		++i;
	}
	/* get all digits including '.' */
	while(isdigit(s[i])){
		++i;
	}
	if (s[i] == '.'){
		++i;
	}
	while(isdigit(s[i])){
		++i;
	}
	/* check and return */
	if (i > 0 && s[i] == '\0'){
		return 1;
	}
	return 0;
}