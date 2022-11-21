#include<stdio.h>
#include<math.h>

int main(void){
    double x, output;
    printf("please input as double number:");
    scanf("%lf", &x);
    output = pow(sin(x), 2) + pow(cos(x), 2);
    printf("sin(x)^2 + cos(x)^2 = %f\n", output);

    return 0;
}
