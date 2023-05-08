#include <stdio.h>

static char dtab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yday, int* month, int* day);

int main()
{
	int yearday;
	int year, month, day;
	
	while(1){
		printf("> year month day: ");
		if (scanf("%d %d %d", &year, &month, &day) != 3){
			return -1;
		}
		if ((yearday = day_of_year(year, month, day)) == -1){
			fprintf(stderr, "error day_of_year: wrong input\n");
			return -1;
		}
		printf("day of year: %d\n", yearday);

		printf("> year yearday: ");
		if (scanf("%d %d", &year, &yearday) != 2){
			return -1;
		}
		if (month_day(year, yearday, &month, &day) == -1){
			fprintf(stderr, "error month_day: wrong input\n");
			return -1;
		}
		printf("date: %02d/%02d/%d\n", day, month, year);
	}

	return 0;
}

/* return `day of year` on success and -1 on error */
int day_of_year(int year, int month, int day)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	// error checking
	if (day < 1 || month < 1 || month > 12 || day > *(*(dtab+leap)+month)){
		return -1;
	}
	// continue
	while (--month > 0){
		day += *(*(dtab+leap)+month);
	}
	return day;
}

/* return 0 on success and -1 on error */
int month_day(int year, int yday, int* month, int* day)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	// error checking
	if (yday < 1 || yday > ((leap) ? 366 : 365)){
		return -1;
	}
	// continue
	int local_month = 0;
	while (yday > *(*(dtab+leap)+local_month)) {
		yday -= *(*(dtab+leap)+local_month);
		++local_month;
	}
	*month = local_month;
	*day = yday;
	return 0;
}
