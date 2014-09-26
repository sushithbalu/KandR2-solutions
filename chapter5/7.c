/*
Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, 
rather than calling alloc to maintain storage. How much faster is the program?
solution:
The overhead of local variables is zero. Each time you call a function, 
you are already setting up the stack for the parameters, return values, etc.
 Adding local variables means that you're adding a slightly bigger number 
to the stack pointer (a number which is computed at compile time).

Also, local variables are probably faster due to cache locality.

cache locality (read more here): Frequently accessed global variables probably
 have temporal locality. They also may be copied to a register during function 
execution, but will be written back into memory (cache) after a function returns 
(otherwise they wouldn't be accessible to anything else; registers don't have
 addresses).

Local variables will generally have both temporal and spatial locality (they get
 that by virtue of being created on the stack). Additionally, they may be 
"allocated" directly to registers and never be written to memory.

completely removed part of alloc function. new argument to readlines
*linestore, 
linestore points to an array with size maxlines in main function.

*/
#define MAXLEN 1000
#define MAXSTOP 4000

int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[],char *linestore, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];

	char *p = linestore;
	char *linestop = linestore + MAXSTOP;
	nlines = 0;
	while((len = getline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p + len) > linestop){
			return -1;
			}
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
