
/* Exercise 5-5. 
Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are 
in Appendix B.
*/


#include<stdio.h>
void strnncat(char *s, char *t, int n);
int main()
{
	char s1[1000] = "loka ";
	char s2[1000] ="samastha sukhino bhavantu!";
	int n = 4; 
	strnncat(s1, s2, n);
	printf("\nstrncat: s= %s\nt= %s\n", s1, s2);
 return 0;
}

/*strncpy*/
void strnncpy(char *s, char *t, int n)
{
	while((*s = *t) && n-- > 0){
		s++;
		t++;
	}
}

/*strncat*/
void strnncat(char *s, char *t, int n)
{
	while(*s)
		s++;

	while((*s = *t) && n-- >0){
		s++;
		t++;
	}

}

/*strncmp*/
int strnncmp(char *s, char *t, int n)
{
	while((*s == *t) && n-- <=0){
		s++;
		t++;
	if(*s == '\0')
		return 0;
	else
	return (*s - *t);
	}
}
