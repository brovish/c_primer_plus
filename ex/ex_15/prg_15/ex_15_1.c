#include <stdio.h>
#include <math.h>
#include <string.h>
#define ON '1'
#define OFF '0'

int cnv_char_to_int(char * st, int len);


int main(void)
{
	char * pbin = "00011001";
	int len = 0;
	len = strlen(pbin);
	printf("%s=%d\n", pbin, cnv_char_to_int(pbin, len));
}

int cnv_char_to_int(char * st, int len)
{
	//int n = 0;
	int sum = 0;
	int j = 0;
	//const static int size = sizeof(int);
	
	for (int i = len - 1; i >= 0; i--, j++)
	{
		//printf("st[%i]=%c\t%f\n", i, st[i], pow(2, j));
		if (st[i]==ON) 
			sum += (int) pow(2, j);
	}
	
	//printf("%d\n", size);
	
	return sum;
}