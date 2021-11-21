#include <stdio.h>

void show(const double ar1[], int n);
void show2(const double ar2[][3], int n);

int main(void)
{
    //const int *pt1;
    
    //pt1 = (double [4]){8,3,9,2};
    
    show((const double [4]){8,3,9,2}, 4);
    show2((const double [2][3]){{8,3,9},{5,4,1}}, 2);
    return 0;
}

void show(const double ar1[], int n)
{
    int i = 0;
    for (;i<n;i++)
	printf("ar1[%d]=%.2f\n", i, ar1[i]);
}
void show2(const double ar2[][3], int n)
{
    int r = 0; int c = 0;
    for (;r<n;r++)
    {
	c=0;
	for (;c<3;c++)
	printf("ar2[%d][%d]=%.2f ", 
	    r,c, ar2[r][c]);
    printf("\n");
    }
    

}
