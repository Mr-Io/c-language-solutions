#include <stdio.h>
#include <ctype.h>

/* return 1 on success, 0 if not a number and EOF on end of file */
int getint(int* pn);

int main()
{
	int res, n;

	do{
		printf("> ");
		res = getint(&n);
		switch (res){
		case 0:
			printf("Not an integer!\n");
			break;
		case 1:
			printf("Integer: %d\n", n);
			break;
		case EOF:
			printf("End Of File!\n");
			break;
		}
	}while (res > 0);

	return 0;
}

int getint(int* pn)
{
	int c;

	/* remove trailing spaces */
	while (isspace(c = getc(stdin)));

	/* return if end of file  or not a number */
	if (c == EOF) {
		return EOF;	
	}
	if (!isdigit(c) && c != '+' && c != '-') {
		ungetc(c, stdin);
		return 0;	
	}

	/* sign handling */
	int sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+'){
		c = getc(stdin);
	}
	if (!isdigit(c)) {
		ungetc(c, stdin);
		return 0;	
	}

	/* number computation */
	*pn = 0;
	while(isdigit(c)){
		*pn = *pn * 10 + c - '0';
		c = getc(stdin);
	} 
	*pn *= sign;
	ungetc(c, stdin);
	return 1;
}