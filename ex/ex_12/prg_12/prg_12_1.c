#include <stdio.h>
int critic(int units);
int main(void)
{
	int units = 0;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
	{
		units = critic(units);
	}
	printf("You must looked it up!\n");
	return 0;
}

int critic(int units)
{
	printf("No luck, not %d my friend. Try again.\n", 
		units);
	scanf("%d", &units);
	return units;
}