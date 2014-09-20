/*Write a program to copy its input to its output, replacing each tab by \t, each
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
unambiguous way.
 
*/
#include <stdio.h>

#define BS '\\'

main()
{
	int c;
	while ((c = getchar()) != EOF)
	{
	    
	if (c == '\b')
		{
			putchar(BS);
			putchar('b');
	    }
	else if (c == '\t')
		{
			putchar(BS);
			putchar('t');
	    }
	else if (c == '\\')
		{
			putchar(BS);
			putchar(BS);
	    }
	else    
		putchar(c);
	}
}

