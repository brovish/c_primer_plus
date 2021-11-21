#include <stdio.h>
#include <string.h>
int main(void)
{
	
	struct fullname {
		char fname[20];
		char lname[20];
	};
	
	struct bard {
		struct fullname name;
		int born;
		int died;
	};
	
	struct bard willie = {{"Kurt", "Cobain"}, 1967, 1994};
	struct bard *pt = &willie;
	
	printf("willie.born=%d\n", willie.born);
	printf("pt->born=%d\n", pt->born);
	
	scanf("%d", &willie.born);
	printf("willie.born=%d\n", willie.born);
	
	scanf("%d", &pt->born);
	printf("pt->born=%d\n", pt->born);
	
	scanf("%s", willie.name.lname);
	printf("willie.name.lname=%s\n", willie.name.lname);
	
	scanf("%s", pt->name.lname);
	printf("pt->name.lname=%s\n", pt->name.lname);
	
	
	printf("willie.name.fname=%s\n", willie.name.fname);
	printf("willie.name.lname=%s\n", willie.name.lname);
	
	printf("willie.name.fname[2]=%c\n", willie.name.fname[2]);
	
	unsigned long len;
	len = strlen(willie.name.fname) + strlen(willie.name.lname);
	
	printf("srtlen(%s)+strlen(%s)=%ld; %ld+%ld=%ld\n",
	willie.name.fname, willie.name.lname, len,
	strlen(willie.name.fname), strlen(willie.name.lname), 
	len);
	
	return 0;
	
}