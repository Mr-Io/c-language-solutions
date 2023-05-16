#include <stdio.h>

#define TABLEN 8

int main()
{
	int c;
	int nb = 0;
	int pos = 0;

	while ((c = getchar()) != EOF){
		if (c == ' '){
			++nb;	
		}else if (c == '\t'){
			putchar(c);
			nb = 0;
		} else {
			while(nb > 0){
				putchar(' ');
				--nb;
			}
			putchar(c);
		}
		++pos;
		if(c == '\n' || c == '\t' || pos == TABLEN){
			pos = 0;
			if (nb > 0){
				putchar('\t');
				nb = 0;
			}
		}
	}
	return 0;
}