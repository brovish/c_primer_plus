#include <stdio.h>
#include <string.h>
#define EXIT "CTRL+C"
#define LIM 1000
char * s_gets(char *str, int n);
char * string_in(char *str, const char *str2);
int main(void)
{
	char target[LIM];
	char input[LIM];
	while (1)
	{
		printf("Enter target string (%s to exit):\n", EXIT);
		
		s_gets(target, LIM);
		printf("target string:[%s]\n", target);
		
		printf("Enter input string:\n");
		s_gets(input, LIM);
		printf("input string:[%s]\n", input);
		
		char *ptr;
		ptr = string_in(target, input);
		if (*ptr)
		{
			printf("target string [%s] containt input [%s] "
				"string: [%s]\n", target, input, ptr);
		}		
		else
		{
			printf("target string [%s] not containt input [%s] "
				"string\n", target, input);
		}
		
		
	}
		
	return 0;
}

char * string_in(char *str, const char *str2)
{
	
	int i = 0;
	int z = 0;
	int is_match = 0;
	int l_str2 = strlen(str2);
	
	/*
	printf("debug: is_match=[%d];l_str2=[%d]\n", 
			is_match, l_str2);
	printf("debug2: str=[%s];str2=[%s]\n", 
			str, str2);
	*/	
	while(*str)
	{
		if (*str == str2[z])
		{
			is_match = 1;
			l_str2 -= 1;
			z++;
				
		}
		else
		{
			is_match = 0;
			l_str2 = strlen(str2);
			z=0;
		}
		
		/*
		printf("debug: is_match=[%d];l_str2=[%d];z=[%d];i=[%d]\n", 
			is_match, l_str2, z, i);
		*/		
		if(!l_str2 && is_match)
		{
			//printf("debug3: str=[%s];str2=[%s]\n", 
			//str, str2);
			str -= strlen(str2) - 1;	
			//printf("debug4: str=[%s];str2=[%s]\n", 
			//str, str2);
			return str;
		
		}
		++str;
		i++;
	}
	
	/*
	printf("debug3: str=[%s];str2=[%s];z=[%d];i=[%d]\n", 
			str, str2, z, i);
	*str = 0;
	*/
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