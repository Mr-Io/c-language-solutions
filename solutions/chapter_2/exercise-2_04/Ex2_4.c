#include <stdio.h>

enum boolean {FALSE, TRUE};

int haschar(char s[], char c);
void squeeze(char s[], char e[]);

int main() 
{
	char s[] = "Hello my name is Mario, Mario Rigaud";
	char e[] = "aeiou";
	squeeze(s, e);
	printf("%s", s);
}

int haschar(char s[], char c) 
{
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == c) {
			return TRUE;
		}
	}
	return FALSE;

}

void squeeze(char s[], char e[])
{
	int i;
	int j;
	for (i = 0, j = 0; s[i] != '\0'; ++i) {
		if (haschar(e, s[i])==FALSE) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}
