#include<stdio.h>
#include <math.h>

int main(void){
    int n, i, Tn;

    printf("Please number of layers of triangle:");
    scanf("%i", &n);

    Tn = 0;
    for (int i=0; i<n; i++){
        Tn += i;
        printf("Tn: %i\n", Tn);
    }

    Tn = 0;
    for (int i=0; i<n; i++){
        Tn = i*(i+1)/2;
        printf("Tn: %i\n", Tn);
    }

    return 0;
    
 
    


}