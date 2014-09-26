/*
   Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
leading or trailing - is taken literally.
*/
#include<stdio.h>
#include<ctype.h>

void expand(char s1[], char s2[]);
main()
{
	char s1[50];
	char s2[200];

	scanf("%s", s1);
	expand(s1, s2);
	printf("s1 = %s\n s2 = %s\n", s1, s2);
	return 0;
}

void expand(char s1[], char s2[]){

	int i, j, k;

	i = j = 0;
	for(i=0; s1[i] != '\0'; i++){
		if(s1[i]=='-'){
			if((isalpha(s1[i-1])&&isalpha(s1[i+1]))||(isdigit(s1[i-1])&&isdigit(s1[i+1]))){
				if(s1[i-1] < s1[i+1]){
					for(k = s1[i-1]; k <= s1[i+1]; k++) 
						s2[j++] = k;
					}
				else if(s1[i-1] > s1[i+1]){
					for(k = s1[i-1]; k >= s1[i+1]; k--) 
						s2[j++] = k;
					}
				else{
					i++;
				}
				break;
			}
		}
	}
	s2[j]='\0';
}

