#include <stdio.h>
#define LITRES_IN_GALLON 3.785
#define KM_IN_MILE 1.609
int main(void)
{
    float miles, gallons;
    float mpg, lpkm;
    
    printf("Enter number of miles and number of gallons: [miles gallons]\n");
    scanf("%f %f", &miles, &gallons);
    
    mpg = miles/gallons;
    /*The calculation is: litres / distance * 100 = l/100km.
    For example: 57 litres / 635 km * 100 = 8.98l/100km.*/
    lpkm = LITRES_IN_GALLON * gallons / (miles * KM_IN_MILE) * 100;
    
    printf("Miles per gallon: %.1f\n", mpg);
    printf("%.2fl/100km\n", lpkm);
    
    return 0;
}