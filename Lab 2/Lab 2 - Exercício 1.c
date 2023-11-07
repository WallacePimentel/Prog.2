#include <stdio.h>
#include <stdlib.h>

int * mat2vet(int ** mat, int lin, int col){
    int * vet, z = (lin * col), i, j, k = 0;
    vet = (int *) malloc (sizeof(int) * (z));
    for(i = 0; i < lin; i++){
        for (j = 0; j < col; j++){
            vet[k] = mat[i][j];
            k++;
        }
    }
    return vet;
}

int main(void){
    int **mat,*vet_final;
    int lin, col;
    scanf("%d%d",&lin,&col);
    if (lin <= 0)return 0;
    else if (col <= 0)return 0;
    else{
        mat = (int **) malloc (sizeof(int *) * lin);
        int i,j;
        for(i = 0; i < lin; i++){
            mat[i] = (int *) malloc (sizeof(int) * col);
        }
        for(i = 0; i < lin; i++){
            for(j = 0; j < col; j++){
                scanf("%d",&mat[i][j]);
            }
        }
        vet_final = mat2vet(mat,lin,col);
        for(i = 0; i < (lin * col); i++) printf("%d\t",vet_final[i]);
        free(mat);
        free(vet_final);
    }return 0;
}