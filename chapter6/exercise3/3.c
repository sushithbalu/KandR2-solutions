/*
 * Write a cross-refferencer that prints a list of all words in a document,
and for each word, a list of the line numbers on which it occures.
Remove noise words like "the", "and" and so on.
 *
 *
 * cross-reference: list of words and line number of occurance 
 * code almost same as in text book, for line number we have to 
 * take a new linked list which contains pointer and integer value
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> /*malloc()*/

#define MAXWORD 100

struct tnode {
	char *word;
	struct linenum *lines;
	struct tnode *left;
	struct tnode *right;
};
struct linenum {
	int num;
	struct linenum *next;
};

struct tnode *addtree1(struct tnode *p, char *w, int nline);
void treeprint (struct tnode *);
int getword(char *, int);

/*cross-referencer */
int main()
{
	int lines = 1;
	int noisewords(char *);
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])&&!noisewords(word)) {
			root = addtree1(root, word, lines);	
		}
		else if (word[0] == '\n')
			lines++;
	}
	treeprint (root);
	return 0;
}

/*
struct key *binsearch(char *word, struct key *tab, int n)
{
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;

	while(low < high){
		mid = low + (high - low)/2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}
*/

/* noice words */
int noisewords(char *w){
	static char *nw[] = {
		"a", "an",
		"and", "are",
		"be", "in",
		"into", "is", "on",
		"of", "or",
		"that", "the",
		"this", "were"
		};
	char ** word = nw;
	char ** end = nw + sizeof(nw)/sizeof(nw[0]);
		for (; word != end; word++){
			if (strcmp(*word, w) == 0){
				return 1;
			}
		}
	return 0;
}
struct tnode *talloc(void);
struct linenum *lalloc(void);
char *strdup1(char *s);

/* addtree: add a node with w, at or below p */
struct tnode *addtree1(struct tnode *p, char *w, int nline)
{
	int cond;
	struct linenum *temp;

	if (p == NULL) {      /* a new word has arrived */
		p = talloc(); /* make a new node */

		p->word = strdup(w);
		p->left = p->right = NULL;
		p->lines = lalloc();
		p->lines->num = nline;
		p->lines->next = NULL; 
	} else if ((cond = strcmp(w, p->word)) == 0) {
			temp = p->lines; /* add line numbers,linked list */
			while(temp->next != NULL && temp->num != nline) 
				temp = temp->next; /*requred position */
			if(temp->num != nline) {   /*not found*/
				temp->next = lalloc();  /*build a block(space allocaed)*/
				temp->next->num = nline;  /*line number added*/
				temp->next->next = NULL;  /*end of linked list*/
			}
	} else if(cond < 0)
		p->left = addtree1(p->left, w, nline);
	else
		p->right = addtree1(p->right, w, nline);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	struct linenum *temp;
	
	if (p != NULL) {
		treeprint(p->left);
		printf("%13s", p->word);
	for(temp = p->lines ; temp != NULL; temp = temp->next)
		printf("%4d", temp->num);
		printf("\n");
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* lalloc: make space for numline*/
struct linenum *lalloc(void)
{
	return (struct linenum *) malloc(sizeof(struct tnode));
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
/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()) && c != '\n')
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
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
