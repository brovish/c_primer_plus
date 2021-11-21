#include <stdio.h>
int main(void)
{
    int true_val, falce_val;
    
    true_val = (10 > 2);
    falce_val = (10 == 2);
    
    printf("true = %d; falce = %d\n", true_val, falce_val);
    
    return 0;
}