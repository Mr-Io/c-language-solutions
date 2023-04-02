#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 80

void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);

int main() 
{
	char s[MAXLINE]; 
	char *t;
	int len;
	long unsigned n;

	t = NULL;
	n = 0;
	while ((len = getline(&t, &n, stdin)) > 0){
		if (len >= MAXLINE){
			printf("error: line too long (max. size:%d)\n", MAXLINE);
			return 1;
		}
		escape(s, t);
		printf("%s\n", s);
		unescape(t, s);
		printf("%s", t);
	}
	free(t);
	return 0;
}


void escape(char s[], const char t[])
{
	int i, j;
	for (i = 0, j = 0; t[i] != '\0'; ++i, ++j) {
		switch (t[i]) {
		case '\a':
			s[j] = '\\';
			s[++j] = 'a';
			break;
		case '\b':
			s[j] = '\\';
			s[++j] = 'b';
			break;
		case '\f':
			s[j] = '\\';
			s[++j] = 'f';
			break;
		case '\n':
			s[j] = '\\';
			s[++j] = 'n';
			break;
		case '\r':
			s[j] = '\\';
			s[++j] = 'r';
			break;
		case '\t':
			s[j]= '\\';
			s[++j] = 't';
			break;
		case '\\':
			s[j] = '\\';
			s[++j] = '\\';
			break;
		case '\?':
			s[j] = '\\';
			s[++j] = '\?';
			break;
		case '\'':
			s[j] = '\\';
			s[++j] = '\'';
			break;
		case '\"':
			s[j] = '\\';
			s[++j] = '\"';
			break;
		default:
			s[j] = t[i];
		}
	}
	s[j] = '\0';
}

void unescape(char s[], const char t[])
{
	int i, j;
	for (i = 0, j = 0; t[i] != '\0'; ++i, ++j) {
		if (t[i] != '\\'){
			s[j] = t[i];
		}else{
			switch (t[i+1]) {
		    case 'a':
			    s[j] = '\a';
			    ++i;
			    break;
		    case 'b':
			    s[j] = '\b';
			    ++i;
			    break;
		    case 'f':
			    s[j] = '\f';
			    ++i;
			    break;
		    case 'n':
			    s[j] = '\n';
			    ++i;
			    break;
		    case 'r':
			    s[j] = '\r';
			    ++i;
			    break;
		    case 't':
			    s[j] = '\t';
			    ++i;
			    break;
		    case '\\':
			    s[j] = '\\';
			    ++i;
			    break;
		    case '\?':
			    s[j] = '\?';
			    ++i;
			    break;
		    case '\'':
			    s[j] = '\'';
			    ++i;
			    break;
		    case '\"':
			    s[j] = '\"';
			    ++i;
			    break;
		    default:
			    s[j] = '\\';
		    }
		}
	}
	s[j] = '\0';
}