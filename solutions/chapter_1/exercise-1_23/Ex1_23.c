#include <stdio.h>

#define NORMAL 0
#define INSTRING 1
#define INCHAR 2
#define INCOMMENT 3

int main()
{
	int state = NORMAL;
	int c;
	int last_c = '\0';

	while ((c = getchar()) != EOF) {
		if ((state == INSTRING	&& c == '"' ) || (state == INCHAR	&& c == '\''))  {
			state = NORMAL;
			putchar(c);
		}
		else if (state == INCOMMENT && (last_c == '*' && c == '/')) {
			state = NORMAL;
		}
		else if (c == '"' && state==NORMAL) {
			state = INSTRING;
			putchar(c);
		}
		else if (c == '\'' && state==NORMAL) {
			state = INCHAR;
			putchar(c);
		}
		else if (c == '/' && state==NORMAL){
			if ((c = getchar()) == '*') {
				state = INCOMMENT;
			} 
			else { 
				putchar('/');
				putchar(c);
			}
		}
		else if (state != INCOMMENT) { 
			putchar(c);
		}
		last_c = c;
	}
}
