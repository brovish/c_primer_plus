#include <stdio.h>
#include <stdlib.h>
float calc_mean(float sum, int cnt);
int main(int argc, char *argv[])
{

	int cnt = 0;
	float number;
	float sum = 0.0;
		
	if (argc < 2)
	{
		printf("Write float numbers (q to exit), then I will "
		"calculate mean (the average)\n"
		"Sum of observation/Total number of observation\n");
		
		while (scanf("%f", &number) == 1)
		{
			//printf("number=%f\n", number);
			sum += number;
			cnt++;		
		}
			
		printf("Mean: %f\n", calc_mean(sum, cnt));
	}
	else if (argc == 2)
	{
		FILE *fp;
		
		if ((fp = fopen(argv[1], "r")) == NULL)
		{	fprintf(stderr, "Could not open %s file "
				"(\"r\" mode)\n", argv[1]);		
			return(EXIT_FAILURE);
		}
		while (fscanf(fp, "%f", &number) == 1)
		{
			sum += number;
			cnt++;		
		}
		
		printf("Mean: %f\n", calc_mean(sum, cnt));;	
		
	}
	
	return 0;
}

float calc_mean(float sum, int cnt)
{
	
	return (float) (sum / cnt);
}