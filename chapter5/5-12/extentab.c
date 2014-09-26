/*
 * Exercise 5-12. Extend entab and detab to accept the shorthand
 * entab -m +n
 * to mean tab stops every n columns, starting at column m.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXL 1000
#define TABW 8
#define YES 1
#define NO 0

void exttab(int argc, char *argv[], char *tab);
void entaba (char *destination, char *source, int maxw);
int get_line (char *s, int maxline);
/*replace tabs with blanks*/
int main(int argc, char *argv[])
{
	char s1[MAXL];
	char s2[MAXL+1];


	while(get_line(s1, MAXL) == 0)
        exttab(argc, argv, s1)
		;
	entaba(s1, s2, TABW);

	printf("%s\n", s2);
	return 0;
}
/**************exttab: tabstops in array tab*****************/
void exttab(int argc, char *argv[], char *tab)
{
	int i, increment, position;

	if (argc <= 1) /*default tabstops*/
		for (i = 1; i <= MAXL; i++)
			if (i % TABW == 0)
				tab[i] = YES;
			else
				tab[i] = NO;

	else if (argc == 3 && *argv[1] == '-' || *argv[2] == '*'){ /*user*/
		position = atoi(&(*++argv)[1]);
		increment = atoi(&(*++argv)[1]);
		for (i = 1; i < MAXL; i++)
			if (i != position)
				tab[i] = NO;
			else {
				tab[i] = YES;
				position += increment;
			}
	} else {                           /*tabstop*/
		for (i = 1; i <MAXL; i++)
			tab[i] = NO;
		while (--argc > 0) {
			position = atoi(*++argv);
			if (position > 0 && position < MAXL)
				tab[position] = YES;
		}
	}
}

/*_____________________________getline()_____________________________*/
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


/*_______________entab:  'source' into 'destination'________________*/
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
				i += nb - 1;
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

