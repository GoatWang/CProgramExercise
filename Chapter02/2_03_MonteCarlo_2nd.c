#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#define N 10000

bool hit_the_circle(double x, double y, double r);
void test();

int main(void)
{
    test();

    bool hit;
    int hit_count = 0;
    for (int i=1; i<N; i++){
        long double r, x, y;
        r = 1;
        x = (double) rand() / (double) RAND_MAX;
        y = (double) rand() / (double) RAND_MAX;
        if (hit_the_circle(x, y, r)){
            hit_count += 1;
        }

        if (i%100 == 0){
            printf("%i, %.4f\n", i, (4*(double) hit_count)/(double) i);
        }
    }

}


bool hit_the_circle(double x, double y, double r)
{
    if (pow(x, 2) + pow(y, 2) <= pow(r, 2)){
        return true;
    }
    else{
        return false;
    }

}

void test()
{
    assert(hit_the_circle(1, 1, 1) == false);
    assert(hit_the_circle(0.5, 0.5, 1) == true);
}