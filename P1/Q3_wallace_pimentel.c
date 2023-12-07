#include <stdio.h>
#include <stdlib.h>

int **aloca(int lin, int col){
  int **resp = (int **) malloc(sizeof(int *) * lin), i;
  for(i = 0; i < lin; i++)
    resp[i] = (int *) malloc(sizeof(int) * col);
  return resp; 
}

void desaloca(int **mat, int lin){
  int i;
  for(i = 0; i < lin; i++) free(mat[i]);
  free(mat);
}

int* misc(int **mat, int lin, int col){
  /*
  Minha correção nessa foi apenas trocar os valores das variáveis no começo de 0 pra 1, (que já deveria ter sido assim, eu apenas esqueci
  no momento durante a prova) e também alterei o índice no final na criação do vetor resposta, por algum motivo na prova eu criei 
  o indice z e começei a usar um indice i que não existia, agora está correto.
  */
  int a = 1, b = 1, c = 1, d = 1, x, i, j;
  for(i = 0; i < lin; i++){
    x = 0;
    for (j = 0; j < col; j++) x += mat[i][j];
    if (x <= 0) d = 0;
    if (x >= col) a = 0;
  }
  for (j = 0; j < col; j++){
    x = 0;
    for (i = 0; i < lin; i++) x += mat[i][j];
    if (x <= 0) b = 0;
    if (x >= lin) c = 0;
  }
  int final = a + b + c + d + 1, z = 1;
  int * vet = (int *) malloc (sizeof(int) * final);
  if (final <= 1){
    vet[0] = 0;
    return vet;
  }
  vet[0] = final - 1;
  while (z != final){
    if (a){
      vet[z] = 1;
      z++;
    }
    if (b){
      vet[z] = 2;
      z++;
    }
    if (c){
      vet[z] = 3;
      z++;
    }
    if (d) vet[z] = 4;
    return vet;
  }
}

int main(void){
  int n, m;
  while(1){
    scanf("%d%d", &n, &m);
    if((n <= 0) && (m <= 0)) return 0;
    if((n < 2) || (m < 2)) continue;

    int **mat = aloca(n, m), i, j;
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++) scanf("%d", &mat[i][j]);

    int *resp; 
    resp = misc(mat, n, m);
    /*
    Tive que modificar a main na questão 3, pois ela utiliza o resp[0] como restrição do índice do for loop para passar pelo vetor 
    final recebido e imprimí-lo, porém o resp[0] informa quantos casos foram válidos no caso de teste,
    por exemplo: se os 4 casos forem atingidos, o vetor final seria * vet = [4,1,2,3,4], porém utilizando o resp[0] = 4 como
    restrição o for loop só chegaria no índice 3 do vetor e não imprimiria o último elemento, logo, foi necessário essa modificação
    para a resposta sair da forma desejada.
    */
    for(i = 0; i < (resp[0] + 1); i++) printf("%d ", resp[i]);
    printf("\n");
    free(resp); 
  
    desaloca(mat, n);
  } 
}
