/*Exercise 1-20: Detab */

#include <stdio.h>

#define MAXLINE 1000
#define TABA 5

int etline(char line[], int max);
void detaba(char to[], char from[]);

main()
{
	char line[MAXLINE];
	char det[MAXLINE];
	int len;
	while ((len= etline(line, MAXLINE)) > 0){
		detaba(det,line);
	printf("%s\n",det);
	}
	return 0;
}

/*getline*/
int etline(char s[],int max){

	int c, i, j;

	j=0;
	for (i=0; i < max-1 && ((c=getchar())!=EOF)&&(c!='\n' ); ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* detab:  'from' into 'to'; */
void detaba(char to[], char from[]){

	int i, j, n;

	i = j = 0;
	while ((to[i] = from[j]) != '\0'){

		if(to[i]=='\t'){
			for(n = 0; n < TABA; ++n,++i)
				to[i] = ' ';
		}
		else	
		++i;
	++j;
	}
}

