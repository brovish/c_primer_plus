#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	printf("The square root of %f is %f\n", 
		atof(*(argv+1)), sqrt(atof(argv[1])));
	return 0;
}