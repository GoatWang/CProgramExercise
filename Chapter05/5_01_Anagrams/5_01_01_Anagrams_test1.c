#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#define CHARSTART 'a'
#define CHARLENGTH 26
#define STRLENGTH 256
#define ARRLENGTH 256

bool same_chars(char* str1, char* str2);
void make_hist(char* str, int hist[CHARLENGTH]);
void test();

int main(int argc, char* argv[])
{
    test();
    if (argc != 3){
        fprintf(stderr, "please specify only one filename and only one word");
        exit(0);
    }

    // char* word = (char*) calloc(1, strlen(argv[2]) * sizeof(char));
    // strcpy(word, argv[2]);

    // int cursor = 0;
    char* str_temp;
    str_temp = malloc(1 * sizeof(char));
    char line_str[STRLENGTH];
    // char* same_strs[ARRLENGTH];
    char** same_strs;
    same_strs = malloc((1) * sizeof(*same_strs));
    FILE* fp = fopen(argv[1], "r");
    int arrlength = 0;
    while (fgets(line_str, STRLENGTH, fp) != NULL){
        int length = strlen(line_str)-1;
        if (line_str[length] == '\n'){
            line_str[length] = '\0';
        }
        same_strs = realloc(same_strs, (arrlength+1) * sizeof(*same_strs));
        // str_temp = realloc(str_temp, strlen(line_str) * sizeof(char));
        // strcpy(str_temp, line_str);
        // *(same_strs+arrlength) = realloc(*(same_strs+arrlength), strlen(line_str) * sizeof(char));
        // strcpy(*(same_strs+arrlength), line_str);

        str_temp = realloc(str_temp, strlen(line_str) * sizeof(char));
        strcpy(str_temp, line_str);
        *(same_strs+arrlength) = str_temp;
    

        // same_strs += 1;
        str_temp = NULL;
        arrlength += 1;

        // if (same_chars(line_str, word)){
        //     same_strs[cursor] = (char*) calloce(1, strlen(line_str) * sizeof(char));
        // }
        
        
    }

    int cursor = 0;
    while (same_strs[cursor] != NULL){
        printf("%s\n", same_strs[cursor]);
        cursor += 1;
    }


    fclose(fp);
}

void make_hist(char* str, int hist[CHARLENGTH])
// void make_hist(char* str, int hist[])
// void make_hist(char* str, int* hist)
{
    memset(hist, 0, CHARLENGTH);

    int cursor = 0;
    while (str[cursor] != '\0'){
        hist[(str[cursor] - CHARSTART)] += 1;
        cursor += 1;
    }
}

bool hist_cmp(int* hist1, int* hist2)
{
    for (int i=0; i< CHARLENGTH; i++){
        if (hist1[i] != hist2[i]){
            return false;
        }
    }
    return true;
}

bool same_chars(char* str1, char* str2)
{
    // be sure that the arr init in the function cannot be taken out
    // int char_hist1[CHARLENGTH]; 
    // int char_hist2[CHARLENGTH];
    int char_hist1[10000]; 
    int char_hist2[10000];
    // int* char_hist1 = (int*) calloc(1, 1000*sizeof(int));
    // int* char_hist2 = (int*) calloc(1, CHARLENGTH*sizeof(int));
    make_hist(str1, char_hist1);
    make_hist(str2, char_hist2);
    return hist_cmp(char_hist1, char_hist1);
}

void test()
{
    // test make_hist
    int char_hist[CHARLENGTH] = {0};
    int char_hist_answer[CHARLENGTH] = {0};
    for (int i=0; i<CHARLENGTH; i++){
        if (i<3){
            char_hist_answer[i] += 1;  
        }
    }
    make_hist("abc", char_hist);
    assert(hist_cmp(char_hist, char_hist_answer));

    // test same_chars
    assert(same_chars("abc", "cba"));

}
