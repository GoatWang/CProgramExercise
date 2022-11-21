#include<stdio.h>
#include <math.h>

int main(void){
    int inp, valid, n_notes;

    do{
        printf("How much money would you like ?");
        scanf("%i", &inp);

        valid = ((inp % 20) == 0);
        n_notes = floor(inp / 20);
        if (!valid){
            printf("I can give you %i or %i, try again.\n", n_notes*20, (n_notes+1)*20);
        }
    }while(!valid);

    printf("OK, dispensing ...");
    return 0;
}