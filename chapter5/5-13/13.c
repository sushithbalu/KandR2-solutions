/*
 * Exercise 5-13. Write the program tail, which prints the last n lines of its input. 
 * By default, n is set to 10, let us say, but it can be changed by an optional 
 * argument so that tail -n
 * prints the last n lines. The program should behave rationally no matter how 
 * unreasonable the input or the value of n. Write the program so it makes the best 
 * use of available storage; lines should be stored as in the sorting program of 
 * Section 5.6, not in a two-dimensional array of fixed size.
 *
 * tail -n 
    ``````````````````````````````````
	USAGE
 * Optional argument -n 12      --prints last 12 lines 
 * By Default 10 lines
 *
 */
#include <stdio.h>
#include <stdlib.h> /*atoi()*/

#define MAXI 5000 /*input*/
#define MAXL 100 /*number of lines*/
#define DEFAULT 10 /*Default number of lines*/

int get_line(char *s, int maxline);
void args (int argc, char **argv);

int nlines = DEFAULT;
char  lines[MAXI];
char *linep[MAXL];

int main(int argc,char *argv[])
{
	int len, lenp = 0, i, c;
	
	*linep = lines;
	if(argc > 1)
		args (argc, argv);
	len = get_line(lines, MAXI);
	if(nlines == 0)
		nlines = DEFAULT;
	lenp = (len < nlines) ? len : nlines;

	if(lenp == DEFAULT){
		printf("\n\nDefault:%d lines\n__________________\n", DEFAULT);
	} else {
	        printf("\n\n%d line(s)\n_________\n", lenp);
	}
	printf("\n");
	for(i = len; i > 0; i--) {
		while (( c = *linep[0]++) != '\n'){
			if (i <= lenp) {
				printf("%c", c);
			}
		}
		if(c == '\n' && i <= lenp){
			printf("\n");
		}
	}
	return 0;
}

/*****************************getline()********************************/
int get_line(char *s, int maxline)
{
        int c, count=0;
        while(--maxline > 0 && (c = getchar()) !=EOF){
                *s++ = c;
		if(c == '\n')
                	linep[++count] = s;
	}
        *s = '\0';
        return count;
}

/**************************parse arguments****************************/
void args (int argc, char *argv[])
{
	char c;

	while (--argc > 0 && (*++argv)[0] == '-') {
		c = *++argv[0];
		/*if input to atoi is not n then it will return 0 */
		if(c == 'n') {
			nlines = atoi(*(argv + 1)); 
			break;
		}
	}
}
