#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int g, m, a
} Date;

typedef struct {
    Date *d;
    char *nome;
} Person;

Date *createDate(int g, int m, int a){
    Date *d = (Date *) malloc(sizeof(Date));
    d->g = g;
    d->m = m;
    d->a = a;
    return d;
}

void killDate(Date *d){
    free(d);
}

Person *createPerson(Date *d, char *nome){
    Person *p = (Person *) malloc(sizeof(Person));
    p->d = createDate(d->g, d->m, d->a); // duplica la data
    p->nome = strdup(nome);               // duplica la stringa
    return p;
}

void setPerson(Person *p, Date *d, char *nome){
    killDate(p->d);                       // libera vecchia data
    p->d = createDate(d->g, d->m, d->a);  // copia nuova data
    free(p->nome);                         // libera vecchia stringa
    p->nome = strdup(nome);                // copia nuova stringa
}

void killPerson(Person *p){
    killDate(p->d);
    free(p->nome);
    free(p);
}

int main() {
    Date d1 = {1, 1, 2000};
    Person *p = createPerson(&d1, "Mario");
    printf("Nome: %s, Data: %d/%d/%d\n", p->nome, p->d->g, p->d->m, p->d->a);
    Date d2 = {2, 2, 2025};
    setPerson(p, &d2, "Luigi");
    printf("Nome: %s, Data: %d/%d/%d\n", p->nome, p->d->g, p->d->m, p->d->a);
    killPerson(p);
    return 0;
}