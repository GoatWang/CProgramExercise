#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>
#include<ctype.h>

bool is_vowel(char x);
void test();

int main(void)
{
    test();

    printf("please input a character: ");
    char c;
    while ((c = getchar()) != EOF){
        if (is_vowel(c)){
            putchar(toupper(c));
        }
        else{
            putchar(tolower(c));
        }
    }
    printf("\n");

    return 0;
}


bool is_vowel(char x)
{
    if (tolower(x) == 'a' || tolower(x) == 'e' || tolower(x) == 'i' || tolower(x) == 'o' || tolower(x) == 'u'){
        return true;
    }
    else{
        return false;
    }
}


void test()
{
    assert(is_vowel('a') == true);
    assert(is_vowel('e') == true);
    assert(is_vowel('i') == true);
    assert(is_vowel('c') == false);
    assert(is_vowel('A') == true);
    assert(is_vowel('E') == true);
    assert(is_vowel('I') == true);
    assert(is_vowel('C') == false);
}