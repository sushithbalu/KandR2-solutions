/*Exercise 2-8. Write a function rightrot(x,n) that returns the value 
of the integer x rotated to the right by n positions.*/

#include <stdio.h>
unsigned int rightrot(unsigned int x, int n);
main()
{
	int  p, n;
	unsigned int x, z;

	printf("Enter: x, n :");
	scanf("%u %d",&x, &n);
	z = rightrot(x, n);
	printf("rightrot(%u, %d) = %u \n", x, n, z);
	return 0;
}

unsigned int rightrot(unsigned int x, int n) {
     int p;
     for (p = 31; len >= 0 && !((~0 << p) & x);p--);
     len++; 

	return ((x >> n) | (x << (p - n)) & ((1 << p) - 1));
}
