#include <stdio.h>
#include <stdlib.h>

#define MAXL 1000
#define TABW 4
#define TABMAX 10
#define YES 1
#define NO 0

void detaba (char *to, char *from, int maxw[]);
int get_line (char *s, int maxline);

int main(int argc, char **argv)
{
	char s1[MAXL];
	char s2[MAXL];
	int maxw[MAXL + 1];
	int i, j, nt;

	if (argc > TABMAX)
		argc = TABMAX;
	j = 0;
	for (i = 2; i <=argc; ++i){
		nt = atoi(*++argv);
		if (nt > 0)
			maxw[j++] = nt;
	}
	if (i == 2)
		maxw[j++] = TABW;
	maxw[j] = 0;	
	while(get_line(s1, MAXL) == 0)
		;
	detaba(s1, s2, maxw);
	printf("%s", s2);
	return 0;
}

int get_line(char *s, int maxline)
{
        int c;
        char *t = s;
        while(--maxline > 0 && (c = getchar()) !=EOF && c!= '\n'){
                *s++ = c;
        }
        if(c == '\n')
                *s++ = c;
        *s = '\0';
        return s - t;
}


/* detab:*/
void detaba(char *to, char *from, int maxw[]){

	int i, j, k, c, nb, state;
	i = k = 0;
 	while ((c = *to++) != '\0'){
 		if(c =='\t'){
			if(maxw[k] == 0)
				k = 0;
			nb = maxw[k] -i % maxw[k];
			k++;
			for (j = 1; j < nb; ++j){
			 	*from++ = ' ';
				i++;
			}
		} else {
			*from++ = c;
			i++;
		}
	}
	*from = '\0';
}

