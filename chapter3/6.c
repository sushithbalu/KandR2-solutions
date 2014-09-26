/*
Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[],int p);
main()
{
	int n, p;
	char s[132];

	printf("Enter an integer and width:\n");
	scanf("%d %d",&n, &p);
	itoa(n, s, p);
	printf("\n %s\n", s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int p){
	int i, j, sign;
	void reverse(char s[]);
	i = 0;
	do {
	s[i++] = n % 10 + '0'; /* get next digit */
	}
	while (n /= 10);
		if (sign < 0)
		s[i++] = '-';
	while (i<p)
		s[i++] = ' ';

	reverse(s);
}

void reverse(char s[]){
	int i, j, c;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
