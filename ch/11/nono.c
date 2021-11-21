#include <stdio.h>
int main(void)
{
	char side_a[] = "Side A";
	char dont[] = {'W','O','W','!'};
	char side_b[] = "Side B";
	
	puts(dont);
	
	for (int i = 0; dont[i] != '\0'; i++)
	{
		puts(dont[i]);
	}
	return 0;
}