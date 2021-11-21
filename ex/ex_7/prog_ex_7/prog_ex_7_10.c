/*
Single 15% of first $17,850 plus 28% of excess
Head of Household 15% of first $23,900 plus 28% of excess
Married, Joint 15% of first $29,750 plus 28% of excess
Married, Separate 15% of first $14,875 plus 28% of excess
*/
#include <stdio.h>
#include <stdlib.h>
#define SEP "*********************************************\n"
#define STOP 5
#define SINGLE_PERCENT 0.15f
#define EXCESS_PERCENT 0.28f
#define INCOME_LIMIT_1 17850.00
#define INCOME_LIMIT_2 23900.00
#define INCOME_LIMIT_3 29750.00
#define INCOME_LIMIT_4 14875.00

float startmenu_income();
void startmenu_category();
int clear_screen();
float calculate_tax(float limit, float income);

int main()
{
    int ch;
    float income = startmenu_income();
    float active_limit;
    int is_exit = 0;
    int input_category = 0;
    int scanf_res = 0;
    float tax;
    startmenu_category();
    
    while (1)
    {
	scanf_res = scanf("%d", &ch);
	if (scanf_res)
	{
	    switch (ch)
	    {
	        case 1:
		    active_limit = INCOME_LIMIT_1;
		    input_category = 1;
		    break;
		case 2:
		    active_limit = INCOME_LIMIT_2;
		    input_category = 1;
		    break;
		case 3:
		    active_limit = INCOME_LIMIT_3;
		    input_category = 1;
		    break;
		case 4:
		    active_limit = INCOME_LIMIT_4;
		    input_category = 1;
		    break;
		case STOP:
		    is_exit = 1;
		    break;
	        default:
		    clear_screen();
		    startmenu_category();
		    break;
	    }
	}
	else
	{
	    scanf("%*s");//clear the invalid character(s) from stdin
	    clear_screen();
	    startmenu_category();
	}
	if (is_exit)
	{
	    break;
	}
	
	if (input_category)
	{
	    tax = calculate_tax(active_limit, income);
	    clear_screen();
	    printf("Total income: %.0f; Tax amount: %.2f\n", income, tax);
	    startmenu_category();
	}
    }
    return 0;
}

float startmenu_income()
{
    float income = 0.f;
    printf("%s", SEP);
    printf("Please enter taxable income:\n");
    scanf("%f", &income);
    printf("%s", SEP);
    return income;
}

float calculate_tax(float limit, float income)
{
    float tax;
    //0.15 * $17,850 + 0.28 * ($20,000 - $17,850)
    if ((income - limit) > 0)
	tax = SINGLE_PERCENT * limit  + EXCESS_PERCENT * (income - limit);
    else
	tax = SINGLE_PERCENT * income;
    return tax;
}

void startmenu_category()
{
    printf("%s", SEP);
    printf("Please enter taxable category:\n");
    printf("1) Single %0.f%% of first $%0.f plus %0.f%% of excess\n", 
	SINGLE_PERCENT*100, INCOME_LIMIT_1, EXCESS_PERCENT*100);
    printf("2) Head of Household %0.f%% of first $%0.f plus %0.f%% of excess\n", 
	SINGLE_PERCENT*100, INCOME_LIMIT_2, EXCESS_PERCENT*100);
    printf("3) Married, Joint %0.f%% of first $%0.f plus %0.f%% of excess\n", 
	SINGLE_PERCENT*100, INCOME_LIMIT_3, EXCESS_PERCENT*100);
    printf("4) Married, Separate %0.f%% of first $%0.f plus %0.f%% of excess\n",
	SINGLE_PERCENT*100, INCOME_LIMIT_4, EXCESS_PERCENT*100);
    printf("5) quit.\n");
    printf("%s", SEP);
}

int clear_screen()
{
    return system("clear");
}