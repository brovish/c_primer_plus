#include <stdio.h>
int main(void)
{
float weight; /*user weight*/
float value; /*platinum equivalent*/
printf("Are you worth your weight in platinum?\n");
printf("Let's check it out\n");
printf("Please enter your weight in pounds\n");
/*get input from user*/
scanf("%f", &weight);
getchar();
getchar();
/*Assume that platium is $1233.12 per ounce
 *14.5833 converts pound avd. to ounce troy
 */
value = 1233.12 * weight * 14.5833;
printf("Your weight in platinum is worth $%.2f\n",value);
printf("Your are easily worth that! If platinum prices drop,\n");
printf("eat more and maintain your value.\n");
return 0;
}
