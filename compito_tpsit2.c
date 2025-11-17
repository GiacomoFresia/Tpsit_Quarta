//Scrivere un programma in C che stampi tutti i numeri interi inseriti da linea di comando, ordinati dal più piccolo al più grande

#include <stdio.h>
#include <stdlib.h>

void leggi_numeri(int n, char *argv[], int vett[]) {
    for (int k = 0; k < n; k++) {
        if (sscanf(argv[k + 1], "%d", &vett[k]) != 1) exit(1);
    }
}

void scambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int vett[], int n){
    int k, sup;
    for (sup = n-1; sup > 0; sup--){
        for (k = 0; k < sup ; k++){
            if (vett[k] > vett[k+1]){
                scambio( &vett[k],&vett[k+1]);
            }
        }
    }
}

void stampa(int n, int vett[]) {
    for (int k = 0; k < n; k++){      
    printf("%d ", vett[k]);
    }
}

int main(int argc, char *argv[]){
    int n = argc - 1;
    int numeri[n];
    leggi_numeri(n, argv, numeri);
    bubble(numeri, n);
    printf("Numeri ordinati: ");
    stampa(n, numeri);
    return 0;
}