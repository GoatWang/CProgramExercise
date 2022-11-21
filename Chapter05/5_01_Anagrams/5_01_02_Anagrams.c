#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
#include<time.h>
#include "5_01_01_Anagrams.h"
#define LENGTH 256

//TODO: how to free memory of linked list
struct matched_strings{
    char s[LENGTH];
    struct matched_strings* next;
};
typedef struct matched_strings matched_strings;

struct list_matched_strings{
    struct matched_strings* ms;
    struct list_matched_strings* next;
};
typedef struct list_matched_strings list_matched_strings;

void test();
void append_string(char* str_dst, char* str_src);
void matched_strings_2str(matched_strings* ms, char str[LENGTH]);
void list_matched_strings_2str(list_matched_strings* lms, char str[LENGTH]);
matched_strings* append_head_ms(matched_strings* ms, char* str);
list_matched_strings* append_head_lms(list_matched_strings* lms, matched_strings* ms);
list_matched_strings* check_append_strings(char* str, list_matched_strings* lms);
void print_matched_strings(matched_strings* ms);
void print_list_matched_strings(list_matched_strings* lms);

int main(int argc, char* argv[])
{
    test();

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // FILE* fp = fopen("./Words/34words.txt", "r");
    FILE* fp = fopen("./test.txt", "r");
    if (fp == NULL){
        fprintf(stderr, "Cannot read the file!");
        exit(0);
    }

    char strfpline[LENGTH];
    int line_id = 0;
    list_matched_strings* lms;
    lms = calloc(1, sizeof(list_matched_strings));
    while (fgets(strfpline, LENGTH, fp) != NULL){
        int length_strfp = strlen(strfpline) - 1;
        strfpline[length_strfp] = '\0';
        if (line_id == 0){
            matched_strings* ms;
            ms = calloc(1, sizeof(matched_strings));
            strcpy(ms->s, strfpline);
            ms->next = NULL;
            lms->ms = ms;
            lms->next = NULL;
        }
        else{
            lms = check_append_strings(strfpline, lms);
        }
        line_id += 1;
    }


    print_list_matched_strings(lms);


    fclose(fp);


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time used: %lf\n", cpu_time_used);
    return 1;
}

// TODO: is it a problem to create function like this?
list_matched_strings* check_append_strings(char* str, list_matched_strings* lms)
{
    list_matched_strings *lms_start;
    lms_start = calloc(1, sizeof(list_matched_strings));
    lms_start = lms;

    bool matched = false;

    do{
        if (char_matching(str, lms->ms->s)){
            lms->ms = append_head_ms(lms->ms, str);
            matched = true;
        }
        lms = lms->next;
    }while (lms != NULL);

    if (!matched){
        matched_strings* ms_new; // TODO: why can't I init with {str, NULL}
        ms_new = calloc(1, sizeof(matched_strings));
        strcpy(ms_new->s, str); // TODO: ms_new->s = str;
        ms_new->next = NULL; 
        lms_start = append_head_lms(lms_start, ms_new);
    }
    return lms_start;
}

list_matched_strings* append_head_lms(list_matched_strings* lms, matched_strings* ms)
{
    list_matched_strings *lms_new;
    lms_new = calloc(1, sizeof(list_matched_strings));
    lms_new->ms = ms;
    lms_new->next = lms;
    return lms_new;
}

// TODO: is it possible to append element at the head of a linkedlist?
matched_strings* append_head_ms(matched_strings* ms, char* str)
{   
    matched_strings *ms_new;
    ms_new = calloc(1, sizeof(matched_strings));
    strcpy(ms_new->s, str);
    ms_new->next = ms;
    return ms_new;
}

void append_string(char str_dst[], char str_src[])
{
    int cursor_dst = strlen(str_dst);
    for (int i=0; i<strlen(str_src); i++){
        str_dst[cursor_dst] = str_src[i];
        cursor_dst += 1;
    }
}

void matched_strings_2str(matched_strings* ms, char str[LENGTH])
{
    memset(str, 0, LENGTH);
    if(ms != NULL){
        do{
            append_string(str, ms->s);
            append_string(str, " -> ");
            ms = ms->next;
        }while(ms != NULL);
    }
    append_string(str, "NULL\0");
}

void list_matched_strings_2str(list_matched_strings* lms, char str[LENGTH])
{
    memset(str, 0, LENGTH);
    if(lms != NULL){
        do{
            char str_ms[LENGTH];
            matched_strings_2str(lms->ms, str_ms);
            append_string(str, str_ms);
            append_string(str, "\n");
            lms = lms->next;
        }while(lms != NULL);
    }
    append_string(str, "NULL\0");
}

void print_matched_strings(matched_strings* ms)
{
    bool first_str = true;
    if(ms != NULL){
        do{
            if (!first_str){
                printf(", ");
            }
            printf("%s", ms->s);
            ms = ms->next;
            first_str = false;
        }while(ms != NULL);
    }
    printf("\n");

}

void print_list_matched_strings(list_matched_strings* lms)
{
    if(lms != NULL){
        do{
            print_matched_strings(lms->ms);
            lms = lms->next;
        }while(lms != NULL);
    }
}

void test()
{
    char str[LENGTH];
    matched_strings ms1 = {"123", NULL};
    matched_strings ms2 = {"132", &ms1};
    matched_strings ms3 = {"312", &ms2};
    matched_strings_2str(&ms3, str);
    assert(strcmp(str, "312 -> 132 -> 123 -> NULL") == 0);

    matched_strings* ms4_p;
    ms4_p = append_head_ms(&ms3, "321");
    matched_strings_2str(ms4_p, str);
    assert(strcmp(str, "321 -> 312 -> 132 -> 123 -> NULL") == 0);

    list_matched_strings lms1 = {&ms1, NULL};
    list_matched_strings* lms2_p = append_head_lms(&lms1, &ms2);
    list_matched_strings_2str(lms2_p, str);
    assert(strcmp(str, "132 -> 123 -> NULL\n123 -> NULL\nNULL") == 0);


}