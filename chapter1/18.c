/*Exercise 1-18: Write a program to remove trailing blanks and tabs from 
  each line of input, and to delete entirely blank lines.*/

#include <stdio.h>

#define MAXLINE 1000

/* delete trailing blanks, tabs, and blank lines */

int etline(char s[], int max);
int multispace(char str[]);

int main(void)
{
    int len, i,j;
	char line[MAXLINE], longest[MAXLINE];

    while ((len = etline(line, MAXLINE)) != 0) {
		if(len>1){	
			for(i=0;i<len;i++){
				if((line[i]==' ')&&(line[i+1]==' '))
					for(;;){
						if(line[i+1]!=' ')
							break;
				        else
    			    		for(j = i; j < len; j++)
    			      			line[j] = line[j+1];
							len--;
					}
				else if((line[i] == '\t') && (line[i+1] == '\t'))
					for(;;){
						if(line[i+1]!='\t')
							break;
				        else
    			    		for(j=i;j<len;j++)
    			      			line[j]=line[j+1];
							len--;
					}
				else if((line[i]=='\n')&&(line[i+1]=='\n'))
					for(;;){
						if(line[i+1]!='\n')
							break;
				        else
    			    		for(j=i;j<len;j++)
    			      			line[j]=line[j+1];
							len--;
					}
			}
		}
		printf("%s",line);
   		return 0;
	}
}
int etline(char s[], int max){
    int i, c;
    for (i=0; i<max-1 && (c=getchar())!=EOF ; ++i)
	    s[i] = c;
    	s[i] = '\0'; 
    return i;
}

