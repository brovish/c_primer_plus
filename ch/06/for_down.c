#include <stdio.h>
int main(void)
{
    int num;
    for (num = 5;num > 0; --num)
	printf("%d seconds\n", num);
    printf("We have ignition!\n");
    return 0;
}