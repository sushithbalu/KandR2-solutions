/*
 * Exercise 5-20. Expand dcl to handle declarations with function argument types,
 * qualifiers like const, and so on.
 *
 * storage-class-specifier: auto, register, static, extern, typedef.
 * type-specifier:          void, char, short, int, long, float, double, signed
 *                          unsigned etc.
 * type-qualifier:          const, volatile.
 * 
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 200

enum {NAME, BRACKETS, SPECIFIER, QUALIFIER};

void  dcl(void);
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
	while(1){
		datatype[0] = '\0';
		while(gettoken() == SPECIFIER|| tokentype == QUALIFIER){
			strcat(datatype, token);
			strcat(datatype, " ");
		}
		if(tokentype == EOF)
			break;
		if(tokentype == '\n')
			continue;
		name[0] = '\0';
		out[0] = '\0';
		dcl();
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;	
}

/********************dcl: parse a declarator**********************/
#include <stdio.h>
#include <string.h>

void dcl(void)
{
	char add[1000];
	add[0] ='\0';
	while ( tokentype == '*'){
		while(gettoken() == QUALIFIER){
			strcat(add, " ");
			strcat(add, token);
		}
		strcat(out, "pointer to ");
	}
	dirdcl();
	strcat(out, add);
}

/***************dirdcl: parse a direct declarator*****************/
void dirdcl(void){
	int type;
	char datatype_function[1000];

	if (tokentype == '('){   /* (dcl) */
		gettoken();
		dcl();
		if (tokentype != ')'){
			printf("error: missing )\n");
		}
	} else if (tokentype == NAME){ /*variable name*/
		if(name[0] == '\0'){
			strcpy(name, token);
		}
	} else {
		printf("error: expected name or (dcl)\n");
	}	
	type = gettoken();
	if(type == '('){
		strcat(out, "function (");
		gettoken();
		while(tokentype != ')'){
			datatype_function[0] = '\0';
			while(tokentype == SPECIFIER ||
				tokentype == QUALIFIER){
				strcat(datatype_function," ");
				strcat(datatype_function, token);
				gettoken();
			}
			dcl();
			strcat(out, datatype_function);
		}
		strcat(out, " ) returning");
		gettoken();
	} else {
		while(type == BRACKETS){
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
			type = gettoken();
		}
	}
}

/************************ gettocken() ***************************/

int gettoken(void) /*return next token*/
{
	int c, getch(void);
	void ungetch(int);
	
	char *p = token;
	
	while((c = getch()) == ' ' || c == '\t')
		;
	if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch());)
			*p++ = c;
		*p = '\0';
		ungetch(c);
		if(strcmp(token, "auto") == 0
		|| strcmp(token, "register") == 0
		||strcmp(token, "static") == 0
		||strcmp(token, "extern") == 0
		||strcmp(token, "typedef") == 0
		||strcmp(token, "void") == 0
		||strcmp(token, "char") == 0
		||strcmp(token, "short") == 0
		||strcmp(token, "int") == 0
		||strcmp(token, "long") == 0
		||strcmp(token, "float") == 0
		||strcmp(token, "double") == 0
		||strcmp(token, "signed") == 0
		||strcmp(token, "unsigned") == 0)
			return tokentype = SPECIFIER;
		else if(strcmp(token, "const") == 0
			||strcmp(token, "volatile") == 0)
			return tokentype = QUALIFIER;
		else
			return tokentype = NAME;
        } else if (c == '(') {
                return tokentype = '(';

        } else if (c == '[') {
                for(*p++ = c; (*p++ = getch()) != ']';)
                        ;
        *p = '\0';
        return tokentype = BRACKETS;

	} else 
		return tokentype = c;
}
/********************getch() and ungetch()*********************/
#define MAXSIZE 300
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
