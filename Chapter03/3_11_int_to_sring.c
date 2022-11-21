#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#define MAXBASE 6 // max number is 999999 (which is smaller than 10**6) 
#define STRING_LENGTH 256

void int2string(int number, char string_out[]);
void test();

int main(void)
{
    test();

    int i;
    char s[STRING_LENGTH]; 
    scanf("%d", &i); 
    int2string(i,s);
    printf("%s\n", s);
    return 0;

}

void int2string(int number, char string_out[])
{
    int cursor = 0;
    if (number < 0){
        string_out[cursor] = 45;
        cursor += 1;
        number *= -1;
    }

    int base = 0;
    for (int i=0; i<MAXBASE; i++){
        if (((int) (number / pow(10, i))) > 0){
            base = i;
        }
    }

    for (int i=base; i>-1; i--){
        string_out[cursor] = ((int) (number / pow(10, i))) + 48;
        cursor += 1;
        number = number % ((int) pow(10, i));
    }
    string_out[cursor] = '\0';
}


void test()
{
    int i = -321;
    char s[STRING_LENGTH]; 
    int2string(i, s);
    assert(strcmp(s, "-321") == 0);
}