#include <stdio.h>
int main(void)
{
    
    float fnum;
    
    printf("Enter float number: \n");
    scanf("%f", &fnum);
    printf("The input is %.1f or %.1e\n", fnum, fnum);
    printf("The input is %+.3f or %.3E\n", fnum, fnum);
    
    return 0;
}