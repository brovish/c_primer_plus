#include <stdio.h>
int main(void)
{
    int num = 0;
    for (printf("Guess number!\n"); num != 6 ;)
	scanf("%d", &num);
    printf("That's number is correct, done.\n");
    return 0;
}