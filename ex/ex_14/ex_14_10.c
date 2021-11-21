#include <stdio.h>

struct gas {
	float distance;
	float gals;
	float mpg;
};

void calc_mpg(struct gas *);
struct gas calc_mpg2(struct gas);

int main(void)
{
	
	typedef struct gas gasinfo;
	gasinfo g =  {
	 	.distance = 456.87,
	 	.gals = 56.73,
	 	.mpg = .0f
	 };
	
	gasinfo g2 =  {
	 	.distance = 46.87,
	 	.gals = 6.73,
	 	.mpg = .0f
	 };
		
	printf("distance=%f;gals=%f;mpg=%f\n", 
		g.distance, g.gals, g.mpg);
	
	printf("distance=%f;gals=%f;mpg=%f\n", 
		g2.distance, g2.gals, g2.mpg);
	
	
	calc_mpg(&g);
	
	g2 = calc_mpg2(g2);
			
	printf("distance=%f;gals=%f;mpg=%f\n", 
		g.distance, g.gals, g.mpg);
	
	printf("distance=%f;gals=%f;mpg=%f\n", 
		g2.distance, g2.gals, g2.mpg);
	
				
	return 0;
}

struct gas calc_mpg2(struct gas g)
{	
	 //struct gas temp;
	 //temp = g;
	 g.mpg = (float) (g.distance/g.gals);
	 return g; 
}

void calc_mpg(struct gas * g)
{
	g->mpg = (float) (g->distance/g->gals);
}