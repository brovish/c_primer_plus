#include <stdio.h>
int main(void)
{
    int ch;
    /*
    while (scanf("%d", &ch) == 1)
	printf("%d\n", ch);
    */
    
    while ((ch = getchar()) != '\n')
    {
	//ch+='\n';
	//putchar(ch);
	putchar(ch++);
	printf("\n");
	putchar(++ch);
	printf("\n");
    }
    return 0;
}