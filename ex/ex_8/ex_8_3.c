#include <stdio.h>
int main(void)
{
    char ch;
    int char_count = 0;
    while (scanf("%c", &ch)==1)
	char_count++;
    printf("Char count: %d\n", char_count);
    return 0;
}