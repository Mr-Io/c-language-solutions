#include <stdio.h>
#include <ctype.h>

int chtoi(char c) {
	if (!isxdigit(c)) {
		return -1;
	}
	c = tolower(c);
	if (isdigit(c)) {
		return c - '0';
	}
	else {
		return c - 'a' + 10;
	}
}

int htoi(const char s[]) {
	int vc;
	int n=0;
	int i=0;
	if (s[0] == '0' && tolower(s[1]) == 'x') {
		i = 2;
	}
	while (s[i] != '\0') {
		if ((vc = chtoi(s[i])) == -1) {
			return -1;
		}
		else {
			n = n * 16 + vc;
		}
		++i;
	}
	return n;
}

int main()
{
	printf("%d", htoi("0xFF"));

} 

