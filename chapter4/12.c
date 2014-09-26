/*Exercise 4-12
adapt the ideas of printd to write a recursive version of itoa; 
that is, convert an integer into a string by calling a recursive 
routine.
*/

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i = 0, sign;
	if (n/10)
		itoa(n/10,s);
	else {
		if(n<0)
			S[i++] = '-';
	}	
	s[i++] = abs(n % 10) + '0'; 
	s[i] = '\0';
}

