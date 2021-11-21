#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void init_arr(int *,int);
void print_arr(int *, int);
void pick_arr(int *, int, int);
bool search_arr(int *, int, int);

int main(void)
{
	int picks, size, rv;
	
	while (true)
	{
		puts("Enter size of array (type q to exit):");
		rv = scanf("%d", &size);
		if(rv)
		{
			int arr[size];
			srand((unsigned int) time(0));
			init_arr(arr, size);
			puts("Enter number of picks: ");
			rv = scanf("%d", &picks);
			if (rv)
			{
				
				if (picks > size)
				{
					puts("Try again, picks must be lesser or equal than size.");
					continue;
				}
				
				puts("\nSource array:");
				print_arr(arr, size);
				puts("\nPicked items:");
				pick_arr(arr, size, picks);
			} else 
				break;
		}
		else 
			break;
		puts("\nNext size: ");
	}
	
	return 0;
}

void pick_arr(int * arr, int size, int picks)
{
	int p_arr[picks];
	int rand_pick;
	int r_num;
	int p_cnt = 0;
	if (picks == size)
	{
		print_arr(arr, size);
		return;
	}
	for (; p_cnt < picks;)
	{
		r_num = (rand() % (size - 0 + 1)) + 0;
		//printf("r_num=%d\n", r_num);
		rand_pick = arr[r_num == size ? r_num - 1: r_num];
		if (!search_arr(p_arr, picks, rand_pick))
		{
			p_arr[p_cnt] = rand_pick;	
			p_cnt++;
			
		}
	}
	
	print_arr(p_arr, picks);
}

bool search_arr(int * p_arr, int size, int searh)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (p_arr[i] == searh)
		{
			found = true;
			break;
		}
	}
	return found;
}

void init_arr(int ar[],int size)
{
	for (int i = 0; i < size; i++)
		ar[i] = i + 1;
}

void print_arr(int *ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%3d ", ar[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
}