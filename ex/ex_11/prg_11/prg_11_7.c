#include <stdio.h>
#include <string.h>
#define EXIT "CTRL+C"
#define LIM 1000
char * s_gets(char *str, int n);
char * mystrncpy(char *str, const char *input, int num);
int main(void)
{
	char target[LIM];
	char input[LIM];
	int count;
	while (1)
	{
		printf("Enter target string (%s to exit):\n", EXIT);
		
		s_gets(target, LIM);
		printf("target string:[%s]\n", target);
		
		printf("Enter input string:\n");
		s_gets(input, LIM);
		printf("input string:[%s]\n", input);
		
		printf("Enter count of chars to copy:\n");
		scanf("%d", &count);
		while (getchar() == '\0')
			continue;
		mystrncpy(target, input, count);
		
		printf("target string after:[%s]\ncount inserted chars:[%d]"
		"\ntarget len:[%ld]\n"
			, target, count, strlen(target));
		
	}
		
	return 0;
}

char * mystrncpy(char *str, const char *input, int num)
{
	int i;
	int l_target = strlen(str);
	char *end_target;
	
	end_target = str + l_target;
	
	//printf("end_target=[%s];l_input=[%d];l_target=[%d]\n", 
	//	end_target, l_input, l_target);
	
	for (i = 0; i < num; i++)
	{
		*end_target = input[i];
		//printf("input[%d]=[%c]\n", i, input[i]);
		end_target++;
	}
	
	*end_target = 0;
	
	//printf("end_target=[%s];l_input=[%d];l_target=[%d]\n", 
	//	end_target, l_input, l_target);
	
	
	return end_target;
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