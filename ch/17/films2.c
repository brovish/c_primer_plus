#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

char * s_gets(char *, int);

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;
	
};

int main(void)
{
	struct film * head = NULL;
	struct film * prev;
	struct film * current;
	char input[TSIZE];
	
	puts("Enter first movie title:");
	
	while (s_gets(input, TSIZE) != NULL && input[0] != 0)
	{
		current = (struct film *) malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		
		puts("Enter rating: ");
		scanf("%d", &current->rating);
	
		while (getchar() != '\n')
			continue;
		
		puts("Enter next movie title (empty string to exit)");
		
		prev = current;
		
	}
	
	if (head == NULL)
		puts("No movies data.");
	else
		puts("Here is your list of movies:");
	current = head;	
	while (current != NULL)
	{
		printf("Movie: %s\tRating: %d\n", current->title,
			current->rating);
		current = current->next;
	}
	
	current = head;
    	while (head != NULL)
    	{
        	current = head;
        	head = current->next;  
        	free(current);
    	}

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