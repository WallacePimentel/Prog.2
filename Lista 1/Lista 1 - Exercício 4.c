#include <stdio.h>

int mdc(int a, int b){
    int numt;
    numt = (a > b)? a : b;
    while(numt != 0){
        if(a % numt == 0 && b % numt == 0)break;
        else{
            numt--;
            continue;
        }
    }
    return numt;
}

int main(void){
    int partidas;
    scanf("%d",&partidas);
    while(partidas != 0){
        int f1,f2,result;
        scanf("%d%d",&f1,&f2);
        result = mdc(f1,f2);
        printf("%d",result);
    }    
    return 0;
}