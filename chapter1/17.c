/*Exercise1-17: Write a program to print all input lines that are longer 
  than 80 characters. */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define MAXA 81

/* maximum input line length */

int etline(char line[], int maxline);

int main()
{
	int len,j;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = etline(line, MAXLINE)) > 0){
		if(len > MAXA)
			printf("\nthis line is longer than 80 characters=%s\n", line);
	}
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

