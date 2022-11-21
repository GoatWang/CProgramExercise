#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<ctype.h>

char encoding(char c);
void test();

int main(void)
{
    test();

    char c;
    while ((c = getchar()) != EOF){
        putchar(encoding(c));
    }
    printf("\n");

    return 0;
}

char encoding(char c)
{
    if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))){
        if (islower(c)){
            return ('z' - 'a') - (c - 'a') + 'a';
        }
        else{
            return ('Z' - 'A') - (c - 'A') + 'A';
        }
    }
    else{
        return c;
    }
}


void test()
{
    assert(encoding('a') == 'z');
    assert(encoding('b') == 'y');
    assert(encoding('c') == 'x');
    assert(encoding('A') == 'Z');
    assert(encoding('B') == 'Y');
    assert(encoding('C') == 'X');
}