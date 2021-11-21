#include <stdio.h>
int main(void)
{
    float fsize;
    float dspeed;
    
    printf("Enter download speed in megabits per second (Mbs) "
    "and file size in megabytes (MB): [18.3, 200]\n");
    
    scanf("%f , %f", &dspeed, &fsize);
    //File Size In Megabytes / (Download Speed In Megabits / 8) = Time In Seconds
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", dspeed, fsize);
    printf("dowloads in %.2f seconds\n", fsize/(dspeed/8));
    
    return 0;
}