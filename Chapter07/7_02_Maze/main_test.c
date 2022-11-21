#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define LINELENGTH 128

typedef struct {
    int row_idx;
    int col_idx;
} Point;

void find_entrance(Point* entrance);

int main(void)
{
    Point* entrance = NULL;
    entrance = (Point*) calloc(1, sizeof(Point));
    printf("entrance: %d, %d\n", (int)entrance->row_idx, (int)entrance->col_idx);
    find_entrance(entrance);
    printf("entrance: %d, %d\n", (int)entrance->row_idx, (int)entrance->col_idx);
    printf("entrance is NULL: %d\n", entrance == NULL);
}

void find_entrance(Point* entrance)
{
    entrance->row_idx = 1;
    entrance->col_idx = 1;
    printf("entrance: %d, %d\n", (int)entrance->row_idx, (int)entrance->col_idx);
}
