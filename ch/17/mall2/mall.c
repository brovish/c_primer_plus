#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);
int random_queue_selection(void);

int main()
{

    Queue line_1;
    Queue line_2;
    Item temp;

    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaways_1 = 0;
    long turnaways_2 = 0;
    long customers_1 = 0;
    long customers_2 = 0;
    long served_1 = 0;
    long served_2 = 0;
    long sum_line_1 = 0;
    long sum_line_2 = 0;
    int wait_time_1 = 0;
    int wait_time_2 = 0;
    double min_per_cust;
    long line_wait_1 = 0;
    long line_wait_2 = 0;

    InitializeQueue(&line_1);
    InitializeQueue(&line_2);

    srand((unsigned int) time(0));
    puts("Case study: Sigmund Lander's Advice Booth (two lines)");
    puts("Enter the number of the simulation hours: ");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour: ");
    scanf("%d", &perhour);

    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line_1) || QueueIsFull(&line_2))
            {
                turnaways_1++;
                turnaways_2++;
            }
            else if (QueueIsFull(&line_1))
            {
                turnaways_1++;
            }
            else if (QueueIsFull(&line_2))
            {
                turnaways_2++;
            }
            else if (line_1.items < line_2.items)
            {
                customers_1++;
                temp = customertime(cycle);
                EnQueue(temp, &line_1);
            }
            else if (line_2.items < line_1.items)
            {
                customers_2++;
                temp = customertime(cycle);
                EnQueue(temp, &line_2);
            }
            else if (line_2.items == line_1.items)
            {

                int r = random_queue_selection();
                if (r == 1)
                {
                    customers_1++;
                    temp = customertime(cycle);
                    EnQueue(temp, &line_1);
                }
                else
                {
                    customers_2++;
                    temp = customertime(cycle);
                    EnQueue(temp, &line_2);
                }
            }
        }



        if (wait_time_1 <= 0 && !QueueIsEmpty(&line_1))
        {
            DeQueue(&temp, &line_1);
            wait_time_1 = temp.proccesstime;
            line_wait_1 += cycle - temp.arrive;
            served_1++;
        }

        if (wait_time_2 <= 0 && !QueueIsEmpty(&line_2))
        {
            DeQueue(&temp, &line_2);
            wait_time_2 = temp.proccesstime;
            line_wait_2 += cycle - temp.arrive;
            served_2++;
        }

        if (wait_time_1 > 0)
            wait_time_1--;
        if (wait_time_2 > 0)
            wait_time_2--;
        sum_line_1 += QueueItemCount(&line_1);
        sum_line_2 += QueueItemCount(&line_2);
    }

    if (customers_1 > 0)
    {

        printf("Line 1:\n");
        printf("Customers accepted: %4ld\n", customers_1);
        printf("  Customers served: %4ld\n", served_1);
        printf("\t turnaways: %4ld\n", turnaways_1);
        printf("average queue size: %.2f\n",
               (double) sum_line_1/ cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double) line_wait_1 / served_1);
    }
    else
    {
        puts("Line 1: no customers.");
    }

    if (customers_2 > 0)
    {

        printf("Line 2:\n");
        printf("Customers accepted: %4ld\n", customers_2);
        printf("  Customers served: %4ld\n", served_2);
        printf("\t turnaways: %4ld\n", turnaways_2);
        printf("average queue size: %.2f\n",
               (double) sum_line_2/ cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double) line_wait_2 / served_2);
    }
    else
    {
        puts("Line 2: no customers.");
    }

    if (customers_1 > 0 && customers_2 > 0)
    {
        printf("Line 1 and 2:\n");
        printf("Customers accepted: %4ld\n", customers_1 + customers_2);
        printf("  Customers served: %4ld\n", served_1 + served_2);
        printf("\t turnaways: %4ld\n", turnaways_1 + turnaways_2);
        printf("average queue size: %.2f\n",
               (double) sum_line_1/ cyclelimit + (double) sum_line_2/ cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double) line_wait_1 / served_1 + (double) line_wait_2 / served_2);
    }

    if (customers_1 == 0 && customers_2 == 0)
    {
        puts("No customers.");
    }

    EmptyQueue(&line_1);

    return 0;
}

bool newcustomer(double x)
{
    if ((rand() * x / RAND_MAX) < 1)
        return true;
    else
        return false;
}

int random_queue_selection(void)
{
    return 1 + rand() % 2;
}

Item customertime(long when)
{
    Item cust;
    cust.proccesstime = rand() % 25 + 1;
    cust.arrive = when;

    return cust;
}
