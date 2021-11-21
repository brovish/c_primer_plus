#include <stdio.h>
int main(void)
{
    const int secret_code = 13;
    int code_entered;
    int status;
    
    printf("To enter triskaidekaphobia therapy club, \n");
    printf("Please enter secret number code.\n");
    
    status = scanf("%d", &code_entered);
    
    while (status == 1&&code_entered != secret_code)
    {
	
	//printf("To enter triskaidekaphobia therapy club, \n");
        printf("Wrong code, please try againt.\n");

	status = scanf("%d", &code_entered);
    
    }
    
    if (status == 1){
	printf("Congratulations! You are cured now.\n");

    } else {
        printf("Ohh no! You are not cured now. Please try againt later.\n");
    }
    
    return 0;
}