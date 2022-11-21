#include<stdio.h>
#include<assert.h>
#define STRING_LENGTH 256

int roman_convert(char s[]);
int roman_convert_char(char c);
void test();

int main(void)
{  
    test();
    return 0;
}

int roman_convert(char s[])
{
    int n = 0;
    int nums[STRING_LENGTH];
    while (s[n] != '\0'){
        nums[n] = roman_convert_char(s[n]);
        n += 1;
    }

    for (int i=0; i<(n-1); i++){
        if (nums[i] < nums[i+1]){
           nums[i] *= -1; 
        }
    }

    int summary = 0;
    for (int i=0; i<n; i++){
        summary += nums[i];
    }
    return summary;
}

int roman_convert_char(char c)
{
    switch (c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

void test()
{
    assert(roman_convert_char('I') == 1);
    assert(roman_convert_char('M') == 1000);

    char s1[STRING_LENGTH] = "MCMXCIX";
    char s2[STRING_LENGTH] = "MCMLXVII";
    char s3[STRING_LENGTH] = "MCDXCI";
    assert(roman_convert(s1) == 1999);
    assert(roman_convert(s2) == 1967);
    assert(roman_convert(s3) == 1491);
}