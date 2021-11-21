#include <stdio.h>
int main(void)
{
    
    int a = 1, b = 1;
    int a_post, b_pre;
    
    a_post = a++;
    b_pre = ++b;
    
    printf("a=%d;b=%d;a_post=%d;b_pre=%d\n", a, b, a_post, b_pre);
    
    return 0;
}