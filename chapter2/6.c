/* Exercise 2-6:
Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
unsigned setbits(unsigned x, unsigned y, int p, int n);
#include <stdio.h>

main()
{
	int  p, n;
	unsigned int x, y, z;
	printf("Enter: x, y, p, n");
	scanf("%u %u %d %d",&x, &y, &p, &n);
		
		z = setbits(x, y, p, n);
		printf("x, p, n, y:%u, %d, %d, %u, %u\n", x, p, n, y, z);

	return 0;
}

unsigned setbits(unsigned x, unsigned y, int p, int n)

{	int a = (p + 1 - n);
	int b = ~((~0) << n);
	return( (x & ((~0 << (p + 1)) | (~(~0 << a)))) | ((y & b) << a));
	
}
