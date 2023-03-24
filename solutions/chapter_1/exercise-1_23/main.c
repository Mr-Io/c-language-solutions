#include <stdio.h>

void in_comment(void);
void in_string(char c);

/* program that eliminates C comments */
int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '/'){
			if ((c = getchar()) != '*'){
				putchar('/');
				putchar('c');
			}else{
				in_comment();
			}
		}else if (c == '"' || c == '\''){
			in_string(c);
		}else{
			putchar(c);
		}
	}
	return 0;
}

void in_comment(void)
{
	int last_c;
	int c;

	last_c = getchar();
	while ((c = getchar()) != EOF){
		if (last_c == '*' && c == '/'){
			return;
		}
		last_c = c;
	}
}

void in_string(char edge)
{
	int c;

	putchar(edge);
	while((c = getchar()) != EOF){
		putchar(c);
		if (c == '\\'){
			putchar(getchar());
		}
		if (c == edge){
			return;
		}
	}
}