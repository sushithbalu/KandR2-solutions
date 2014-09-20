/*Exercise 1-15:Rewrite the temperature conversion program of 
Section 1.2 to use a function for conversion.*/

#include <stdio.h>

#define M 300
#define N 0
#define STEP 20

float conversion( float q);

main()
{
	int f;
	float c;

	printf(" ------------|-----------\n");
	printf("| Fahrenheit |  Celsius  |\n");
	printf(" ------------|-----------\n");	
	for (f = N; f <= M; f=f+STEP)	
		printf("  %5d\t     | \t%6.2f\n",f , conversion(f));
	printf(" ------------|-----------\n");
	return 0;
}
  
float conversion(float q){
	float h;
	int f;
	h=0;
	for (f = N; f <= M; f=f+STEP)	{	
		h = (5.0/9.0)*(q-32);
	}
	return h;
}

