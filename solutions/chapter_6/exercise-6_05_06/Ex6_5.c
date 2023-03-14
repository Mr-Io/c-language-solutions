#include "readutils.h"
#include "lookup.h"
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

int main()
{
	char w[MAXWORD];
	int res;
	char key[MAXWORD];
	char val[MAXWORD];
	struct keypair* kp;
	while ((res = getword(w, MAXWORD)) != EOF) {
		if (!strcmp(w, "#define")){
			putchar('\n');
			getword(key, MAXWORD);
			getword(key, MAXWORD);
			getline(val, MAXWORD);
			install(key, val);
			res = getword(w, MAXWORD);
		}
		else if (!strcmp(w, "#undef")) {
			putchar('\n');
			getword(key, MAXWORD);
			getword(key, MAXWORD);
			getline(val, MAXWORD);
			undef(key);
			res = getword(w, MAXWORD);
		}
		if ((kp = lookup(w)) != NULL)
			printf("%s", kp->value);
		else
			printf("%s", w);
	}
	printtable();
	
	return 0;
}
