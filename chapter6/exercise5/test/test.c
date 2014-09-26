/*
 *
 */ 

#define HASHSIZE 101
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> /*isspace()*/

struct nlist{
	char *name;
	char *defn;
	struct nlist *next;
};

unsigned hash(char*);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);
struct nlist *hashtab[HASHSIZE];

int getword(char *word, int lim);

int main()
{
	int i;
	int count;
	struct nlist *p;
	char word[100000];

	while(getword(word, 100000) != EOF){
		if (isalpha(word[0]))
			install(word, "1");
		}
		
	for (i = 0; i<HASHSIZE; i++){
		count = 0;
		for (p = hashtab[i]; p != NULL; p = p->next){
			printf ("(%d)\t%s\t\t%s\n", i, p->name, p->defn);
			count++;
		}
		printf("group_%3d_____________%d\n", i, count);
	}
}
/* hash: form hash value for string */
unsigned hash(char *s){
	unsigned hashval;
	for (hashval = 0; *s !='\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval%HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s){
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != '\0'; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

/*install: put name and defn in hashtab*/
struct nlist *install(char *name, char *defn){

	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {    /*not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else               /* already there*/
	free((void *) np->defn);     /*free previous defn*/
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
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



#define BUFSIZE 10000
char s[BUFSIZE];
int bufp = 0;

/*getch: get a charecter*/
int getch(void){
        return (bufp > 0) ? s[--bufp] : getchar();
}
/*ungetch:push charecter back to input*/
void ungetch(int c){
        if(bufp > BUFSIZE)
                printf("too many charecters");
        else
                s[bufp++] = c;
}

