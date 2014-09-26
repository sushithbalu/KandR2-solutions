
/*Exercise 5-1
first store the sign locally, and check the charecter after 
the sign, if it is a not number ungetch, and ungetch the sign, and 
return sign to indicate the situation */

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint (int *pn)
{
	int c, d, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c =='+' || c == '-'){
		d = c;
		if(!isdigit(c = getch())){
			if(c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		 }
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);

	return c;
}
