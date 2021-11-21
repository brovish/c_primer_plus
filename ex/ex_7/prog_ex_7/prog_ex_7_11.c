#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SEP "------------------------------------------------------\n"
#define SEP1 "******************************************************\n"
int clear();
void show_menu(float a, float b, float c);
void show_err();
void print_totals(float w_a, float w_b, float w_c, 
    float c_a, float c_b, 
    float c_c, float t_c, 
    float t_w, float t_d, 
    float t_d_c, float t_d_a);

int main()
{
    const float a_cost = 2.05f;
    const float b_cost = 1.15f;
    const float c_cost = 1.09f;
    const float o_discount_percent = 0.05f;
    const float o_discount = 100.0f;
    const float ship_cost_1 = 6.5f;
    const float ship_th_1 = 5.0f;
    const float ship_cost_2 = 14.0f;
    const float ship_th_2 = 20.0f;
    const float ship_cost_3 = 0.5f;
    float ship_cost_1_ok = 1;
    float ship_cost_2_ok = 1;
    float total_delivery_cost = 0.f;
    float total_p = 0.f;
    float old_total_p = 0.f;
    float total_cost = 0.f;
    float total_cost_a = 0.f;
    float total_cost_b = 0.f;
    int order_discount_ok = 1;
    float total_cost_c = 0.f;
    float total_discount = 0.f;
    float w_a = 0.f;
    float w_b = 0.f;
    float w_c = 0.f;
    float total_a = 0.f;
    float total_b = 0.f;
    float total_c = 0.f;
    char ch;
    int err;
    int i;
    
    clear();
    show_menu(a_cost, b_cost, c_cost);
    
    while ((ch = getchar()) != 'q')
    {
	//printf("ch=%c\n", ch);
        err = 0;
        switch (tolower(ch))
        {
	    case 'a':
	        printf("Please enter artichok pounds:\n");
	        while ((scanf("%f", &w_a)) != 1)
	        {
		    printf("Please enter artichok pounds.\n");
		    fseek(stdin,0,SEEK_END);
		    continue;
	        }
	        total_a += w_a;
	        break;
	    case 'b':
	        printf("Please enter beets pounds:\n");
	        while ((scanf("%f", &w_b)) != 1)
	        {
		    printf("Please enter beets pounds.\n");
		    fseek(stdin,0,SEEK_END);
		    continue;
	        }
	        total_b += w_b;
	        break;
	    case 'c':
		printf("Please enter carrots pounds:\n");
	        while ((scanf("%f", &w_c)) != 1)
	        {
		    printf("Please enter carrots pounds.\n");
		    fseek(stdin,0,SEEK_END);
		    continue;
	        }
	        total_c += w_c;
	        break;
    	    default:
		err = 1; 
	        fseek(stdin,0,SEEK_END);
	        break;
	}
	
	fseek(stdin,0,SEEK_END);
        
        if (err)
        {
	    clear();
	    show_err();
	    show_menu(a_cost, b_cost, c_cost);
	    continue;
	    err=0;
	} else 
	{
	    clear();
	    old_total_p = total_p;
	    total_p = total_a + total_b + total_c;
	    
	    total_cost_a = total_a * a_cost;
	    total_cost_b = total_b * b_cost;
	    total_cost_c = total_c * c_cost;
	    total_cost = total_cost_a + total_cost_b + total_cost_c;
	    
	    
	    if (ship_cost_1_ok && total_p < ship_th_1)
	    {
		ship_cost_1_ok = 0;
		total_delivery_cost = ship_cost_1;
		total_cost += ship_cost_1;
	    }
	    
	    if (ship_cost_2_ok && total_p < ship_th_2 && total_p > ship_th_1)
	    {
		ship_cost_2_ok = 0;
		total_cost += ship_cost_2;
		total_cost -= ship_cost_1;
		total_delivery_cost = ship_cost_2;
	    }
	    
	    if (total_p >= ship_th_2)
	    {
	        i = total_p - old_total_p;
	        
	        //if we have cost under per pound limit 
	        if (ship_cost_2_ok)
	        {
	    	    i -= ship_th_2;
	        }
	        
		//printf("i=%d;old:%f; cir:%f\n", i, old_total_p, total_p);
	        if (i >= 1)
	        {
	    	    do
	    	    {
	    		total_cost += ship_cost_3;
	    		total_delivery_cost += ship_cost_3;
	    		i--;
	    		//printf("i=%d;old:%f; cir:%f\n", i, old_total_p, total_p);
	    	    } while ( i > 0);
	        }

	        //printf("i=%d;old:%f; cir:%f\n", i, old_total_p, total_p);
	        
    		if (ship_cost_2_ok)
    		{
    		    total_cost += ship_cost_2;
    		    total_delivery_cost += ship_cost_2;
    		    ship_cost_2_ok = 0;
    		}
	    }
	    
	    if (total_cost >= o_discount && order_discount_ok)
	    {
		order_discount_ok = 0;
		total_discount = o_discount*o_discount_percent;
		total_cost -= total_discount;
	    }
	    
	    show_menu(a_cost, b_cost, c_cost);
	    print_totals(total_a, total_b, total_c, total_cost_a, 
		total_cost_b, total_cost_c, total_cost, total_p, 
		order_discount_ok ? 0 : o_discount_percent, total_delivery_cost, total_discount);
	    

	}
	
	
    }

    return 0;
    
}

void show_menu(float a, float b, float c)
{
    printf("%s", SEP1);
    printf("Please enter a, b, c to order vegetables (q to quit):\n");
    printf("a) artichokes ($%.2f per pound)\n", a);
    printf("b) beets ($%.2f per pound)\n", b);
    printf("c) carrot ($%.2f per pound)\n", c);
    printf("q) quit\n");
    printf("%s", SEP1);
}

void show_err()
{
    printf("error input!\n");
}

int clear()
{
    return system("clear");
}

void print_totals(float w_a, float w_b, float w_c, 
    float c_a, float c_b, float c_c, float t_c, float t_w, 
    float t_d, float t_d_c, float t_d_a)
{
    printf("%s", SEP);
    printf("Total pounds: %.2f\n", t_w);
    printf("Artichokes: %.2f pounds\nBeets: %.2f pounds\nCarrots: %.2f pounds\n", w_a, w_b, w_c);
    printf("%s", SEP);
    printf("Total cost:%.2f\n", t_c);
    printf("Artichokes: %.2f$\nBeets: %.2f$\nCarrots: %.2f$\n", c_a, c_b, c_c);
    printf("Total discount:%.2f%%\n", t_d*100);
    printf("Total discount amount:%.2f$\n", t_d_a);
    printf("Total delivery cost:%.2f$\n", t_d_c);
    printf("%s", SEP);
}
