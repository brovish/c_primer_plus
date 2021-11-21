#include <stdio.h>
#define KELVIN_TO_CELSIUS 273.16
#define FAHR_TO_CELIUS_1 5.0/9.0
#define FAHR_TO_CELIUS_2 32.0
void Temperatures(double f);
int main(void)
{
    double f;
    //int res;
    printf("Convert fahrenheit to kelvins and celsius\n");
    printf("or enter non numeric value to exit\n");
    printf("Please enter fahrenheit temperature:    ");
    printf("\b\b\b");
    
    //scanf("%lf", &f);
    
    while ((scanf("%lf", &f)) > 0)
    {
	Temperatures(f);
	
	printf("Please enter fahrenheit temperature:      (enter non numeric value to exit)");
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	printf("\b\b\b\b\b\b\b\b\b\b\b\b");
    }

    return 0;
}

void Temperatures(double f)
{
    double c, k;
    c = FAHR_TO_CELIUS_1 * (f - FAHR_TO_CELIUS_2);
    k = c + KELVIN_TO_CELSIUS;
    
    printf("%.2lf fahrenheit = %.2lf celsius = %.2lf kelvins\n", 
	f, c, k);
}