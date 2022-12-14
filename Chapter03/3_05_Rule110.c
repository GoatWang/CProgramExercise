#include<stdio.h>
#include<math.h>
#include<assert.h>
#define LENGTH 34
#define HEIGHT 29

void cal_rule110(int arr_in[LENGTH], int arr_out[LENGTH]);
void print_arr(int arr[], int length);
void test();

int main(void)
{
    test();
    int arr_in[LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    int arr_out[LENGTH];
    print_arr(arr_in, LENGTH);
    for (int i=0; i<HEIGHT; i++){
        cal_rule110(arr_in, arr_out);
        for (int j=0; j<LENGTH; j++){
            arr_in[j] = arr_out[j];
        }
        printf("%2i ", i+1);
        print_arr(arr_in, LENGTH);
    }
    // print_arr(arr_out, LENGTH);


    return 0;
}

void cal_rule110(int arr_in[LENGTH], int arr_out[LENGTH])
{
    arr_out[0] = 0;
    arr_out[LENGTH-1] = 0;
    for (int i=1; i<LENGTH-1; i++){
        int rule;
        rule = arr_in[i-1] * pow(2, 2) + arr_in[i] * pow(2, 1) + arr_in[i+1] * pow(2, 0);
        if ((rule == 0) || (rule == 4) || (rule == 7)){ // 0: 000, 4: 100, 7: 111
            arr_out[i] = 0;
        }
        else{
            arr_out[i] = 1;
        }
    }
}

void print_arr(int arr[], int length)
{
    for (int i=0; i<length; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void test()
{
    int arr_in[LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    int arr_out[LENGTH];
    cal_rule110(arr_in, arr_out);
    assert(arr_out[28] == 0);
    assert(arr_out[29] == 1);
    assert(arr_out[30] == 1);
    assert(arr_out[31] == 0);
}




//  0 0000000000000000000000000000001000
//  1 0000000000000000000000000000011000
//  2 0000000000000000000000000000111000
//  3 0000000000000000000000000001101000
//  4 0000000000000000000000000011111000
//  5 0000000000000000000000000110001000
//  6 0000000000000000000000001110011000
//  7 0000000000000000000000011010111000
//  8 0000000000000000000000111111101000
//  9 0000000000000000000001100000111000
// 10 0000000000000000000011100001101000
// 11 0000000000000000000110100011111000
// 12 0000000000000000001111100110001000
// 13 0000000000000000011000101110011000
// 14 0000000000000000111001111010111000
// 15 0000000000000001101011001111101000
// 16 0000000000000011111111011000111000
// 17 0000000000000110000001111001101000
// 18 0000000000001110000011001011111000
// 19 0000000000011010000111011110001000
// 20 0000000000111110001101110010011000
// 21 0000000001100010011111010110111000
// 22 0000000011100110110001111111101000
// 23 0000000110101111110011000000111000
// 24 0000001111111000010111000001101000
// 25 0000011000001000111101000011111000
// 26 0000111000011001100111000110001000
// 27 0001101000111011101101001110011000
// 28 0011111001101110111111011010111000
// 29 0110001011111011100001111111101000
