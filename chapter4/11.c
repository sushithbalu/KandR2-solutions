/*
Exercise 4-11. Modify getop so that it doesn't need to use ungetch . 
Hint: use an internal static variable.
*/
#include <stdio.h>
#include <stdlib.h> 

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

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

			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

int sp = 0;
double val[MAXOP];
void push(double f)
{
	if (sp < MAXOP)
	val[sp++] = f;
	else
	printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else 
		printf("error: stack empty\n");
		return 0.0;
}


int getch(void);


#include <ctype.h>
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	static int state;  /*improtant*/
	if(state != EOF)
		c = getch();
	else
		c = state;
		state= EOF; 

	while ((s[0] = c = getch()) == ' ' || c == '\t'|| c == EOF)
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	/* collect integer part */
	if(isdigit(c))
	while (isdigit(s[++i] = c = getch()))
		;
	if (c == '.')
	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c !=EOF)
		state = c;
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

