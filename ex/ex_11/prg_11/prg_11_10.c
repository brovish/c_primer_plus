#include <stdio.h>
#include <string.h>
#define EXIT "CTRL+C"
#define LIM 1000
char * s_gets(char *str, int n);
char * s_remove_space(char str[]);
int main(void)
{
	char target[LIM];
	while (1)
	{
		printf("Enter target string (%s to exit):\n", EXIT);
		
		s_gets(target, LIM);
		printf("target string:[%s]\n", target);
		s_remove_space(target);
		printf("target without spaces string:[%s]\n", target);
	}
		
	return 0;
}

char * s_remove_space(char str[])
{
	char temp[LIM];
	memset(&temp[0], 0, sizeof(temp));
	
	//printf("temp=%s;str=%s;\n", temp, str);
	int z = 0;
	int i = 0;
	int len;
	len = strlen(str) - 1;
	
	for (int z = 0; i < len; z++)
	{
		if (str[z] != ' ')
		{
			temp[i] = str[z];
			i++;
		}
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