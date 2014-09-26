/*
 * Exercise 5-14. Modify the sort program to handle a -r flag, which indicates 
 * sorting in reverse (decreasing) order. Be sure that -r works with -n.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> /*atof()*/

#define MAXL 5000
#define MAXLINES 5000 /*maximum number of lines*/ 
#define MAXLEN 100 /*maximum length of line*/

void q_sort(void *v[], int left, int right, int (*comp)(void *, void*),int order);
int numcmp(void*, void*);
int get_line(char [], int lim);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
char *lineptr[MAXLINES];
char *alloc(int);
void afree(char *p);
char *lineptr[MAXLINES]; /* pointers to text lines */

int order = 0; /* 1 if sorting in increasing order*/


int main(int argc, char *argv[])
{
	int nlines; /* number of input lines read */
	int numeric = 0; /* 1 if numeric sort */
	int i;

	for (i = 1; i < argc ; i++) {
		if (*argv[i] == '-') {
			switch (*(argv[i] + 1)) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					order = 1;
					break;
				default:
					break;
			}
		}
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		q_sort((void**)lineptr, 0, nlines-1,(int(*)(void*, void*))(numeric ?numcmp:strcmp),order);

		printf("\nResult:\n======\n");
        	writelines(lineptr, nlines);
        	return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
	else {
		line[len-1] = '\0'; /* delete the newline */
		strcpy(p, line);
		lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
/
/* numcmp: compare s1 and s2 numerically */
int numcmp(void *s,void *t)
{
	double v1, v2;

	v1 = atof(s);
	v2 = atof(t);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else /* not enough room */
		return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

/* getline: read a line into s, return length*/
int get_line(char s[],int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

#include <string.h>

/* qsort: sort v[left]...v[right] into increasing/decreasing order */
void q_sort(void *v[], int left, int right, int (*comp)(void *,void *),int order)
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
	if(!order&&(*comp)(v[i], v[left])<0)
            swap(v, ++last, i);
	else if(order&&(*comp)(v[i], v[left])>0)
		swap(v, ++last, i);
    swap(v, left, last);
	q_sort(v, left, last-1, comp, order);
	q_sort(v, last+1, right, comp, order);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
