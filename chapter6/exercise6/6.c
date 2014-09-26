/*
 * Exercise 6-6: Implement a simple version of the #define processor
 * (i.e, no arguments) suitable for use with C programs, based on
 * routines of this section. You may also find 
 * getch and ungetch helpful.
 * eg:usage #define MAXLEN 1000
 */ 

#define HASHSIZE 101
#define MAXWORD 1000
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct nlist{
	char *name;
	char *defn;
	struct nlist *next;
	};

unsigned hash(char*);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);
struct nlist *hashtab[HASHSIZE];

int getch(void);
void ungetch(int);
int getword(char *word, int lim);
void mydef(void);
void undef(char *);
void skipspace(void);
void error(int c, char *s);

int main()
{
	int i;
	int num;
	char w[MAXWORD];
	struct nlist *p;
	while (getword(w, MAXWORD) != EOF){
	if (strcmp(w, "#") == 0)
		mydef();
	else if (!isalpha(w[0]))
		printf("%s",w);
	else if ((p = lookup(w)) == NULL)
		printf("%s", w);
	else
		printf("%s", p->defn);
	}
	return 0;	
}
/* hash: form hash value for string */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s !='\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != '\0'; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

/*install: put name and defn in hashtab*/
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {    /*not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else    /* already there*/
	free((void *) np->defn);    /*free previous defn*/
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}
/*define: add name and defn*/
void mydef(void)
{
	int i, c;
	char def[MAXWORD], dir[MAXWORD], name[MAXWORD];
	skipspace();		
	if (!isalpha(getword(dir, MAXWORD)))
		error(dir[0], "wrong usage");
	else if (strcmp(dir, "define") == 0){
		skipspace();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "name error");
		else {
			skipspace();
			for (i = 0; i < MAXWORD-1; i++)
				if ((def[i] = getch()) == EOF || def[i] == '\n')
					break;
			def[i] = '\0';
			install(name, def);
			printf("%s = %s", name, def);
		}
	} else 
		error(dir[0],"usage:#define [variable] [value]");
}


#if 0
/*undef: remove name and defn*/
void undef(char *name)
{
	unsigned hashval;
	hashval = hash(name);
	struct nlist *current = hashtab[hashval];
	struct nlist *previous = NULL;
	
//	if(current == NULL) /*does not exist*/

	while (current != NULL){
		if(strcmp(name, current->name) == 0)
			break;
		else
			previous = current; /*name exist and remember*/
	}	
	if (previous ==NULL) /* first occurence */
		hashtab[hashval] = NULL;
	else  /* elsewhere */
		previous->next = current->next;
	free((void*)current->name);
	free((void*)current->defn);
	free((void*)current);
}

#endif
void skipspace(void)
{
	int c;
	while(isspace(c = getch()))
		;
	ungetch(c);
}

void error(int c, char *s)
{
	printf("error: %s\n",s);
	while (c != EOF && c != '\n')
		c = getch();
}
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for(; --lim > 0; w++)
		if(!isalnum(*w = getch())){
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
