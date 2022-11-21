#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define STRLENGTH 256
#define ARRLENGTH 10000

void sort_and_insert(char* str_list[ARRLENGTH], char* str);
void print_str_list(char* str_list[ARRLENGTH]);
void test();


int main(int argc, char* argv[])
{
    test();

    if (argc != 2){
        fprintf(stderr, "Please specify only one filename!\n");
        exit(0);
    }

    // // TODO0. Work
    // FILE* fp = fopen(argv[1], "r");
    // if (fp == NULL){
    //     fprintf(stderr, "Cannot read the file!\n");
    //     exit(0);
    // }

    // // TODO1. Work
    // char *filenanme;
    // filenanme = argv[1];
    // FILE* fp = fopen(filenanme, "r");
    // if (fp == NULL){
    //     fprintf(stderr, "Cannot read the file!\n");
    //     exit(0);
    // }

    char filenanme[STRLENGTH];
    strcpy(filenanme, argv[1]);
    FILE* fp = fopen(filenanme, "r");
    if (fp == NULL){
        fprintf(stderr, "Cannot read the file!\n");
        exit(0);
    }


    // remember1: char* str_list[ARRLENGTH] mean ARRLENGTH long array with char* (pointer).
    // remember2: assigning a value to a pinter have to firstly allocate the memory.
    // remember3: assigning string should always use strcpy.
    // remember4: str_list is array, which cannot be assign value (e.g. str_list++).
    char str[STRLENGTH];
    char* str_list[ARRLENGTH];
    while (fgets(str, STRLENGTH, fp) != NULL){
        int length = strlen(str)-1;
        str[length] = '\0';
        sort_and_insert(str_list, str);
    }
    
    fclose(fp);
    print_str_list(str_list);
}


void sort_and_insert(char* str_list[ARRLENGTH], char* str)
{
    // printf("str: %s\n", str);
    int distance;
    int cursor = 0;
    int target_cursor=0;
    while (str_list[cursor] != NULL){
        distance = strcmp(str, str_list[cursor]);
        cursor += 1;
        if (distance>0){
            target_cursor = cursor;
        }
    };

    // TODO: how to get the length of the array
    // int arr_length = sizeof(str_list);
    int arr_length = 0;
    while (str_list[arr_length] != NULL){
        arr_length += 1;
    }

    // printf("target_cursor: %i\n", target_cursor);
    if (target_cursor == arr_length){
        str_list[target_cursor] = (char*) malloc(sizeof(char) * sizeof(str));
        strcpy(str_list[target_cursor], str);
    }
    else{
        int mv_cursor = arr_length;
        while(mv_cursor>target_cursor){
            // printf("mv_cursor: %i\n", mv_cursor);
            // printf("str_list[mv_cursor-1]: %s\n", str_list[mv_cursor-1]);
            // printf("str_list[mv_cursor]: %s\n", str_list[mv_cursor]);
            str_list[mv_cursor] = (char*) malloc(sizeof(char) * sizeof(str_list[mv_cursor-1]));
            strcpy(str_list[mv_cursor], str_list[mv_cursor-1]);
            mv_cursor -= 1;
        }
        // printf("mv_cursor: %i\n", mv_cursor);
        // printf("str_list[mv_cursor]: %s\n", str_list[mv_cursor]);
        // printf("str: %s\n", str);
        
        str_list[mv_cursor] = (char*) malloc(sizeof(char) * sizeof(str));
        strcpy(str_list[mv_cursor], str);
        // printf("===========\n");
    }
}

void print_str_list(char* str_list[ARRLENGTH])
{
    int cursor = 0;
    while(str_list[cursor] != NULL){
        printf("%s\n", str_list[cursor]);
        cursor += 1;
    }
}

void test()
{
    char* str_list1[ARRLENGTH] = {"aaaaa", "bbbbb", "ddddd"};
    char* str1 = "cccccc";
    sort_and_insert(str_list1, str1);
    // print_str_list(str_list1);
    assert(strcmp(str_list1[2], str1) == 0);

    char* str_list2[ARRLENGTH] = {"bbbbb", "ddddd"};
    char* str2 = "aaaaa";
    sort_and_insert(str_list2, str2);
    // print_str_list(str_list2);
    assert(strcmp(str_list2[0], str2) == 0);


    char* str_list3[ARRLENGTH] = {"aaaaa", "bbbbb"};
    char* str3 = "ddddd";
    sort_and_insert(str_list3, str3);
    // print_str_list(str_list3);
    // assert(strcmp(str_list3[2], str3) == 0);
}