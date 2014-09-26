/*
Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers
 instead of indexing.
*/

#include<stdio.h>
main()

	static char daytab[2][3] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
/* day_of_year: set day of year from month &day */
int day_of_year(int year, int month, int day)
{
	int leap;
	char* p;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab[leap][i];
	while(--month)
		day += *++p;
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab[leap][i];
 	while(yearday > *++p)
		yearday -= *p;
}
