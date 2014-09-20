/*Exercise 1-22: Write a program to ``fold'' long input lines into two or more
 shorter lines after the last non-blank character that occurs before the n-th 
column of input. Make sure your program does something intelligent with very 
long lines, and if there are no blanks or tabs before the specified column. */

#include <stdio.h>
#define MAXA 1000
 
char line[MAXA];
int etline(void);

main()
{
	int i, len, h, state;
	 int fold = 30;
 
	while (( len = etline()) > 0 )
	{
		if( len < fold )
		{
		 }
		else
		{
			i = 0;
			state = 0;
			while(i<len)
			{
				if(line[i] == ' ')		
					h = i;
					if(state==fold)
					{
						line[h] = '\n';
 						state = 0;
					}
					state++;
					i++;
			}
		}
		printf ( "%s %d", line,len);
	}
	return 0;
}
 
int etline(void)
{
	int c, i;
	extern char line[];
 
	for ( i=0;i<MAXA-1 && ( c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i; 
}
