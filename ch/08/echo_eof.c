#include <stdio.h>
int main()
{
    int ch;
    while ((ch = getchar()) != EOF)
	putchar(ch);
    putchar('\n');
    return 0;
}