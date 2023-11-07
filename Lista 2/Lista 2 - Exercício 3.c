//Author: Wallace Pimentel. Date: 23.10.2023
//List 2: Task 3

#include <stdio.h>

void binario (int num){
    if (num < 0) return;
    if (num < 2) printf("%d",num);
    else{
        binario(num/2);
        printf("%d",num % 2);
    }
}

int main(void){
    int num;
    do{
        scanf("%d",&num);
        binario(num);
        printf("\n");
    }while(num >= 0);
    return 0;
}