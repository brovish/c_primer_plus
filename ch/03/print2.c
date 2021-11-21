#include <stdio.h>
void binprintf(int v);
int main(void)
{
    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    short big2 = 65537;
    long long verybig = 12345678908642;
    
    binprintf(big);	
    binprintf(big2);	
    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and not %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig = %lld and not %ld\n", verybig, verybig);
    
    return 0;
}

void binprintf(int v)
{
    unsigned int mask=1<<((sizeof(int)<<3)-1);
    while(mask) {
        printf("%d", (v&mask ? 1 : 0));
        mask >>= 1;
    }
    printf("\n");
}
