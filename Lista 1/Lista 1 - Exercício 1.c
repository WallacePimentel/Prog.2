#include <stdio.h>

int primo(int x){
    int i;
    for (i = 2; i <= x/2; i++){
    if (x % i == 0)return 0;
    }
    return 1;
}


int main(void){

    int n, i;
    do{
        scanf("%d",&n);
        for(i = 2; i <= n; i++){
            if (primo(i) == 1) printf("%d\n",i);
        }
    }while(n > 0);
    return 0;
}