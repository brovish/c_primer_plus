#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct polar_v {
	double magnitude;
	double angle;
} Polar_V;

typedef struct rect_v {
	double x;
	double y;
} Rect_V;

Polar_V set_Polar_V(double, double);
void print_Polar_V(const Polar_V *);
Rect_V set_Rect_V(const Polar_V *);
void print_Rect_V(const Rect_V *);

int main(void)
{
	
	Polar_V pv;
	Rect_V rv;
	
	double magnitude;
	double angle;
	int input = 1;		
	
	puts("Enter polar coordinates (type q to exit): ");
	
	while(true)
	{
		puts("Enter magnitude: ");
		input = scanf("%lf", &magnitude);
		
		if (input)
		{
			puts("Enter angle: ");
			input = scanf("%lf", &angle);
			if (input) 
			{
				pv = set_Polar_V(magnitude, angle);
				print_Polar_V(&pv);
				
				rv = set_Rect_V(&pv);
				print_Rect_V(&rv);
				
				puts("Next.. (type q to exit)");
			}
			else break;
		}
		else break;
		
	}
	
	return 0;
}

Rect_V set_Rect_V(const Polar_V * pv)
{
	Rect_V rv;
	//x = r cos A y = r sin A
	rv.x = pv->magnitude * cos(pv->angle);
	rv.y = pv->magnitude * sin(pv->angle);
	
	return rv;
}

void print_Rect_V(const Rect_V * rv)
{
	printf("RECTAGULAR:\nx:%0.2lf\ty:%.2lf\n", 
		rv->x, rv->y);
}

Polar_V set_Polar_V(double magnitude, double angle)
{
	Polar_V pv;
	pv.magnitude = magnitude;
	pv.angle = angle;
	
	return pv;
}

void print_Polar_V(const Polar_V * pv)
{
	printf("POLAR:\nmagnitude:%0.2lf\tangle:%.2lf\n", 
		pv->magnitude, pv->angle);
}
