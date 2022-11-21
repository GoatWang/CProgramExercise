#include<stdio.h>
#include<stdlib.h>


int main(void){
    int x, inp;
    x = rand();
    printf("The answer is %i\n", x);
    x = x % 1000;
    printf("The answer is %i\n", x);

    do{
        printf("please input a number:");
        scanf("%i", &inp);
        if (inp > x){
            printf("It should be lower!\n");
        }
        if (inp < x){
            printf("It should be higher!\n");
        }
    }while (inp != x);

    printf("The answer is right!\n");

    return 0;


}