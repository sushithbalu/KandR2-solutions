/* Exercise 2-2:
 Write a loop equivalent to the for loop above without using && or ||.
*/
#include <stdio.h>
main()
{
	int i, c, lim;
	char s[100];
	
	lim = 200;
	i=0;

	while(i<lim-1){
		if((c = getchar()) !='\n')
			s[i] = c;
		else if(c = EOF)
			break;
		i++;
	}

	printf("%s", s);
	return 0;
}		
