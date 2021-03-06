#include <stdio.h>
#include <stdbool.h>
//validate input is an integer
long get_long(void);
//validate range of input
bool bad_limits(long begin, long end, 
    long low, long high);
//calculate sum of squares of the integers
long sum_squares(long a, long b);

int main(void)
{
    const long MIN = -10000000L;
    const long MAX = 10000000L;
    long start;
    long stop;
    double answer;
    
    printf("This program computates the sum of the squares of "
	"integers in range.\nThe lower bound should not "
	"be less then %ld and\nthe upper bound "
	"should not be greater than %ld.\nEnter the "
	"limits (enter 0 for both limits to quit):\n",
	MIN, MAX);
    printf("lower limit: ");
    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    
    while (start != 0 || stop != 0)
    {
	if (bad_limits(start, stop, MIN, MAX))
	    printf("Please try again.\n");
	else
	{
	    answer = sum_squares(start, stop);
	    printf("The sum of squares of integers ");
	    printf("from %ld to %ld is %.2lf\n", start, stop, answer);
	}
	
	printf("Enter the limits (enter 0 for both "
	"limits to quit):\n");
	printf("Lower limit: ");
	start = get_long();
	printf("Upper limit: ");
	stop = get_long();
    }
    printf("Done.\n");
    
    return 0;
}

long sum_squares(long a, long b)
{
    double total = 0;
    long i;
    for (i = 0; i <= b; i++)
    {
	total += (double)i * (double) i;
    }
    return total;

}

long get_long(void)
{
    long input;
    char ch; 
    while (scanf("%ld", &input) != 1)
    {
	while ((ch = getchar()) != '\n')
	    putchar(ch);
	printf(" is not an integer.\nPlease enter an ");
	printf("integer value, such as 25, -12, 1: ");
    }
    return input;
}


bool bad_limits(long begin, long end, 
    long low, long high)
{
    bool not_good = false;
    
    if (begin > end)
    {
	printf("%ld isn't smaller than %ld\n", begin, end);
	not_good = true;
    }
    
    if (begin < low || end < low)
    {
	printf("Values must be %ld or greater\n", low);
	not_good = true;
    }
    
    if (begin > high || end > high)
    {
	printf("Values must be %ld or less.\n", high);
	not_good = true;
    }
    
    return not_good;
}