#include <stdio.h>
int main(void)
{
    int guess = 1;
    char responce;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it wrong.\n");
    printf("Uh... is your number %d?\n", guess);
    while ((responce = getchar()) != 'y')
    {
	if (responce == 'n')
	    printf("Well, then, is it %d?\n", ++guess);
	else 
	    printf("I understand only \"y\" or \"n\" responce.\n");
	while ((responce = getchar()) != '\n')
	    continue;
    }
    printf("I knew I could do it!\n");
    return 0;
}
