#include <stdio.h>
#include "pe12-2a.h"

static void p_distance(void);
static void p_fuel(void);

int mmode = 0;
int distance = 0;
double fuel = 0.0f;

void setmode(int imode)
{
	if ((imode < -1) || (imode > 1))
		printf("Incorect mode: %d. Used recent mode: %d (%s)\n", 
			imode, mmode, mmode ? "US" : "EU");
	else 	
		mmode = imode;
}

void get_info(void)
{
	
	p_distance();
	
	int status;
	status = scanf("%d", &distance);
	
	while (1)
	{
		if (!status)
		{
			printf("Incorect distance.\n");
			p_distance();
			while (getchar() != '\n')
				continue;
			status = scanf("%d", &distance);			}
		else break;
	}	
	
	p_fuel();
	status = scanf("%lf", &fuel);
	
	while (1)
	{
		if (!status)
		{
			printf("Incorect consuption.\n");
			p_fuel();
			while (getchar() != '\n')
				continue;
			status = scanf("%lf", &fuel);	
		}
		else break;
	}
	
	//puts("get_info");
}

void show_info(void)
{
	/*puts("show_info");
	printf("mmode=%d;distance=%d;fuel=%.2f\n"
		, mmode, distance, fuel);
	*/
	if (!mmode)
		printf("Fuel consumption is %.2lf liters per 100km.\n" 
			, (fuel / distance) * 100.0);
			
	else
		printf("Fuel consumption is %.1lf miles per gallon.\n" 
			, distance / fuel);
	
}

static void p_distance(void)
{
	if (mmode == 0)
		printf("Enter distance traveled in kilometers: ");
	else
	    printf("Enter distance traveled in miles: ");	 	
}	

static void p_fuel(void)
{
	if (mmode == 0)
		printf("Enter fuel consumed in litres: ");
	else
	    printf("Enter fuel consumed in gallons: ");	 	
}	
