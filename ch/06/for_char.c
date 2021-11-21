#include <stdio.h>
int main(void)
{
    char ch;
    for(ch = 'a'; ch <= 'z'; ch++)
	printf("The ASCI value for %c is %d\n", ch, ch);
    printf("\n");
    return 0;
}