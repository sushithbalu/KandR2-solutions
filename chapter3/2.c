/*
   Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters.
*/
#include <stdio.h>

void escape(char* s,char* t);
main()
{
	char s[100] = "\nfree,\t...\bfor\ffreedom\a for\vall..";
	char t[101];

	printf("String = \n%s\n\n", s);
	escape(t, s);
	printf("Escaped string = \n%s\n\n", t);
	return 0;
}

void escape(char* s, char* t){
	int i, j;
	i = j = 0;

	while(t[i]){
	
		switch(t[i]){
		case '\n':
			s[j++] = '\\';
			s[j] = 'n';
			break;

                case '\t':
                        s[j++] = '\\';
                        s[j] = 't';
                        break;

                case '\a':
                        s[j++] = '\\';
                        s[j] = 'a';
                        break;

                case '\b':
                        s[j++] = '\\';
                        s[j] = 'b';
                        break;

                case '\v':
                        s[j++] = '\\';
                        s[j] = 'v';
                        break;

                case '\f':
                        s[j++] = '\\';
                        s[j] = 'f';
                        break;

                case '\\':
                        s[j++] = '\\';
                        s[j] = '\\';
                        break;
		default:
			s[j] = t[i];
			break;
		}
		++i;
		++j;
	}
	s[j] = t[i];
}

