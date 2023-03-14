#include <stdio.h>
#include <limits.h>
#include <float.h>


int main()
{
	printf("CHAR_BIT:  %12d\n", CHAR_BIT);
	printf("CHAR_MIN:  %12d\n", CHAR_MIN);
	printf("CHAR_MAX:  %12d\n", CHAR_MAX);
	printf("In this machine 'char == signed char'\n");
	putchar('\n');
	printf("INT_MIN:   %12d\n", INT_MIN);
	printf("INT_MAX:   %12d\n", INT_MAX);
	printf("SHRT_MIN:  %12d\n", SHRT_MIN);
	printf("SHRT_MAX:  %12d\n", SHRT_MAX);
	printf("LONG_MIN:  %12ld\n", LONG_MIN);
	printf("LONG_MAX:  %12ld\n", LONG_MAX);
	putchar('\n');
	printf("UCHAR_MAX: %12d\n", UCHAR_MAX);
	printf("UINT_MAX:  %12u\n", UINT_MAX);
	printf("USHRT_MAX: %12d\n", USHRT_MAX);
	printf("ULONG_MAX: %12lu\n", ULONG_MAX);
	putchar('\n');
	putchar('\n');

	printf("FLT_DIG:   %12d\n", FLT_DIG);
	printf("FLT_MIN:   %12e\n", FLT_MIN);
	printf("FLT_MAX:   %12e\n", FLT_MAX);
	putchar('\n');
	printf("DBL_DIG:   %12d\n", DBL_DIG);
	printf("DBL_MIN:  %13e\n", DBL_MIN);
	printf("DBL_MAX:  %13e\n", DBL_MAX);

	printf("%f", -1.0);
} 