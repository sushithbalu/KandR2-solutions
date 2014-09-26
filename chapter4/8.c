/*Exercise 4-8
Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.
*/
char buf = 0;
int c;
int getch(void)
{
	c = (buf != 0) ? buf : getchar();
	buf = 0;
	return c;
}
void ungetch(int c)
{
	if (buf != 0)
		printf("ungetch: too many characters\n");
	else
		buf = c;
}

