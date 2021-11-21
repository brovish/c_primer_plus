#include <stdio.h>
#include <string.h>

int main(void)
{
	double data1[100];
	double data2[300];
	
	int i = 300;
	for(int j = 0; i > 0; i--, j++)
		data2[j] = i + 10;
	
	for(i = 0; i < 100; i++)
		data1[i] = i + 1;
	
	puts("data1:");
	
	for(i = 0; i < 100; i++)
	{	
		printf("%2.2f ", data1[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
	
	puts("data2:");
	
	for(i = 0; i < 300; i++)
	{	
		printf("%2.2f ", data2[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
	memcpy(data1, data2, 100 * sizeof(double));
	puts("data1:");
	
	for(i = 0; i < 100; i++)
	{	
		printf("%2.2f ", data1[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
	
	memcpy(data1, data2+200, 100 * sizeof(double));
	puts("data1:");
	
	for(i = 0; i < 100; i++)
	{	
		printf("%2.2f ", data1[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
	
	
	
	return 0;
}