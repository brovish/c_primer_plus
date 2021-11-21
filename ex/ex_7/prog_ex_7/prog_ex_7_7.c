/*Write a program that requests the hours worked in a week and then 
prints the gross pay,
the taxes, and the net pay. Assume the following:
a. Basic pay rate = $10.00/hr
b. Overtime (in excess of 40 hours) = time and a half
c. Tax rate: #15% of the first $300
20% of the next $150
25% of the rest*/
#include <stdio.h>
#include <stdlib.h>
#define PAY_RATE_1 8.75f
#define PAY_RATE_2 9.33f
#define PAY_RATE_3 10.f
#define PAY_RATE_4 11.20f
#define EXIT 5
#define OVERTIME_RATE 1.5
#define OVERTIME_LIMIT 40
#define TAX_15 0.15f
#define TAX_20 0.20f
#define TAX_25 0.25f
#define TAX_LIMIT_15 300.0f
#define TAX_LIMIT_20 150.0f
#define SEP "*****************************************************************"
void startmenu();
int clear();
int main()
{
    int hours;
    int rate = 0;
    int scanf_res;
    int signal_stop;
    float net_pay = 0.f;
    float gross_pay = 0.f;
    float taxes_base = 0.f;
    float overpay_sum = 0.f;
    float sum_tax = 0.f;
    
    float actual_pay_rate;
[23~    
    clear();
    
    signal_stop = 0;
    
    startmenu();
    
    while (1)
    {
	//printf("%d\n", rate);
	scanf_res = scanf("%d", &rate);
	if (scanf_res)
	{
	    //printf("%d\n", rate);
	    switch (rate)
	    {
		case 1 :
		    actual_pay_rate = PAY_RATE_1;
		    break;
		case 2 :
		    actual_pay_rate = PAY_RATE_2;
		    break;
		case 3 :
		    actual_pay_rate = PAY_RATE_3;
		    break;
		case 4 :
		actual_pay_rate = PAY_RATE_4;
		    break;
	        case EXIT:
		    signal_stop = 1;
		    break;
		default :
		    clear();
		    printf("Please enter number from 1 to 5 (5 to quiot)\n");
		    startmenu();
		    continue;
	    }
	
	    if (!signal_stop)
	    {
		clear();
		printf("Enter the number of hours worked in 1 week:\n");
    		printf("%s\n", SEP);
	        scanf("%d", &hours);
	        
		if (hours > OVERTIME_LIMIT)
		{
		    overpay_sum = (float) (hours - OVERTIME_LIMIT) 
		    * actual_pay_rate * OVERTIME_RATE;
		}
    
		net_pay = (float) (actual_pay_rate * hours) + overpay_sum;
		gross_pay = taxes_base = net_pay;
    
		if (taxes_base > 0)
		{
		    sum_tax = (float) TAX_LIMIT_15*TAX_15;
			taxes_base -= TAX_LIMIT_15;
		}

		if (taxes_base > 0)
		{
		    sum_tax += (float) (taxes_base-(taxes_base-TAX_LIMIT_20))*TAX_20;
			taxes_base -= TAX_LIMIT_20;
		}

		if (taxes_base > 0)
		{
		    sum_tax += (float) taxes_base*TAX_25;
		}
    
		net_pay -= (float) sum_tax;
	    
	        printf("Total information for %d hours per 1 week with $%2.2f/hr.\n"
		    , hours, actual_pay_rate);
		printf("Gross pay: %.2f; Net pay: %.2f; Taxes: %.2f\n"
		    , gross_pay, net_pay, sum_tax);
		
		//clear();
		startmenu();
		
	    } else if (signal_stop)
		    break;
	} else
	{
	    //printf("%d\n", rate);
	    clear();
	    printf("Please enter number from 1 to 5 (5 to quiot)\n");
	    scanf("%*s");//clear the invalid character(s) from stdin
	    //clear();
	    startmenu();
	    
	    continue;
	}
    }
        
    return 0;
}

void startmenu()
{
    printf("%s\n", SEP);
    
    printf("Enter the number corresponding to the desired "
	    "pay rate action:\n");
    printf("1) $%2.2f/hr                    2) $%2.2f/hr\n", 
	PAY_RATE_1, PAY_RATE_2);
    printf("3) $%2.2f/hr                   4) $%2.2f/hr\n", 
	PAY_RATE_3, PAY_RATE_4);
    printf("5) quit\n");
    
    printf("%s\n", SEP);
}

int clear()
{
    return system("clear");
}