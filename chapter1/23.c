#include <stdio.h>
#define MAXLINE 1000
/* maximum input line length */
int get_line(char line[], int maxline);
main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0)
	if (len > 0)
	printf("%s", line);
	return 0;
}

/* tline: specialized version */
int get_line(char line[], int maxline)
{
	int c, i;
	char s[MAXLINE];
	for (i = 0; i < MAXLINE-1 && ((c=getchar()) != EOF && c != '\n'); ++i)
	s[i] = c;

	if (c == '/') {
		while(c == '*'){		
			s[i] = ' ';
		}
	i++;
	}

	s[i] = '\0';
	return i;
}

