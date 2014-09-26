#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);
int errorstate;
int tokentype; /*type of last token*/

char token[MAXTOKEN]; /*last token string*/
char name[MAXTOKEN]; /*Identifier name*/
char datatype[MAXTOKEN]; /*char, int .etc*/
char out[1000];

int main()
{
	while(gettoken() != EOF){
	if(tokentype != '\n'){	
			strcpy(datatype, token);
			out[0] = '\0';
			dcl();
			printf("%s: %s %s\n", name, out, datatype);
	      		if (tokentype != '\n')
				 printf("syntax error\n");
			
		}
	}
	getchar();
	return 0;	
}

/*dcl: parse a declarator*/
#include <stdio.h>
#include <string.h>

void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*';)
		ns++;
	dirdcl();
	while(ns-- > 0)
		strcat(out, " pointer to");
}

/*dirdcl: parse a direct declarator*/
void dirdcl(void){
	int type;

	errorstate = 0;
	if (tokentype == '('){   /* (dcl) */
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME) /*variable name*/
		strcpy(name, token);
	else{
		printf("error: expected name or (dcl)\n");
		errorstate = 1;
		}	
	if(!errorstate)
	while ((type=gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}

/* gettocken() */

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
/*getch and ungetch*/
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
