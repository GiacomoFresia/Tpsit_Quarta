//Scrivere un programma in C che crei un duplicato del suo sorgente

#include <stdio.h>     //.h sta per header   istruzioni per il precompilatore // Header = riferimenti alla libreria
#define FILE_SOURCE “fileSorgente.c”
#define FILE_OUT "copia.c"

int main(int argc, char*argv[]){    //argc dice quanti elementi ci sono (argc è la dimensione di argv)
    FILE *originale, *copia;
    originale = fopen(“FILE_SOURCE”, “r”);
    if(originale == NULL){
        printf(“Impossibile aprire il file”); return 0;  
    }
    copia = fopen("FILE_OUT", "w");
    if(copia == NULL){
        printf("Impossibile aprire il file"); return 0;
    }
    char c;
    while((c = fgetc(originale)) != EOF){
        fputc(c, copia);
    }
    fclose(originale);
    fclose(copia);
}