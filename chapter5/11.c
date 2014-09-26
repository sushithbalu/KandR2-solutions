/*
Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
*/
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define TAB 8 
#define YES 1
#define NO 0
void entaba(char *tab);
void detaba(char *tab);
void tabstop(int argc, char *argv[], char *tab);

int main(int argc, char *argv[])
{
	char line1[MAXLINE] = "Modify the           program			enab"; 
	char line2[MAXLINE] = "hello            world! 					detab"  ;
	printf("%s\n",line1);
	printf("%s\n",line2);
	tabstop(argc, argv, tab);
	entaba(line1);
	detaba(line2);
	printf("%s\n",line1);
	printf("%s\n",line2);
	return 0;
}

#include <stdlib.h>

/* tabstop: */
void tabstop(int argc, char *argv[], char *tab)
{
	int i, pos;

	if(argc <= 1)
		for(i = 1; i <MAXLINE; i++)
			if(i%TAB == 0)
				tab[i] = YES;
			else 
				tab[i] = NO;
	else {
		for(i = 1; i <= MAXLINE; i++)
			tab[i] = YES;
		while(--argc >0){
			if(pos > 0 && pos <= MAXLINE)
				tab[pos] = NO;
	}

}

/* detab */
void detaba(char *tab)
{
	int c, pos = 1, nb = 0;

	while((c = getchar()) != EOF){
		if(c == '\t'){
			nb = TAB - (pos-1) % TAB;
			while(nb > 0){
				putchar(' ');
				++pos;
				--nb;
			}
		}
		else if(c == '\n'){
			putchar(c);
			pos = 1;
		}
		else {
			putchar(c);
			++pos;
		}
	}
			
}
