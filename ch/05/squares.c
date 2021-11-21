#include <stdio.h>
int main(void)
{

    int i = 1;
    while (i < 21)
    {
	printf("i=%d i*i=%d\n", i, i*i);
	i++;
    }
    return 0;
}