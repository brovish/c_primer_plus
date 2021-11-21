#include <stdio.h>
int main(void)
{
    int weight, height;
    scanf("%d %d", &weight, &height); /* 5 */

    if (weight < 100 && height >= 72) /* 6 */
    {
        printf("You are very tall for your weight.\n");
    } 
    else if (weight >= 300 && height <= 48) /* 12 */
    {
	printf(" You are quite short for your weight.\n");
    }
    else if (weight < 300 && height < 72 && height > 64)
    {
	printf("You are tall for your weight.\n"); /* 10 */
    }
    else /* 15 */
	printf("Your weight is ideal.\n"); /* 16 */

    return 0;
}