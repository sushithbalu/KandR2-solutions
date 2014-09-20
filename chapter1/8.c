/*Exercise 1-8. Write a program to count blanks, tabs, and newlines.*/

#include <stdio.h>
/* count lines,blanks and tabs in input */
int main()
{
	int s,nl,sl,tl;
	nl = sl = tl = 0;
	
	while ((s = getchar()) != EOF)
	if (s == ' ')
		++sl;	
		
	else if (s == '\t')
		++tl;
		
	else if (s == '\n')
		++nl;
		
		printf("\nNumber of lines = %d\n", nl);
		printf("\nwhite spaces = %d\n", sl);
		printf("\ntabs = %d\n", tl);	
	return 0;
}

