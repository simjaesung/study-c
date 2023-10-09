#include<stdio.h>

int test(int a)
{
	if (a < 0) return;

	test(a - 1);
	printf("test(%d)\n", a);
	//test(a - 1);
}	



int main(void)
{
	test(5);
	
	return 0;
}