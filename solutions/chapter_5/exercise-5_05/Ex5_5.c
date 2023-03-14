#include <stdio.h>

char* strncpy(char* s, char* t, int n) 
{
	char* tmp = s;
	
	while (n-- > 0 && (*s++ = *t++));
	return tmp;
}

int strncmp(char* s, char* t, int n) 
{
	int i;
	for (i=0; *s == *t && *s != '\0' && i < n-1; ++i, ++s, ++t);
	return *(s) - *(t);
}

char* strncat(char* s, char* t, int n) 
{
	char* sstart = s;
	while (*s++ != '\0');
	s--;

	int	i;
	for (i = 0; i < n && (s[i] = t[i]); ++i);
	if (s[i] != '\0')
		s[i + 1] = '\0';
	return sstart;
}

int main()
{
	char s[100] = "Hello, ";
	char t[] = "babe";

	printf("%s\n", strncat(s, t, 3));
	
	printf("%d\n", strncmp("abcda", "abcda", 100));
	printf("%d\n", strncmp("abcda", "abcdz", 100));
	printf("%d\n", strncmp("abcdz", "abcda", 100));

	printf("%d\n", strncmp("abcda", "abcda", 5));
	printf("%d\n", strncmp("abcda", "abcdz", 5));
	printf("%d\n", strncmp("abcdz", "abcda", 5));

	printf("%d\n", strncmp("abcda", "abcda", 4));
	printf("%d\n", strncmp("abcda", "abcdz", 4));
	printf("%d\n", strncmp("abcdz", "abcda", 4));

	printf("%d\n", strncmp("", "abcda", 4));
	printf("%d\n", strncmp("abcda", "", 4));
	printf("%d\n", strncmp("abc", "abcdef", 4));

	printf("%s\n", strncpy(s, t, 2));
	printf("%s\n", strncpy(s, "I am Mario", 100));
	printf("%s\n", strncpy(s, t, -3));
	printf("%s\n", strncpy(s, t, 0));
	printf("%s\n", strncpy(s, t, 10));

	return 0;
}
