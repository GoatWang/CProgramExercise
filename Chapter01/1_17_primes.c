#include<stdio.h>
#include<assert.h>

int check_is_prime(int num);

int main(void){
    assert(check_is_prime(2) == 1);
    assert(check_is_prime(3) == 1);
    assert(check_is_prime(5) == 1);
    assert(check_is_prime(7) == 1);
    assert(check_is_prime(11) == 1);
    assert(check_is_prime(13) == 1);

    int cnt, num, is_prime;
    cnt = 0;
    num = 2;
    while (cnt < 3000){
        is_prime = check_is_prime(num);
        if (is_prime == 1){
            cnt += 1;
            printf("%5i: %3i is prime\n", cnt, num);
        }
        num += 1;
    }
    return 0;
}

int check_is_prime(int num){
    int is_prime;
    is_prime = 1;
    for (int i=2; i<num; i++){
        if ((num % i) == 0){
            is_prime = 0;
        }
    }
    return is_prime;
}



