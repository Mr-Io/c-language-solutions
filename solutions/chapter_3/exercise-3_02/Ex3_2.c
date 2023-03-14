#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);
void revescape(char s[], char t[]);

int main() 
{
	char s[MAXLINE];
	char t[] = "\\ \?\bhello, \fpeople,\r\t\"I am \* Mario\'\n";
	escape(s, t);
	printf("%s\n", t);
	printf("%s\n\n", s);
	revescape(s, s);
	printf("%s\n", s);


}

void revescape(char s[], char t[])
{
	int i;
	int j;
	for (i = 0, j = 0; t[i] != '\0'; ++i) {
		if (t[i] == '\\')
		switch (t[i+1]) {
		case 'a':
			s[j++] = '\a';
			++i;
			break;
		case 'b':
			s[j++] = '\b';
			++i;
			break;
		case 'f':
			s[j++] = '\f';
			++i;
			break;
		case 'n':
			s[j++] = '\n';
			++i;
			break;
		case 'r':
			s[j++] = '\r';
			++i;
			break;
		case 't':
			s[j++] = '\t';
			++i;
			break;
		case '\\':
			s[j++] = '\\';
			++i;
			break;
		case '\?':
			s[j++] = '\?';
			++i;
			break;
		case '\'':
			s[j++] = '\'';
			++i;
			break;
		case '\"':
			s[j++] = '\"';
			++i;
			break;
		default:
			s[j++] = '\\';
		}
		else {
			s[j++] = t[i];
		}
	}
	s[j] = '\0';
}
void escape(char s[], char t[])
{
	int i;
	int j;
	for (i = 0, j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
		case '\a':
			s[j++] = '\\';
			s[j++] = 'a';
			break;
		case '\b':
			s[j++] = '\\';
			s[j++] = 'b';
			break;
		case '\f':
			s[j++] = '\\';
			s[j++] = 'f';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\r':
			s[j++] = '\\';
			s[j++] = 'r';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\\':
			s[j++] = '\\';
			s[j++] = '\\';
			break;
		case '\?':
			s[j++] = '\\';
			s[j++] = '\?';
			break;
		case '\'':
			s[j++] = '\\';
			s[j++] = '\'';
			break;
		case '\"':
			s[j++] = '\\';
			s[j++] = '\"';
			break;
		default:
			s[j++] = t[i];
		}
	}
	s[j] = '\0';
}
