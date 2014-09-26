/*Exercise 5-4
strend: return1 t occurs at the end of s otherwise return 0 */

#include <stdio.h>
#include <ctype.h>
int strend(char *ps, char *pt);
int main()
{
	char *s1, *s2, *s3;
	
	s1 = "at the end of sting";
	s2 = "ing";
	s3 = "end";
	
	printf("%d\n", strend(s1, s2));
	printf("%d", strend(s1, s3));
	return 0;
}
int strend(char *ps, char *pt)
{
	char *s = ps;
	char *t = pt;

	for (; *ps; ps++)/*end of ps*/
		;
	for (; *pt; pt++)/*end of pt*/
		;
	
	for(;(*ps == *pt) ; ps--, pt--)
		if(pt == t)
		break;
	if(*ps == *pt)
		return 1;
	else 
		return 0;
}
