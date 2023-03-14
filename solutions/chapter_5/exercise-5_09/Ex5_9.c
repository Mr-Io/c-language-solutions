#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yday, int* month, int* day);

int main()
{
	int y, m, d;
	
	y = 1988;
	month_day(y, 366, &m, &d);

	printf("%d %d %d\n", y, m, d);
	printf("%d\n", day_of_year(y, m, d));
	return 0;
}

static char dtab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day < 1 || month < 1 || month>12 || day > *(*(dtab+leap)+month)) // error checking
		return -1;
	while (--month > 0)
		day += *(*(dtab + leap) + month);
	return day;
}

int month_day(int year, int yday, int* month, int* day)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (yday < 1 || yday > ((!leap) ? 365 : 366)) // error checking
		return -1;
	*month = 0;
	while (yday > *(*(dtab+leap) + *month)) {
		yday -= *(*(dtab+leap) + *month);
		++(*month);
	}
	*day = yday;
	return year;
}
