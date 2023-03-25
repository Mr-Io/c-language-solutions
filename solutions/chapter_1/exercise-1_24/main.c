#include <stdio.h>

# define MAXNESTED 16


void in_comment(void);
void in_string(char c);
int popsep(void);
int pushsep(char c);
int check_separators(int c);


char separatorstack[MAXNESTED];
int pos = 0;


/* program that check unbalanced parentheses, brackets and braces */
int main()
{
	int c;
	int res;

	while ((c = getchar()) != EOF) {
		if (c == '/'){
			if ((c = getchar()) != '*'){
				if ((res = check_separators(c)) == -1){
					printf("error\n");
					return 1;
				}else if(res == 1){
					printf("Unbalanced separators\n");
					return 0;
				}
			}else{
				in_comment();
			}
		}else if (c == '"' || c == '\''){
			in_string(c);
		}else{
			if ((res = check_separators(c)) == -1){
				printf("error\n");
				return 1;
			}else if(res == 1){
				printf("Unbalanced separators\n");
				return 0;
			}
		}
	}
	if (pos == 0){
		printf("Balanced separators\n");
	}else{
		printf("Unbalanced separators\n");
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

	while((c = getchar()) != EOF){
		if (c == '\\'){
			getchar();
		}
		if (c == edge){
			return;
		}
	}
}

/* return 0 on success and -1 on error */
int pushsep(char c)
{
	extern char separatorstack[MAXNESTED];
	extern int pos;

	if (pos >= MAXNESTED){
		return -1;
	}else{
		separatorstack[pos++] = c;
	}
	return 0;
}

/* return a char value on success and EOF if the stack is empty */
int popsep(void)
{
	extern char separatorstack[MAXNESTED];
	extern int pos;

	if (pos <= 0){
		return EOF;
	}else{
		return separatorstack[--pos];
	}
}

/* 
* return 0 is everything is ok,
* return 1 if an unbalance separator is detected and
* return -1 on error  
*/
int check_separators(int c)
{
	if (c == '(' || c == '[' || c == '{'){
		if (pushsep(c) == -1){
			return -1;
		}
	}else if (c == ')'){
		if (popsep() != '('){
			return 1;
		}
	}else if (c == ']'){
		if (popsep() != '['){
			return 1;
		}
	}else if (c == '}'){
		if (popsep() != '{'){
			return 1;
		}
	}
	return 0;
}