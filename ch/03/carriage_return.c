#include <stdio.h>
int main(void)
{

char cr1=13;
char cr2=0x0D;
char cr3='\015';

printf("%d\n", cr1);
printf("----");
printf("----");
printf("----");
printf("%d\n", cr2);
printf("%d\n", cr3);
printf("%c\n", cr3);

return 0;
}
