#include <stdio.h>
int main(void)
{
double g;
double tax, rate;
g = .0e21;
tax = rate*g;
printf("%f=%f*%e\n", tax,rate, g);
return 0;
}
