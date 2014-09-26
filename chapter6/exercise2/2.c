/*
 * Exercise 6-2. Write a program that reads a C program and prints in alphabetical 
 * order each group of variable names that are identical in the first 6 characters, 
 * but different somewhere thereafter. Don't count words within strings and comments. 
 * Make 6 a parameter that can be set from the command line.
 *
 * Usage  ./<file_name> -n <number> <words list>
 * eg:    ./2 -n 7 apple mango orange grape
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> /*malloc()*/

#define MAXWORD 100
#define DEFAULT 6
#define YES 1
#define NO 0

struct tnode {
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};
struct tnode *addtree1(struct tnode *p, char *w, int , int );
void treeprint (struct tnode *);
int getword(char *, int);

/* word frequency count */
int main(int argc, char *argv[])
{
	int n = DEFAULT;
	struct tnode *root;
	char word[MAXWORD];

	if(argc == 3){
		if(strcmp("-n",argv[1]) == 0)
			n = atoi(argv[2]);
		printf("  Tree\n--------\n");	
	}
	else {
		printf("error:1132\nusage: ./file_name -n number\neg:./2 -n 7 apple mango orange ..");
	}
	root = NULL;
	while (getword(word, MAXWORD) != EOF){
		if (isalpha(word[0]))
			root = addtree1(root, word, 0, n);
	}
	treeprint (root);
	return 0;
}

struct tnode *talloc(void);
char *strdup1(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree1(struct tnode *p, char *w, int found, int n)
{
	int cond;

	if (p == NULL) {      /* a new word has arrived */
		p = talloc(); /* make a new node */
		p->word = strdup1(w);
		p->match = (found) ? YES : NO;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) < 0){
		if (strncmp(w, p->word, n) == 0){
			found = YES;
			p->match = YES;
		}
		p->left = addtree1(p->left, w, found, n);
	} else if (cond > 0) {     
 /* greater than into right subtree */
		if (strncmp(w, p->word, n) == 0){
			found = YES;
			p->match = YES;
		}
		p->right = addtree1(p->right, w, found, n);
	}
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
			if(p->match){
				printf(" %s\n", p->word);
			}
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
/* strdup: copies string to safe place */
char *strdup1(char *s) /*make a duplicate of s*/
{
	char *p;

	p = (char *) malloc(strlen(s)+1); /*+1 for '\0'*/
	if (p != NULL)
		strcpy(p,s);
	return p;
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
