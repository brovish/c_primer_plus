#include <stdio.h>
int main(void)
{

long long l_age;

printf("Please enter your age (int): \n");
scanf("%lld",&l_age);
printf("Your age in seconds: %lld\n", l_age*31556952);
return 0;
}
