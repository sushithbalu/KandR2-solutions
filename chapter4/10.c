/*
Exercise 4-10. An alternate organization uses getline to read an entire 
input line; this makes getch and ungetch unnecessary. Revise the 
calculator to use this approach.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXA 1000

int getop(char []);
void push(double);
double pop(void);
int g_etline(char [], int );

static int j; /*11th question*/
static char line[MAXA];
/* reverse Polish calculator */
main()

{
	int type;
	double op2;
	char s[MAXOP];
	while(g_etline(line, MAXA) != 0)
	{	
		while ((type = getop(s)) != '\0') {
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
		j = 0;
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

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
	if (sp > 0)
		return val[--sp];
	else 
		printf("error: stack empty\n");
	return 0.0;
}

/*getline:return i*/
int g_etline(char s[], int lim)
{
	int i, c;
	i = 0;
	while(--lim > 0 &&(c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

#include <ctype.h>
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = line[j++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	return c;
	/* not a number */
	i = 0;
	if (isdigit(c))
	/* collect integer part */
	while (isdigit(s[++i] = c = line[j++]))
		;
	if (c == '.')
	/* collect fraction part */
		while (isdigit(s[++i] = c = line[j++]))
			;
	s[i] = '\0';
	j--;
	return NUMBER;
}
