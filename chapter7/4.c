/*Exercise7.4: write private version of scanf analogous to miniprintf from the
  previous section.*/

#include<stdio.h>
#include<ctype.h>
#include<stdarg.h>

void minscanf(char *fmt, ...);

int main()
{
	int i;
	float f;
	minscanf("%d %f", &i, &f);
	printf("%d, %f", i, f);
	return 0;
}

void minscanf(char *fmt, ...)
{
	va_list ap; /*A place to store list of arguments*/
	char *p, *sval;
	int *ival;
	float *dval;
	
	va_start(ap, fmt); /*make ap point to first unnamed arg*/
	for(p = fmt; *p; p++){
		if(*p != '%'){
			continue;
		}
		switch(*++p){
		case 'd':
			ival = va_arg(ap, int*);
			scanf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, float*);
			scanf("%f", dval);
			break;
		default:
			break;
		}
	}
	va_end(ap); /*cleanup when done*/
}

