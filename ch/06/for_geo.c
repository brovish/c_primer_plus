#include <stdio.h>
int main(void)
{
    double debt;
    for (debt = 100.0; debt < 200.0; debt = debt*1.1)
	printf("Your debt now is %.2lf$\n", debt);
    return 0;
}