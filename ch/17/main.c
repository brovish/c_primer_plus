#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
    struct film * next;
    struct film * parent;
};

char * s_gets(char *, int);

int main()
{
    struct film * head = NULL;
    struct film * prev, * current;

    char input[TSIZE];

    puts("Enter film name:");

    while (s_gets(input, TSIZE) != NULL && input[0] != 0)
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = current;
            current->parent = NULL;
        }
        else
        {
            prev->next = current;
            current->parent = prev;

        }
        current->next = NULL;

        strcpy(current->title, input);

        puts("Enter rating:");

        scanf("%d", &current->rating);

        while (getchar() != '\n')
            continue;

        prev = current;
        puts("Enter next movie: ");

    }

    if (head == NULL)
        puts("No data entered.");
    else
    {
        puts("Movies list (from start to end): ");

        current = head;

        while (current != NULL)
        {
            printf("%s, rating %d\n", current->title, current->rating);
            current = current->next;
        }

        current = prev;

        puts("Movies list (from end to start): ");

		while (current != NULL)
		{
			printf("%s, rating %d\n", current->title, current->rating);
            current = current->parent;
		}
    }

    current = head;
    struct film * temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

	system("pause");

    return 0;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * temp;

    ret_val = fgets(str, n, stdin);

    if (ret_val)
    {
        temp = strchr(str, '\n');
        if (temp)
            *temp = 0;
        else
            while (getchar() != '\n')
                continue;
    }


    return ret_val;
}
