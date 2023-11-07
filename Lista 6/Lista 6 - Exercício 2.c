#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
char nome[31];
char mat[10], turma[3];
float p1, p2;
}TALUNO;

void imprime (TALUNO **mat, int n){

	int i;
	for(i = 0; i < n;i++){
		if (((mat[i]->p1) + (mat[i]->p2)/2) >= 6){
			printf("%s",mat[i]->nome);
		}
	}

}

int main (void){
	TALUNO **matriz;
	int n, i;
	scanf("%d",&n);
	matriz = (TALUNO **) malloc (sizeof(TALUNO *) * n);

	for(i = 0;i < n; i++){
		scanf("%30[^\n]s",&matriz[i]->nome);
		scanf("%30[^\n]s",&matriz[i]->mat);
		scanf("%30[^\n]s",&matriz[i]->turma);
		scanf("%f%f", &matriz[i]->p1,&matriz[i]->p2);
	}
	imprime(matriz,n);
	return 0;
}