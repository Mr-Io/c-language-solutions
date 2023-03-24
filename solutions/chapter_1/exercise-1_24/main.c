#include <stdio.h>

#define FALSE 0
#define TRUE 1

int check_char() {
	int c;
	c = getchar();
	if (c  == '\'') {
		return FALSE;		/* quoted string should contain at least one character*/
	} 
	else if (c == '\\') {	/* scape character */
		getchar();
	}
	if (getchar() == '\'') {
		return TRUE;
	}
	return FALSE;
}

int check_string() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\\') {	/*	Scape character	*/
			getchar();
		}
		if (c == '"') { 
			return TRUE;
		}
	}
	return FALSE;
}

int check_comment() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '*' && getchar()=='/') {
			return TRUE;
		}
	}
	return FALSE;
}

int check_csc(char c) {
	if (c == '\'' && check_char() == FALSE) {
		return EOF;
	}
	else if (c == '"' && check_string() == FALSE) {
		return EOF;
	}
	else if (c == '/'){
		c = getchar();
		if (c == EOF) {		/* when the last character of file is '/'	*/
			return '/0';	/* just return a whatever character			*/
		}
		if (c == '*' && check_comment() == FALSE) {
			return EOF;
		}
	}
	return c;
}

int check_end(char end) {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == end) {
			return TRUE;
		}
		if (check_syntax(c) == FALSE) {
			return FALSE;
		}
	}
	return FALSE;
}

int check_pbb(char c) {
	if (c == '(' && check_end(')') == FALSE) {
		return FALSE;
	}
	else if (c == '[' && check_end(']') == FALSE) {
		return FALSE;
	}
	else if (c == '{' && check_end('}') == FALSE) {
		return FALSE;
	}
	else if (c == ')' || c == ']' || c == '}') {
		return FALSE;
	}
	return TRUE;
}

int check_syntax(char c) { 
	if ((c = check_csc(c)) == EOF) {
		return FALSE;
	}
	if (check_pbb(c) == FALSE) {
		return FALSE;
	}
	return TRUE; 
}

int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (check_syntax(c) == FALSE) {
			printf("INVALID SYNTAX\n");
			break;
		}
	}
}
