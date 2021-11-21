#include <stdio.h>
#include <limits.h>
#define IBITS 4

char * itobs(int n, char * st);
void show_bstr(char * st);
int invert_end(int num, int bits);
int invert_end_ex(int num, int bits);

int main (void)
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;
	
	puts("Enter inegers and see then in binary.");
	puts("Non numeric input terminates program.");
	
	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d is  ", number);
		show_bstr(bin_str);
		putchar('\n');
		
		number = invert_end(number, IBITS);
		printf("Inverting the last %d bits gives\n", 
			IBITS);
		show_bstr(itobs(number, bin_str));
		putchar('\n');
		
		number = invert_end_ex(number, IBITS);
		printf("Reinverting the last %d bits gives\n", 
			IBITS);
		show_bstr(itobs(number, bin_str));	
		putchar('\n');
		
		
	}
		
	puts("Bye!");	
		
	return 0;
}

int invert_end_ex(int num, int bits)
{
	int mask = 0;
	int bitval = 1;
	while (bits-- > 0)
	{
		mask |= bitval;
		bitval *= 2;
	}
	
	return num ^ mask;
}



int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;
	while (bits-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}
	
	return num ^ mask;
}

char * itobs(int n, char * st)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	
	for (i = size - 1; i >= 0; i--, n >>= 1)
	{
		st[i] = (01 & n) + '0';		
	}
	
	st[size] = 0;
		
	return st;	
}

void show_bstr(char * st)
{
	int i = 0;
	int j = 0;
	putchar('\t');
	putchar('\t');
	while (st[i])
	{
		putchar(st[i++]);
		if (++j == 4)
		{
			putchar(' ');
			j = 0;
		}
	}
}