#include<stdio.h>
#include<stdlib.h>

int main(void){
	int i, medium, oscillate;
	int minus_cnt=0, plus_cnt=0;

	for (i=0;i<500;i++){
		medium = RAND_MAX/2;
		int random_val = rand();
		if (random_val < medium)
		minus_cnt ++;
		else
		plus_cnt ++;
		oscillate = minus_cnt - plus_cnt;
		printf("%i\n", oscillate);
	}
}


