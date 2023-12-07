#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
  int mat;
  char data_nasc[9];
  char nome[31];
}TP;

int comparador (const void *i1, const void *i2){
  /*
  Na função comparador, apenas corrigi colocando as comparações mais restritas antes das menos restritas e também otimizei a comparação,
  pois eu estava criando strings proprias pra fazer o dia, mês e ano, porém isso é redundante pois após comparar o ano, se comparar o mês
  com o ano junto, o ano não dara conflito pois se eles fossem diferentes ja teria saido do loop previamente, e também coloquei o & antes
  das strings com índice para funcionar.
  */
  TP ** pp1 = (TP **) i1;
  TP ** pp2 = (TP **) i2;
  TP *p1 = (*pp1), *p2 = (*pp2);

  if(strcmp(&p1->data_nasc[4],&p2->data_nasc[4]) < 0) return -1;
  if(strcmp(&p1->data_nasc[4],&p2->data_nasc[4]) > 0) return 1;

  if(strcmp(&p1->data_nasc[2],&p2->data_nasc[2]) < 0) return -1;
  if(strcmp(&p1->data_nasc[2],&p2->data_nasc[2]) > 0) return 1;

  if(strcmp(p1->data_nasc,p2->data_nasc) < 0) return -1;
  if(strcmp(p1->data_nasc,p2->data_nasc) > 0) return 1;

  if(strcmp(p1->nome,p2->nome) < 0) return -1;
  if(strcmp(p1->nome,p2->nome) > 0) return 1;

  if ((p1->mat) < (p2 -> mat)) return -1;
  return 1;
}

TP* retira_k(TP **vet, int n, int k){
  /*
  Na função retira, ordenei um vetor auxiliar invés do original, guardei o elemento igual fiz antes e invés de fazer todos os elementos
  após o k-ésimo o sobreporem, apenas tornei o k-ésimo elemento como NULL
  */
  TP ** vet_aux = (TP **) malloc (sizeof(TP *) * n);
  int i;
  for(i = 0; i < n; i++){
    vet_aux[i] = vet[i];
  }
  qsort(vet_aux,n,sizeof(TP *),comparador);
  TP * temp = vet_aux[k-1];
  for(i = 0; i < n; i++){
    if ((vet[i]->mat) == (temp->mat)){
      vet[i] = NULL;
      break;
    }
  }
  free(vet_aux);
  return temp;
}

int main(void){
  int n;
  printf("Digite o tamanho do vetor... ");
  scanf("%d", &n);
  if(n <= 0) return 0;
  TP* elem, *vet[n];
  int i = 0;
  while(i < n){
    elem = (TP *) malloc(sizeof(TP));
    printf("Digite os dados (insc, data e nome) do candidato...\n");
    scanf("%d", &elem->mat);
    scanf(" %8[^\n]", elem->data_nasc);
    scanf(" %30[^\n]", elem->nome);
    vet[i++] = elem;
  }
  printf("Digite a posicao do elemento a ser retirado... ");
  int k;
  scanf("%d", &k);
  elem = NULL;
  elem = retira_k(vet, n, k);
  free(elem);
  printf("Depois de retira_k:\n");
  for(i = 0; i < n; i++) 
    if(vet[i]) printf("%d %s %s\n", vet[i]->mat, vet[i]->data_nasc, vet[i]->nome);
  for(i = 0; i < n; i++) 
    free(vet[i]);
  return 0; 
}
