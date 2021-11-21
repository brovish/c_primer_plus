#include <stdio.h>
int main(void)
{
    int n;
    
    printf("Please enter 3 integers:\n");
    scanf("%*d %*d %d",&n);
    printf("Last integer: %d\n", n);
    
    return 0;
}