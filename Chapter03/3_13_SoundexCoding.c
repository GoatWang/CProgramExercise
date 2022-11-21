// TODO: Deal with "Pfister", first P and f hace the same code
#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#define STRING_LENGTH 256
#define SOUNDEX_LENGTH 4

void test();
void convert_to_soundex(char string_in[], char string_out[SOUNDEX_LENGTH]);
char convert_to_soundex_char(char c);
void reset_arr(char arr[], int length);

int main(void)
{
    test();



    return 0;
}

void convert_to_soundex(char string_in[], char string_out[SOUNDEX_LENGTH])
{
    // encoding
    bool first_skip = false;
    int cursor_in = 0;
    int cursor_enc1 = 0;
    char string_encoding1[STRING_LENGTH] = {'0'};
    while (string_in[cursor_in] != '\0'){
        char encode = convert_to_soundex_char(string_in[cursor_in]);
        string_encoding1[cursor_enc1] = encode;
        cursor_enc1 += 1;
        cursor_in += 1;
    }

    // remove continous duplicate
    // remove duplicates seperated by 'H' or 'W'
    int cursor_enc1_max = cursor_enc1;
    int cursor_enc2 = 0;
    char string_encoding2[STRING_LENGTH] = {'0'};
    for (cursor_enc1=0; cursor_enc1<cursor_enc1_max; cursor_enc1++){
        bool skip = false;
        if (cursor_enc1 > 0){
            bool same_with_previous = string_encoding1[cursor_enc1-1] == string_encoding1[cursor_enc1];
            if (same_with_previous){
                skip = true;
            }
        }
        if (cursor_enc1 > 1){
            bool middle_is_hw = string_encoding1[cursor_enc1-1] == '8';
            bool same_seperate_by_hw = string_encoding1[cursor_enc1-2] == string_encoding1[cursor_enc1];
            if (same_seperate_by_hw && middle_is_hw){
                skip = true;
            }
        }

        if (!skip){
            string_encoding2[cursor_enc2] = string_encoding1[cursor_enc1];
            cursor_enc2++;
        }        
        if ((cursor_enc1==0) && skip){
            first_skip = true;
        }
    }

    int cursor_enc2_max = cursor_enc2;
    int cursor_enc3 = 0;
    char string_encoding3[STRING_LENGTH] = {'0'};
    for (cursor_enc2=0; cursor_enc2<cursor_enc2_max; cursor_enc2++){
        bool skip = false;
        if (string_encoding2[cursor_enc2] == '7' || string_encoding2[cursor_enc2] == '8'){
            skip = true;
        }

        if (!skip){
            string_encoding3[cursor_enc3] = string_encoding2[cursor_enc2];
            cursor_enc3++;
        }
        if ((cursor_enc2==0) && skip){
            first_skip = true;
        }
    }

    int cursor_out = 0;
    string_out[0] = toupper(string_in[0]);
    cursor_out += 1;

    int cursor_enc3_max = cursor_enc3;
    cursor_enc3 = first_skip ? 0:1;
    while((cursor_out < SOUNDEX_LENGTH) && (cursor_enc3 < cursor_enc3_max)){
        string_out[cursor_out] = string_encoding3[cursor_enc3];
        cursor_out++;
        cursor_enc3++;
    }
    
    while (cursor_out < SOUNDEX_LENGTH){
        string_out[cursor_out] = '0';
        cursor_out += 1;
    }
    string_out[cursor_out] = '\0';

    printf("string_in: %s\n", string_in);
    printf("string_encoding1: %s\n", string_encoding1);
    printf("string_encoding2: %s\n", string_encoding2);
    printf("string_encoding3: %s\n", string_encoding3);
    printf("string_out: %s\n", string_out);
    printf("================\n");
}


char convert_to_soundex_char(char c)
{
    switch (toupper(c)){
        case 'B':
        case 'F':
        case 'P':
        case 'V':
            return '1';

        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z':
            return '2';

        case 'D':
        case 'T':
            return '3';

        case 'L':
            return '4';

        case 'M':
        case 'N':
            return '5';

        case 'R':
            return '6';

        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
            return '7';

        case 'H':
        case 'W':
            return '8';

        default:
            return '9';
    }


}


void reset_arr(char arr[], int length)
{
    for (int i=0; i<length; i++){
        arr[i] = '\0';
    }
}


void test()
{
    assert(convert_to_soundex_char('B') == '1');
    assert(convert_to_soundex_char('H') == '8');


    char soundex[SOUNDEX_LENGTH];
    convert_to_soundex("Washington", soundex);
    assert(strcmp(soundex, "W252") == 0);

    reset_arr(soundex, SOUNDEX_LENGTH);
    convert_to_soundex("Wu", soundex);
    assert(strcmp(soundex, "W000") == 0);

    reset_arr(soundex, SOUNDEX_LENGTH);
    convert_to_soundex("DeSmet", soundex);
    assert(strcmp(soundex, "D253") == 0);

    reset_arr(soundex, SOUNDEX_LENGTH);
    convert_to_soundex("Gutierrez", soundex);
    assert(strcmp(soundex, "G362") == 0);

    reset_arr(soundex, SOUNDEX_LENGTH);
    convert_to_soundex("Pfister", soundex);
    assert(strcmp(soundex, "P236") == 0);

    reset_arr(soundex, SOUNDEX_LENGTH);
    convert_to_soundex("Jackson", soundex);
    assert(strcmp(soundex, "J250") == 0);

    reset_arr(soundex, SOUNDEX_LENGTH);
    convert_to_soundex("Tymczak", soundex);
    assert(strcmp(soundex, "T522") == 0);

    reset_arr(soundex, SOUNDEX_LENGTH);
    convert_to_soundex("Ashcraft", soundex);
    assert(strcmp(soundex, "A261") == 0);
}



// 1 B, F, P, V Labial
// 2 C, G, J, K, Q, S, X, Z Gutterals and sibilants
// 3 D, T Dental
// 4 L Long liquid
// 5 M, N Nasal
// 6 R Short liquid
// SKIP A,E,H,I,O,U,W,YVowels(andH,W,andY)areskipped
