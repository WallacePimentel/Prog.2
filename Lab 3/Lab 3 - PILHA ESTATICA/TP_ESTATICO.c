#include "TP_ESTATICO.h"

TP * TP_inicializa(void){
    TP *p =  (TP *) malloc (sizeof(TP));
    p->topo = 0
}

int TP_vazia(TP *p){
    return p->topo == 0;
}

int TP_pop(TP *p){
    if (TP_vazia(p)) exit(1);
    int resp = p->vet[(--p->topo)];
    return resp;
}

void TP_libera(TP *p){
    free(p);
}

void TP_push(TP *p, int x){
    if (p->topo > 100) return;
    p->vet[topo++] = x;
}

void TP_imprime(TP *p){
    if (TP_vazia(p)) return;
    int i;
    for(i = 0; i < 100; i++) printf("%d",p->vet[i]);
}

