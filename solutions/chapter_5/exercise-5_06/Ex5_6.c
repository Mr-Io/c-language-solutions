#include <stdio.h>
#include <ctype.h>

char* strstr(char* haystack, char* needle);
int atoi(const char* s);
char* itoa(int n, char* s);		// no standard,the maximum length must be provided
char* reverse(char* s);			// no standard

#define MAXLINE 100
char* getline(char* s, int lim);

// main program
int main()
{
	printf("%s\n", strstr("Mario Riga Rigaud", "Riga"));
	printf("%s\n", strstr("Mario Riga Rigaud", "Rigua"));

	char a[] = "Mario";
	char b[] = "";
	char c[] = "12ab34";
	printf("%s\n", reverse(a));
	printf("%s\n", reverse(b));
	printf("%s\n", reverse(c));

	printf("%d\n", atoi("-1234"));
	printf("%d\n", atoi("12ab34"));
	printf("%d\n", atoi(""));
	printf("%d\n", atoi("-"));

	printf("%s\n", itoa(1234, c));
	printf("%s\n", itoa(-1234, c));
	printf("%s\n", itoa(0, c));

	char s[MAXLINE];
	printf("%s\n", getline(s, MAXLINE));
	printf("%s\n", getline(s, MAXLINE));
	printf("%s\n", getline(s, MAXLINE));

	return 0;
}

char* strstr(char* haystack, char* needle) 
{
	int i, j, k;
	for (i = 0; haystack[i]!='\0' ; ++i) {
		for (k = i, j = 0; haystack[k] == needle[j] && haystack[k] != '\0'; ++k, ++j);
		if (needle[j] == '\0')
			return haystack + i;
	}
	return NULL;
}


int atoi(const char* s)
{
	//capture sign
	int sign = (*s == '-')?-1:1;
	if (*s == '-' || *s == '+')
		++s;
	// capture num values	
	int n=0;
	while (*s != '\0' && isdigit(*s)) {
		n = n * 10 + *s -'0';
		s++;
	}
	return sign * n;
}

char* itoa(int n, char* s) 
{
	char* tmp = s;
	//represent sign
	int sign=0;
	if (n < 0) {
		n = -n;
		sign = -1;
	}
	//represent number
	while (n > 10) {
		*s = n % 10 + '0';
		n /= 10;
		++s;
	}
	*s++ = n + '0';
	if (sign == -1)
		*s++ = '-';
	*s = '\0';
	reverse(tmp);
	return tmp;
}

int strlen(char* s) {
	int n;
	for (n = 0; s[n] != '\0'; n++);
	return n;
}

char* reverse(char* s)
{
	int i, j;
	char ctmp;
	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		ctmp = s[i];
		s[i] = s[j];
		s[j] = ctmp;
	}
	return s;
}

char* getline(char* s, int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	s[i] = '\0';
	printf(">>> %s\n", s);
	return s;
}
