#include<stdio.h>
#include<math.h>
#define min2sec 60



int main(void)
{
    int t;
    printf("Type the time required:");
    while(scanf("%i", &t) == 1){
        int cooking_time[3] = {600, 60, 10};
        int b1, b2, b3;
        b1 = floor(t / cooking_time[0]);
        b2 = floor((t - (b1 * cooking_time[0])) / cooking_time[1]);
        b3 = ceil((double) (t - (b1 * cooking_time[0]) - (b2 * cooking_time[1])) / (double) cooking_time[2]);
        
        printf("b1: %i\n", b1);
        printf("b2: %i\n", b2);
        printf("b3: %i\n", b3);
        printf("Number of button presses = %i\n", b1 + b2 + b3);
        printf("Type the time required:");
    }


    return 0;
}