/*Exercise 1-13. Write a program to print a histogram of the lengths of words 
in its input. It is easy to draw the histogram with the bars horizontal; a 
vertical orientation is more challenging.*/
/* Prints a histogram of the lengths of words */

#include<stdio.h>
#include <string.h>

#define MAXA 100

main()
{
	int c, length, word, r, i, j, state, len[MAXA];

	word = length = r = 0;
	state = 0;
	for (i = 0; i < MAXA; ++i) len[i] = 0;
		while ((c = getchar()) != EOF && word < MAXA){
			if (c == ' ' || c == '\t' || c == '\n'){
				state = 0;
			}
			else if (word == 0){
				state = 1;
				++word;
				++length;
			}
			else if (state == 1)
				++length;
			else if (state == 0){
				len[word] = length;
				++word;
        		   	length = 1;
        		   	state = 1;
			}
		}
	len[word] = length;
	printf("\n_______________________________________________\n");
 	for (i = 1; i <= word; ++i){
   		printf("%3d %4d: ",i,len[i]);
		for (j = 0; j < len[i]; j++)
		putchar('=');
		putchar('\n');

    	}
	printf("\n_______________________________________________\n");

}

