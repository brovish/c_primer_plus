#include <stdio.h>
void report_count();
void accumulate(int k);

int count = 0;

int main(void)
{
	int value;
	register int i;
	
	printf("Enter positive ineger number (0 to exit)\n");
	
	while (scanf("%d", &value) == 1 && value > 0)
	{
		++count;
		for (i = value; i >= 0; i--)
		{
			accumulate(i);
		}
		
		printf("Enter positive ineger number (0 to exit)\n");
	}
	
	report_count();
	
	return 0;
}

void report_count()
{
	printf("Loop executed %d times\n", count);
}

