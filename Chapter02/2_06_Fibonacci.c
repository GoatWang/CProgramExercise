#include<stdio.h>
#include<math.h>
#include<assert.h>
#define phi 1.61803398875
#define N 20

void test();
int fibonacci(int n);


int main(void)
{
    test();

    printf("fibonacci(%i) = ", N);
    for (int i=1; i<21; i++){
        printf("%i", fibonacci(i));
    }
    printf("\n");

    return 0;

}


int fibonacci(int n)
{
    return 2 + floor(n * phi) - floor((n + 1) * phi);
}

void test()
{
    assert(fibonacci(1) == 0);
    assert(fibonacci(2) == 1);
    assert(fibonacci(3) == 0);
    assert(fibonacci(4) == 0);
    assert(fibonacci(5) == 1);

}