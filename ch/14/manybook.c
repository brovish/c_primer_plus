#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTITL 400
#define MAXAUTL 400
#define MAXBKS 100000

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char * st, int n);

int main(void)
{
	struct book library[MAXBKS];
	int idx;
	int cnt = 0;
	
	printf("Please enter the book title: \n");
	printf("Press [enter] at the start of line to stop.\n");
	
	while (cnt < MAXBKS && s_gets(library[cnt].title, MAXTITL) != NULL
		&& library[cnt].title[0] != 0)
	{
		printf("Now enter the author:\n");
		s_gets(library[cnt].author, MAXAUTL);
		printf("Now enter price in $:\n");
		scanf("%f", &library[cnt++].value);
		while (getchar() != '\n')
			continue;
		if (cnt < MAXBKS)
			printf("Now enter next title:\n");
	}
	
	if (cnt > 0)
	{
		system("clear");
		printf("Here is list of your books:\n");
		for (idx = 0; idx < cnt; idx++)
			printf("%d) %s by %s: $%.2f\n", 
				idx + 1,
				library[idx].title, 
				library[idx].author,
				library[idx].value);
		//system("clear");
	} else
		printf("No books?\n Too bad.\n");
	
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = 0;
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val; 
}