#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_int(char *);
double get_double(char *str);

int main(int argc, char *argv[])
{
	int power = 0;
	double dval; 
	power = get_int(argv[2]);
	dval = get_double(argv[1]);
	//printf("power=%d;double = %f\n", power, dval);
	if (argc < 3 || !(power && dval))
		printf("Usage: %s [double argument] [int power]\n",
			*argv);
	else
	{
		
		int i = 1;
		double total = dval;
			
		do 
		{
			total *= dval;
			i++;
		} while (i < power);
		
		printf("%.2f in %d power = %.5f\n",
			dval, power, power == 1 ? dval :total);
	
	}
		
	return 0;
}

int get_int(char *str)
{
	char *end;
	long val = strtol(str, &end, 10);
	
	return (int) val;
}

double get_double(char *str)
{
	char *end;
	double val = strtod(str, &end);
	
	return val;
}
