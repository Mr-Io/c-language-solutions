#include <stdio.h>

#define MAXLINE 1000
#define COLUMN 20

int getline(char line[], int max);
void divideLine(char s[], int len);

int main()
{
	char s[MAXLINE]; 
	int len;

	while ((len=getline(s, MAXLINE))!= 0) {
		divideLine(s, len);
		printf(s);
	}
	return 0;
}

void divideLine(char s[],int len) 
{
	int start = 0;
	while (len - start > COLUMN) {
		int i;
		for (i = start + COLUMN-1; i > start; --i) {
			if (s[i] == ' ') {
				s[i] = '\n';
				break;
			}
		}
		if (i == start) { /*No blanck line before COLUMN :( -> search after column*/
			for (i = start + COLUMN; i < len; ++i) {
				if (s[i] == ' ') {
					s[i] = '\n'; 
					break;
				}
			}
		}
		start = i+1; 
	}
}


int getline(char s[], int lim) {
	int c, i;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1) {
			s[i] = c;
		}
	}
	if (c == '\n' && i < lim-1) {
		s[i] = c;
		++i;
	}
	if (i < lim - 1)
		s[i] = '\0';
	else {
		s[lim - 2] = '\n';
		s[lim - 1] = '\0';
	}
	return i;
}