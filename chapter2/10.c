/*Exercise 2-10. Rewrite the function lower , which converts upper case 
letters to lower case, with a conditional expression instead of if-else .*/
#include <stdio.h>
int upper(int n);

main()
{        
        int c, i, lim = 500;
        char s[1000];

        for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\0'; ++i)
        if(c != ' ')
		s[i] = upper(c);
	else 
		s[i] = c;
	s[i]='\0';	
	printf("\n%s\n", s);
	return 0;
}
int upper(int n)
{	int z;
	z= n>='a' && n<='z' ? (n + 'A' - 'a') : n; 
	return z;
}
