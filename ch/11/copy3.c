#include <stdio.h>
#include <string.h>
#define SIZE 40
#define TARGETSIZE 7
#define LIM 5

char * s_gets(char *, int);

int main(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	
	printf("Enter %d words beginning with q:\n", LIM);
	
	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != 'q')
			printf("%s doesn't begin with q\n", temp);
		else
		{
			strncpy(qwords[i], temp, TARGETSIZE - 1);
			qwords[i][TARGETSIZE - 1] = '\0';
			i++;
		}
	}
	puts("Here are the words:");
	for (i = 0; i < LIM; i++)
		printf("%s\n", qwords[i]);
	return 0;
}

char * s_gets(char * str, int size)
{

	char * ret_val;
	
	int i = 0;
	ret_val = fgets(str, size, stdin);
	
	if (ret_val)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	
	return ret_val;
}