#include<stdio.h>


int main(void)
{
	int i, cnt;
	double inp, max;
	printf("How many numbers do you wish to enter ?");
	scanf("%i", &cnt);

	printf("Enter %i real numbers:", cnt);
	for (i=0;i<cnt;i++){
		scanf("%lf", &inp);
		if (i == 0){
			max = inp;
		}
		else{
			if (inp > max){
				max = inp;
			}
		}
	}

	printf("Maximum value: %.2f\n", max);
	return 0;
}
