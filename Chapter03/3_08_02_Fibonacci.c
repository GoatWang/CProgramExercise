#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
#define N 10000
// #define PHI 1.61
#define PHI 1.61803

void generate_fibsiquence(int fib[], int length);
bool fibword_subs(int n);
bool fib_math(int n);
void test();

int main(void)
{
    test();

    int n = 1;
    while (fib_math(n) == fibword_subs(n)){
        n += 1;
    }
    printf("wrong from the %ith digit\n", n);
    return 0;
}

void generate_fibsiquence(int fib[], int length)
{
    int count = 0;
    int n_iter = 0;
    while (count < length){
        if (fib[n_iter] == 0){
            if ((count+1) < length){
                fib[count+1] = 1;
                count += 1;
            }
            else{
                break;
            }
            if ((count+2) < length){
                fib[count+2] = 0;
                count += 1;
            }
            else{
                break;
            }
        }
        else{
            if ((count+1) < length){
                fib[count+1] = 0;
                count += 1;
            }
            else{
                break;
            }
        }
        n_iter += 1;
    }
}

bool fibword_subs(int n)
{
    int fib[N]={0};
    generate_fibsiquence(fib, n);
    return (bool) fib[n-1];
}

bool fib_math(int n)
{
    return (bool) (2 + floor(n * PHI) - floor((n + 1) * PHI));
}

void test(){
    // test fib sequence is correctly generated
    int fib[69]={0};
    generate_fibsiquence(fib, 69);
    int answer[69] = {0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1};
    for (int i=0; i<69; i++){
        assert(fib[i] == answer[i]);
    }
}