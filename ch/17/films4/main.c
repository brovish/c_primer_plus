#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char * s_gets(char *, int);
void show_movies(Item item);
void eat_line(void);

int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available!\n");
        exit(1);
    }

    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL &&
            temp.title[0] != 0)
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        eat_line();
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }

        if (ListIsFull(&movies))
        {
            puts("The list is full now.");
            break;
        }

        puts("Enter next movies title (empty line to exit)");

    }

    if (ListIsEmpty(&movies))
        puts("No data entered.");
    else
    {
        puts("Here is the list: ");
        Traverse(&movies, show_movies);
    }

    printf("You entered %d movies.\n", ListItemCount(&movies));
    EmptyList(&movies);

	system("pause");

    printf("Bye!\n");

    return 0;
}

void eat_line(void)
{
    while (getchar() != '\n')
        continue;
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
            * find = 0;
        else
            eat_line();
    }

    return ret_val;
}

void show_movies(Item item)
{
    printf("Title: %s\tRating: %d\n", item.title, item.rating);
}
