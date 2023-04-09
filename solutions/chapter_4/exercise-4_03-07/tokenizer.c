#include "tokenizer.h"
#include "myio.h"
#include <stdio.h>
#include <ctype.h>

int isnumber(char s[]);
int ismath(char s[], char op[]);
int isvar(char s[]);

/*
* store a word in buffer s, indicating n as its maximum size
* trailing blanks are removed.
* a newline is considered a word of length 1, independently if it is colliding or now with another word.
* return the number of character readed 
* return 0 if EOF before any word or newline is encountered 
* return -1 if buffer s is not long enough to hold the word
*/
int getword(char s[], unsigned n);

int gettoken(char s[], int n)
{
	/* get next word */
	if (getword(s, n) == -1){
		return -1;
	}

	/* check its type: digit, math, variable or operator */
	if (isnumber(s)){
		return NUM;
	}else if (isvar(s)){
		return VAR;
	}else if (ismath(s, "pow")){
		return POW;
	}else if (ismath(s, "exp")){
		return EXP;
	}else if (ismath(s, "sin")){
		return SIN;
	}else if (ismath(s, "swap")){
		return SWP;
	}else if (ismath(s, "dup")){
		return DUP;
	}else if (ismath(s, "del")){
		return DEL;
	}else if (ismath(s, "clear")){
		return CLR;
	}else if (isvar(s)){
		return VAR;
	}
	return s[0];
}

int getword(char s[], unsigned n)
{
    int c, i;

	/* remove trailing blank lines */
	i = 0;
	while(isblank(c = getch()));
	if (c != EOF){
		s[i++] = c;
	}

	/* return if '\n' */
	if (c == '\n'){
		s[i] = '\0';
		return 1;
	}

	/* read every character until a blank or newline */
	while(i < n && (c = getch()) != EOF && !isblank(c) && c != '\n'){
		s[i++] = c;
	}

	/* error if n is not long enough - we do not try to recover */
	if (i >= n){
		return -1;
	}

	/* ungetch last character and return */
	s[i] = '\0';
	if (ungetch(c) == -1){
		return -1;
	}
    return i;
}

/* return 1 if s represent a number or 0 if not */
int isnumber(char s[])
{
	int i;
	/* get sign */
	i = 0;
	if ((s[0] == '+' || s[0] == '-') && s[1] != '\0'){
		++i;
	}
	/* get all digits including '.' */
	while(isdigit(s[i])){
		++i;
	}
	if (s[i] == '.'){
		++i;
	}
	while(isdigit(s[i])){
		++i;
	}
	/* check and return */
	if (i > 0 && s[i] == '\0'){
		return 1;
	}
	return 0;
}

int ismath(char s[], char op[])
{
	int i;
	for (i = 0 ; s[i] == op[i] && s[i] != '\0' ; ++i);
	if (s[i] == op[i] && s[i] == '\0'){
		return 1;
	}
	return 0;
}

int isvar(char s[])
{
	if (s[0] >= 'a' && s[0] <= 'z' && s[1] == '\0'){
		return 1;
	}
	return 0;
}

