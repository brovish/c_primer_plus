#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

const int size = CHAR_BIT * sizeof(int);

int is_bit_on(int, int);

bool is_valid(int);

int main(void)
{
	
	int num, bit;
	printf("Enter two integers: (number and bit position)\n");
	puts("enter non numeric input to exit.");
	
	while (scanf("%d %d", &num, &bit) == 2)
	{
		if (is_valid(bit))
		{
			printf("In integer \"%d\" %d bit is %s\n", num, bit, 
				is_bit_on(num, bit) ? "on" : "off");
			printf("Enter next two integers: (number and bit position)\n");
			puts("enter non numeric input to exit.");
		}
				
		else 
		{
			printf("Invalid input: bit must be from 1 to %d.\n", size);
			printf("Enter next two integers: (number and bit position)\n");
			puts("enter non numeric input to exit.");
		}
		
		
	}
	
	return 0;
}

int is_bit_on(int num, int bit)
{
	int j = 1;	
	for (int i = size - 1; i >= 0; i--, j++, num >>= 1)
	{
		//printf("%d j=%d bit=%d\n", (01 & num), j, bit);
		if (j == bit && (01 & num) == 1)
			return 1;
		if (j == bit && (01 & num) == 0)
			return 0;
	}	
	
	return 0;
}

bool is_valid(int bit)
{
	if (bit > size || bit < 0)
		return false;
	else return true;
}