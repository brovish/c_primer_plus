#include <stdio.h>
#include <stdlib.h>
int clear(void);
int main(void)
{
    int guess = 50;
    int h_limit = 101;
    int l_limit = -1;
    char responce;
    clear();
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a \"y\" if my guess is right and with");
    printf("\nan \"n\" if it wrong.\n");
    printf("Respond with \"h\" if guess number is higher than specified ");
    printf("\"l\" when number is lower\n");
    printf("Uh... is your number %d?\n", guess);
    while ((responce = getchar()) != 'y')
    {
	switch (responce)
	{
	    case 'h':
		l_limit = guess;
		guess = (h_limit + l_limit) / 2;
		break;
	    case 'l':
	        h_limit = guess;
		guess = (h_limit + l_limit) / 2;
		break;
	}
	clear();
	
	printf("Uh... is your number %d?\n", guess);
	
	printf("I understand only \"y\" or \"n\" responce.\n");
	while ((responce = getchar()) != '\n')
	    continue;
    }
    
    if (responce == 'y')
        printf("I knew I could do it!\n");
    
    return 0;
}

int clear(void)
{
    return system("clear");
}