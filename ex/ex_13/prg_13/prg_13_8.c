#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char ch = 0;
	int cnt = 0;
	FILE *fp;
	
	if (argc < 2)
	{
		fprintf(stderr, "Usage %s [char to searh] [file list]\n", 
			*argv);
		exit(EXIT_FAILURE);
	}
	
	if (argc == 2)
	{
		while ((ch = getchar()) != EOF)
			if (ch == argv[1][0])
				cnt++;
	}
	else
	{
		for (int i = 2; i < argc; i++, cnt = 0)
		{
			//printf("%s\n", *(argv+i));
			if ((fp = fopen(*(argv+i), "r")) == NULL) 
			{
				fprintf(stderr, "Can't open file %s\n",
					 *(argv+i));
				continue;
			}
			
			while ((ch = getc(fp)) != EOF)
				if (ch == argv[1][0])
					cnt++; 
						
			if (fclose(fp) != 0)
				fprintf(stderr, "Error while closing file %s\n", *(argv+i));
			
			printf("Char = \"%c\", file = %s, count = %d\n", 
				argv[1][0], *(argv+i), cnt);		
		}
		
	}
	
	return 0;
}