/* Exercise 2-7:
Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the 
others unchanged.
*/
unsigned int invert(unsigned int x, int p, int n);
#include <stdio.h>
main()
{
		int  p, n;
		unsigned int x, z;

		printf("Enter: x, p, n");
		scanf("%u %d %d",&x, &p, &n);
		z = invert(x, p, n);
		printf(" invert(%u, %d, %d) = %u \n", x, p, n, z);
        return 0;
}

unsigned int invert(unsigned int x, int p, int n)

{  
	unsigned int a = (~0u << ((p+1)-n));
	unsigned int b = (~(~0u << (p+1)));
        return(x ^ (a & b));
}
