
/*Exercise 1-14:Write a program to print a histogram of the frequencies of 
different characters in its input.*/

#include <stdio.h>
int main()
{
	int c;
	int a[91];
	int i, j;

	for(i = 0; i < 91; ++i){
		a[i] = 0;
	}
    while((c = getchar()) != '\n'){
		if(c >= 32 && c <= 123){
			if(c != '\n')
				++a[(c-32)];
			if(c == '\n')
				break;
		}
	}
	printf("Case\t|\tfrequency\n");
	for(i = 0; i < 91; ++i)
		printf("%c\t|\t%d\n", (i+32), a[i]);
}
