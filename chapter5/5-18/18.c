/*Exercise 5-14. Modify the sort program to handle a -r flag, which indicates 
 * sorting in reverse (decreasing) order. Be sure that -r works with -n.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> /*sizeof()*/

#define MAXL 5000
#define MAXLINES 5000 /*maximum number of lines*/ 
#define MAXLEN 100 /*maximum length of line*/
int numcmp(void*, void*);
int ostrcmp(void*, void*);
int get_line(char *, int maxline);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
char *lineptr[MAXLINES];
char *alloc(int);
void afree(char *p);
char *lineptr[MAXLINES]; /* pointers to text lines */

int numeric = 0; /* 1 if numeric sort */
int order = 1; /* 1 if sorting in increasing order*/


int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int c;

    while (--argc > 0 && (*++argv[0]) == '-') {
        while ((c = *++argv[0]) != '\0') {
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    order = 0;
                    break;
                default:
                    break;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, nlines, sizeof(*lineptr), numeric ? numcmp : ostrcmp);
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
int ostrcmp(void *s,void *t)
{
        char *s1 = order ? t : s;
        char *s2 = order ? s : t;
	return strcmp(s1, s2);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp( void *s, void *t)
{
	char  *s1 = order ? t : s;
	char  *s2 = order ? s : t;
	
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
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
