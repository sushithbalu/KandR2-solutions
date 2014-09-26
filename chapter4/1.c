/*
Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
*/
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";
/* pattern to search for */
/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	int index;

	
	while (get_line(line, MAXLINE) > 0){
		index = strindex(line, pattern);
		printf("\n    line: %sposition: %d\n", line, index);
		}
	return 0;
}


/* getline: get line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k, l;
	
	l = -2;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
		 l = i;
	}
	return (l+1);
}

