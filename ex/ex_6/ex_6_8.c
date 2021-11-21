#include <stdio.h>
int main(void)
{
    char ch;
//    scanf("%c", &ch);
    
    /*while(ch != 'g')
    {
	printf("%c", ++ch);
        scanf("%c", &ch);
    }
    
    do 
    {
        scanf("%c", &ch);
	printf("%c", ch);
    
    } while (ch != 'g');
    */
    
    for (ch = '$'; ch != 'g'; scanf("%c", &ch))
    {
	printf("%c", ch);
    }
    
    printf("\n");
    
    return 0;
}