#include <stdio.h>

int lower(int c);

int main() 
{
	putchar(lower('Z'));
	return 0;
}

int lower(int c) {
	return (c < 'A' || c > 'Z') ? c : c + 'a' - 'A';
}
