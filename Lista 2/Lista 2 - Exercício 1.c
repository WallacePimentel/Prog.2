#include <stdio.h>

int mpow(int x, int y){
     int res = 1;
     for(;y > 0;y--){
         res *= 10;
     }
     return res;
 }

int cont(int n){
    int c = 0;
    while (n > 1){
        n /= 10;
        c++;
    }
    return c;
}

int prop(int n){
    int c = cont(n);
    int n1,n2,res,numt;
    n2 = n % 100;
    n1 = n / mpow(10,(c-2));
    res = (n1 * n1) + (2 * n1 * n2) + (n2 * n2);
    numt = (n1 * 100) + n2;
    if (numt == res)
        return 1;
    else 
        return 0;
}

int main(void){
    int num,resultado;
    do{
        scanf("%d",&num);
        printf("%d ",prop(num));
    }while(num >= 0);
    
    return 0;
}