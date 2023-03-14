#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define MAXFORMAT 10
#define MAXSTRING 100

void minscanf(char* s, ...);

int main()
{
	int i;
	float f;
	double lf;
	char c;
	char s[MAXSTRING];
	char s2[MAXSTRING];
	//stdin for example: 123m 143.124 /mario-17.8 Hello-babe-cap this
	minscanf("%d%c%%%f /mario%lf %5s-%s", &i, &c, &f, &lf, s, s2);
	printf("%d\n", i);
	printf("%c\n", c);
	printf("%f\n", f);
	printf("%lf\n", lf);
	printf("%s\n", s);
	printf("%s\n", s2);
	return 0;
}

void delspaces() {
	int c;
	while(isspace(c = getchar()));
	if (c!=EOF)
		ungetc(c, stdin);
}

void minscanf(char* s, ...)
{
	va_list ap;
	va_start(ap, s);
	void* p;
	char format[MAXFORMAT];
	int i, j, c;
	for (i = 0; s[i] != '\0'; ++i) {
		if (isspace(s[i])) {
			delspaces();
			while (isspace(s[i]))
				++i;
		}
		if (s[i] == '%') {
			//get format
			j = 0;
			format[j] = '%';
			do {
				format[++j] = s[++i];
			} while (j + 1 < MAXFORMAT && !isalpha(format[j]) && format[j] != '%');
			if (format[j] == 'h' || format[j] == 'l')
				format[++j] = s[++i];
			format[j+1] = '\0';
			//get argument
			switch (format[j]) {
			case 'd': case 'i': case 'o': case 'u': case 'x':
			case 'c': case 's': case 'e': case 'f': case 'g':
				p = va_arg(ap, void*);
				scanf(format, p); //implicit casting of (void*) to its correct type
				break;
			case '%':
				delspaces();
				if ((c = getchar()) != '%')
					ungetc(c, stdin);
				break;
			default:
				printf("error: unknown type '%c'\n", format[j]);
				return;
				break;
			}
		}
		else { //delete from stdin if it is a matching character
			delspaces();
			if ((c = getchar()) != s[i])
				ungetc(c, stdin);
		}
	}
	va_end(ap);
}