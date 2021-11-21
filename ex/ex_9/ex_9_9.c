#include <stdio.h>
#include <stdbool.h>

void menu(void);

void define_range(int*, int*);

bool check_range(int, int);

int main(void)
{
    
    int min, max;
    bool is_good_range = false;
    define_range(&min, &max);
    printf("Range defined from %d to %d\n", min, max);
    is_good_range = check_range(min, max);
    if (is_good_range)
	printf("Range defined from %d to %d is good\n", min, max);
    else
	printf("Range defined from %d to %d is bad\n", min, max);
    
    menu();
    
    return 0;
}

void define_range(int* min, int* max)
{
    printf("Please define range ([int] [int]):\n");
    while (scanf("%d %d", min, max) != 2)
    {
	scanf("%*s");
	printf("Please define range ([int] [int]):\n");
    }
}

void menu(void)
{
    int code;
    int rc = 0;
    
    printf("1) copy files		2) move files\n");
    printf("3) remove files		4) delete files\n");
    printf("5) quit\n");
    
    while (1)
    {
	rc = scanf("%d", &code);
	if (!rc)
	{
	    scanf("%*s");
	    printf("Please enter int from 1 to 5\n");
        }
        else if (code == 5)
    	    break;
        printf("1) copy files		2) move files\n");
    	printf("3) remove files		4) delete files\n");
    	printf("5) quit\n");
    }
}

bool check_range(int min, int max)
{
    return (min > max && max < min) ? false : true;
}