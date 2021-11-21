#include <stdio.h>
int main(void)
{
    
    int x, y;
    x = (2+3)*6;
    
    printf("%d=(2+3)*6\n", x);
    
    x = (12+6)/2*3;
    printf("%d=(12+6)/2*3)\n", x);
    
    y = x = (2+3)/4;
    
    printf("%d=%d=(2+3)/4\n", y, x);
    
    y = 3 + 2*(x=7/2);
    printf("%d=3+2*(x=7/2)\n", y);
    
    x = (int) 3.8 + 3.3;
    printf("%d=(int) 3.8+3.3\n", x);
    
    x = (2+3) * 10.5;
    printf("%d=(2+3)*10.5\n", x);
    
    x = 3/5 * 22.0;
    printf("%d=3/5*22.0\n", x);
    
    x = 22.0 * 3 / 5;
    printf("%d=22.0*3/5\n", x);
    
    printf("30.0/4.0*5.0=%f\n",(float) 30.0/4.0*5.0);
    printf("30.0/(4.0*5.0)=%f\n", (float) 30.0/(4.0*5.0));
    printf("30/4*5=%f\n",(float) 30/4*5);
    printf("30*5/4=%f\n",(float) 30*5/4);
    printf("30/4.0*5=%f\n",(float) 30/4.0*5);
    printf("30/4*5.0=%f\n",(float) 30/4*5.0);

    return 0;
}