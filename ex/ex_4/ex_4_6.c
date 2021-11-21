#include <stdio.h>
#include <string.h>
int main(void)
{
    char fname[40];
    char lname[40];
    int flenght, llenght;
    
    printf("Please enter your first name and last name: [fname lname] \n");
    scanf("%s %s", fname, lname);
    
    flenght = strlen(fname);
    llenght = strlen(lname);
    
    printf("%s %s\n", fname, lname);
    printf("%*d %*d\n", flenght, flenght, llenght, llenght);
    printf("%s %s\n", fname, lname);
    printf("%-*d %-*d\n", flenght, flenght, llenght, llenght);
    
    return 0;
}