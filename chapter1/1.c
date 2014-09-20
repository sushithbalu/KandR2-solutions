/* Exercise 1-1. Run the `` hello, world '' program on your system. 
   Experiment with leaving out parts of the program, to see what 
   error messages you get.

	-> error: missing terminating charecter
	-> warning: incompatible im
	implicit declaration of built-in function ‘printf’ [enabled by default]
  	
	   ^
	-> error: expected declaration or statement at end of input
  	^
	 }
	^
*/
#include<stdio.h>
int main()
{
	printf("hello world\n");
	return 0;
}

