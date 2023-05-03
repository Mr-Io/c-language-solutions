#include <stdio.h>

#define MAXLINE 40

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	char line[MAXLINE], longest[MAXLINE];
	int len=0, max=0;

	while ((len = mygetline(line, MAXLINE)) > 0){
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0){
		printf("longest line(%d):%s", max, longest);
	}
	return 0;
}

/* 
* read a line from stdin and store it in buffer `s`
* The total line is readed but at most `n` characters 
* are stored in `s` including `\n` and the terminating '\0'.
* The total length of the line readed is returned. 
*/
int mygetline(char s[], int lim) 
{
	int c, i;

	for (i = 0; i<lim-2 &&  (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c != EOF || i != 0){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';

	while (c != EOF && c != '\n'){ /* Everylane has '\n' except EOF with 0 length */
		c = getchar();
		++i;
	}
	return i;
}

void copy(char to[], char from[]) 
{
	int i = 0;
	for (i = 0; from[i] != '\0'; ++i){
		to[i] = from[i];
	}
	to[i] = '\0';
}
