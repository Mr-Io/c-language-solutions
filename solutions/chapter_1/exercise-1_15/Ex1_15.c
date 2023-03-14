#include <stdio.h>

float celsius(int fahr);

int main()
{
	int fahr;
	int start = 0, end = 300, step = 20;

	printf("Fahrenheit  Celsius\n");
	for (fahr = start; fahr <= end; fahr = fahr + step)
	{
		printf("%10d %8.1f\n", fahr, celsius(fahr));
	}

	return 0;
}

float celsius(int fahr) {
	return 5.0 / 9.0 * (fahr - 32.0);
}