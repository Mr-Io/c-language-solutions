#include "variables.h"
#include <stdio.h>
#include <math.h>

#define VARSIZE ('z' - 'a' + 1)

double vars[VARSIZE];
	
/* initialize variables values */
void initvar(void)
{
	int i;
	for (i = 0 ; i < VARSIZE ; ++i){
		vars[i] = NAN;
	}
}


double getvar(char var)
{
	return vars[var - 'a'];
}

void setvar(char var, double x)
{
	vars[var - 'a'] = x;
}

int hasvalue(char var)
{
	return !isnan(vars[var - 'a']);
}

void printvar(void)
{
	double v;
	int somevar;
	int i;

	somevar=0;
	printf("(");
	for (i = 0 ; i < VARSIZE ; ++i){
		v = vars[i];
		if (!isnan(v)){
			somevar = 1;
			printf("%c=%.1f, ", 'a' + i, v);
		}
	}
	if (somevar){
		printf("\b\b)\n");
	}else{
		printf("\b");
	}
}