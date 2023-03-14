#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define HEXLEN 4

int pos = 0;
void incp(int n);

int main()
{
	int c;
	while ((c = getchar()) != EOF){
		if (isprint(c)) {
			incp(1);
			putchar(c);
		}
		else {
			incp(4);
			printf("\\%02Xx", c);
		}
		if (c == '\n') {
			pos = 0;
			putchar(c);
		}
	}
	return 0;
}

void incp(int n)
{
	if ((pos + n) <= MAXLINE) {
		pos += n;
	}
	else {
		putchar('\n');
		pos = n;
	}
}
