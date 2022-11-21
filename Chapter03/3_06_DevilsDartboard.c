#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdlib.h>
#define NUMBEROFDART 20
#define NLOOPS 5000000

int cal_score(int arr[NUMBEROFDART]);
void swap(int arr[], int n1, int n2);
void print_arr(int arr[], int length);
void test();

int main(void)
{
    test();
    int arr[NUMBEROFDART];
    for (int i; i<NUMBEROFDART; i++){
        arr[i] = i+1;
    }

    int score, min_score=-1;
    for (int i=0; i<NLOOPS; i++){ // NLOOPS
        int n1, n2;
        n1 = rand() % NUMBEROFDART;
        n2 = rand() % NUMBEROFDART;
        swap(arr, n1, n2);
        score = cal_score(arr);
        if (min_score == -1){
            min_score = score;
        }

        if (score < min_score){
            min_score = score;
        }
        else{
            swap(arr, n1, n2);
        }

        // if ((i % 10000) == 0){
        //     printf("%07i min_score: %i\n", i, min_score);
        // }
    }

    printf("Total = %i ", min_score);
    print_arr(arr, NUMBEROFDART);
    return 0;
}

int cal_score(int arr[NUMBEROFDART])
{
    int score = 0;
    for (int i=0; i<NUMBEROFDART; i++){
        int current_sum = 0;
        for (int j=0; j<3; j++){
            int idx = i + j;
            if (idx >= NUMBEROFDART){
                idx -= NUMBEROFDART;
            }
            current_sum += arr[idx];
        }
        score += pow(current_sum, 2);
    }
    return score;
}

void swap(int arr[], int n1, int n2)
{
    int c;
    c = arr[n1]; arr[n1] = arr[n2]; arr[n2] = c;
}

void print_arr(int arr[], int length){
    for (int i=0; i<length; i++){
        printf("%3i ", arr[i]);
    }
    printf("\n");
}

void test()
{
    int arr[NUMBEROFDART] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};
    assert(cal_score(arr) == 20478);
    swap(arr, 0, 19); assert(arr[0] == 5); assert(arr[19] == 20);
}
