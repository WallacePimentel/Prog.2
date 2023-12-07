#include "TF_EST.h"

TF * TF_inicializa(void){
    TF * f = (TF *) malloc (sizeof(TF));
    f->ini = 0;
    f->fim = 0;
    return f;
}

int TF_vazia(TF *f){
    return f->ini == 0;
}

int TF_retira(TF *f){
    if (TF_vazia(f)) exit(1);
    int resp = f->vet[f->ini];
    
}