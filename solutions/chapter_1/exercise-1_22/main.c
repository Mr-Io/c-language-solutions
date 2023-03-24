#include <stdio.h>
#include <ctype.h>

#define MAXWORD 20
#define LINEWIDTH 40
#define TABLEN 8

int getword(char s[], int n);

int main()
{
	int c;
	int len;
	char w[MAXWORD];
	char s[LINEWIDTH];
	int pos;

	pos = 0;
	while ((c = getchar()) > 0)	{
		if (c == ' '){
			putchar(c);
			++pos;
		}else if (c == '\n'){
			putchar(c);
			pos = 0;
		}else if (c == '\t'){
			putchar(c);
			pos = (pos/TABLEN + 1) * TABLEN;
		}else{
			if(ungetc(c, stdin) == EOF){
				printf("ungetc() error\n");
				return -1;
			}
			if ((len = getword(s, MAXWORD)) == -1){
				printf("getword() error\n");
				return -1;
			}
			if (len + pos < LINEWIDTH){
				pos += len;
			}else{
				putchar('\n');
				pos = len;
			}
			printf("%s", s);
		}
	}
	return 0;
}

/* 
* A word is any sequence of characters that do not contain a blank, tab or newline. 
* At maximum `n` characters are buffered, the rest remain on stdin.
* if 0 characters are readed before encountering a  blank, tab or newline; 0 is returned.
* if 0 characters are readed before encountering EOF or there is any error; -1 is returned.
*/
int getword(char s[], int n) 
{
    int c, i;

    for (i = 0; i<n-1 && (c = getchar()) != EOF && !isblank(c) &&  c != '\n'; ++i) {
        s[i] = c;
    }
    s[i] = '\0';
	if (isblank(c) || c == '\n'){
		if (ungetc(c, stdin) == EOF){
			return -1;
		}
	}else if(c == EOF && i == 0){
		i = -1;
	}
    return i;
}