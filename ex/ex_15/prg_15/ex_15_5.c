#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define SIZEBITS CHAR_BIT * sizeof(unsigned int)

void rotate(unsigned int, int);
void itobst(unsigned int, char *);
int bstrtoint(char *);
int conv_bit(int);

int main(void)
{
	unsigned int num = 0;
	int bit = 0;
	
	printf("Enter integer value and number of bits to shift left.\n");
	printf("non integer value terminates program.\n");
	
	while (scanf("%d %d", &num, &bit) == 2)
	{
		rotate(num, bit);	
		printf("Enter next values.\n");
	}
		
	return 0;
}

int conv_bit(int bit)
{
	if (bit > SIZEBITS)
		bit -= SIZEBITS;
	return bit;
}

int bstrtoint(char * st)
{
	int num = 0;
	while (*st)
		num = num * 2 + (*st++ - '0');
	
	return num;
}

void rotate(unsigned int num, int bit)
{
	//printf("bit=%d ", bit);
	int mbit = conv_bit(bit);
	//printf("bit=%d\n", mbit);
	
	static char bstr[SIZEBITS];
	char tbstr[bit];
	itobst(num, bstr);
	int i = 0;
	for (i = 0; i < mbit; i++)
		tbstr[i] = bstr[i]; 
	
	tbstr[mbit] = 0;
	
	printf("Original number %4d; \t\t\t [%s]\n",
		 num, bstr);
	
	for (i = 0; i < SIZEBITS; i++)
		bstr[i] = bstr[i+mbit];
	
	strcat(bstr, tbstr);
	
	printf("Modified number %4d; shift left %2d bits [%s]\n",
		 bstrtoint(bstr), bit, bstr);
}

void itobst(unsigned int num, char * st)
{
	for (int i = SIZEBITS - 1; i >= 0; i--, num >>= 1)
		st[i] = (01 & num) + '0';		
	st[SIZEBITS] = 0;
}