#include <stdio.h>
#include <string.h>
#define MAXTITL 50
#define MAXAUTL 50
#define MAXBKS 100
#define SEP "----------------------------"

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char *, int n);
void print_by_title(struct book ptrlibr[MAXBKS], int count);
void print_by_value(struct book library[MAXBKS], int count);

int main(void)
{
	
	struct book library[MAXBKS];
	int count = 0;
	int index;
	
	
	printf("Please enter the book tiitle.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != 0)
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Enter next title.\n");
	}
	
	if (count > 0)
	{
		printf("%s\nHere is a list of your books:\n", SEP);
		
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, 
			library[index].author, library[index].value);
		
		print_by_title(library, count);
		print_by_value(library, count);
		
		printf("%s\nHere is originale list of your books:\n", SEP);
		
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, 
			library[index].author, library[index].value);
		
		
	}
	else 
	{
		printf("No books? Too bad.\n");
	}
	
	return 0;
}

void print_by_value(struct book library[MAXBKS], int count)
{
	struct book ptrlibr;
	struct book copylibs[count];
	
	for (int i = 0; i < count; i++)
	{
		copylibs[i] = library[i];
	}	
			
	int top, seek;
		
	for (top = 0; top < count - 1; top++)
	{
		for (seek = top + 1; seek < count; seek++)
		{
			//printf("%c %c\n", ptrlibr[top]->title[0], ptrlibr[seek]->title[0]);
			if (copylibs[top].value > copylibs[seek].value)
			{
				ptrlibr = copylibs[top];
				copylibs[top] = copylibs[seek];
				copylibs[seek] = ptrlibr;
				
			}
			
		}
	}
	printf("%s\nHere is a list of your books sorted by price\n", SEP);
			
	for (int index = 0; index < count; index++)
		printf("%s by %s: $%.2f\n", copylibs[index].title, 
		copylibs[index].author, copylibs[index].value);
		
}

void print_by_title(struct book library[MAXBKS], int count)
{
	struct book ptrlibr;
	struct book copylibs[count];
	
	for (int i = 0; i < count; i++)
	{
		copylibs[i] = library[i];
	}
		
	int top, seek;
		
	for (top = 0; top < count - 1; top++)
	{
		for (seek = top + 1; seek < count; seek++)
		{
			//printf("%c %c\n", ptrlibr[top]->title[0], ptrlibr[seek]->title[0]);
			if (copylibs[top].title[0] > copylibs[seek].title[0])
			{
				ptrlibr = copylibs[top];
				copylibs[top] = copylibs[seek];
				copylibs[seek] = ptrlibr;
				
			}
			
		}
	}
	printf("%s\nHere is a list of your books sorted by title:\n", SEP);
			
	for (int index = 0; index < count; index++)
		printf("%s by %s: $%.2f\n", copylibs[index].title, 
		copylibs[index].author, copylibs[index].value);
		
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