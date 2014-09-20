/* Exercise 2-4:
Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.
*/
#include <stdio.h>
void squeeze(char s1[], char s2[]);

main()
{
	int i, k, c;
	char s[50] = "recursivetech";
	char t[50] = "technology"; 
	printf("s = %s\n t = %s \n ",s ,t);
	squeeze(s,t);
	printf("squeeze = %s\n  \n ",s);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	int state = 0;

	for(i = j = 0; s1[i] != '\0'; i++){
		state = 0;
		for(k = 0; s2[k] != '\0'; k++){
			if(state==0)
				if(s2[k] == s1[i]){
				state = 1;
			}
		} 
		if(!state){
		s1[j++] = s1[i];
		} 
	}
	s1[j] = '\0';
}
