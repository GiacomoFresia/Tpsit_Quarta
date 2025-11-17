//  myLib.c

void errore(char* s, int n) {
    printf("Errore %d in %s (%s) \n (exiting with error level %d)\n", errno, s, strerror(errno), n);
    exit(n);
}

char* readLine(FILE* f) {
    char buffer[MAX_STRING_LENGTH];
    int i;
    for(i = 0;
        ((buffer[i]=fgetc(f))!='\n') && (buffer[i]!=EOF);
        i++) { }  
    buffer[i] = '\0';
    return (i==0)? NULL: strdup(buffer);
}

// ATTENZIONE: Altera la stringa originale con strtok()
char** splitString(char* s, char separator) {
    char** tokens = NULL;
    char delimiter[2] = {separator, '\0' };
    int count = 0;
    char* token = strtok(s, delimiter);
    while(token != NULL) { //fino a che trova sottostringhe le restituisce (NULL)
        // realloc(): come malloc(), ma rialloca la memoria copiando i vecchi dati
        tokens = realloc(tokens, sizeof(char*) * (count + 1));
        tokens[count] = strdup(token);  //mette la prima sottostringa
        count++;
        token = strtok(NULL, delimiter);
    }
    tokens = realloc(tokens, sizeof(char*) * (count + 1));
    tokens[count] = NULL; // Terminatore
    return tokens;
}

void disposeStringArray(char** arr) {
    for(char** temp = arr; *temp; temp++) {   //*temp = quello che è puntato da temp è diverso da 0?
        free(*temp);
    }
    free(arr);
}

int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}