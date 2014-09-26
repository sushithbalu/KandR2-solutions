/*
 * Exercise 6-1 Our version of getword does not properly handle underscores,
 * string constands, comments, or preprocessor control lines. write a better
 * version.
 *
 * method1
 * input: auto register register_auto auto "de" etc.
 * output: 2 auto
 * 	   1 register
 *
 * method2(redirection)
 * exec.: ./executable_file_of_this_program < example_program.c
 * output: 1 auto
 * 	   5 break
 *	   ... 		
 */

#include<stdio.h>
#include<string.h>/*getchar() and strcmp()*/
#include <ctype.h>/*isspace(), isalpha() and isalnum()*/

struct key {
	char *word;
	int count;
} keytab[] = {
	/*list of keywords must be sorted in alphabetical order(binary search)*/
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"double", 0,
	"else" , 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};
#define MAXL 100
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);
int binarysearch(char *word, struct key tab[], int n);
int main()
{	
	int n;
	char word[MAXL];
	
	while (getword(word, MAXL) != EOF)
		if (isalpha(word[0]))
			if((n = binarysearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

/* binarysearch: find word in tab[0]..tab[n-1] */
int binarysearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* getword: get next word or charecter form input */
int getword (char *word, int lim)
{
	int c, d, getch(void), comment1(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (isalpha(c)||c == '_'|| c == '#'){
		for (; --lim > 0; w++)
			if(!isalnum(*w = getch()) && *w != '_'){
				ungetch(*w);
				break;
			}
	} else if (c == '/'){
		if((d = getch()) == '*')
			c = comment1();
		else
			ungetch(d);
	} else if (c == '\'' || c == '"'){
		for (; --lim > 0; w++)
			if ((*w = getch()) == '\\')
				*++w = getch();
			else if (*w == c) {
				w++;
				break;
			} else if(*w == EOF)
				break;
	}
	*w = '\0';
	return c;
}
/*comment: skip over comment and return a charecter*/
int comment1(void)
{
	int c, getch(void);
	void ungetch(int);

	while ((c = getch()) != EOF)
		if (c == '*'){
			if((c =getch()) == '/')
				break;
			else
				ungetch(c);
		}
	return c;
}

#define BUFSIZE 1000
char s[BUFSIZE];
int bufp = 0;

/*getch: get a charecter*/
int getch(void){
	return (bufp>0) ? s[--bufp] : getchar();
}
/*ungetch:push charecter back to input*/	
void ungetch(int c){
	if(bufp>BUFSIZE)
		printf("too many charecters");
	else
		s[bufp++] = c;
}
