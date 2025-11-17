// Creare una matrice, stampare gli elementi con un doppio for, poi fare la free (for)

#include <stdio.h>
#include <stdlib.h>
#define DIM1 5
#define DIM2 8

int main(){
    int **a;
    a = (int **) malloc(DIM1 * DIM2 * sizeof(int));
    for(int k = 0; k < DIM1; k++){
        for(int j = 0; j < DIM2; j++){
            **a = k + j;
            printf("%d ", **a);
        }
        printf("\n");
    }
    free(a);
    return 0;
}