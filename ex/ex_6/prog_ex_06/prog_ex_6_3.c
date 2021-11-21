#include <stdio.h>
#define LOOP_SIZE 6
int main(void)
{

    //char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, j;
    int ch;
    /*
    F
    FE
    FED
    FEDC
    FEDCB
    FEDCBA
    */
    
    for (i = 1; i <= LOOP_SIZE; i++)
    {
	for (j = 1, ch = 70; j <= i; j++)
	{
	    printf("%c", ch--);
	}
	printf("\n");
    }
    
    return 0;
}