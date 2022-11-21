#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 12000
#define R 1

int main(void){

    int circle_cnt = 0;
    for (int i=0; i<N; i++){
        double x, y;
        x = rand()/(double)RAND_MAX;
        y = rand()/(double)RAND_MAX;
        if ((pow(x, 2) + pow(y, 2)) <= R){
            circle_cnt+=1;
        }
        if ((i % 1000) == 0){
            // printf("%i\n", circle_cnt);
            printf("%i %lf\n", i, (4 * (double) circle_cnt) / (double) i);
        }
    }


    return 0;
}