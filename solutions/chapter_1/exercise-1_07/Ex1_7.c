#include <stdio.h>

int main()
{
	printf("size of EOF:		%3d\n", sizeof(EOF));
	printf("value of EOF:		%3d\n", EOF);
	printf("value of EOF(char):	%3c\n", EOF);
	printf("value of ÿ(bin):      %x\n", 'ÿ');
	printf("	It must be only ff == 1111 1111");
}