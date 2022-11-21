#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define NPRIMES 1000
#define ARRLEN 128
#define START '0'

void find_primes(int primes[NPRIMES]);
bool is_prime(int x);
void find_factors_rec(int N, int *primes, int factors[ARRLEN], int cursor);

int main(void)
{
    int primes[NPRIMES];
    find_primes(primes);

    int cursor=0;
    int factors[ARRLEN]={0};
    find_factors_rec(768, primes, factors, cursor);

    cursor = 1;
    printf("%i", factors[0]);
    while (factors[cursor] != 0){
        printf("x%i", factors[cursor]);
        cursor++;
    }
    printf("\n");
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

void find_factors_rec(int N, int *primes, int factors[ARRLEN], int cursor)
{
    if (N == 1){
        return;
    }

    bool found = N % *primes == 0;
    if (found){
        factors[cursor] = *primes;
        cursor += 1;
        find_factors_rec(N/ *primes, primes, factors, cursor);
    }
    else{
        primes++;
        find_factors_rec(N, primes, factors, cursor);
    }
}
