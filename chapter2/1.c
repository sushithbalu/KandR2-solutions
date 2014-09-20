/* Exercise 2-1:
Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
*/
#include <stdio.h>
#include <limits.h>
main()
{
	printf("\nbits in a char: %d\n\n",CHAR_BIT);

	printf("maximum value of char: %d\n",CHAR_MAX);
	printf("minimum value of char: %d\n\n",CHAR_MIN);

	printf("maximum value of unsigned char: %u\n\n",UCHAR_MAX);

	printf("maximum value of int: %d\n",INT_MAX);
	printf("minimum value of int: %d\n\n",INT_MIN);

	printf("maximum value of unsigned int: %u\n\n",UINT_MAX);

	printf("maximum value of short: %d\n",SHRT_MAX);
	printf("minimum value of short: %d\n\n",SHRT_MIN);

	printf("maximum value of unsigned short: %u\n\n",USHRT_MAX);

	printf("maximum value of long: %ld\n",LONG_MAX);
	printf("minimum value of long: %ld\n\n",LONG_MIN);

	printf("maximum value of unsigned long: %lu\n\n",ULONG_MAX);
}
