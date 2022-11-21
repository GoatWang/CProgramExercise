#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#define LENGTH 256
#define CSEC (double)(CLOCKS_PER_SEC)
#define TARGETWORD "love"

struct node{
    char word[LENGTH];
    struct node* next;
};
typedef struct node node;

node* insert_linkedlist(node* head, char*str);
void write_linkedlist(node* head, char* str, int num_str);
void print_linkedlist(node* head);
int linear_search(node* head, char* target_word);
void test();

int main(int argc, char* argv[])
{
    test();
    if (argc != 2){
        fprintf(stderr, "Please specify one filename only.\n");
        exit(0);
    }

    clock_t c1 = clock();
    node* head = NULL;
    char line_str[LENGTH];
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "Please specify a valid filename.\n");
        exit(0);
    }
    while(fgets(line_str, LENGTH, fp) != NULL){
        // raplace \n with '\0' (didn't deal with \r\n) 
        int length = strlen(line_str)-1;
        line_str[length] = '\0';
        head = insert_linkedlist(head, line_str);
    }
    fclose(fp);
    clock_t c2 = clock();

    clock_t c3 = clock();
    int target_idx = linear_search(head, TARGETWORD);
    clock_t c4 = clock();

    char output_str[LENGTH];
    write_linkedlist(head, output_str, 10);
    printf("top 10 strings: %s\n", output_str);
    printf("time (building list): %lf\n", ((double)(c2 - c1))/CSEC);
    printf("target_idx (%s): %i\n", TARGETWORD, target_idx);
    printf("time (search): %lf\n", ((double)(c4 - c3))/CSEC);
    return 0;
}

node* insert_linkedlist(node* head, char*str)
{
    node* word_node;
    word_node = (node*) calloc(1, sizeof(node));
    strcpy(word_node->word, str);

    node* curr_node;
    curr_node = (node*) calloc(1, sizeof(node));

    node* prev_node;
    prev_node = (node*) calloc(1, sizeof(node));

    if (head == NULL){
        // insert first element 
        head = (node*) calloc(1, sizeof(node));
        head = word_node;
        // curr_node = head;
    }
    else{
        curr_node = head;
        bool is_head = true;
        bool inserted = false;
        while(curr_node != NULL){
            int dist = strcmp(word_node->word, curr_node->word);
            if (is_head && (dist < 0)){
                // insert at head
                word_node->next = curr_node;
                head = word_node;
                inserted = true;
            }
            else if (!inserted && (dist < 0)){
                // insert at middle
                word_node->next = curr_node;
                prev_node->next = word_node;
                inserted = true;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
            is_head = false;
        }
        if (!inserted){
            // insert at tail
            prev_node->next = word_node;
        }
    }
    return head;
}

void appends_str2_to_str1(char* str1, char* str2){
    int cursor_str1 = strlen(str1);
    int cursor_str2 = 0;
    for (int i=0; i<(int)strlen(str2); i++){
        str1[cursor_str1] = str2[cursor_str2];
        cursor_str1 += 1;
        cursor_str2 += 1;
    }
}

void write_linkedlist(node* head, char* str, int num_str)
{
    int num = 0;
    memset(str, 0, LENGTH);
    while((head != NULL) && (num < num_str)){
        appends_str2_to_str1(str, head->word);
        appends_str2_to_str1(str, " => ");
        head = head->next;
        num += 1;
    }

    if (head == NULL){
        appends_str2_to_str1(str, "null");
    }
    else{
        appends_str2_to_str1(str, "...");
    }
}

void print_linkedlist(node* head)
{
    while(head != NULL){
        printf("%s\n", head->word);
        head = head->next;
    }
}

int linear_search(node* head, char* target_word)
{
    int target_idx = 0;
    node* curr_node = (node*) calloc(1, sizeof(node));
    curr_node = head;
    while (curr_node != NULL){
        if (strcmp(curr_node->word, target_word) == 0){
            return target_idx;
        }
        curr_node = curr_node->next;
        target_idx += 1;
    }

    return -1;
}

void test()
{   
    node* head;
    char result[LENGTH];
    char test_str[LENGTH];

    // Insert at middle
    node test_node4 = {"ddd", NULL};
    node test_node2 = {"bbb", &test_node4};
    node test_node1 = {"aaa", &test_node2};
    strcpy(test_str, "ccc");
    head = insert_linkedlist(&test_node1, test_str);
    write_linkedlist(head, result, 4);
    assert(strcmp(result, "aaa => bbb => ccc => ddd => null") == 0);

    // Insert at tail
    node test_node7 = {"ggg", NULL};
    node test_node6 = {"fff", &test_node7};
    node test_node5 = {"eee", &test_node6};
    strcpy(test_str, "hhh");
    head = insert_linkedlist(&test_node5, test_str);
    write_linkedlist(head, result, 4);
    assert(strcmp(result, "eee => fff => ggg => hhh => null") == 0);

    // Insert at head
    node test_node12 = {"lll", NULL};
    node test_node11 = {"kkk", &test_node12};
    node test_node10 = {"jjj", &test_node11};
    strcpy(test_str, "iii");
    head = insert_linkedlist(&test_node10, test_str);
    write_linkedlist(head, result, 4);
    assert(strcmp(result, "iii => jjj => kkk => lll => null") == 0);

    // insert first element 
    node* test_node13 = NULL;
    strcpy(test_str, "mmm");
    head = insert_linkedlist(test_node13, test_str);
    write_linkedlist(head, result, 1);
    assert(strcmp(result, "mmm => null") == 0);

    // test linear_search
    node test_node17 = {"dddd", NULL};
    node test_node16 = {"cccc", &test_node17};
    node test_node15 = {"bbbb", &test_node16};
    node test_node14 = {"aaaa", &test_node15};
    assert(linear_search(&test_node14, "aaaa") == 0);
    assert(linear_search(&test_node14, "bbbb") == 1);
    assert(linear_search(&test_node14, "cccc") == 2);
    assert(linear_search(&test_node14, "dddd") == 3);

}

