#include<stdio.h>
#include<assert.h>
#define N 3000
int check_is_prime(int num);
int check_ends_with_three(int num);

int main(void){
    assert(check_is_prime(2) == 1);
    assert(check_is_prime(3) == 1);
    assert(check_is_prime(5) == 1);
    assert(check_is_prime(7) == 1);
    assert(check_is_prime(11) == 1);
    assert(check_is_prime(13) == 1);

    assert(check_ends_with_three(2) == 0);
    assert(check_ends_with_three(3) == 1);
    assert(check_ends_with_three(5) == 0);
    assert(check_ends_with_three(7) == 0);
    assert(check_ends_with_three(11) == 0);
    assert(check_ends_with_three(13) == 1);
    
    int i, is_prime, endswith3;
    double cnt_prime, cnt_prime3;
    i = 0;
    cnt_prime = cnt_prime3 = 0;

    while (cnt_prime < N){
        is_prime = check_is_prime(i);
        endswith3 = check_ends_with_three(i);
        if (is_prime == 1){
            cnt_prime += 1;
        }
        if ((is_prime == 1) && (endswith3 == 1)){
            cnt_prime3 += 1;
        }
        i += 1;
    }

    printf("cnt_prime, cnt_prime3 = %.0f, %.0f\n", cnt_prime, cnt_prime3);
    printf("fraction = %.2f\n", cnt_prime3/cnt_prime);
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

int check_ends_with_three(int num){
    if ((num % 10) == 3){
        return 1;
    }
    return 0;

}

