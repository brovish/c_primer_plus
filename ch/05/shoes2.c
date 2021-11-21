#include <stdio.h>
#define ADJUST 7.31
int main(void)
{
    const double SCALE = 0.333;
    double shoe, foot;
    
    printf("Shoe size (men's)   foot lenght           centimeters\n");
    shoe = 3.0;
    while (shoe < 18.5)
    {
	foot = SCALE * shoe + ADJUST;
	printf("%10.1f %15.2f inches %15.2f cm\n", shoe, foot, foot * 2.54);
	//shoe = shoe + 1.0;
	shoe = shoe + 1.0;
    }
    
    printf("If the shoe fits, wear it.\n");
    
    return 0;
}