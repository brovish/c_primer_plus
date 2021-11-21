#include <stdio.h>
#include <string.h>
#define EXIT "CTRL+C"
#define LIM 1000
char * s_gets(char *str, int n);
char * s_reverse(char str[]);
int main(void)
{
	char target[LIM];
	while (1)
	{
		//printf("Enter target string (%s to exit):\n", EXIT);
		
		s_gets(target, LIM);
		//printf("target string:[%s]\n", target);
		s_reverse(target);
		//printf("reversed target string:[%s]\n", target);
		printf("%s", target);
	}
		
	return 0;
}

char * s_reverse(char str[])
{
	char temp[LIM];
	int i = strlen(str) - 1;
	int z = 0;
	for (;i >=0; i--,z++)
	{
		temp[z] = str[i];
	}		
		
	z = 0;
	while (*str)
	{
		*str = temp[z];
		str++;
		z++;
	}
	//printf("temp=%s;str=%s;\n", temp, str);
	return str;	
}

char * s_gets(char *str, int n)
{
	
	fgets(str, n, stdin);
	char *find;
	find = strchr(str, '\n');
	if (*find)
		*find = 0;
	return str;	
}