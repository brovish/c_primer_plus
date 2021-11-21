#include <stdio.h>
int main(void)
{
float cups;
printf("Please enter volume in cups: \n");
scanf("%f",&cups);

float pint;
float ounces = cups*8;
float tablespoons = ounces*2;
float teaspoons = tablespoons*3;

printf("In %.0f cups: \n", cups);
printf("%.2f pints; %.0f ounces; %.0f tablespoon; %.0f teaspoons\n",
		cups/2, ounces, tablespoons, teaspoons);
return 0;
}
