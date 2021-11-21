#include <stdio.h>
void print_ar(int ar[], int n);
int main(void)
{
    int ar[5] = {1,2,4,8,16,35};
    
    int val3 = ar[2];
    
    printf("val3=%d\n", val3);
    
    int ar1[100] = {[99] = -1};
    
    
    printf("ar1[99]=%d\n", ar1[99]);
    
    print_ar(ar1, 100);
    
    int ar2[100] = {[3]=101,[5]=101,[10]=101,[11]=101,[12]=101};
    
    print_ar(ar2, 100);
    
    return 0;
}

void print_ar(int ar[], int n)
{
    int s = 0;
    for (;s<n;s++)
	printf("ar[%d]=%d\n", s, ar[s]);
}