#include <stdio.h>
#define ARR_SIZE 5

void printf_arr(int arr[], int n, char *name);
void sp_copyarr(int arr1[], int arr2[], int arr_t[], int n);

int main(void)
{
    int source1[ARR_SIZE] = {1, 2, 3, 4, 5};
    int source2[ARR_SIZE] = {0, 1, 2, 3, 4};

    printf_arr(source1, ARR_SIZE, "source1");
    printf_arr(source2, ARR_SIZE, "source2");

    int target[ARR_SIZE];
    sp_copyarr(source1, source2, target, ARR_SIZE);
    printf_arr(target, ARR_SIZE, "target");
    putchar('\n');
    return 0;
}

void sp_copyarr(int arr1[], int arr2[], int arr_t[], int n)
{
    for (int r = 0; r < n; r++)
    {
        arr_t[r] = arr1[r] + arr2[r];
    }
}

void printf_arr(int arr[], int n, char *name)
{
    for (int r = 0; r < n; r++)
    {
    if ((r % 5) == 0)
        putchar('\n');
    printf("%s[%d]=%d\t", name, r, arr[r]);
    }
    putchar('\n');
}