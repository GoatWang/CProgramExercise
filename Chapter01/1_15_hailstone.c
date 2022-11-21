#include<stdio.h>
#include <math.h>

int main(void){
    int value;
    printf("Please input a number:");
    scanf("%i", &value);

    while(value != 1){
        printf("%u\n", value);
        if (value % 2 == 0){
            value = value / 2;
        }
        else{
            value = 3 * value + 1;
        }
    }
    printf("%u\n", value);
    return 0;
}