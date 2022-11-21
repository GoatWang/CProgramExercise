#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#define LENGTH 256

bool all_true(bool* matches, int length);
bool char_matching(const char* str1, const char* str2);
void test();

int main(int argc, char* argv[])
{
    test();
    
    if (argc != 2){
        fprintf(stderr, "please enter one string only!");
        exit(0);
    }

    char* strinput;
    strinput = argv[1];
    int length_strinput = strlen(strinput);

    FILE* fp = fopen("./Words/34words.txt", "r");
    if (fp == NULL){
        fprintf(stderr, "Cannot read the file!");
        exit(0);
    }

    char strfpline[LENGTH];
    while (fgets(strfpline, LENGTH, fp) != NULL){
        int length_strfp = strlen(strfpline) - 1;
        strfpline[length_strfp] = '\0';
        if (char_matching(strinput, strfpline)){
            fprintf(stdout, "%s\n", strfpline);
        }
    }

    return 1;
}

bool all_true(bool* matches, int length)
{
    bool all_match=true;
    for (int i=0; i<length; i++){
        if (matches[i] == false){
            all_match = false;
        }
    }
    return all_match;
}

bool char_matching(const char* str1, const char* str2)
{   
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    if (l1 != l2){
        return false;
    }

    bool* matches1 = (bool*) malloc(l1);
    bool* matches2 = (bool*) malloc(l2);
    memset(matches1, false, l1);
    memset(matches2, false, l2);
    for (int i=0; i<l1; i++){
        for (int j=0; j<l2; j++){
            if (!matches1[i] && !matches2[j] && (str1[i] == str2[j])){
                matches1[i] = true;
                matches2[j] = true;
            }
        }
    }

    // printf("matches1:");
    // for (int i=0; i<l1; i++){
    //     printf("%i", matches1[i]);
    // }
    // printf("\n");

    // printf("matches2:");
    // for (int i=0; i<l2; i++){
    //     printf("%i", matches2[i]);
    // }
    // printf("\n");

    if (all_true(matches1, l1) && all_true(matches2, l2)){
        return true;
    }

    return false;
}

void test()
{
    assert(char_matching("test", "tset") == true);
    assert(char_matching("test", "tret") == false);
}