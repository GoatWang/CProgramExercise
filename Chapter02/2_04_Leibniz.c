#include<stdio.h>
#include<math.h>
# define PI 3.14159265358979323846

int main(void){

    long long int n_iter = 0;
    long double pi_approx = 4;
    double sign = -1;
    double divider = 3;
    do{
        pi_approx += sign*4/divider;
        divider += 2;
        sign *= -1;
        n_iter += 1;
        printf("%lli, %.9Lf, %.9f, %.9Lf\n", n_iter, pi_approx, PI, fabsl(pi_approx-PI));
    }while (!(fabsl(pi_approx - PI) < pow(10, -9)));




    return 0;
}