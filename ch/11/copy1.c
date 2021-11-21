#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIMIT 5

char * s_gets(char *, int);

int main(void)
{
	char qwords[LIMIT][SIZE];
	char temp[SIZE];
	
	int i = 0;
	
	printf("Enter %d words beginnig with q:\n", LIMIT);
	while (i < LIMIT && s_gets(temp, SIZE))
	{
		if (temp[0] != 'q')
			printf("%s doesn't begin with q!\n", temp);
		else
		{
			strcpy(qwords[i], temp);
			i++;
		}
	}
	
	puts("Here are the words accepted:");
	for (i =0; i < LIMIT;i++)
		puts(qwords[i]);
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