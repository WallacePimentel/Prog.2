#include <stdio.h>

int main(void){
    /*
    Nessa main, modifiquei o "y = x" faltando na condição do else para atualizar e também coloquei o contador como 1 para não pular a
    contagem do elemento que quebrou o ultimo ciclo. Como por exemplo: 1 3 5 1 3, nesse exemplo, apos o segundo 1 quebrar o ciclo ele
    não seria contabilizado para a proxima contagem.
    Também, para propósito de maior clareza, alterei o nome das variáveis principais para ficar mais claro o seu papel no código.
    */
    int n;
    while(1){
        scanf("%d",&n);
        if (n <= 0) return 0;
        int atual = 0, anterior = 0, contador = 0, sentinela_maior = 0;
        do{
            scanf("%d",&atual);
            if(anterior == 0){
                contador++;
                anterior = atual;
                continue;
            }
            else{
                if (atual > anterior){
                    contador++;
                    anterior = atual;
                }
                /*
                Aqui também utilizei um temporario para guardar a maior contagem antes do contador ser resetado
                */
                else{
                    if (contador > sentinela_maior) sentinela_maior = contador;
                    contador = 1;
                    anterior = atual;
                }
            }
            //Aqui uma verificação caso toda a sequência seguisse a regra e nunca entrasse no else
            if(sentinela_maior == 0) sentinela_maior = contador;
            n--;
        }while(n > 1);
        printf("%d",sentinela_maior);
    }
    return 0;
}