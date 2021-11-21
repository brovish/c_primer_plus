#include <stdio.h>
int main(void)
{
    int chars = 0;
    char ch;
    while (scanf("%c", &ch) == 1)
	chars++;
    printf("Chars count: %d\n", chars);
    return 0;
}