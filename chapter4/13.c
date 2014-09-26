/* Exercise 4-13
Write a recursive version of the function reverse(s), which reverses the
string s in place.
*/
#include<stdio.h>
#include <string.h>
/*reverse: reverse string s in place using recursion*/
void reverse(char s[])
{
	int i, j, c;
	
	for(i = 0; j = strlen(s)-1; i <j; i++, j++){
		reverse(s) = s[j];
	}

}
