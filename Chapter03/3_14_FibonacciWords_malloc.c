#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>
#include <stdlib.h>

// difference between malloc and char string[100]
// https://stackoverflow.com/questions/58154387/the-difference-between-char-string100-and-char-string-malloc100
bool fibword_str(int n);


int main(void)
{
    // fibword_str(5);
    int answer[69] = {0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1};
    for (int i=1; i<30; i++){
        int result = (int) fibword_str(i);
        printf("%ith number\n", i);
        printf("answer: %i\n", answer[i-1]);
        printf("predict: %i\n", result);
        printf("=============\n");
        assert(result == answer[i-1]);
    }
    
}

bool fibword_str(int n)
{   
    char *Skm2;
    Skm2 = (char*) malloc(2);
    char *Skm1;
    Skm1 = (char*) malloc(3);
    char *Sk;
    Sk = (char*) malloc(4);

    strcpy(Skm2, "0");
    strcpy(Skm1, "01");
    int length = 0;
    while (length < n){
        int lengthm2 = strlen(Skm2);
        int lengthm1 = strlen(Skm1);
        length = (lengthm1) + (lengthm2);

        Sk = (char *) realloc(Sk, (length+1) * sizeof(char)); 
        // strcpy(Sk, strcat(Skm1, Skm2)); // this doesn't work since the strcpy will directly change the length of Skm1
        for (int n=0; n<length; n++){
            for (int n1=0; n1<lengthm1; n1++){
                Sk[n] = Skm1[n1];
                n++;
            }
            for (int n2=0; n2<lengthm2; n2++){
                Sk[n] = Skm2[n2];
                n++;
            }
        }
        Skm2 = (char *) realloc(Skm2, (lengthm1+1) * sizeof(char));
        Skm1 = (char *) realloc(Skm1, (length+1) * sizeof(char));
        strcpy(Skm2, Skm1);
        strcpy(Skm1, Sk);
        // printf("Skm2: %s\n", Skm2);
        // printf("Skm1: %s\n", Skm1);
        // printf("Sk: %s\n", Sk);
        // printf("=============\n");
    }

    bool result = (bool) (Sk[n-1] == '1');
    free(Skm2);
    free(Skm1);
    free(Sk);

    return result;
}