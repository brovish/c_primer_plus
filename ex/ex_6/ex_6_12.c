#include <stdio.h>
long square(int x);
int main(void)
{
    int i = 5;
    printf("%ld\n", square(i));
    return 0;
}

long square(int x)
{
    return (long) x * x;
}