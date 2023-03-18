#include <stdio.h>

int main()
{
	int bc = 0;
	int c;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			++bc;
		}
	}
	printf("Number of blanks, tabs and newlines: %d\n", bc);
}