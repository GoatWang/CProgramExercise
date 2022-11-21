#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define NPRIMES 1000

void find_primes(int primes[NPRIMES]);
bool is_prime(int x);
void find_factors_rec(int N, int *primes);


int main(void)
{
    int primes[NPRIMES];
    find_primes(primes);
    find_factors_rec(210, primes);
}

void find_primes(int primes[NPRIMES])
{
    int cnt = 0;
    int num = 2;
    while (cnt < 1000){
        if (is_prime(num)){
            primes[cnt] = num;
            cnt++;
        }
        num++;
    }
}

bool is_prime(int x)
{
    int i = x-1;
    while (i>1){
        if ((x % i) == 0){
            return false;
        }
        i--;
    }
    return true;
}

void find_factors_rec(int N, int *primes)
{
    if (N == 1){
        return;
    }

    bool found = N % *primes == 0;
    if (found){
        find_factors_rec(N/ *primes, primes);
        printf("%i ", *primes);
    }
    else{
        primes++;
        find_factors_rec(N, primes);
    }
}
