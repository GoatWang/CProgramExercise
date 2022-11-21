#include<stdio.h>
#define A 9
#define C 5
#define M 11

int main(void){
	int i, seed=0;
	int first_num, loop_cnt=2;
	printf("A, C, M: %i %i %i\n", A, C, M);

	/* Linear Congruential Generator */
	seed = (A*seed + C) % M;
	printf("%i\n", seed);
	first_num = seed;
	seed = (A*seed + C) % M;
	printf("%i\n", seed);
	while (seed != first_num){
		seed = (A*seed + C) % M;
		printf("%i\n", seed);
		loop_cnt++;
	}
	/* Seed now contains your new random number */
	printf("loop_cnt: %i\n", loop_cnt-1);
	return 0;
}
