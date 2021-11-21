#include <stdio.h>
int main(void)
{
int i = 2147483647;
printf("Inger %d owerflow: %d\n",i, i+1);
float f = 3.4e38 * 100.0f;
float f2 = 0.1234E-38;
printf("%f\n", f);
printf("%e\n", f2/2.0);

return 0;
}
