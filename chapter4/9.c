/* Exercise 4-9
Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.
*/

#define BUFSIZE 100
int buf[BUFSIZE]; /*buffer for next ungetch*/
int bufp = 0; /*next free positon in buf*/
int getch(void){
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

