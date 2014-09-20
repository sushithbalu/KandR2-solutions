/*Exercise 1-2. Experiment to find out what happens when prints 's 
  argument string contains \c, where c is some character not listed 
  above.
  warning: unknown escape sequence: '\c' [enabled by default]

*/

#include <stdio.h>

int main()
{
	printf("hello world\c");
	return 0;
}

