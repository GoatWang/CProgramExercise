#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define ARRLENGTH 10000
#define STRLENGTH 256
#define NOTFOUND -1

void sort_and_insert(char* line_strs[ARRLENGTH], char* line_str);
void print_line_strs(char* line_strs[ARRLENGTH]);
int search_linear(char* line_strs[ARRLENGTH], char* word);

int main(int argc, char* argv[])
{
    if (argc != 3){
        fprintf(stderr, "please specify only one file and only one word!");
        exit(0);
    }

    char* filename = (char*) calloc(1, sizeof(argv[1]));
    strcpy(filename, argv[1]);

    char* word = (char*) calloc(1, sizeof(argv[2]));
    strcpy(word, argv[2]);

    char line_str[STRLENGTH];
    char* line_strs[ARRLENGTH];
    FILE* fp = fopen(filename, "r");
    int cursor = 0;
    while (fgets(line_str, STRLENGTH, fp) != NULL){
        int length = strlen(line_str) - 1;
        line_str[length] = '\0';
        sort_and_insert(line_strs, line_str);
        cursor += 1;
    }

    print_line_strs(line_strs);
    int result = search_linear(line_strs, word);
    printf("result: %i\n", result);
    fclose(fp);

}

void print_line_strs(char* line_strs[ARRLENGTH])
{
    int cursor = 0;
    while (line_strs[cursor] != NULL){
        printf("%i. %s\n", cursor, line_strs[cursor]);
        cursor += 1;
    }
}

void sort_and_insert(char* line_strs[ARRLENGTH], char* line_str)
{
    int distance;
    int cursor = 0;
    int target_cursor=0;
    while (line_strs[cursor] != NULL){
        distance = strcmp(line_str, line_strs[cursor]);
        cursor += 1;
        if (distance>0){
            target_cursor = cursor;
        }
    };

    int arr_length = 0;
    while (line_strs[arr_length] != NULL){
        arr_length += 1;
    }

    if (target_cursor == arr_length){
        line_strs[target_cursor] = (char*) malloc(sizeof(char) * sizeof(line_str));
        strcpy(line_strs[target_cursor], line_str);
    }
    else{
        int mv_cursor = arr_length;
        while(mv_cursor>target_cursor){
            line_strs[mv_cursor] = (char*) malloc(sizeof(char) * sizeof(line_strs[mv_cursor-1]));
            strcpy(line_strs[mv_cursor], line_strs[mv_cursor-1]);
            mv_cursor -= 1;
        }
        line_strs[mv_cursor] = (char*) malloc(sizeof(char) * sizeof(line_str));
        strcpy(line_strs[mv_cursor], line_str);
    }
}

int search_linear(char* line_strs[ARRLENGTH], char* word)
{
    int cursor = 0;
    while (line_strs[cursor] != NULL){
        if (strcmp(word, line_strs[cursor]) == 0){
            return cursor;
        }
        cursor += 1;
    }
    return NOTFOUND;
}