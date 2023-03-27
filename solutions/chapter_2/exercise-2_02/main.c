#include <stdio.h>

#define MAXLINE 1000

enum {CONTINUE, BREAK};

int main()
{
	char s[MAXLINE];
	int lim = MAXLINE;
	int c;
	int i;
	/*
	* 	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	*		s[i] = c;
	* 	}
    */
	/* equivalent loop */
	int cont;
	for (i = 0, cont = CONTINUE; cont == CONTINUE; ++i){
		if (i >= lim - 1){
			cont = BREAK;
		}else if ((c = getchar()) == EOF ){
			cont = BREAK;
		}else if (c == '\n'){
			cont = BREAK;
		}else{
			s[i] = c;
		}
	}
	s[i-1] = '\0';
	printf("%s\n", s);
	return 0;
}