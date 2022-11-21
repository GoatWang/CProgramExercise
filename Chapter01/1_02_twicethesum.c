#include <stdio.h>
int main(void)
{
	int a, b, c, s;
	printf("Input three integers: ");
	scanf( "%i %i %i", &a, &b, &c);
	s = ((a + b + c) * 2) + 7;
	printf("Twice the sum of integers plus 7 is %i !\n", s);
	return 0;
}

