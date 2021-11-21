#include <stdio.h>
int units = 0;
void critic(void);
int main(void)
{
	extern int units;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
		critic();
	printf("You must loocked it up!\n");
	return 0;
}

void critic(void)
{
	printf("No luck, not %d my friend. Try again.\n", 
		units);
	scanf("%d", &units);
}