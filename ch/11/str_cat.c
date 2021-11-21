#include <stdio.h>
#include <string.h>
char * s_gets(char *, int);
#define SIZE 80

int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	puts("What is your favorite flower?");
	if (s_gets(flower, SIZE))
	{
		strcat(flower, addon);
		//puts(flower);
		
		puts(flower);
		puts(addon);
		
	}
	else
	{
		puts("End of file encountered!");
	}
	puts("bye");
	
	return 0;
}

char * s_gets(char * string, int n)
{
	char *ret_val;
	int i = 0;
	
	ret_val = fgets(string, SIZE, stdin);
	if (ret_val)
	{
		while(string[i] != '\n' && string[i] != '\0')
			i++;
		if (string[i] == '\n')
			string[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}