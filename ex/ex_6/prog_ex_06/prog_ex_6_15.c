#include <stdio.h>
#include <string.h>
#define SIZE 255
#define nl "\n"
int main(void)
{
    char arr[SIZE];
    int i;
    
    scanf("%s", arr);
    
    for (i = strlen(arr);i>=0;i--)
    {
	printf("%c", arr[i]);
    }
    printf(nl);
    
    return 0;
}