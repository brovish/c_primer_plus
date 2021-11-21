#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ch;
    FILE * fp;
    
    char fname[50];
    
    printf("Enter file name and press ENTER:\n");
    scanf("%s", fname);
    
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
	printf("Error reading file %s\n", fname);
	exit(1);
    }
    
    while ((ch = getc(fp)) != EOF)
	putchar(ch);
    fclose(fp);
    
    return 0;
}