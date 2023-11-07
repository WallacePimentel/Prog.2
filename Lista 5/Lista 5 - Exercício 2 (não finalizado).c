#include <stdio.h>
#include <stdlib.h>

int ** mult (int m1, int n1, int **mat1, int m2, int n2, int ** mat2){
	int **mat3,i,j;
	mat3 = (int **) malloc (sizeof(int *) * m1);

	for(i = 0;i < m1; i++){
		mat3[i] = (int *) malloc (sizeof(int) * n2);
	}

	for(i = 0; i < m1; i++){
		for(j = 0; j< n2; j++){
			mat3[i][j] = mat1[i]
		}
	}
}

int main (void){
	int lin1, col1,lin2, col2,i,j;
	int **mat1,**mat2,**matfinal;

	scanf("%d%d%d%d",&lin1,&col1,&lin1,&col2);

	if (col1 != lin2) return 0;

	mat1 = (int **) malloc (sizeof(int *) * lin1);

	for(i = 0; i < lin1; i++){
		mat1[i] = (int *) malloc (sizeof(int) * col1);
	}

	mat2 = (int **) malloc (sizeof(int *) * lin2);

	for(i = 0; i < lin2; i++){
		mat2[i] = (int *) malloc (sizeof(int) * col2);
	}
	for(i = 0; i < lin1; i++){
		for(j = 0; j < col1; j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	for(i = 0; i < lin2; i++){
		for(j = 0; j < col2; j++){
			scanf("%d",&mat2[i][j]);
		}
	}

	matfinal = mult(lin1,col1,mat1,lin2,col2,mat2);

}