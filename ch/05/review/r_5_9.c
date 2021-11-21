#include <stdio.h>
int main(void)
{
    int n = 96;
    while (n++ < 103)
	printf("%5c", n);
    printf("\n");
    return 0;
}