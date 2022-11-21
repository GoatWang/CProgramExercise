#include<stdio.h>
#include<assert.h>

int check_triange(double a, double b, double c);

int main(void){

    assert(check_triange(-999, 0, 0) == 0);
    assert(check_triange(1, 2, 3) == 0);
    
    // int a, b, c
    // printf("Please input 3 sides of a triangle:")
    // if (scanf("%i%i%i", &a, &b, &c) != 3){
    //     check_triange(double a, double b, double c)
    // }

    return 0;
}


int check_triange(double a, double b, double c){
    if ((a < 0) || (b < 0) || (c < 0)){
        printf("a, b, c = %f, %f, %f\n", a, b, c);
        printf("triangle sides should not less than zero!\n");
        return 0;
    }
    if ((a + b <= c) || (a + b <= c) || (a + b <= c)){
        printf("a, b, c = %f, %f, %f\n", a, b, c);
        printf("sum of any two sides of triangleshould be bigger than thirs side!\n");
        return 0;
    }
    return 1;
}
