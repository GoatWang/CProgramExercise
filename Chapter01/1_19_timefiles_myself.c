#include<stdio.h>
#include<assert.h>


int check_valid_time(int a, int b);


int main(void){
    int a, b, c, d;

    printf("please specify two times in 24-hour clock:");
    scanf("%02i:%02i %02i:%02i", &a, &b, &c, &d);

    assert(check_valid_time(a, b) == 1);
    assert(check_valid_time(c, d) == 1);


    if (a > c){
        c += 24;
    }
    if (b > d){
        d += 60;
        c -= 1;
    }

    int hour_diff, minute_diff;

    hour_diff = c - a;
    minute_diff = d - b;

    printf("%02i:%02i\n", hour_diff, minute_diff);
}

int check_valid_time(int a, int b){
    if ((a > 24) || (a < 0)){
        return 0;
    }
    if ((b > 60) || (b < 0)){
        return 0;
    }

    return 1;
}

