#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#define LARGESTRING 1000


void mystrcpy(char* s_dst, const char* s_src, int length);
void strmerge(const char* s1, const char* s2, char*s3);

int main(void) 
{
    char s[LARGESTRING];

    strmerge("Hello World!", "World! & Everyone.", s); 
    printf("answer: %s\n", s);
    printf("=============\n");
    assert(strcmp(s, "Hello World! & Everyone.")==0);
    memset(s, 0, sizeof(s));

    strmerge("The cat sat", "sat on the mat.", s); 
    printf("answer: %s\n", s);
    printf("=============\n");
    assert(strcmp(s, "The cat sat on the mat.")==0);
    memset(s, 0, sizeof(s));

    strmerge("The cat sat on the mat", "The cat sat on the mat.", s); 
    printf("answer: %s\n", s);
    printf("=============\n");
    assert(strcmp(s, "The cat sat on the mat.")==0);
    memset(s, 0, sizeof(s));

    strmerge("One ", "Two", s); 
    printf("answer: %s\n", s);
    printf("=============\n");
    assert(strcmp(s, "One Two")==0);
    memset(s, 0, sizeof(s));

    strmerge("", "The cat sat on the mat.", s);
    printf("answer: %s\n", s);
    printf("=============\n");
    assert(strcmp(s, "The cat sat on the mat.")==0);
    memset(s, 0, sizeof(s));

    strmerge("The cat sat on the mat.", "", s); 
    printf("answer: %s\n", s);
    printf("=============\n");
    assert(strcmp(s, "The cat sat on the mat.")==0);
    memset(s, 0, sizeof(s));

    // memset(s, 0, sizeof(s));
    // printf("=============\n");
    // assert(strcmp(s, "123412341234")==0);

    strmerge("123456789", "5678912345", s); 
    printf("answer: %s\n", s);
    printf("=============\n");
    assert(strcmp(s, "12345678912345")==0);
    memset(s, 0, sizeof(s));
}


void mystrcpy(char* s_dst, const char* s_src, int length)
{
    for (int i=0; i<length; i++){
        s_dst[i] = s_src[i];
    }
}

void strmerge(const char* s1, const char* s2, char* s3)
{
    // printf("s1_tail: %s\n", &s1[3]);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int min_len = l1 < l2 ? l1 : l2;

    // char* s1_tail;
    // s1_tail = malloc(2 * sizeof(char));
    // char* s2_head;
    // s2_head = malloc(2 * sizeof(char));

    int same_num_of_char = 0;
    for (int num_char=1; num_char<(min_len+1); num_char++){
        // s1_tail = realloc(s1_tail, (num_char+1) * sizeof(char));
        // s2_head = realloc(s2_head, (num_char+1) * sizeof(char));
        // mystrcpy(s1_tail, &s1[l1-num_char], num_char);
        // mystrcpy(s2_head, s2, num_char);
        // if (strncmp(s1_tail, s2_head, num_char) == 0){
        if (strncmp(&s1[l1-num_char], s2, num_char) == 0){
            same_num_of_char = num_char;
            // printf("s1_tail: %s\n", s1_tail);
            // printf("s2_head: %s\n", s2_head);
            break;
        }
        
    }
    // free(s1_tail);
    // free(s2_head);


    int cursor = 0;
    for (int i=0; i<(l1-same_num_of_char); i++){
        s3[cursor] = s1[i];
        cursor++;
    }

    for (int i=0; i<l2; i++){
        s3[cursor] = s2[i];
        cursor++;
    }
    // printf("s2: %s\n", s2);

}



