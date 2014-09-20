/*Exercise 2-9:In a two's complement number system, x &= (x-1) deletes 
the rightmost 1-bit in x. Explain why. Use this observation to write a
 faster version of bitcount.*/
 
#include <stdio.h>
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &=(x-1))
	++b;
	return b;
}

main()
{
	int n;
	unsigned int x;

	printf("Enter: x = ");
	scanf("%u",&x);
	n = bitcount(x);
	printf(" bitcount(%u) = %d \n", x, n);
	return 0;
}

