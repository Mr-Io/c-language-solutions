#include <stdio.h>

float celsius(int fahr);

#define START 0
#define END 300
#define STEP 20

int main()
{
	int fahr;

	printf("Fahrenheit  Celsius\n");
	printf("----------  -------\n");
	for (fahr = START; fahr <= END; fahr = fahr + STEP){
		printf("%10d %8.1f\n", fahr, celsius(fahr));
	}
	return 0;
}

/* No need to check for int overflow 
*  since there is no user input and
*  the edge cases are well defined  
*/
float celsius(int fahr) 
{
	return 5.0 / 9.0 * (fahr - 32.0); 
}