#include <stdio.h>

int moduli(int f, int s);
int main(void)
{
    int first, second;
    printf("This program computates moduli.\n");
    printf("Enter an integer to serve as the second operand:    ");
    printf("\b\b\b");
    scanf("%d", &second);
    //printf("\n");
    printf("Now enter the first operand:    ");
    printf("\b\b\b");
    scanf("%d", &first);
    
    while ( first > 0 ) 
    {
    
    //printf("\n");
    printf("%d %% %d is %d\n", first, second, moduli(first, second));
    printf("Enter the next number for the first operand (<= 0 to exit):    ");
    
    printf("\b\b\b");
    scanf("%d", &first);
    
    }
    
    return 0;
}

int moduli(int f, int s)
{
    return f%s;
}