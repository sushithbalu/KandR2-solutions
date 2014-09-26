/*
Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char s[]);
void itoa(int n, char s[],int p);
main()
{
	int n, p;
	char s[132];

	printf("Enter an integer and base:\n");
	scanf("%d %d",&n, &p);
	itoa(n, s, p);
	printf("\nThe number %d to the base: %d is = %s\n", n, p, s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int p){
	int i, j, sign;
	void reverse(char s[]);
		if ((sign = n) < 0)
			n = -n;
		i = 0;
	do {
		if(n%p <= 9)
			s[i++] = (n % p + '0');
		else
			s[i++] = (n % p + 'a' -10);
	}
	while ((n /= p) > 0);
	if (sign < 0)
		s[i++] = '-';
		s[i] = '\0';
		reverse(s);
}

void reverse(char s[]){
		int i, j, c;

		for (i = 0, j = strlen(s)-1; i < j; i++, j--)
			c = s[i], s[i] = s[j], s[j] = c;
}

