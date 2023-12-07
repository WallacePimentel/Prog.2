#include "TP.h"

void imprime(TP *p){
  if(TP_vazia(p)) return;
  TP *aux = TP_inicializa();
  while(!TP_vazia(p)){
       int x = TP_pop(p);
       printf("%d ", x);
       TP_push(aux, x);
  }
  printf("\n");
  while(!TP_vazia(aux))
      TP_push(p, TP_pop(aux));
  TP_libera(aux);
}

void retira_pares (TP *p){
  if(TP_vazia(p)) return;
  TP *aux1 = TP_inicializa(), *aux2 = TP_inicializa();
  while (!TP_vazia(p)){
    int x = TP_pop(p);
    if ((x % 2) == 0) TP_push(aux2,x);
    else TP_push(aux1,x);
  }
  while(!TP_vazia(aux1)) TP_push(p,TP_pop(aux1));
  TP_libera(aux1);
  TP_libera(aux2);
}

int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    imprime(p);
    printf("\n");
    TP_libera(p);

  return 0;
}
