#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// #define E 2.71828182818281849364
#define E 3.14159265358979323846
#define N 100000

int main(void){
    int a, b;
    int closest_a, closest_b;
    long double approx, cloest_dist=RAND_MAX;
    for (b=1; b<N; b++){
        a = round(E * (double) b);
        approx = (double) a / (double)b;
        if (fabsl(approx - E) < cloest_dist){
            closest_a = a;
            closest_b = b;
            cloest_dist = fabsl(approx - (long double)E);
        }
        // printf("%i/%i=%.20Lf(%.20Lf)\n", a, b, (long double) a / (long double)b, cloest_dist);
    } 
    printf("%i/%i=%.20Lf\n", closest_a, closest_b, (long double) closest_a / (long double)closest_b);
    return 0;
}
