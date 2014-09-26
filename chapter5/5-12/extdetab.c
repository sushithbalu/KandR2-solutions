/*
 * Exercise 5-12. Extend entab and detab to accept the shorthand
 * entab -m +n
 * to mean tab stops every n columns, starting at column m.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXL 1000
#define TABW 4
#define YES 1
#define NO 0

void exttab(int argc, char *argv[], char *tab);
void detaba(char *to, char *from, int maxw);
int get_line (char *s, int maxline);
/*replace tabs with blanks*/
int main(int argc, char *argv[])
{
	char s1[MAXL];
	char s2[MAXL+1];


	while(get_line(s1, MAXL) == 0)
//        exttab(argc, argv, s1)
		;
	detaba(s1, s2, TABW);

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

/*************************getline()**************************/
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


/***********************detab'***********************/

void detaba(char *to, char *from, int maxw){

	int i, j, k, c, nb, state;
	i = k= 0;
	
 	while ((c = *to++) != '\0'){
 		if(c =='\t'){
			nb = maxw -i % maxw;
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

