#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define BIT_ON '1'

char * tobis(int num, char * st);
int cnt_bitson(char * st);
int char_to_int(char * st);

int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		fprintf(stderr, "Usage %s [binary string].\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	char btrs[CHAR_BIT * sizeof(int) + 1];
	
	int num = char_to_int(argv[1]);
	
	printf("%d = %s; bits on: %d\n", num, tobis(num, btrs), cnt_bitson(btrs));
	
	
	return 0;
}

int char_to_int(char * st)
{
	int num = 0;
	
	num = (int)strtol(st, NULL, 10);
	
	return num;
	
}

char * tobis(int num, char * st)
{
	int i;
	static const int size = CHAR_BIT * sizeof(int);
	for (i = size - 1; i >= 0; i--, num >>= 1)
	{
		st[i] = (01 & num) + '0';
	}
	
	st[size] = 0;
	return st;
}

int cnt_bitson(char * st)
{
	int cnt = 0;
	while (*st)
	{
		if (*st == BIT_ON)
			cnt++;
		st++;
	}
	return cnt;	
}