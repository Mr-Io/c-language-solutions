#include <stdio.h>
#include <ctype.h>

#define MAXLINE 80 
#define CINTLEN 20
#define V_LEN 6


enum {NUMBER};
enum {POSITIVE, NEGATIVE};


int mygetline(char *s, int n);
int atoi(const char* nptr);
void itoa(int n, char *str);
void reverse(char *str);
int strindex(char *s, char *t);
int getop(char *s);

int main()
{
	char s[MAXLINE], t[MAXLINE], number[MAXLINE];
	int slen, tlen;
	int n;
	while (1){
		// read a line
		do{
			printf("> ");
		}while((slen = mygetline(s, MAXLINE)) == 0);
		if (slen == -1){
			return -1;
		}
		// read a 2nd line
		do{
			printf("> ");
		}while((tlen = mygetline(t, MAXLINE)) == 0);
		if (tlen == -1){
			return -1;
		}

		// test functions
		printf("%03d: %s\n", slen, s);
		reverse(s);
		printf("rev: %s\n", s);
		reverse(s);
		printf("int: %d\n", n = atoi(s));
		itoa(n, number);
		printf("str: %s\n", number);
		printf("pos: %d\n", strindex(s, t));

		// read an operator (and discard rest of the line)
		printf("> ");
		getop(s);
		mygetline(t, MAXLINE);
		printf("ope: %s\n", s);
	}

	return 0;
}

/* 
* NON STANDARD
* read a line from stdin and store it in buffer `s` (whitout '\n')
* The total line is readed but at most `n` characters 
* are stored in `s` including the terminating '\0'.
* The total length of the line readed is returned. 
*/
int mygetline(char *s, int n) 
{
	int c, res;
	char *save_s = s;
	char *send = s + n;

	while(s < send - 2 &&  (c = getchar()) != EOF && c != '\n') {
		*s++ = c;
	}
	*s++ = '\0';

	res = s - save_s - 1;
	while (c != EOF && c != '\n'){
		c = getchar();
		++res;
	}
	return res;
}

/*
* STANDARD
* The  atoi() function converts the initial portion of the string 
* pointed to by `nptr` to int.
*/
int atoi(const char* nptr)
{
	// capture sign 
	int sign = (*nptr == '-') ? -1 : 1;
	if (*nptr == '-' || *nptr == '+'){
		++nptr;
	}
	// capture num values	
	int n=0;
	while (*nptr != '\0' && isdigit(*nptr)) {
		n = n * 10 + *nptr - '0';
		++nptr;
	}
	return sign * n;
}

/*
* NON STANDARD
* The itoa() function converts an integer `n` to a 
* null-terminated string and stores the result in the array 
* given by `str` parameter.
* If the value is negative, the resulting string is preceded 
* with a minus sign (-). 
*/
void itoa(int n, char *str)
{
    int sign;
    unsigned un;
	char *save_str = str;

    un = (unsigned) n;
    sign = n < 0 ? NEGATIVE : POSITIVE;
    if (n < 0){
        un = ~un + 1;
    }
    do{
        *str++ = un % 10 + '0';
    } while ((un /= 10) > 0);
    if (sign == NEGATIVE){
        *str++ = '-';
    }
    *str = '\0';
    reverse(save_str);
}

/*
* NON STANDARD
* The reverse() function reverse the sequence of characters
* in string `str` ('\n' will also get reversed!) 
*/
void reverse(char *str) 
{
	char *pend;
	pend = str;
	while (*pend != '\0'){
		++pend;
	}
	--pend;

	char c;
	while (str < pend){
		c = *str;
		*str++ = *pend;
		*pend-- = c;
	}
}

/* return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
	char *s_base, *t_base;
	char *s2;

	s_base = s;
	t_base = t;
	while (*s != '\0'){
		s2 = s;
		t = t_base;
		while (*s2 == *t && *t != '\0'){
			++s2;
			++t;
		}
		if (*t == '\0'){
			return s-s_base;
		}
		++s;
	}
	return -1;
}

/* get next operator or numeric operand */
int getop(char *s)
{
	int c; 

	while (isblank(*s = c = getchar()));
	*++s = '\0';
	if (!isdigit(c) && c != '.'){
		return c;	// not a number
	}
	if (isdigit(c)){ // collect integer part
		while (isdigit(*s++ = c = getchar()));
	}
	if (c == '.'){ // collect decimal part
		while (isdigit(*s++ = c = getchar()));
	}
	*--s = '\0';
	ungetc(c, stdin);
	return NUMBER;
}