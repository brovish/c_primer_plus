#include <stdio.h>
int main(void)
{
    int x;    
    x = x + 10;
    x = x + 1;
    int a, b, c;
    a = b = 2;
    c = 0;
    
    printf("a=%d;b=%d;c=%d\n", a, b, c);
    c = a + b + a + b;
    printf("%d\n", c);
    
    //Assign a plus twice b to c
    c = 0;
    c = a + 2*b;
    printf("a=%d;b=%d;c=%d\n", a, b, c);
    printf("%d\n", c);
    
    int m, n, k;
    m = 0; n = 10; k = 3;
    m = n%k;
    printf("m=%d;n=%d;k=%d;n%%k=%d\n", m, n, k, n%k);
    
    int q, p;
    a = 1; q = 22; b = 4; p = 1;
    p = q / (b - a);
    printf("q=%d;b=%d;a=%d;\n", q, b, a);
    printf("p=%d\n", p);
    
    int d = 2;
    float z;
    z = 0; a = 2, b = 4, c = 3;
    z = (float) (a+b)/c*d;
    printf("%f\n", z);
    
    return 0;
}