/*
 * Exercise 5-19. Modify undcl so that it does not add redundant 
 * parentheses to declarations.
 *
 * Example1: Input: i * int               ->(i is a pointer to int)
 *     udcl Output: int (*i)              ->(Parentheses are 'redundant')
 * Example2: Input: daytab [13] * int     ->(Daytab is an array of pointers int)
 *     udcl Output: int (*daytab[13])     ->(Wrong, parentheses are redundant)
 * modified udcl Output: int *daytab[13]  ->(correct)
 *
 * daytab -> daytab[13] -> *daytab[13] -> int *daytab[13]
 *
 *  Input: pfa [] * ()
 * Output: pfa -> pfa[] -> *pfa[] -> (*pfa[])()
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 200

enum {NAME, PARENS, BRACKETS};
enum {NO, YES};

int gettoken(void);
int tokentype; /*type of last token*/

char token[MAXTOKEN]; /*last token string*/
char name[MAXTOKEN]; /*Identifier name*/
char datatype[MAXTOKEN]; /*char, int .etc*/
char out[1000];

int main()
{
	int type;
	char temp[MAXTOKEN];
	int prevtype = EOF;
	
	while (gettoken() != EOF){
		strcpy(out, token);
		while ((type = gettoken()) != '\n'){
			if (type == PARENS || type == BRACKETS){
				if (prevtype == '*') {
					sprintf(temp, "(%s)%s", out, token);
					strcpy(out, temp);
				} else
					strcat(out,token);
			} else if (type == '*'){
				sprintf(temp, "*%s", out);
				strcpy(out, temp);

			} else if (type == NAME){
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
			prevtype = type;
		}
		printf("%s\n", out);		
	}
	return 0;
}

/************************* gettocken() *****************************/

int gettoken(void) /*return next token*/
{
	int c, getch(void);
	void ungetch(int);
	
	char *p = token;
	
	while((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for(*p++ = c; (*p++ = getch()) != ']';)
			;
	*p = '\0';
	return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch());)
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else 
		return tokentype = c;
}

/**********************getch() and ungetch()************************/
#define MAXSIZE 100
char s[MAXSIZE];
int bufp = 0;

/*getch:get a charecter*/
int getch(void){
	return (bufp > 0) ? s[--bufp] : getchar();
}

/*ungetch:push charecter back to input*/
void ungetch(int c){
	if(bufp>=MAXSIZE)
		printf("ungetch:too many charecters");
	else
		s[bufp++] = c;
}
