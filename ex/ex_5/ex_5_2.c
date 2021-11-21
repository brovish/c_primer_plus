#include <stdio.h>
#include <stdlib.h>
#define MSG_SEP "*****************************\n"
int climit = 10;
int main(void)
{
    
    int i;
    system("clear");
    printf("Please enter int number [number]\n");
    scanf("%d", &i);
    climit = climit + i;
    printf("%s", MSG_SEP);
    while (i <= climit)
    {
	
	printf("%2d;\n", i);
	i++;
    }
    
    printf("%s", MSG_SEP);
    printf("\n");
    
    return 0;
}