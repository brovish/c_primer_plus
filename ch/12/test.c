#include <stdio.h>
int main(void)
{
	int entity = 3;
	int *pt = &entity;
	int ranks[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10};
	
	printf("%d\n", *(ranks + 2*entity));
	
	
	return 0;
}
