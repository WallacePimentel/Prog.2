#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
char nome[31];
char mat[10], turma[3];
float p1, p2;
}TALUNO;

float media_geral (TALUNO **mat, int n, char *turma_desejada){
  float somatorio = 0, media, contador = 0;
  int i;
  for(i = 0; i < n; i++){
    if((mat[i]->turma) == (turma_desejada)){
      somatorio += ((mat[i]->p1) + (mat[i]->p2));
      contador++;
    }
  }
  if (!contador) return 0.0;

  media = somatorio / contador;
  return media; 
}

int main(void){
  TALUNO **al;
  int n, i;
  scanf(" %d",&n);
  if(n <= 0) return 0;

  al = (TALUNO **) malloc (sizeof(TALUNO *) * n);

  for(i = 0; i < n; i++){
    al[i] = (TALUNO *) malloc (sizeof(TALUNO));
    printf("Nome do aluno %d : ",i + 1);
    scanf(" %30[^\n]s",&al[i]->nome);
    printf("Numero de matricula: ");
    scanf(" %9[^\n]s",&al[i]->mat);
    printf("Numero da turma: ");
    scanf(" %2[^\n]s",&al[i]->turma);
    printf("Notas 1 e 2: ");
    scanf(" %f %f",&al[i]->p1,&al[i]->p2);
  }

  char turma_desejada[3];
  printf("Digite a turma: ");
  scanf(" %2[^\n]s",&turma_desejada);

  float media_final;

  media_final = media_geral(al,n,turma_desejada);
  printf("%f",media_final);
  for(i = 0; i < n; i++) free(al[i]);
  free(al);
  return 0;
}