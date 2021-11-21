#include <stdio.h>
#include <limits.h>

char * iotobs(int, char *);
void show_bstr(const char *);

int main(void)
{

	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;
	
	puts("Enter integers and see them in binary.");
	puts("Non-numberic input terminates program.");
	while (scanf("%d", &number) == 1)
	{
		iotobs(number, bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
	}
	
	puts("Bye.");
	
	return 0;
}


char * iotobs(int n, char * st)
{
	int i;
	const static int size = CHAR_BIT *  sizeof(int);
	for (i = size - 1; i >= 0; i--, n >>= 1)	
	{
		st[i] = (01 & n) + '0';
	}
	
	st[size] = 0;
	
	return st;
}
void show_bstr(const char * st)
{
	int i = 0;
	int j = 0;
	while (st[i])
	{
		putchar(st[i]);
		//printf("i=%d %d\n", i, ++i & 4);
		if (++j==4)
		{
			putchar(' ');
			j = 0;	
		}
		i++;
	}
}
