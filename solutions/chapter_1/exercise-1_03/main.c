#include <stdio.h>

/* print Fahrenheit-Celsius table for
* fahr= 0, 20, ..., 300 
* floating point with headings version
*/
int main()
{
	float celsius; 
	int fahr; 
	
	int start=0, end=300, step=20;

	printf("Fahrenheit  Celsius\n");
	printf("----------  -------\n");
	for (fahr = start; fahr <= end; fahr = fahr+step){
		celsius = 5.0/9.0 * (fahr-32.0);
		printf("%10d %8.1f\n", fahr, celsius);
	}

	return 0;
}