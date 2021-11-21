#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define RND_MAX 10
#define MAX_SZ 1000

int grand();
void printarr(int arr[]);
void countarr(int arr[]);
void refillarr(int arr[]);

int seed = 1;
int arr[MAX_SZ];

int main(void)
{
	
	for (int i = 0; i < 10; i++)
	{
		srand((unsigned int) seed);
		refillarr(arr);
		//printarr(arr);
		countarr(arr);
		seed++;
	}
	return 0;
}

void refillarr(int arr[])
{

	int i = 0;
	
	for (; i < MAX_SZ; i++)
		arr[i] = grand();
	
}

int grand()
{
	int r;
	r = rand() % RND_MAX + 1;
	return r;
}

void printarr(int arr[])
{
	for (int i = 0; i < MAX_SZ; i++)
	{
		if (i % 15 == 0)
			puts("");
		printf("%d ", arr[i]);
	}
	
	puts("");
}

void countarr(int arr[])
{

	int cnt1, cnt2, cnt3, cnt4, cnt5,
	cnt6, cnt7, cnt8, cnt9, cnt10;
	
	int cntsum = 0;
	
	cnt1 = cnt2 = cnt3 = cnt4 = cnt5 = cnt6
		= cnt7 = cnt8 = cnt9 = cnt10 = 0;
	
	for (int i = 0; i < MAX_SZ; i++)
	{
		switch (arr[i])
		{
			case 1 :
				cnt1++;
				break;
			case 2 :
				cnt2++;
				break;
			case 3 :
				cnt3++;
				break;
			case 4 :
				cnt4++;
				break;
			case 5 :
				cnt5++;
				break;
			case 6 :
				cnt6++;
				break;
			case 7 :
				cnt7++;
				break;
			case 8 :
				cnt8++;
				break;
			case 9 :
				cnt9++;
				break;		
			case 10 :
				cnt10++;
				break;	
		}
	}
	
	cntsum = cnt1 + cnt2 + cnt3 + cnt4
			+ cnt5 + cnt6 + cnt7 + cnt8
			+ cnt9 + cnt10;
	
	printf("*********SEED:%d****************\n", seed);
	printf("1=%2d\n", cnt1);
	printf("2=%2d\n", cnt2);
	printf("3=%2d\n", cnt3);
	printf("4=%2d\n", cnt4);
	printf("5=%2d\n", cnt5);
	printf("6=%2d\n", cnt6);
	printf("7=%2d\n", cnt7);
	printf("8=%2d\n", cnt8);
	printf("9=%2d\n", cnt9);
	printf("10=%2d\n", cnt10);
	printf("*******total=%d******************\n", 
		cntsum);

}