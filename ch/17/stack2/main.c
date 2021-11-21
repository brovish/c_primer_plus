#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define STRSIZE 100

char * s_gets(char * str, int n);

int main()
{
    char input[STRSIZE];
    char * str;
    char ch;
	bool pres;

    Stack s;

    InitializeStack(&s);

	printf("Stack size: %d\n", MAXSTACK);

    printf("Enter 1 string (press enter to quit):\n");
    while (s_gets(input, STRSIZE) != NULL && input[0] != 0)
    {
        str = input;
        while (*str)
        {
            if (!Push(*str, &s))
            {
                printf("Stack is full.\n");
                break;
            }
            str++;
        }

        printf("Popped items:\n");

        while (Pop(&ch, &s))
        {
            printf("%c", ch);
        }
        puts("");

        printf("next string:\n");
    }
    return 0;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            * find = 0;
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
