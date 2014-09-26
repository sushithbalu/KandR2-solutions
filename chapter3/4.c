#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);
main()
{
	int n;
	char s[132];
 	printf("Enter:");
	scanf("%d",&n);
	itoa(n, s);
	printf("%d %s", n, s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
	int i, sign;
	void reverse(char s[]);
	i = 0;

	do {
	s[i++] =abs(n % 10 + '0'); /* get next digit */
	}

	 while(n /= 10);
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
