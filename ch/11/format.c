#include <stdio.h>
#define MAXSIZE 20

char * s_gets(char *, int);

int main(void)
{
	char first[MAXSIZE];
	char last[MAXSIZE];
	char formal[2 * MAXSIZE + 10];
	double prize;
	
	puts("Enter your First Name:");
	s_gets(first, MAXSIZE);
	
	puts("Enter your Last Name:");
	s_gets(last, MAXSIZE);
	
	puts("Enter your prize money:");
	scanf("%lf", &prize);
	
	sprintf(formal, "%s, %-19s: $%6.2f\n", first, last, prize);
	
	puts(formal);
	
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