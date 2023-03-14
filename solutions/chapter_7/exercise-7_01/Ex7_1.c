#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
	printf("%s\n", argv[0]);
	int(*to)(int) = toupper;
	if (!strcmp(argv[0], "lower")) // more than 1 executables needs to be done!
		to = tolower;

	int c;
	while ((c = getchar()) != EOF)
		putchar((*to)(c));

	return 0;
}
