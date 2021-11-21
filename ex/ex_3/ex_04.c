#include <stdio.h>
int main(void)
{
printf("Please enter floating point number: \n");
float f_num;
scanf("%f", &f_num);
printf("decimal point notation: %f\n", f_num);
printf("exponental notation: %e\n", f_num);
printf("p notation: %a\n", f_num);
return 0;
}
