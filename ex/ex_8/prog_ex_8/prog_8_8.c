#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
char get_char(void);
float get_num(char operation);
void menu(void);
int clear(void);
int main(void)
{
    
    char resp;
    float num1 = 0.f;
    float num2 = 0.f;
    
    clear();
    menu();
    
    while ((resp = get_char()) != 'q')
    {

	switch (resp)
        {
	    case 'a':
		num1 = get_num(resp);
	        num2 = get_num(resp);
		if (num1 > 0 && num2 < 0)
		    printf("%.2f + % .2f = %.2f\n", num1, num2, num1+num2);
		else if (num2 > 0 && num1 < 0)
		    printf("%.2f + % .2f = %.2f\n", num1, num2, num2+num1);
		else if (num1 < 0 && num2 < 0)
		    printf("% .2f + % .2f = %.2f\n", num1, num2, num1+num2);
		else
		    printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
		break;
	    case 'b':
		num1 = get_num(resp);
		num2 = get_num(resp);
		if (num1 > 0 && num2 < 0)
		    printf("%.2f + % .2f = %.2f\n", num1, num2, num2+num1);
		else if (num2 > 0 && num1 < 0)
		    printf("%.2f + % .2f = %.2f\n", num1, num2, num2+num1);
		else if (num1 < 0 && num2 < 0)
		    printf("% .2f + % .2f = %.2f\n", num1, num2, num1+num2);
		else
		    printf("%.2f - %.2f = %.2f\n", num1, num2, num1-num2);
		break;
	    case 'c':
		num1 = get_num(resp);
		num2 = get_num(resp);
		printf("% .2f * % .2f = %.2f\n", num1, num2, num1*num2);
		break;
	    case 'd':
		//printf("%c\n", resp);
		num1 = get_num(resp);
		num2 = get_num(resp);
	        printf("% .2f / % .2f = %.2f\n", num1, num2, num1/num2);
		break;
	}
    
	menu();
    }
    
    printf("Done!\n");
    
    return 0;
}

char get_char()
{
    char ch = '\0';
    int i;
    char chbuf[100];
    scanf("%s", chbuf);
    
    for (i = 0; i < 100; i++)
    {
	if (!isblank(chbuf[i]))
	{
	    ch = chbuf[i];
	    break;
	}
    }
    
    return ch;
}

float get_num(char operation)
{
    float num;
    char ch;
    printf("Enter number: ");
    while ((scanf("%f", &num)) != 1)
    {
	
	while((ch = getchar()) != '\n')
	    putchar(ch);
	printf(" is not a number.\n");
	printf("Please provide a valid number (23, 23.23, -123 and etc.)\n");
	printf("Enter number: ");
    }
    
    printf("%f\n", num);
    if (num == 0 && operation == 'd')
    {
        printf("enter other number than %0.g:\n", num);
        return get_num(operation);
    }
    
    return num;
}

void menu()
{
    //clear();
    printf("Choise operation with two numbers:\n");
    printf("a) Add			b) substract\n");
    printf("c) Multiply		d) division\n");
    printf("q) Quit\n");
}

int clear()
{
    return system("clear");
}