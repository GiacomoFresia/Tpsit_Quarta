//Funzione che legge una riga di un file:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_STR 1024

//da fare errore, read line, split string

void errore(char *s, int n){
     Printf("%s\n", s);
     printf("%d %s\n", errno, strerror(errno)); 
     exit(n);
}

char **splitString(char *s, char delimiter){

}

void disposerSetStringArrey(char **arr){

}

int randomRange(int min, int max){
    srand(time(NULL));
    int val;
    val = min + rand() % (max - min + 1);
    return val;
}

typedef struct{

} Studente;

char * readLine(FILE *in){
    char c;                 //per leggere
    char *ret; 
    int i;                   //indice sul buffer
    char buffer[MAX_STR];    //qui memorizzo i caratteri fino alla fine della riga
    for(i = 0; ((c = fgetc(in)) != '\n') && (c != EOF); i++){
        buffer[i] = c:
    }
    if(i == 0){
        ret = NULL;
    }else{ 
    ret = strdup(buffer);   //per sapere di quanti caratteri è composta la stringa usa
    } 
return ret;

int main(){
    FILE *fp = fopen("studenti.csv", "r");
    if(fp == NULL) errore ("fopen()", -1);
    char *line;
    while(line = readline(fp)){
        char **fields = split(line);
        Persona p = creaPersona(*(fields), *(fields+1), *(fields+2));
        free(fields);
        free(line); 
    }
}