#include "TP.h"
#include "TF.h"
#include "TLSE.h"

//Funções da Lista 8 da matéria de programação estruturada

//Letra (A)
TP * f2p (TF * f){
  //Verificando se a fila está vazia
  if (TF_vazia(f)) return NULL;
  //Inicializando a pilha final e uma auxiliar para manter a ordem da fila de entrada e saída
  TP * p = TP_inicializa(), *aux = TP_inicializa;
  /*
  Para manter a ordem da fila em que o primeiro da fila é o que sai, coloquei os itens da fila na pilha primeiro em que o ultimo
  item da fila estaria no topo e depois fiz o mesmo processo para outra pilhar, para que o primeiro item da fila estivesse no topo
  da pilha final, dessa forma, respeitando a lógica do enunciado.
  */
  while (!TF_vazia(f)) TP_push(aux,TF_retira(f));
  while(!TP_vazia(aux)) TP_push(p,TP_pop(aux));
  //Liberando a auxiliar e retornando p
  TP_libera(aux);
  return p;
}

//Letra (B)
TF * inv_fila (TF * f){
  //Verificando se a pilha está vazia
  if (!TF_vazia(f)) return NULL;
  //Iniciando uma pilha auxiliar e a fila auxiliar que seria a resposta final
  TP * aux_pilha = TP_inicializa();
  TF * aux_fila TF_inicializa();
   /*
  Aqui eu utilizei uma pilha auxiliar para conseguir inverter a fila, pois se eu utilizasse a função TF_retira e depois TF_insere na
  nova fila, a ordem se manteria a mesma pois na retirada sai o primeiro da fila e na inserção se coloca no ultimo lugar, porem na
  pilha o primeiro iria para a base e o ultimo ficaria no topo, e devido a ordem de entrada e saida da pilha (FIFO) o topo sairia
  primeiro e entraria primeiro na fila final, invertendo ela no processo.
  */
  while(!TF_vazia(f)) TP_push(aux_pilha,TF_retira(f));
  while(!TP_vazia(aux_pilha)) TF_insere(aux_fila,TP_pop(aux_pilha));
  TP_libera(aux_pilha);
  return aux_fila; 
}

//Letra (C)
TF * junta_filas(TF *f1, TF *f2){
  //Verificando se alguma das filas estão vazias, se tiverem retorne a que não está vazia ou NULL
  if (TF_vazia(f1)){
    if (TF_vazia(f2)) return NULL;
    return f2;
  }
  if (TF_vazia(f2)) return f1;
  //Aqui criei duas LSE auxiliares uma para passar pelos elementos da fila e outra para armazená-los
  TLSE * aux = TLSE_inicializa(), *p = TLSE_inicializa();
  p = f1->ini;
  //Passando por todos os elementos da fila 1 e os inserindo na lista auxiliar
  while (p){
    TLSE_insere(aux,p->info);
    p = p->prox;
  }
  p = f2->ini;
  //O mesmo processo anterior só que com a fila 2
  while (p){
    TLSE_insere(aux,p->info);
    p = p->prox;
  }
  //Criando a fila de resposta final
  TF * resp = TF_inicializa()
  //Passando pela auxiliar e colocando todos os seus elementos na fila nova
  while(aux){
    TF_insere(resp,aux->info);
    aux = aux->prox;
  }
  TLSE_libera(aux);
  TLSE_libera(p);
  return resp;
}


//Letra (D)
void retira_pares (TP *p){
  //Verificando se a pilha se encontra vazia
  if(TP_vazia(p)) return;
  //Criando pilhas auxiliares
  TP *aux1 = TP_inicializa(), *aux2 = TP_inicializa();
  //Verificação da pilha original a partir do topo, os pares vão para a pilha auxiliar 2 e o restante para a pilha auxiliar 1
  while (!TP_vazia(p)){
    int x = TP_pop(p);
    if ((x % 2) == 0) TP_push(aux2,x);
    else TP_push(aux1,x);
  }
  /*
  Do jeito que inserimos os elementos na aux1 ela possui o topo da original na sua base e na sua base o topo da original
  e então revertendo o processo sem os elementos pares agora, os elementos retornarão a lista p na ordem correta
  */
  while(!TP_vazia(aux1)) TP_push(p,TP_pop(aux1));
  //Liberando ambos as auxiliares para não ocorrer perda de memória
  TP_libera(aux1);
  TP_libera(aux2);
}

//Letra (E)
TF * p2f (TP * p){
  //Verificando se a pilha se encontra vazia
  if (TP_vazia(p)) return NULL;
  TF * fila = TF_inicializa()
  /*
  Como precisamos seguir a ordem da pilha de que o primeiro elemento a sair da pilha tem que ser o primeiro elemento a sair da fila,
  precisamos somente utilizar a função insere, pois na fila o primeiro item a sair é o primeiro e o primeiro item da fila, utilizando 
  a função inserir será o elemento do topo da pilha até a sua base, seguindo a ordem lógica desejada pelo enunciado
  */
  while (!TP_vazia(p)) TF_insere(fila,TP_pop(p));
  return fila;
}