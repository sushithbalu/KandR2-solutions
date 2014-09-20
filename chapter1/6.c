/* Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>
main()
{	
	printf("Enter a key\n");
	int i = (getchar() != EOF);
	printf("\n%d\n", i);
			
}	

