#include <stdio.h>

/* print Celsius-Fahrenheit table for
* Ceslius= 0, 20, ..., 300 
* floating point with headings version
*/
int main()
{
	float fahr; 
	int celsius; 
	
	int start=0, end=300, step=20;

	printf("Celsius Fahrenheit\n");
	printf("------- ----------\n");
	for (celsius = start; celsius <= end; celsius = celsius+step){
		fahr = 9.0 / 5.0 * celsius + 32.0;
		printf("%7d %10.1f\n", celsius, fahr);
	}
}