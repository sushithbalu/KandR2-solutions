/* Exercise 1-16: Revise the main routine of the longest-line program so it will
  correctly print the length of arbitrary long input lines, and as much as 
  possible of the text. */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
/* maximum input line length */

int etline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = etline(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
		if (max > 0)
		printf("\nLongest line is=%s\n", longest);
		return 0;
}

/* getline: read a line into s, return length*/
int etline(char line[],int maxline){

	int c, i;
	for (i=0; i < maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	    line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){

	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
	++i;	
}

