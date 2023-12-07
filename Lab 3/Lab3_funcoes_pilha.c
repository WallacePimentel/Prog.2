#include "TP.h"
#include "TLSE.h"

//------QUESTÃO-3.1-E-3.2------//

void mult_k (TP *p, int k){
  if (TP_vazia(p)) return;
  TP *aux1 = TP_inicializa(), *aux2 = TP_inicializa();
  while(!TP_vazia(p)){
    int x = TP_pop(p);
    if ((x % k) == 0) TP_push(aux2,x);
    else TP_push(aux1,x);
  }
  while(!TP_vazia(aux1)){
    TP_push(p,TP_pop(aux1));
  }
  TP_libera(aux1);
  TP_libera(aux2);
}

TP * mult_k2 (TP *p, int k){
    if (TP_vazia(p)) exit(1);
    TP *aux1 = TP_inicializa(), *aux2 = TP_inicializa(), *resp = TP_inicializa();
    while(!TP_vazia(p)){
        int x = TP_pop(p);
        if ((x % k) == 0) TP_push(aux2,x);
        else TP_push(aux1,x);
    }
    while(!TP_vazia(aux1)){
        TP_push(resp,TP_pop(aux1));
    }
    TP_libera(aux1);
    TP_libera(aux2);
    return resp;
}