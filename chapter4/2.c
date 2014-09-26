/*
Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and 
an optionally signed exponent.
*/
#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

main()
{	
	printf("%f\n", atof("123.45e-6"));
	return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power, r, exp, pow;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;/*first*/
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	else
		return sign*(val/power);
	if(s[i]=='-')
		r = 0.1;
	else
		r = 10;
	if(s[i] == '+' || s[i] == '-')
		i++;/*second*/
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	for (pow = 1; exp > 0; exp--)
		pow = pow * r;
	return sign * pow * (val/power); 
}

