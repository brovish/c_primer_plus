#include <stdio.h>
#include <string.h>
int main(void)
{
    char fname[40];
    int fnamel;
    
    printf("Please enter your firstname:\n");
    scanf("%s", fname);
    
    fnamel = strlen(fname) + 3;
    
    printf("\"%s\"\n", fname);
    printf("\"%20s\"\n", fname);
    
    printf("\"%-20s\"\n", fname);
    printf("%*s\n", fnamel, fname);
    
    return 0;
}