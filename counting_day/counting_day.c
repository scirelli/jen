#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void){
	struct tm athena_birthday_time = { .tm_year=116, // = year 2016; 1900 + 116 = 2016
	                          .tm_mon=11,    // = 10th month; 0 based
	                          .tm_mday=23,   // = 23th day
	                          .tm_hour=5,   // = 5 hours
	                          .tm_min=25,   // = 25 minutes
	                          .tm_sec=00    // = 00 secs
	};

	time_t todayInSec = time(NULL), //Today in seconds since 00:00, Jan 1 1970 UTC
			athenaBd   = mktime(&athena_birthday_time);

	printf("Today: %s\n", ctime(&todayInSec));
	printf("Athena's birthday: %s\n", ctime(&athenaBd));

	double diffInSec = difftime(todayInSec, athenaBd),

 		days = (diffInSec/60.f/60.f/24.f),
		hours = (days - floor(days))*24.f,
		minutes = (hours - floor(hours))*60.f,
		years = (days - floor(days))/365.f;

	int daysDisplay = (int)days;
	int hoursDisplay = (int)hours;
	int minutesDisplay = (int)minutes;
	int yearsDisplay = (int)years;

	printf("Difference in seconds: %f\n", diffInSec);

	printf("Days since Athena's birthday: %d\n", daysDisplay);

	printf("Hours since Athena's birthday: %d\n", hoursDisplay);

	printf("Minutes since Athena's birthday: %d\n", minutesDisplay);

	printf("Years since Athena's birthday: %d\n", yearsDisplay);

	return EXIT_SUCCESS;
}
