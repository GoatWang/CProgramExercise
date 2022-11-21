#include "neillsdl2.h"
#include "math.h"

// #define TRIANGLESIZE 20
// #define MILLISECONDDELAY 20
#define MILLISECONDDELAY 20

typedef struct {
    int xys[6];
} Triangle;

void find_next_rec(Triangle* t0, SDL_Simplewin* sw);
void draw_triangle(SDL_Simplewin* sw, Triangle* t);

int main(void)
{
    SDL_Simplewin sw;
    Neill_SDL_Init(&sw);

    // do{
    SDL_Delay(MILLISECONDDELAY);
    SDL_SetRenderDrawColor(sw.renderer, 
                            rand()%SDL_8BITCOLOUR, 
                            rand()%SDL_8BITCOLOUR, 
                            rand()%SDL_8BITCOLOUR, 
                            SDL_ALPHA_OPAQUE);

    int length = 512;
    int x = (WWIDTH-length)/2;
    int y = (WHEIGHT+length)/2;
    int x1, y1, x2, y2, x3, y3;
    x1 = x;
    y1 = y;
    x2 = x+length/2;
    y2 = y-(pow(3,1/2)*length/2);
    x3 = x+length;
    y3 = y;
    Triangle t0 = {{x1, y1, x2, y2, x3, y3}};
    draw_triangle(&sw, &t0);
    find_next_rec(&t0, &sw);
    // }while(!sw.finished);

   /* Clear up graphics subsystems */
   SDL_Quit();
   atexit(SDL_Quit);
   return 0;
}

void find_next_rec(Triangle* t0, SDL_Simplewin* sw)
{
    if (sw->finished){
        return ;
    }

    int x01, y01, x02, y02, x03, y03;
    x01 = t0->xys[0];
    y01 = t0->xys[1];
    x02 = t0->xys[2];
    y02 = t0->xys[3];
    x03 = t0->xys[4];
    y03 = t0->xys[5];

    int x11, y11, x12, y12, x13, y13;
    x11 = x01;
    y11 = y01;
    x12 = (x01+x02)/2;
    y12 = (y01+y02)/2;
    x13 = (x01+x03)/2;
    y13 = (y01+y03)/2;
    Triangle t1 = {{x11, y11, x12, y12, x13, y13}};

    int x21, y21, x22, y22, x23, y23;
    x21 = (x01+x02)/2;
    y21 = (y01+y02)/2;
    x22 = x02;
    y22 = y02;
    x23 = (x02+x03)/2;
    y23 = (y02+y03)/2;
    Triangle t2 = {{x21, y21, x22, y22, x23, y23}};

    int x31, y31, x32, y32, x33, y33;
    x31 = (x01+x03)/2;
    y31 = (y01+y03)/2;
    x32 = (x02+x03)/2;
    y32 = (y02+y03)/2;
    x33 = x03;
    y33 = y03;
    Triangle t3 = {{x31, y31, x32, y32, x33, y33}};


    if ((x03 - x01) / 2 > 3){
        draw_triangle(sw, &t1);
        draw_triangle(sw, &t2);
        draw_triangle(sw, &t3);

        find_next_rec(&t1, sw);
        find_next_rec(&t2, sw);
        find_next_rec(&t3, sw);
    }

}

void draw_triangle(SDL_Simplewin* sw, Triangle* t)
{    
    int x1, y1, x2, y2, x3, y3;
    x1 = t->xys[0];
    y1 = t->xys[1];
    x2 = t->xys[2];
    y2 = t->xys[3];
    x3 = t->xys[4];
    y3 = t->xys[5];

    SDL_RenderDrawLine(sw->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(sw->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(sw->renderer, x3, y3, x1, y1);

    Neill_SDL_UpdateScreen(sw);
    Neill_SDL_Events(sw);
}


