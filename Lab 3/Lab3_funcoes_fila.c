#include "TF.h"
#include "TLSE.h"

//------QUESTÃO-3.3-E-3.4------//

void mult_k3 (TF *f, int k){
    if (TF_vazia(f)) exit(1);
    TF *aux1 = TF_inicializa();
    TF *aux2 = TF_inicializa();
    while(!TF_vazia(f)){
        int x = TF_retira(f);
        if ((x % k) == 0) TF_insere(aux2,x);
        else TF_insere(aux1,x);
    }
    while(!TF_vazia(aux1)) TF_insere(f,TF_retira(aux1));
    TF_libera(aux1);
    TF_libera(aux2);
}

TF* mult_k4 (TF *f, int k){
  if (TF_vazia(f)) exit(1);
  TF *aux1 = TF_inicializa();
  TF *aux2 = TF_inicializa();
  TF *resp = TF_inicializa();
  while(!TF_vazia(f)){
      int x = TF_retira(f);
      if ((x % k) == 0) TF_insere(aux2,x);
      else TF_insere(aux1,x);
  }
  while(!TF_vazia(aux1)) TF_insere(resp,TF_retira(aux1));
  TF_libera(aux1);
  TF_libera(aux2);
  return resp;
}