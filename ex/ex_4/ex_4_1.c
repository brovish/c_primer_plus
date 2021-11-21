#include <stdio.h>
int main(void)
{
    char fname[40];
    char lname[40];
    
    printf("Please enter your name, lastname [name,lastname]\n");
    scanf("%s , %s", fname, lname);
    printf("%s,%s\n", lname, fname);
    
    return 0;
}