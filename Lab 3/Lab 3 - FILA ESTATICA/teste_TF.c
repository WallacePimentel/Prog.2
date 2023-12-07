#include <limits.h>
#include "TF.h"
#include "TP.h"

TF * inv_fila (TF * f){
  if (!TF_vazia(f)) return NULL;
  TP * aux_pilha = TP_inicializa();
  TF * aux_fila TF_inicializa();
  while(!TF_vazia(f)) TP_push(aux_pilha,TF_retira(f));
  while(!TP_vazia(aux_pilha)) TF_insere(aux_fila,TP_pop(aux_pilha));
  TP_libera(aux_pilha);
  return aux_fila; 
}

int main(void){
  TF *f = TF_inicializa();
  printf("f:\n");
  int n;
  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    TF_insere(f, n);
  }
  TF_imprime(f);
  printf("\n");
  TF_libera(f);
  return 0;
}
