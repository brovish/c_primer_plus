#include <stdio.h>
int main(void)
{
    float assets;
    char pet[30];
    int age;
    
    printf("Enter your age, assets, and favorite pet. \n");
    scanf("%d %f", &age, &assets);
    scanf("%s", pet);
    
    printf("You are %d years old, you have %.2f, and "
	"%s is your favorite pet name.\n", age, assets, pet);
    
    return 0;
}