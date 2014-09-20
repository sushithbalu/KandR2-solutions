/*Exercise 1-21: entab */

#include <stdio.h>

#define MAXLINE 1000
#define TABW 4 

void entaba(char to[], char from[], int maxline);
int etline(char s[], int max);
// void entaba(char to[], char from[]);

main()
{
	char line[MAXLINE];
	char entab[MAXLINE];
	int len;
	while ( etline(line, MAXLINE) == 0)
		;
		entaba(line, entab, TABW);
	printf("%s\n",entab);
	return 0;
}

/*getline*/
int etline(char s[],int max){

	int c, i, n;

	for (i=0; i < max-1 && ((c=getchar())!=EOF)&&(c!='\n' ); ++i)
		s[i] = c;
	if(c == '\n')
		s[i] = c;
		i++;
	s[i] = '\0';
	
	return i;
}

/* entab:  'from' into 'to'*/
void entaba(char to[], char from[], int maxline){

	int i, j, k, c, nb, state;

	i = k = 0;
	while ((c = to[i]) != '\0'){
		if(c ==' '){
			state = 1;
			nb = maxline -i % maxline;
			for (j = 1; j < nb; ++j)
				if (to[i+j] != ' '){
					state = 0;
					break;
				}
			if (state){
				from[k] = '\t';
				k++;
				i = i + nb - 1;
			}
			else {
				from[k] = c;
				k++;
			}
		}
		else {
			from[k] = c;
			k++;
		}
		++i;
	}
	from[k] = '\0';
}

