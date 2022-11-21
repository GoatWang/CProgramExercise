#include<stdio.h>
#include<string.h>
#define SEQLENGTH 4

int main(int argc, char* argv[])
{
    if (argc != 3){
        fprintf(stderr, 'Please sepcify two words to crate the word ladder.');
    }


    // create_word_ladder(argv[1], argv[2]);

}


void create_word_ladder(char* word1, char* word2, int seq[SEQLENGTH]) 
{

}


void create_word_ladder_permutation(char* word1, char* word2)
{
    if (strlen(word1) != strlen(word2)){
        fprintf(stderr, "Length of word1 and word2 should be the same");
    }

    int seq[SEQLENGTH] = {0, 1, 2, 3};
    
   

}