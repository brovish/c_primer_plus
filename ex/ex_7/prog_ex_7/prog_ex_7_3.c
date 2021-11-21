/*
Write a program that reads integers until 0 is entered. 
After input terminates, the program should report the total number 
of even integers (excluding the 0) entered, the
average value of the even integers, the total number of odd integers entered, and the
average value of the odd integers.*/
#include <stdio.h>
#define STOP_INT 0
int main(void)
{
    int input;
    int c_even,  c_odd; 
    float avg_even, avg_odd;
    c_even = c_odd = 0;
    avg_even = avg_odd = 0.f;
    
    while (scanf("%d", &input))
    {
	if (input == STOP_INT) break;
	if (input % 2)
	{
	    //c_odd++;
	    avg_odd += (float) input/++c_odd;
	}
	else
	{
	    avg_even += (float) input/++c_even;
	}
    }

    printf("Count of even ingers: %d\n", c_even);
    printf("Count of odd ingers: %d\n", c_odd);
    printf("Average value of even integers: %.2f\n", avg_even);
    printf("Average value of odd integers: %.2f\n", avg_odd);
    
    return 0;
}