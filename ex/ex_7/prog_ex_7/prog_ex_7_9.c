/*Write a program that accepts a positive integer as input and then
displays all the prime numbers smaller than or equal to that number.*/
#include <stdio.h>
int main() {
    
    int num, i, j;
    int flag;
    
    while ((scanf("%d", &num)) == 1)
    {
	if (num <= 0) 
	{
	    printf("Enter positive number please.\n");
	}
	else
	{
	    for (; num > 0; num--)
	    {
		flag = 0;
		j = num/2;
		for (i = 2; i <= j; i++)
		{
		    //printf("i=%d;j=%d\n", i, j);
		    if (num % i == 0)
		    {
			flag=1;
			break;
		    }
		}
		if (flag == 0 && num != 1)
		    printf("%d ", num);
	    }
	    printf("\n");
	break;
	}
    }
    return 0;
}