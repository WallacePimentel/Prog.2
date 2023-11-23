#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prod{
  char misc[51];
  float preco;
}TPROD;

int char_cmp (const void * p1, const void * p2){
	char *c1 = (char *) p1;
	char *c2 = (char *) p2;
	return strcmp(c1,c2);	
}

void ordena_a(TPROD **vet, int n){
	

}

int main(void){
  int n;
  do{
    scanf("%d", &n);
    if(n > 0)break;
  }while(1);

  TPROD **vet = (TPROD **) malloc(sizeof(TPROD *) * n);
  int i;
  for(i = 0; i < n; i++){
    vet[i] = (TPROD *) malloc(sizeof(TPROD));
    scanf(" %50[^\n]", vet[i]->misc);
    scanf("%f", &vet[i]-> preco);
  }
  ordena_a(vet, n);
  for(i = 0; i < n; i++){
    printf("%s\t%f\n", vet[i]->misc, vet[i]-> preco);
    free(vet[i]);
  }
  free(vet);

  return 0;
}