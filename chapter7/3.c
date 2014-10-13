/*Exercise7.3: Revise minprintf to handle more of other facilities of printf*/

#include<stdio.h>
#include<ctype.h>
#include<stdarg.h>
int main()
{
	
	return 0;
}

void minprintf(char *fmt, ...)
{
	va_list ap; /*A place to store list of arguments*/
	char *p, *sval;
	int ival;
	double dval;
	
	va_start(ap, fmt); /*make ap point to first unnamed arg*/
	for(p = fmt; *p; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p){
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for(sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		case 'c':			/*charecter input*/
			ival = va_arg(ap, int);
			putchar(ival);
			break;
		case 'o':			/*octal*/
			ival = va_arg(ap, int);
			printf("%o", ival);
			break;
		case 'x':			/*hexadecimal, abcdef*/
			ival = va_arg(ap, int);
			printf("%x", ival);
			break;
		case 'X':			/*hexadecimal, ABCDEF*/
			ival = va_arg(ap, int);
			printf("%X", ival);
			break;
		case 'e':			/*exponent*/
			dval = va_arg(ap, double);
			printf("%e", dval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap); /*cleanup when done*/
}

