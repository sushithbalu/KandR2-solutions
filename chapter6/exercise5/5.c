/*
 * Exercise 6-5: write a function undef that will remove a name and definition
 * from the table maintained by lookup and install.
 *
 */ 

#define HASHSIZE 101
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
void undef(char *);

int main()
{
	int i;
	int num;
	struct nlist *p;
	install("MAX", "1");
	install("MAXLEN", "2");
	install("MAX1", "3");

	for (i = 0; i<HASHSIZE; i++){
		for (p = hashtab[i]; p != NULL;p = p->next)
			printf ("[%d]\tname(%s)--defn (%s)\n", i, p->name, p->defn);
	}
	printf("\n");
	undef("MAX1");
	for (i = 0; i<HASHSIZE; i++){
		for (p = hashtab[i]; p != NULL;p = p->next)
			printf ("[%d]\tname(%s)--defn (%s)\n", i, p->name, p->defn);
	}

	printf("\n%d\n", num);

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
