#include<stdio.h>
#include<ctype.h>

#define fisupper(c) ((unsigned)c >= 'A'&& (unsigned)c <= 'Z') ? 1 : 0


int main()
{
	int c, i;
	while((c = getchar())!= EOF){
		i = fisupper(c);
		printf("%d",i);
	}
	return 0;
}
