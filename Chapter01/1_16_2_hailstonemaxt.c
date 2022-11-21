#include<stdio.h>
#include <math.h>

int main(void){
    int max_seq_length;
    unsigned long long int i, value, lgnum, max_lgnum, max_lgnum_number;

    max_lgnum = 0;
    max_lgnum_number = 0;
    for (i=1; i<=10000000; i++){
        value = i;
        lgnum = 0;
        while(value != 1){
            if (value % 2 == 0){
                value = value / 2;
            }
            else{
                value = 3 * value + 1;
            }
            if (value > lgnum){
                lgnum = value;
            }
        }

        if (lgnum > max_lgnum){
            max_lgnum_number = i;
            max_lgnum = lgnum;
            printf("max_lgnum_number: %llu \n", max_lgnum_number);
            printf("max_lgnum: %llu \n", max_lgnum);
            printf("======================================================\n");
        }
    }


    
    return 0;
}