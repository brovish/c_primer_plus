#include <stdio.h>
int main(void)
{
int ch;
printf("Please enter char code (int): \n");
scanf("%d", &ch);
//char c = &ch;
printf("Code: %d; char:%c\n", ch, ch);
printf("\n");
return 0;
}
