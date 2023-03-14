#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
/*
typedef void* va_list;
#define va_start(p, arg) (p = ((va_list)&arg + sizeof(arg)))
#define va_arg(p, type) (*(type *)((p += sizeof(type))-sizeof(type)))
#define va_end(p) p = NULL;
*/

void minprintf(char* s, ...);

int main()
{
	minprintf("Mario-%8d-%u-%u-%.2f-%c-%5.3s-%10d", 29, 1u, -1, 10.4, 'm', "hello babe", 30);
	return 0;
}

#define MAXFORMAT 10

void minprintf(char* s, ...)
{
	union {
		int d;		// int, octal, hexadecimal, unsigned int, char
		double f;	// float, double, exponencial, g, G
		char* s;	// char* 
		void* p;	// void* 
	} arg;
	va_list ap;
	va_start(ap, s);
	int i, j;
	char format[MAXFORMAT];
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] != '%')
			putchar(s[i]);
		else {
			j = 0;
			format[j] = '%';
			do{
				format[++j] = s[++i];
			} while (j + 1 < MAXFORMAT && !isalpha(format[j])
				&& format[j] != '%' && format[j] != '\0');
			format[j+1] = '\0';
			switch (format[j]) {
			case 'd': case 'i': case 'o': case 'O': case 'x': case 'X': 
			case 'u': case 'c':
				arg.d = va_arg(ap, int);
				printf(format, arg.d);
				break;
			case 'f': case 'e': case 'E': case 'g': case 'G':
				arg.f = va_arg(ap, double);
				printf(format, arg.f);
				break;
			case 's':
				arg.s = va_arg(ap, char*);
				printf(format, arg.s);
				break;
			case 'p':
				arg.p = va_arg(ap, void*);
				printf(format, arg.p);
				break;
			case '%':
				printf("%%%%");
				break;
			default:
				printf("YIHAAAA");
				break;
			}
		}
	}
	va_end(ap);
}

