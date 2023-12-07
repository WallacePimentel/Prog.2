#include <stdio.h>
#include <stdlib.h>

typedef struct PILHA{
    int topo, vet[100];
}TP;

TP * TP_inicializa(void);
int TP_vazia (TP *p);
int TP_pop(TP *p);
void TP_libera(TP *p);
void TP_push(TP *p, int x);
void TP_imprime(TP *p);
