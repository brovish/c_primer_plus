#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
	int dice, roll;
	int sides = 0;
	int status;
	int sets = 0;
	
	srand((unsigned int) time(0));
	
	printf("Enter the number of sets; enter q to stop: ");
	
	while (scanf("%d", &sets) == 1 && sets > 0)
	{
		printf("How many sides and how many dice?\n");
		status = scanf("%d %d", &sides, &dice);
	
		if (status == EOF || status != 2)
		{
			printf("You should have entered two integers!\n");
			printf("Let's begin again:\n");
			while (getchar() != '\n')
				continue;
			printf("How many sides and how many dice?\n");
				continue;
		}
		
		printf("Here are %d sets of %d %d-sided throws.", 
				sets, dice, sides);
		for (int i = 0; i < sets; i++)
		{
			roll = roll_n_dice(dice, sides);
			if (i % 15 == 0)
				puts("");
			printf(" %d", roll);
		
		}
		printf("\nHow many sets? enter q to stop: ");
	}
	
	printf("The rollem() funtion called %d times.\n", 
		roll_count);
		
	printf("GOOD FORTUNE TO YOU.\n");	
	
	return 0;
}
