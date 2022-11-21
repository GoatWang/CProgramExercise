#include<stdio.h>

int main(void)
{
	//int a=0;
	//printf("%i\n", ++a);
	//printf("%i\n", a);
	//printf("%i\n", a++);
	//printf("%i\n", a);
	//return 0;

	int a, b = 0, c = 0;
	a = ++b + ++c;
	printf("%d %d %d\n", a, b, c);
	a = b++ + c++;
	printf("%d %d %d\n", a, b, c); 
	a = ++b + c++;
	printf("%d %d %d\n", a, b, c); 
	a = b-- + --c;
	printf("%d %d %d\n", a, b, c); 
}
