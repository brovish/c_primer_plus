#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MLEN 30
#define MLENABB 3
#define MC 12
#define DAYS_O 31

struct month {
	char c_month[MLEN];
	char c_month_abb[MLENABB];
	int i_month;
	int day;
	int year;
};

struct month months_ordinal[MC] =
{
	{"january", "jan", 1, 31}, {"february", "feb", 2, 28},
        {"march", "mar", 3, 31}, {"april", "apr", 4, 30},
        {"may", "may", 5, 31}, {"june", "jun", 6, 30},
        {"jule", "jul", 7, 31}, {"august", "aug", 8, 31},
        {"september", "sep", 9, 30}, {"october", "oct", 10, 31},
        {"november", "nov", 11, 30} ,{"december", "dec", 12, 31}
};

struct month months_leap[MC] =
{
	{"january", "jan", 1, 31}, {"february", "feb", 2, 29},
        {"march", "mar", 3, 31}, {"april", "apr", 4, 30},
        {"may", "may", 5, 31}, {"june", "jun", 6, 30},
        {"jule", "jul", 7, 31}, {"august", "aug", 8, 31},
        {"september", "sep", 9, 30}, {"october", "oct", 10, 31},
        {"november", "nov", 11, 30} ,{"december", "dec", 12, 31}
};

void clean_input(void);
int is_leap(int year);
//int valid_day_ch(int isleap, int day, char * month);
int get_month_num(char * month);
char * get_month_name(int month);
int valid_day_int(int isleap, int day, int month);
int valid_month_name(char * input_m);
int valid_month(int mnum);
int date_days(int year, int month, int day, int isleap);
void show_all_months(int year, int isleap);

int main(void)
{
	
	int day, year, i_month, isleap;
	char c_month[MLEN];
	//char c_month_abb[MLENABB];
	int rv = 0;
	int is_month_int = 0;
	//printf("%d %d\n", 2020, is_leap(2020));	
	while (!rv)
	{
		printf("Enter year: ");
		rv = scanf("%d", &year);
		if (rv == 0)
			printf("Invalid year.\n");
		clean_input();
		isleap = is_leap(year);
	}

	rv = 0;

	while (!rv)
	{
		printf("Enter month (can be a month number, "
		"a month name, or a month abbreviation):\n");
		rv = scanf("%s", c_month);
		i_month = (int)strtol(c_month, NULL, 10);
		//printf("i_month=%d\n", i_month);
		if (i_month)
		{
			//printf("%d\n", i_month);
			if (!valid_month(i_month))
			{
				rv = 0;
				printf("Invalid month.\n");
			}
			is_month_int = 1;
			//c_month = get_month_name(i_month);
		}
		else
		{
			//printf("%d\n", valid_month(c_month));
			if (!valid_month_name(c_month))
			{
				rv = 0;
				printf("Invalid month name.\n");
				continue;
			}
			//printf("c_month=%s\n", c_month);
			i_month = get_month_num(c_month);
			//printf("i_month=%d\n", i_month);
					
		}
		
		clean_input();
	}
	
	rv = 0;
	while (!rv)
	{
		printf("Enter day: ");
		rv = scanf("%d", &day);
		clean_input();
		if (rv == 0 || (day < 1 || day > DAYS_O))
		{	printf("Invalid day.\n");
			rv = 0;
			continue;
		}
		if(!valid_day_int(isleap, day, i_month))
		{
			printf("Invalid day.\n");
			rv = 0;
			continue;
		}
		
		show_all_months(year, isleap);
		
		printf("input data: %d year, %s (%d) month, %d day.\n", 
			year, c_month, i_month, day);
		printf("Total days: %d\n", date_days(year, i_month, day, isleap));	
	}
	
	//rv = 0;
		
	return 0;
}


/*
int valid_day_ch(int isleap, int day, char * month)
{
	int valid = 0;
	int days;
	int i = 0;
		
	for (; i < MC; i++)
	{
		if (isleap)
		{
			if (strcmp(month, months_ordinal[i].c_month) == 0 || 
				strcmp(month, months_ordinal[i].c_month_abb) == 0)
			{
				days = months_ordinal[i].day;
				if (day <= months_ordinal[i].day)
					valid = 1;
			}
		}	
		else
		{
			if (strcmp(month, months_leap[i].c_month) == 0 || 
				strcmp(month, months_leap[i].c_month_abb) == 0)
			{
				days = months_leap[i].day;
				if (day <= months_leap[i].day)
					valid = 1;
			}
		}

	}
	
	
	if (!valid && isleap)
		printf("In %s only %d days\n", month, days);
	else if (!valid && !isleap)
		printf("In %s only %d days\n", month, days);
	
	return valid;
}
*/

void show_all_months(int year, int isleap)
{

	int t_days = 0;
	if (isleap)
	{
		for (int i = 0; i < MC; i++)
		{
			t_days += months_leap[i].day;
			printf("%d) %d year %s - total days %d\n", 
				i + 1, year, months_leap[i].c_month, t_days);
		}
	}
	else
	{
		for (int i = 0; i < MC; i++)
		{
			t_days += months_ordinal[i].day;
			printf("%d) %d year %s - total days %d\n", 
				i + 1, year, months_ordinal[i].c_month, t_days);
		}
	}
}

int date_days(int year, int month, int day, int isleap)
{
	int t_days = 0;
	if (isleap)
	{
		for (int i = 0; i < MC; i++)
		{
			//printf("days:%d m=%d\n", t_days, month);
			
			if (months_leap[i].i_month < month)
			{
				t_days += months_leap[i].day;
				//printf("ss");
			}
			else if (months_leap[i].i_month == month)
			{
				t_days += day;
			}
			else break;
		}	
	}
	else
	{
		for (int i = 0; i < MC; i++)
		{
			if (months_ordinal[i].i_month < month)
			{
				t_days += months_ordinal[i].day;
			}
			else if (months_ordinal[i].i_month == month)
			{
				t_days += day;
			}
			else break;
		}
	}
	
	return t_days;
}

int get_month_num(char * month)
{
	int mnum = 0;
	
	for (int i = 0; i < MC; i++)
	{
		if (strcmp(months_ordinal[i].c_month, month) == 0 
			|| strcmp(months_ordinal[i].c_month_abb, month) == 0)
		{
			mnum = months_ordinal[i].i_month;
			break;
		}
	}
	
	return mnum;
	
}

char * get_month_name(int month)
{
	
	char * c_month;
	
	for (int i = 0; i < MC; i++)
	{
		if (months_ordinal[i].day == month)
		{
			c_month = months_ordinal[i].c_month;
		}
	}
	
	return c_month;
	
}


int valid_day_int(int isleap, int day, int month)
{
	int valid = 0;
	
	int i = 0;
	int days;
	char * c_month;
	
	for (; i < MC; i++)
	{
		if (isleap)
		{
			if (months_ordinal[i].i_month == month)
			{
				days = months_ordinal[i].day;
				c_month = months_ordinal[i].c_month;
				if (day <= months_ordinal[i].day)
				{
					valid = 1;
					break;
				}
			}
		}	
		else
		{
			if (months_leap[i].i_month == month)
			{
				days = months_leap[i].day;
				c_month = months_leap[i].c_month;
				if (day <= months_leap[i].day)
				{	valid = 1;
					break;
				}
			}
		}

	}
	
	if (!valid && isleap)
		printf("In %s only %d days\n", c_month, days);
	else if (!valid && !isleap)
		printf("In %s only %d days\n", c_month, days);
	
	
	return valid;
}

int valid_month(int mnum)
{
	int valid = 0;
	for (int i = 0; i < MC; i++)
	{
		if (months_ordinal[i].i_month == mnum)
		{
			valid = 1;
			break;
		}
		
	}
	return valid;
}

int valid_month_name(char * input_m)
{
	int valid = 0;
	for (int i = 0; i < MC; i++)
	{
		if (strcmp(input_m, months_ordinal[i].c_month) == 0 || 
			strcmp(input_m, months_ordinal[i].c_month_abb) == 0)
		{
			valid = 1;
			break;
		}
		
	}
	return valid;	
}

void clean_input(void)
{
	while (getchar() != '\n')
		continue;
}

int is_leap(int year)
{
/*
If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
The year is a leap year (it has 366 days).
The year is not a leap year (it has 365 days).
*/
	int leap = 0;
	
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				leap = 1;
		}
		else leap = 1;	
			
	}
	
	printf("%d is %s year.\n", year, (leap) ? "leap" : "not leap");
		
	return leap;

}