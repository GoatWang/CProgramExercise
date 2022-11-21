#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#define N 100

bool is_vowel(char c);
void test();

int main(void)
{
    for (char i='a'; i<='z'; i++){
        if (is_vowel(i)){
            continue;
        } 
        else{
            for (char j='a'; j<='z'; j++){
                if (!is_vowel(j)){
                    continue;
                } 
                else{
                    for (char k='a'; k<='z'; k++){
                        if (is_vowel(k)){
                            continue;
                        }
                        else{
                            printf("%c%c%c\n", i, j, k);
                        }
                    }
                }
            }
        }
    }
}

bool is_vowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
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
