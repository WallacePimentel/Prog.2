#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
char nome[31];
char mat[10], turma[3];
float p1, p2;
}TALUNO;

void imprime (TALUNO **mat, int n){
  int i;
  for(i = 0; i < n; i++){
    if((((mat[i]->p1) + (mat[i]->p2))/2) >= 6) printf("%s\n",mat[i]->nome);
  }
}

int main(void){;
  int n, i;
  scanf(" %d",&n);
  if(n <= 0) return 0;

  TALUNO ** al = (TALUNO **) malloc (sizeof(TALUNO *) * n);

  for(i = 0; i < n; i++){
    al[i] = (TALUNO *) malloc (sizeof(TALUNO));
    scanf(" %30[^\n]s",al[i]->nome);
    scanf(" %9[^\n]s",al[i]->mat);
    scanf(" %2[^\n]s",al[i]->turma);
    scanf(" %f %f",&al[i]->p1,&al[i]->p2);
  }

  imprime(al,n);
  for(i = 0; i < n; i++) free(al[i]);
  free(al);
  return 0;
}