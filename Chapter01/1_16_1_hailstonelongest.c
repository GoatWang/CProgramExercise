#include<stdio.h>
#include <math.h>

int main(void){
    int seg_length, max_seq_length;
    unsigned long long int i, value, max_seq_length_number;

    max_seq_length = 0;
    max_seq_length_number = 0;
    for (i=1; i<=10000000; i++){
        // printf("i: %i \n", i);
        value = i;
        seg_length = 0;
        while(value != 1){
            if (value % 2 == 0){
                value = value / 2;
            }
            else{
                value = 3 * value + 1;
            }
            seg_length += 1;
        }

        if (seg_length > max_seq_length){
            max_seq_length = seg_length;
            max_seq_length_number = i;
            printf("max_seq_length: %i \n", max_seq_length);
            printf("max_seq_length_number: %llu \n", max_seq_length_number);
            printf("======================================================\n");
        }
        // max_seq_length_number = (seg_length > max_seq_length) ? i : max_seq_length_number
    }


    
    return 0;
}