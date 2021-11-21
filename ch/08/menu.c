#include <stdio.h>
#include <stdlib.h>
char get_choise(void);
char get_first(void);
void count(void);
int get_int(void);
int clear_screen(void);
int main(void)
{
    int choise;
    clear_screen();
    while ((choise = get_choise()) != 'q')
    {
	switch (choise)
	{
	    case 'a': printf("Buy low, sell high.\n");
		break;
	    case 'b': putchar('\a');
		break;
	    case 'c': count();
		break;
	    default: printf("Program error!\n");
		break;
	}
	//clear_screen();
    }
    return 0;
}

void count(void)
{
    int n, i;
    printf("Count how far? Enter a integer:\n");
    n = get_int();
    for (i=1;i<=n;i++)
	printf("%d\n", i);
    /*while (getchar() != '\n')
    {
	continue;
    }*/
}

char get_choise(void)
{
    int ch;
    printf("Enter the letter of your choise:\n");
    printf("a. advice			b. bell\n");
    printf("c. count			q. quit\n");
    
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
	printf("Please enter a, b, c or q.\n");
	ch = get_first();
	/*if (ch == '\n')
	    continue;*/
    }
    return ch;
}

int get_int(void)
{
    int val;
    char ch;
    
    while ((scanf("%d", &val) != 1))
    {
	while ((ch = getchar()) != '\n')
	    putchar(ch);
	printf(" is not an integer.\nPlease enter an");
	printf("valid integer like 25, -23, 1: ");
    }
    
    return val;
}

char get_first(void)
{
    char ch;
    ch = getchar();
    /*while (getchar() != '\n')
    {
	continue;
    }*/
    return ch;
}

int clear_screen(void)
{
    return system("clear");
}
