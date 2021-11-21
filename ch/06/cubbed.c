#include <stdio.h>
int main(void)
{
    int num;
    const int NUMBER = 100;
    printf("     n      cubbed\n");
    for (num = 0; num <= NUMBER; num++)
	printf("    %d    %d\n", num, num*num*num);
    return 0;
}