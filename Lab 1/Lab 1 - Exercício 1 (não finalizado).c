#include <stdio.h>
#include <stdlib.h>

int * add (int *vet, int n, int x){
	int i, contador = 0,n2,*vet_final,j;
	for(i = 0;i < n; i++){
		if (vet[i] == x) contador++;
	}
	n2 = n + (2 * contador);

	vet_final = (int *) malloc (sizeof(int) * n2);

	for(i = 0, j = 0; i < n; i++){
		if (vet[i] == x){
			vet_final[j] = vet[i] - 1;
			vet_final[j] = vet[i + 1];
			vet_final[j] = vet[i + 2] + 1;
			j++;
		}
		else{
			vet_final[j] = vet[i];
			j++;
		}
	
	for(i = 0; i < n2; i++) printf("%d",vet_final[i]);
	}
	return vet_final;
}

int main (void){
	int n;
	scanf("%d",&n);
	if (n <= 0) return 0;

	int vet[n],i;

	for(i = 0; i < n; i++) scanf("%d",&vet[i]);

	int x;
	scanf("%d",&x);

	int *vet_final;
	vet_final = add(vet,n,x);
}