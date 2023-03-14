#include <stdio.h>

void strcat(char* s, char* t) 
{
	while (*s++ != '\0');
	s--;
	while (*s++ = *t++);
}

int main()
{
	char s[100] = "Hello, ";
	char t[] = "Babe";

	strcat(s, t);
	printf("%s", s);

	return 0;
}
