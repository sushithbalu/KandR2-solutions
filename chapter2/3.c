/* Exercise 2-3:
Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. 
The allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
int htoi(char s[]);

main()
{
	int i, lim =100, c;
	char s[1000];

	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
		printf("%d\n",htoi(s));
	return 0;

}
int htoi(char s[])
{
	int i, n, lim, hx;

	n = 0;
	i = 0;
	for(i = 0; i < lim; i++) {
		if( s[i] >= '0' && s[i] <= '9'){
			hx = s[i] - '0';
		} else if(s[i] >= 'a' && s[i] <= 'f'){
			hx = s[i] - 'a' + 10;
		} else if(s[i] >= 'A' && s[i] <= 'F'){
			hx = s[i] - 'A' + 10;
		} else if(s[i] == 'x'){
                        hx = n = 0;
		} else if(s[i] == 'X'){
                        hx = n = 0;			
		} else {
			break;
		}
		n = 16*n + hx;
	}
	return n;
}
