#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIDELENGTH 33
#define ARRSIDELENGTH SIDELENGTH
#define NPTS 4

typedef struct {
    int rmin;
    int cmin;
    int side_length;
} Square;

void draw_square(Square* s, char canvas[][ARRSIDELENGTH]);
void draw_canvas(char canvas[][ARRSIDELENGTH]);
void find_square_rec(Square* s, char canvas[][ARRSIDELENGTH]);

int main(void)
{   
    Square square = {0, 0, SIDELENGTH-1};
    char canvas[ARRSIDELENGTH][ARRSIDELENGTH];
    memset(canvas, ' ', sizeof(canvas));
    draw_square(&square, canvas);
    find_square_rec(&square, canvas);
    draw_canvas(canvas);

}

void draw_square(Square* s, char canvas[][ARRSIDELENGTH])
{
    for (int i=0; i<=s->side_length; i++){
        canvas[s->rmin][s->cmin+i] = '*';
        canvas[s->rmin+i][s->cmin] = '*';
        canvas[s->rmin+s->side_length][s->cmin+i] = '*';
        canvas[s->rmin+i][s->cmin+s->side_length] = '*';
    }
}

void draw_canvas(char canvas[][ARRSIDELENGTH])
{
    for (int i=0; i<ARRSIDELENGTH; i++){
        for (int j=0; j<ARRSIDELENGTH; j++){
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void find_square_rec(Square* s, char canvas[][ARRSIDELENGTH])
{
    if ((s->side_length/2) > 3){
        Square s0;
        s0.rmin = s->rmin;
        s0.cmin = s->cmin + s->side_length/4;
        s0.side_length = s->side_length/2;
        draw_square(&s0, canvas);
        find_square_rec(&s0, canvas);

        Square s1;
        s1.rmin = s->rmin + s->side_length/2;
        s1.cmin = s->cmin;
        s1.side_length = s->side_length/2;
        draw_square(&s1, canvas);
        find_square_rec(&s1, canvas);

        Square s2;
        s2.rmin = s->rmin + s->side_length/2;
        s2.cmin = s->cmin + s->side_length/2;
        s2.side_length = s->side_length/2;
        draw_square(&s2, canvas);
        find_square_rec(&s2, canvas);
    }
}
