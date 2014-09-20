/* Exercise 19: Write a function reverse(s) that reverses the character strings.
 Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>

#define MAXLINE 1000

/* reverse a line at a time */
int etline(char s[], int max);
void reverse(char s[]);

int main(void)
{
    int len, i;
    char line[MAXLINE], longest[MAXLINE];

    while ((len = etline(line, MAXLINE))!= '0') {
        if (len > 1){
            reverse(line);
            printf("%s\n", line);
        }
    }
    return 0;
}
int etline(char s[], int max) {
    int i, c;
    for (i=0; i<max-1 && ((c=getchar())!=EOF)&&(c!='\n'); ++i) 
        s[i] = c;
    s[i] = '\0';
    return i;
}

void reverse(char s[]){
    int i, j;
    char temp;

    for (j = 0; s[j] != '\0'; ++j)
			{
			} 
   		--j;	
   
    for (i = 0; i < j; i++) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        --j;
    }
}
