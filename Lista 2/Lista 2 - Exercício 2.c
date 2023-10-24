//Author: Wallace Pimentel. Date: 23.10.2023
//List 2: Task 2

#include <stdio.h>
#include <math.h>

void palindromo (int n){
    int temp = n,ver = 0,resto;
    while (temp > 0){

            resto = temp % 10;
            ver = (ver * 10) + resto;
            temp = temp / 10;
        }
    if (ver == n) printf("Verdadeiro\n");
    else printf("Falso\n");
}

int main(void){
    int num;
    do{
        scanf("%d",&num);
        palindromo(num);
    }while(num >= 0);
    return 0;
}