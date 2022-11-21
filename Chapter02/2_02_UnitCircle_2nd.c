#include<stdio.h>
#include<math.h>
#include<assert.h>

double unit_circle(double x);
void test();

int main(void)
{
    test();

    double x, y;
    printf("please input any number:");
    scanf("%lf", &x);
    y = unit_circle(x);
    printf("sin^2(x) + cos^2(x) = %.2f\n", y);

}


double unit_circle(double x)
{
    return pow(sin(x), 2) + pow(cos(x), 2);
}

void test()
{
    assert(unit_circle(3.14) - 1 < pow(10, -6));
    assert(unit_circle(1.4141414) - 1 < pow(10, -6));
}