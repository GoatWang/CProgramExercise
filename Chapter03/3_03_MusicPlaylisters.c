#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define TIMES 3

void test();
void set_array(int arr[], unsigned int length, int value);
void shuffle(int playlist[], unsigned int length);
void shuffle2(int playlist[], unsigned int length, unsigned int times);
bool is_in_array(int arr[], unsigned int length, int value);
void arr_add(int arr[], unsigned int length, int value);
void print_arr(int arr[], unsigned int length);

int main(void)
{
    void test();

    int length;
    printf("How many songs required ?");
    if (scanf("%i", &length) == 1){
        int playlist[length];
        for (int i=0; i<length; i++){
            playlist[i] = i+1;
        }

        shuffle(playlist, length); // 3.3.1: calculate the ordered id of shuffled result, use more memory
        // shuffle2(playlist, length, TIMES); //3.3.2:  exchange two item at a time, and do it length*TIMES times
        print_arr(playlist, length);
    }


    return 0;
}

void shuffle(int playlist[], unsigned int length)
{
    int count = 0;
    int orderlist[length];
    set_array(orderlist, length, -1);
    while(count < length){
        int random_number;
        random_number = rand() % length;
        if (is_in_array(orderlist, length, random_number)){
            continue;
        }
        else{
            orderlist[count] = random_number;
            count += 1;
        }
    }

    int playlist_new[length];
    for(int i=0; i<length; i++){
        playlist_new[i] = playlist[orderlist[i]];
    }
    for(int i=0; i<length; i++){
        playlist[i] = playlist_new[i];
    }
}

void shuffle2(int playlist[], unsigned int length, unsigned int times)
{
    for (int i=0; i<length*times; i++){
        int n1 = rand() % length;
        int n2 = rand() % length;
        printf("%i, %i\n", playlist[n1], playlist[n2]);
        int n_temp = playlist[n1];
        playlist[n1] = playlist[n2];
        playlist[n2] = n_temp;
    }
}



void set_array(int arr[], unsigned int length, int value)
{
    for (int i=0; i<length; i++){
        arr[i] = value;
    }
}

bool is_in_array(int arr[], unsigned int length, int value)
{
    for (int i=0; i<length; i++){
        if (arr[i] == value){
            return true;   
        }
    }
    return false;
}

void arr_add(int arr[], unsigned int length, int value)
{
    for (int i=0; i<length; i++){
        arr[i] += value;
    }
}

void print_arr(int arr[], unsigned int length)
{
    for(int i=0; i<length; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void test()
{
    int test_arr1[3];
    set_array(test_arr1, 3, -1);
    assert(test_arr1[0] == -1);
    assert(test_arr1[2] == -1);

    int test_arr2[3] = {2, 5, 9};
    assert(is_in_array(test_arr2, 3, 2) == true);
    assert(is_in_array(test_arr2, 3, 4) == false);


    int test_arr3[3] = {2, 5, 9};;
    arr_add(test_arr3, 3, 2);
    assert(test_arr1[0] == 4);
    assert(test_arr1[2] == 11);
}


