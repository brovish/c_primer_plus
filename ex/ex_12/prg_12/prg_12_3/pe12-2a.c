#include <stdio.h>
#include "pe12-2a.h"

static void p_distance(int);
static void p_fuel(int);

//int mmode = 0;
//int distance = 0;
//double fuel = 0.0f;

void setmode(int *nmode, int *omode)
{
	//printf("*nmode=%d;*omode=%d\n", 
	//	*nmode, *omode);

	if ((*nmode < -1) || (*nmode > 1))
	{
		printf("Incorect mode: %d. Used recent mode: %d (%s)\n", 
			*nmode, *omode, *omode ? "US" : "EU");
		*nmode = *omode;
	}
	else *omode = *nmode;
}


void get_info(int *distance, double *fuel, int nmode)
{
	
	p_distance(nmode);
	
	int status;
	status = scanf("%d", distance);
	
	while (1)
	{
		if (!status)
		{
			printf("Incorect distance.\n");
			p_distance(nmode);
			while (getchar() != '\n')
				continue;
			status = scanf("%d", distance);			
		}
		else break;
	}	
	
	p_fuel(nmode);
	
	status = scanf("%lf", fuel);
	
	while (1)
	{
		if (!status)
		{
			printf("Incorect consuption.\n");
			p_fuel(nmode);
			while (getchar() != '\n')
				continue;
			status = scanf("%lf", fuel);	
		}
		else break;
	}
	
	//puts("get_info");
}

void show_info(int *distance, double *fuel, int nmode)
{
	//puts("show_info");
	//printf("mmode=%d;distance=%d;fuel=%.2f\n"
	//	, mmode, *distance, *fuel);
	
	if (!nmode)
		printf("Fuel consumption is %.2lf liters per 100km.\n" 
			, (*fuel / *distance) * 100.0);
			
	else
		printf("Fuel consumption is %.1lf miles per gallon.\n" 
			, *distance / *fuel);
	
}

static void p_distance(int mmode)
{
	if (mmode == 0)
		printf("Enter distance traveled in kilometers: ");
	else
	    printf("Enter distance traveled in miles: ");	 	
}	


static void p_fuel(int mmode)
{
	if (mmode == 0)
		printf("Enter fuel consumed in litres: ");
	else
	    printf("Enter fuel consumed in gallons: ");	 	
}	
