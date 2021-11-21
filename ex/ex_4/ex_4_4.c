#include <stdio.h>
int main(void)
{
    
    char fname[40];
    float weight;
    
    printf("Enter your name and weight in centimeters: [name, weight]\n");
    scanf("%s , %f", fname, &weight);
    printf("%s, your are %.3f meters tall\n", fname, weight/100.00);
    
    return 0;
}