#include <stdio.h>
#include "pe12-2a.h"
int main(void)
{
	int mode;
	int status = 0; 
	printf("Enter 0 for metric mode, 1 for US mode: ");
	status = scanf("%d", &mode);
	while (mode >= 0)
	{
		if (status)
		{
			setmode(mode);
			get_info();
			show_info();
			printf("Enter 0 for metric mode, 1 for US mode");
			printf(" (-1 it quit): ");
			status = scanf("%d", &mode);
		}
		else
		{
			while (getchar() != '\n')
				continue;
			status = 1;
			mode = 2;
		} 
	}
	printf("Done.\n");
	return 0;
}