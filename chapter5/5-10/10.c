/* 5-10
    write the program expr, which evaluates a reverse Polish expression
from the command line, where each operator or operand is seperate argument, 
For eg: expr 2 3 4 + *       ->evaluates 2*(3+4)

NB: operator '*' is replaced with 'p' for finding product of two numbers,
    because unary operator '*' is also used to indicate a pointer.
*/

#include <stdio.h>
#include <stdlib.h> /*atof()*/
#include <string.h> /*strlen()*/

#define MAXTOP 100
#define NUMBER '0'
 
void push(double);
double pop(void);

/* reverse polish calculator */
int main(int argc, char *argv[])
{
	int type, c;
	double op2;

	while(--argc > 0) {
	if((!isdigit(c = **++argv)) && (strlen(*argv) == 1))
		type = c;
	else
		type = NUMBER;
	switch (type){
		case NUMBER:
			push(atof(*argv));
			break;
		case '+':
			push(pop() + pop());
			break;
		case 'p':
			push(pop() * pop());
			break;		
		case '-':
			op2 = pop();
			push(pop() - op2);
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop()/op2);
			else
				printf("error: zero divisor\n");
			break;
		default:			
		printf("error: unknown command\n");
		argc = 1;
			break;
		}
	}
	printf("%g\n", pop());
	return 0;
}

/*push and pop*/
#define MAXVAL 100 /*maximum of value stack*/
int sp = 0; /*next free stack position*/
double val[MAXVAL]; /*value stack*/

/*push: push f onto value stack*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/*pop: pop and return top value from stack*/
double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty \n");
		return 0.0;
	}
}

