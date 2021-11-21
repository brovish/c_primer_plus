#include <stdio.h>
int main(void)
{
    float rootbeer[10], things[10][5], *pf, value = 2.2;
    
    int i = 3;
    
    rootbeer[2] = value;
    
    printf("rootbeer[2]=%f\n", rootbeer[2]);
    
    scanf("%f", &rootbeer);
    
    printf("%f\n", *rootbeer);
    
    //things[4][4] = rootbeer[3];
    
    //printf("%f\n", things[4][4]);
    
    //things[5] = rootbeer;
    
    //pf = value;
    
    pf = rootbeer;
    
    return 0;
}