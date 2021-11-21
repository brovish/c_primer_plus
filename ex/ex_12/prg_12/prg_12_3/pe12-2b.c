#include <stdio.h>
#include "pe12-2a.h"
int main(void)
{
	int nmode; 
	int omode = 0;
	int status = 0;
	int distance = 0;
	double fuel = 0.0f; 
	printf("Enter 0 for metric mode, 1 for US mode: ");
	status = scanf("%d", &nmode);
	//printf("nmode=%d;omode=%d\n", 
	//			nmode, omode);
	while (nmode >= 0)
	{
		if (status)
		{
			setmode(&nmode, &omode);
			
			//printf("nmode=%d;omode=%d\n", 
			//	nmode, omode);
			
			get_info(&distance, &fuel, nmode);
			show_info(&distance, &fuel, nmode);
			printf("Enter 0 for metric mode, 1 for US mode");
			printf(" (-1 it quit): ");
			status = scanf("%d", &nmode);
		}
		else
		{
			while (getchar() != '\n')
				continue;
			status = 1;
		} 
	}
	printf("Done.\n");
	return 0;
}