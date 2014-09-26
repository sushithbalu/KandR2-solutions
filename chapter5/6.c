/* Exercise 5-6. 
Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline 
(Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), 
reverse (Chapter 3), and strindex and getop(Chapter 4).
*/
#include <stdio.h>
#include <string.h>

void reverse (char *s);

int main()
{
	char s[100] = "redrawer";

	reverse(s);
	printf("%s\n", s);
	return 0;
}

/* getline */
int get_line(char *ps, int max)
{
	int c;
	char *pt = ps;
	while(--max > 0 && (c = getchar()) !=EOF && c!= '\n'){
		*ps++ = c;
	}
	if(c == '\n')
		*ps++ = c;
	*ps = '\0';
	return ps - pt;  
}

/* itoa */
void itoa(int n, char* s)
{
	int i, sign;
	char* t = s;

	if((sign = n) < 0)
		n = -n;
	do {
		*s++ = n % 10 + '0';
	}
	while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	*s = '\0';
	reverse(t);

}

/* atoi */
int atoi (char *s)
{
	int n, sign;
	char *t = s;

	for(; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for(n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');
	return sign * n;
}

/* reverse */
void reverse (char *s)
{
	int c, j;
	char *t = s;

	while(*t)
		t++;
	for ( t = s + (strlen(s)-1); s < t; s++, t--) {
		c = *s;
		*s = *t;
		*t = c;
	}
}

/* strindex */
int strindex(char *s, char t*)
{
	char *a = s;
	char *u, *v;

	for(; *s != '\0'; s++) {
		for(u = s, v = t; *v != '\0' && *u == *v; u++, v++ )
			;
		if(v > t && *v == '\0')
			return s - a;
	}
	return -1;
}
