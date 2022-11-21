#include<stdio.h>
#define LENGTH 256

struct matched_strings{
    // TODO: what's the difference between 
    // char* s;
    char s[LENGTH];
    struct matched_strings* next;
};
typedef struct matched_strings matched_strings;

void test();

int main(int argc, char* argv[])
{
    test();
}

void test()
{
    // TODO: how to assign value to ms1.s 
    //0.
    // matched_strings ms1 = {"11", NULL};
    //1. 
    // matched_strings* ms1;
    // ms1->s = "00";
    //2. 
    // matched_strings* ms1;
    // strcpy(ms1->s, "11");
    //3. 
    // matched_strings* ms1;
    // char str1[LENGTH] = "11";
    // strcpy(ms1->s, str1);


    // 
    // char str1[LENGTH] = "11";
    // matched_strings ms1 = {str1, NULL};
    // char str2[LENGTH] = "22";
    // matched_strings ms2 = {str2, &ms1};
    // char str3[LENGTH] = "33";
    // matched_strings ms3 = {str3, &ms2};


    // char* str1 = "11";
    // matched_strings ms1 = {str1, NULL};
    // char* str2 = "22";
    // matched_strings ms2 = {str2, &ms1};
    // char* str3 = "33";
    // matched_strings ms3 = {str3, &ms2};

}