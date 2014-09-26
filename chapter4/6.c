/*
Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAXOP 100
#define NUMBER '0'
#define ALPHA '1'

int getop(char []);
void push(double);
double pop(void);
void alpha(char s[]);
/* reverse Polish calculator */
main()

{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				push((int)pop() %(int)op2);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			case ALPHA:
				alpha(s);
				break;
				
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
/* maximum depth of val stack */
/* next free stack position */
/* value stack */
/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
	val[sp++] = f;
	else
	printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if(sp != 0)
		return val[--sp];
	else
		;
	return 0.0;
}

#include <math.h>
void alpha(char s[])
{
	double op2;
	if(strcmp(s, "sin") == 0){
		push(sin(pop()));
	}
	else if( strcmp(s, "cos") == 0){
		push(cos(pop()));
	}
	else if(strcmp(s,"tan") == 0){
		push(tan(pop()));
	}
	else if(strcmp(s,"exp") == 0){
		push(exp(pop()));
	}
	else if(strcmp(s,"pow") == 0){
		op2 = pop();
		push(pow(op2,pop()));
	}
	else if(strcmp(s, "clear") == 0){
				
		printf("stack cleared");
	}
	else if(strcmp(s, "swap") == 0){
		op2 = pop();
		push(op2);
		push(pop());
	}
	else if(strcmp(s, "dup") == 0){
	/*Duplicate*/
		op2 = pop();
		push(op2);
		push(op2);
	}
	else if(strcmp(s, "top") == 0){
	/*Top element*/
	printf("top element is:");
	}
	else{
		printf ("unknown command");
	}
	
}

int getch(void);
void ungetch(int);

#include <ctype.h>
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i =0;
	if(isalpha(c)){
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c!=EOF)
			ungetch(c);
		return ALPHA;
	}
	if (!isdigit(c) && c != '.')
	return c;
	/* not a number */
	if (isdigit(c))
	/* collect integer part */
	while (isdigit(s[++i] = c = getch()))
		;
	if (c == '.')
	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

