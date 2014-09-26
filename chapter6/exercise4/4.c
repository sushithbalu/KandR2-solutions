/*
 * Exercise 6.4: write a program that prints the distict words in its
 * input sorted into decreasing order of frequency of occurence. Precede
 * each word by its count.
 * build tree -> store pointers(left and right) -> sort using shell sort
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> /*malloc()*/

#define MAXWORD 100
#define MAXSTORE 1000
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *store[MAXSTORE];
struct tnode *addtree1(struct tnode *p, char *w);
void shellsort(void);
void treeprint (struct tnode *);
void pointer_store(struct tnode *);
int getword(char *, int);
int in = 0;
/*sorted tree */
int main()
{
	struct tnode *root;
	char word[MAXWORD];
	int j;

	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			root = addtree1(root, word);	
		}	
	}	
	pointer_store(root);
//	printf("%d\n", in);
	shellsort();
	for(j=0; j < in; j++)
	printf("%d %s\n", store[j]->count, store[j]->word);
	return 0;
}

/* store pointers */
void pointer_store(struct tnode *p)
{
	if (p != NULL){
		pointer_store(p->left);
		if(in < MAXSTORE)
		store[in++] = p;
//		printf("%d", i);
	 	pointer_store(p->right);
	}
}

struct tnode *talloc(void);
char *strdup1(char *s);

/* addtree: add a node with w, at or below p */
struct tnode *addtree1(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {      /* a new word has arrived */
		p = talloc(); /* make a new node */
		p->count = 1;
		p->word = strdup(w);
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) 
		p->count++;
	else if(cond < 0)
		p->left = addtree1(p->left, w);
	else
		p->right = addtree1(p->right, w);
	return p;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(void)
{
	int gap, i, j; 
	struct tnode *temp;
	for (gap = in/2; gap > 0; gap /= 2)
		for (i = gap; i < in; i++)
			for (j=i-gap; j>=0 ; j-=gap) {
				if ((store[j]->count) >= (store[j+gap]->count))
					break;
				temp = store[j];
				store[j] = store[j+gap];
				store[j+gap] = temp;
			}
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%d, %s\n" ,p->count, p->word);		
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
/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
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
