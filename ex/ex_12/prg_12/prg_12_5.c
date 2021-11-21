#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND 10
#define MAXSZ 100
int grand(int n);
void ssort(int ar[], int n);
void printarr(int arr[], int n);

int main(void)
{
	srand((unsigned int) time(0));
	int arr[MAXSZ];
	
	int i = 0;
	for (; i < MAXSZ; i++)
	{
		arr[i] = grand(RAND);
	}
	
	arr[i] = 0;
	
	printarr(arr, MAXSZ);
	
	ssort(arr, MAXSZ);
	
	printarr(arr, MAXSZ);
		
	return 0;
}

void ssort(int arr[], int n)
{
	int temp;
	
	int top, seek;
	for (top = 0; top < n; top++)
	{
		for (seek = top + 1; seek < n; seek++)
		{
			if (arr[top] < arr[seek])
			{
				temp = arr[top];
				arr[top] = arr[seek];
				arr[seek] = temp;
			}
		}		
	}
}

int grand(int n)
{
	int r;
	r = rand() % n + 1;
	return r;
}

void printarr(int arr[], int n)
{
	printf("\n");
	
	for (int i = 0; i < MAXSZ; i++)
	{
		if (i %10 ==0 )
			printf("\n");
		printf("[%2d]", arr[i]);
	}
	
	printf("\n");

}