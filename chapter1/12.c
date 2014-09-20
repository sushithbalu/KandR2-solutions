/* Exercise 1-12. Write a program that prints its input one word per line */
#include <stdio.h>

int main()
{
	int c;
	int state;

	state=1;
	while ((c = getchar()) != EOF){      
		if((c==' ')||(c=='\t')){
			state=0; 
			putchar('\n');	
		}		
		else
		{
			state=1;
			putchar(c);			
		}
	}
	return 0;	
}
