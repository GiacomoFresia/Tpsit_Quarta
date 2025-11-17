//Scrivere un programma in C che stampi tutti i parametri passati da linea di comando

#include <stdio.h>

int main(int argc, char *argv[]){               //argc è il numero di argomenti //argv è il vettore di stringhe
    printf("Numero di argomenti: %d\n", argc);
    for (int k = 0; k < argc; k++){
        printf("%d argomento: %s\n", k, argv[k]);
    }
    return 0;
}