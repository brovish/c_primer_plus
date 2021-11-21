#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define ON '1'
#define OFF '0'
#define SIZEBTS CHAR_BIT * sizeof(int)

bool is_valid(char * st);
int bstrtoint(char * st);
char * itobs(int num, char * st);
void print_res(int num, int res, char * st);
void print_res_ex(int num, int num2, int rs, char * st);

int main(int argc, char * argv[])
{
	
	if (argc < 3)
	{
		fprintf(stderr, "Usage %s [binary string] "
		"[binary string]\n", *argv);
		exit(EXIT_FAILURE);
	} 
	
	if (is_valid(argv[1]) && is_valid(argv[2]))
	{
		int res = 0;
		int i = 0;
		int j = 0;
	
	
		i = bstrtoint(argv[1]);
		j = bstrtoint(argv[2]);
	
		res = ~i;
		print_res(i, res, "~");
	
		res = ~j;
		print_res(j, res, "~");
	
		res = i & j;
		print_res_ex(i, j, res, "&");
	
		res = i | j;
		print_res_ex(i, j, res, "|");
	
		res = i ^ j;
		print_res_ex(i, j, res, "^");
	
	}
	else
	{
		fprintf(stderr, "binary string "
		"[%s] or [%s] not valid\n", argv[1], argv[2]);
		exit(EXIT_FAILURE);
	
	}
	
	
	
	return 0;
}

void print_res(int num, int res, char * st)
{
	static char btrs[SIZEBTS];
	printf("%s%d=%d [%s]\n", st, num, res, itobs(res, btrs));	
}

void print_res_ex(int num, int num2, int res, char * st)
{
	static char btrs[SIZEBTS];
	printf("%d%s%d=%d [%s]\n", num, st, num2, res, itobs(res, btrs));	
}


char * itobs(int num, char * st)
{
	int i = 0;
	
	for (i = SIZEBTS - 1; i >= 0; i--, num >>= 1)
	{ 
		st[i] = (01 & num) + '0';
	}
	
	st[SIZEBTS] = 0;
	
	return st;
}

int bstrtoint(char * st)
{
	int num = 0;
	
	while (*st)
	{
		num = num * 2 + (*st++ - '0');
	}
	
	return num;
}

bool is_valid(char * st)
{
	bool is_valid = true;
	while (*st)
	{
		//printf("%c\n", *st);
		if (*st != ON && *st != OFF)
		{
			is_valid = false;
			break;
		}
		st++;	
	}
	
	return is_valid;
}

