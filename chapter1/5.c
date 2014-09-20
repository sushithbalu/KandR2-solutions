/*Exercise 1-5. Modify the temperature conversion program to print the table 
in reverse order, that is, from 300 degrees to 0.*/
/* print Fahrenheit-Celsius table */

#include <stdio.h>
main()
{
	int fahr;
	float x;

	for (fahr = 300; fahr >= 0; fahr = fahr - 20){		
		x=5.0 * (fahr - 32) / 9.0;	
		printf("%3d %6.1f\n", fahr,x );
		}
}

