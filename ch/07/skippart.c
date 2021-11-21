#include <stdio.h>
int main(void)
{
    
    const float MIN = 0.0f;
    const float MAX = 100.0f;
    
    float score;
    float total = 0.0f;
    
    int n = 0;
    float min = MAX;
    float max = MIN;
    
    printf("Enter the first score (q to exit).\n");
    
    while ((scanf("%f", &score) == 1))
    {
    if (score < MIN || score > MAX)
    {
    printf("%.0f is a invalid value. Try again: ",
        score);
    continue;
    }
    
    printf("Accepting %0.1f:\n", score);
    min = (score < min) ? score:min;
    max = (score > max) ? score:max;
    total+=score;
    n++;
    printf("Enter next score (q to exit): ");
    }
    
    if (n>0)
    {
    printf("Average of %d scores is %0.1f.\n", n, total/n);
    printf("Low = %0.1f, high = %0.1f\n", min, max);
    }
    else 
    {
    printf("No valid score were entered.\n");
    }
    return 0;
}