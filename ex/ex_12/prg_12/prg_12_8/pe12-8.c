#include <stdlib.h>
#include <stdio.h>
int * make_array(int elem, int val);
void show_array(const int ar[], int n);
void show_array2(const int ar[], int n);
int main(void)
{
	int *pa;
	int size;
	int value;
	
	//system("clear");
	
	printf("Enter the number of elements: ");
	while (scanf("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf("%d", &value);
		
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
	
		printf("Enter the number of elements (<1 to quit): ");
	}
	
	printf("Done.\n");
		
	return 0;
}

int * make_array(int elem, int val)
{
	
	int *ptr;
	ptr = (int *) malloc (elem * sizeof(int));
	for (int i = 0; i < elem; i++, *ptr = val, ptr++);
	*ptr = 0;
	
	return ptr-elem;
}

void show_array(const int ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{	
		if (i % 5 == 0)
			puts("");
		printf("ar[%d]=%d ", i, ar[i]);	
	}
	printf("\nTotal elements:%d\n", i);
	
}

void show_array2(const int ar[], int n)
{
	int i;
	for (i = 0; *ar; i++, ar++)
	{	
		if (i % 5 == 0)
			puts("");
		printf("ar[%d]=%d ", i, *ar);	
	}
	printf("\nTotal elements:%d\n", i);
	
}