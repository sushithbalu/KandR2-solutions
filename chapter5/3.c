
 /*Exercise 5-3 
 strcat: concatenate t to end of s; pointer version */
void strcat(char *ps, char *pt)
{
	while (*ps) /* find end of s */
		ps++;
	while (*ps++ = *pt++) /* copy t */
		;
}
