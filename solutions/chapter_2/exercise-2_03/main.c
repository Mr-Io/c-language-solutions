#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100

int chtoi(char c);
int htoi(const char s[]);

int getword(char s[], int n);

int main()
{
	char s[MAXWORD];
	int len;
	int c;
	while((c = getchar()) != EOF ){
		if (getword(s, MAXWORD) > 0){
			printf("%d\n", htoi(s));
		}
	}
	return 0;
} 

/* 
* return the equivalent positive integer value of a single hexadecimal char 
* return -1 on error
*/
int chtoi(char c) 
{
	if (!isxdigit(c)){
		return -1;
	}
	c = tolower(c);
	if (isdigit(c)){
		return c - '0';
	}else{
		return c - 'a' + 10;
	}
}

/* 
* return the equivalent positive integer value of a string of hexadecimal digits
* return -1 on error
*/
int htoi(const char s[]) 
{
	int vc;
	int n=0;
	int i=0;
	if (s[0] == '0' && tolower(s[1]) == 'x') {
		i = 2;
	}
	for( ; s[i] != '\0' ; ++i) {
		if ((vc = chtoi(s[i])) == -1){
			return -1;
		}
		n = n * 16 + vc;
	}
	return n;
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