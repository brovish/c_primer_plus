#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VALSIZE 100

int seek_item(const int * vals, const int size, const int seek);
void init_str(int * vals, const int size);
int mycomp(const void * p1, const void * p2);
void print_str(const int * vals, const int size);

int main()
{

    int vals[VALSIZE];
    int rd;
    srand((unsigned int) time(0));
    init_str(vals, VALSIZE);
    //print_str(vals, VALSIZE);
    qsort(vals, VALSIZE, sizeof(int), mycomp);
    print_str(vals, VALSIZE);
    rd = 0 + rand()%10;
	printf("Value %d is %s.\n", rd,
			seek_item(vals, VALSIZE, rd) == 0 ? "not found" : "found");


    return 0;
}

int seek_item(const int * vals, const int size, const int seek)
{
    int mid, low, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
		//printf("mid=%d;vals[%d]=%d\n", mid, mid, vals[mid]);
		if (seek == vals[mid])
        {
            return 1;
        }

		if (vals[mid] < seek)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    }

    return 0;
}

void init_str(int * vals, const int size)
{
    for (int i = 0; i < size; i++)
		vals[i] = 0 + rand()%(size);
}

void print_str(const int * vals, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\n", vals[i]);
}

int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values */
    const int * a1 = (const int *) p1;
    const int * a2 = (const int *) p2;
    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;
}
