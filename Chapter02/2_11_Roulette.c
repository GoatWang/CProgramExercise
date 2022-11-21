#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef enum {odd, even, number} bettype;
bettype read_user_bettype(char c);
bool is_odd(int x);
void test();
int main(void)
{
    test();

    int answer;
    int round = 0;
    int user_input_bettype, user_input_number;
    bettype user_bet_type;

    printf("(round %i) please input your bet (0 for odd, 1 for even, or 2 for particular number): ", round);
    while (scanf("%i", &user_input_bettype) == 1){
        answer = rand() % 36;
        user_bet_type = read_user_bettype(user_input_bettype);

        if (answer == 0){
            printf("answer: %i\n", answer);
            printf("you lose the game!\n");
        }
        else if (user_bet_type == odd){
            printf("answer: %i\n", answer);
            if (is_odd(answer)){
                printf("you win 2 to 1!\n");
            }
            else{
                printf("you lose the game!\n");
            }
        }
        else if (user_bet_type == even){
            printf("answer: %i\n", answer);
            if (!is_odd(answer)){
                printf("you win 2 to 1!\n");
            }
            else{
                printf("you lose the game\n!");
            }
        }
        else{ //user_bet_type == number
            printf("please input your bet number: ");
            if (scanf("%i", &user_input_number) == 1){
                printf("answer: %i\n", answer);
                if (user_input_number == answer){
                    printf("you win 35 to 1!\n");
                }
                else{
                    printf("you lose the game!\n");
                }
            }
        }

        printf("\n");
        printf("\n");
        round += 1;
        printf("(round %i), please input your bet ('o' for odd, 'e' for even and number to guess the specific number): ", round);

    }

    return 0;
}

bettype read_user_bettype(char c)
{
    if (c == 0){
        return odd;
    }
    else if (c == 1){
        return even;
    }
    else if (c == 2){
        return number;
    }
    else{
        return number;
    }
}

bool is_odd(int x)
{
    if (x % 2 == 1){
        return true;
    }
    else{
        return false;
    }
}

void test()
{
    assert(read_user_bettype(0) == odd); // 111
    assert(read_user_bettype(1) == even); // 101
    assert(read_user_bettype(2) == number);
    assert(is_odd(1) == true);
    assert(is_odd(10) == false);
}
