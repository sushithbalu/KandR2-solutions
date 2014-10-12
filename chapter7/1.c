#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void utol();
void ltou();

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("error, usage: %s <-u> or <-l>\n", argv[0]);
		exit(1);
	}
	if(strcmp(argv[1], "-u") == 0){
		utol();
	} else if(strcmp(argv[1], "-l") == 0){
		ltou();
	} else {
		printf("error, usage: %s <-u> or <-l>\n", argv[0]);
		exit(1);
	}

	return 0;
}

void utol()
{
	int c, out;
	while((c = getchar()) != EOF){
		out = tolower(c);
		putchar(out);
	}
}

void ltou()
{
	int c, out;
	while((c = getchar()) != EOF){
		out = toupper(c);
		putchar(out);
	}
}

