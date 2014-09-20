/* Exercise 1-4. Write a program to print the corresponding 
   Celsius to Fahrenheit table.
 */

#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	printf("\ncelsius\t\tfahrenheit\n");

	while (celsius <= upper){
		fahr = 32 + celsius * (9.0/5.0);
		printf("%3.0f\t\t%6.2f\n", celsius, fahr);
		celsius  = celsius + step;
	}
}

