#include <stdio.h>

enum boolean {FALSE, TRUE};

int haschar(char s[], char c);
int any(char s[], char e[]);

int main() 
{
	printf("%d", any("Hello my name is Mario", "xMzjo"));
	return 0;
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

int any(char s1[], char s2[])
{
	int i;
	int j;
	for (i = 0, j = 0; s1[i] != '\0'; ++i) {
		if (haschar(s2, s1[i])==TRUE) {
			return i;
		}
	}
	return -1;
}
