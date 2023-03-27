#include <stdio.h>
#include <limits.h>
#include <float.h>


float uint2float(unsigned int n);
double uint2double(long unsigned int n);

int main()
{
	printf("(In this machine 'char == signed char')\n");
	printf("           %24s%24s\n", "standard header",   "direct computation");
	printf("           %24s%24s\n", "---------------",   "------------------");
	/* CHAR */
	/* unsigned char */
	printf("UCHAR_MAX: %24d", UCHAR_MAX);
	printf("%24u\n", (unsigned char)~0);
	/* signed char */
	printf("SCHAR_MIN: %24d", SCHAR_MIN);
	printf("%24d\n", (signed char)(1 << (sizeof(signed char)*8 - 1)));
	printf("SCHAR_MAX: %24d", SCHAR_MAX);
	printf("%24d\n", (signed char)~(1 << (sizeof(signed char)*8 - 1)));
	/* char */
	printf("CHAR_MIN:  %24d", CHAR_MIN);
	printf("%24d\n", (char)(1 << (sizeof(char)*8 - 1)));
	printf("CHAR_MAX:  %24d", CHAR_MAX);
	printf("%24d\n", (char)~(1 << (sizeof(char)*8 - 1)));
	putchar('\n');
	/* INT */
	/* unsigned short int */
	printf("USHRT_MAX: %24d", USHRT_MAX);
	printf("%24u\n", (unsigned short int)~0);
	/* signed short int */
	printf("SHRT_MIN:  %24d", SHRT_MIN);
	printf("%24d\n", (short int)(1 << (sizeof(short int)*8 - 1)));
	printf("SHRT_MAX:  %24d", SHRT_MAX);
	printf("%24d\n", (short int)~(1 << (sizeof(short int)*8 - 1)));
	/* unsigned int */
	printf("UINT_MAX:  %24u", UINT_MAX);
	printf("%24u\n", (unsigned int)~0);
	/* signed int */
	printf("INT_MIN:   %24d", INT_MIN);
	printf("%24d\n", (int)(1 << (sizeof(int)*8 - 1)));
	printf("INT_MAX:   %24d", INT_MAX);
	printf("%24d\n", (int)~(1 << (sizeof(int)*8 - 1)));
	/* unsigned long int */
	printf("ULONG_MAX: %24lu", ULONG_MAX);
	printf("%24lu\n", (long int)~0l);
	/* signed long int */
	printf("LONG_MIN:  %24ld", LONG_MIN);
	printf("%24ld\n", (long int)(1l << (sizeof(long int)*8l - 1l)));
	printf("LONG_MAX:  %24ld", LONG_MAX);
	printf("%24ld\n", (long int)~(1l << (sizeof(long int)*8l - 1l)));
	putchar('\n');
	/* FLOAT */
	printf("FLT_MIN:   %24e", FLT_MIN);
	printf("%24e\n", uint2float(1));
	printf("FLT_MAX:   %24e", FLT_MAX);
	printf("%24e\n", -uint2float(~(1u << 23)));
	putchar('\n');
	/* DOUBLE */
	printf("DBL_MIN:   %24e", DBL_MIN);
	printf("%24e\n", uint2double(1));
	printf("DBL_MAX:   %24e", DBL_MAX);
	printf("%24e\n", -uint2double(~(1lu << 52)));
	return 0;
} 

float uint2float(unsigned int n)
{
	union utmp{
		unsigned int i;
		float f;
	};
	union utmp t;
	t.i = n;
	return t.f;
}

double uint2double(long unsigned int n)
{
	union utmp{
		long unsigned int i;
		double f;
	};
	union utmp t;
	t.i = n;
	return t.f;
}