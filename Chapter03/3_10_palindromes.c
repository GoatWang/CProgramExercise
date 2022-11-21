#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#define STRING_LENGTH 256

int cal_string_length(char s[]);
void preproess_string(char s[], char s_processed[], int length);
bool is_palindromes(char s[]);
void test();

int main(void)
{
    test();
    return 0;
}

int cal_string_length(char s[])
{
    int n = 0;
    int length = 0;
    while (s[n] != '\0'){
        if (isalnum(s[n])){ // is digit or a number
            length += 1;
        }
        n += 1;
    }
    return length;
}

void preproess_string(char s[], char s_processed[], int length)
{
    int nth_char = 0;
    int n_iter = 0;
    while (nth_char < length){
        if (isalnum(s[n_iter])){
            s_processed[nth_char] = tolower(s[n_iter]);
            nth_char += 1;
        }
        n_iter += 1;
    }
}

bool is_palindromes(char s[])
{
    int length = cal_string_length(s);
    char s_processed[STRING_LENGTH];
    preproess_string(s, s_processed, length);

    bool same = true; 
    int n_iter = floor(length/2);
    for (int i=0; i<n_iter; i++){
        if (s_processed[i] != s_processed[length-i-1]){
            same = false;
        }
    }
    return same;
}

void test()
{
    char s1[100] = "kayak";
    char s2[100] = "A man, a plan, a canal: Panama!";
    char s3[100] = "Madam, in Eden I’m Adam,";
    char s4[100] = "Level, madam, level!";
    assert(cal_string_length(s1) == 5);
    assert(cal_string_length(s2) == 21);
    assert(cal_string_length(s3) == 17);
    assert(cal_string_length(s4) == 15);

    int s4_length = cal_string_length(s4);
    char s4_processed[STRING_LENGTH];
    preproess_string(s4, s4_processed, s4_length);
    assert(strcmp(s4_processed, "levelmadamlevel") == 0);

    assert(is_palindromes(s1) == true);
    assert(is_palindromes(s2) == true);
    assert(is_palindromes(s3) == true);
    assert(is_palindromes(s4) == true);

    // int n = 0;
    // while (s4_processed[n] != '\0'){
    //     printf("%c", s4_processed[n]);
    //     n += 1;
    // }
    // printf("\n");
}

