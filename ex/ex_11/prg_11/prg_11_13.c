#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
		printf("Usage: %s arg1 arg2 arg3..\n",
			argv[0]);
	else
	{
		if (argc > 1)
		{
			char **ptr;
			ptr = argv + argc - 1;
			char *temp[argc-1];
			int z, i;
			for (i = argc, z = 0; i > 1; i--, z++)
			{
				temp[z] = *ptr;
				ptr--;
			}
			
			for (i = 0; i < argc - 1; i++)
				printf("%s ", temp[i]);
			puts("");
			
		}
	}			
	return 0;
}