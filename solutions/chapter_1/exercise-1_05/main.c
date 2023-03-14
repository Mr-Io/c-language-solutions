#include <stdio.h>

int main()
{
	printf("Fahrenheit  Celsius\n");
	printf("----------  -------\n");

	int fahr;
	for (fahr = 300; fahr >= 0; fahr = fahr-20){
		printf("%10d %8.1f\n", fahr, 5.0/9.0 * (fahr-32.0));
	}

	return 0;
}