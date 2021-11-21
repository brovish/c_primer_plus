/*nogood.c -- a program with errors*/
#include <stdio.h>
int main(void)
{
    /*simple int variables*/
    int n;
    int n2;
    int n3;
    
    n = 5;
    n2 = n * n;
    n3 = n2 * n2;
    printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
    
    return 0;
}
