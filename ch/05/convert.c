#include <stdio.h>
int main(void)
{
    
    char ch;
    int i;
    float f;
    
    f = i = ch = 'C';
    printf("ch=%c, i=%d, f=%2.2f\n", ch, i, f);
    
    ch = ch + 1;
    i = f + 2 * ch;
    f = 2.0 * ch + i;
    printf("ch=%c, i=%d, f=%2.2f\n", ch, i, f);
    
    ch = 1107;
    printf("Now ch = %c\n", ch);
    
    ch = 80.89;
    printf("Now ch = %c\n");
    
    
    return 0;
}