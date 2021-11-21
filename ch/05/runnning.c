#include <stdio.h>
const int S_PER_M = 60;
const int S_PER_H = 3600;
const double M_PER_K = 0.62137;
int main(void)
{
    
    double distk, distm;
    double rate;
    int min, sec;
    int time;
    double mtime;
    int msec;
    double mmin;
    
    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average\n");
    printf("speed in miles per hour.\n");
    
    printf("Please enter, in kilometers, the distance run.\n");
    scanf("%lf", &distk);
    
    printf("Next enter the time in minutes and seconds.\n");
    printf("Begin entering time in minutes.\n");
    scanf("%d", &min);
    
    printf("Now enter seconds.\n");
    scanf("%d", &sec);
    
    //converts time to pure seconds:
    time = S_PER_M * min + sec;
    //converts km to miles:
    distm = M_PER_K * distk;
    //miles per sec x sec per hours = mph
    rate = distm / time * S_PER_H;
    
    mtime = (double) time / distm;
    //mmin = (int) mtime / S_PER_M; //whole minutes
    mmin = mtime / S_PER_M; //whole minutes
    msec = (int) mtime % S_PER_M; // remaining seconds
    
    //debug
    printf("time=%d\ndistm=%f\nrate=%f\nmtime=%f\nmmin=%f\nmsec=%d\n"
	, time, distm, rate, mtime, mmin, msec);
    
    printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n", 
	distk, distm, min, sec);
    printf("That pace corresponds to running a mile in %f min, "
	, mmin);
    printf("%d sec.\nYour average speed was %1.2f mph.\n",
	msec, rate);    
        
    return 0;
}