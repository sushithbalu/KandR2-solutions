/*
Extend entab and detab to accept the shorthand entab -m +n 
to mean tab stops every n columns, starting at column m. choose convenient(for the user) default behavior
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXL 1000
#define DEFAULT_M 1
#define DEFAULT_N 8

void entaba (char *destination, char *source, int m, int n);
int get_line (char *s, int maxline);

int main(int argc, char *argv[])
{
	char s1[MAXL];
	char s2[MAXL];
	int i, m, n, m1, n1 ;

	m = DEFAULT_M;
	n = DEFAULT_N; 

	for (i = 2; i <=argc; ++i){
		argv++;
		if (*argv[i] == '-'){
			if((m1 = atoi(*++argv[i])) > 0)
				m = m1;
		}
		else if (*argv[i] == '+') {
			if((n1 = atoi(++*argv)) > 0)
				n = n1;
		}
	}
	while(get_line(s1, MAXL) == 0)
		;
	entaba(s1, s2, m, n);
	printf("%s\n", s2);
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

/* entab:  'source' to 'destination'*/
void entaba(char *destination, char *source, int m, int n){

	int i, j, k, c, nb, state;

	i = k = 0;
	while ((c = *destination) != '\0'){
		if(c ==' '){
			state = 1;
//			if(maxw[k] == 0)
				k = 0;
			nb = maxw[k] -i % maxw[k];
			for (j = 1; j < nb; ++j)
				if (*(destination + j) != ' '){
					state = 0;
					break;
				}
			if (state){
 				*source++ = '\t';
				destination += nb;
				i += nb;
			} else {
				*source++ = c;
				i++;
				++destination;
			}
		} else {
			*source++ = c;
			i++;
			++destination;
		}
		++i;
	}
	*source++ = '\0';
}
