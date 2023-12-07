#include "TLSE.h"

//------QUESTÃO-1------//
void inverte1 (TLSE *l){
  if (!l) return;
  TLSE *aux = l, *invertida = TLSE_inicializa();
  while(aux){
    invertida = TLSE_insere(invertida,aux->info);
    aux = aux->prox;
  }
  while(l && invertida){
    l->info = invertida->info;
    l = l->prox;
    invertida = invertida->prox;
  }
  TLSE_libera(invertida);
}

//------QUESTÃO-2------//
TLSE* inverte2 (TLSE *l){
  if (!l) return NULL;
  TLSE *invertida = TLSE_inicializa();
  while(l){
    invertida = TLSE_insere(invertida,l->info);
    l = l->prox;
  }
  return invertida;
}


//------QUESTÃO-3------//
TLSE *desloca (TLSE *l, int n){
  if (!l) return NULL;
  if (!l->prox) return l;
  TLSE *resp = l;
  if ((n % 2) == 0){
    int primeiro = l->info;
    while(l->prox){
      l->info = l->prox->info;
      l = l->prox;
    }
    l->info = primeiro;
    return resp;
  }
  else{
    TLSE *aux = l;
    int ultimo;
    while(aux){
      if (!aux->prox) ultimo = aux->info;
      aux = aux->prox;
    }
    while(l){
      if (l->prox){
        l->prox->info = l->info;
      }
      l = l->prox;
    }
    resp->info = ultimo;
    return resp;
  }
}

//------QUESTÃO-4------//
TLSE* copia (TLSE *l){
  TLSE *copia = (TLSE *) malloc (sizeof(TLSE));
  TLSE *aux = l;
  TLSE *inicio = copia;

  while(aux){
    copia->info = aux->info;
    if (aux->prox){
      copia->prox = (TLSE *) malloc (sizeof(TLSE));
      copia = copia->prox;
    }
    aux = aux->prox;
  }
  return inicio;
}

//------QUESTÃO-5------//
TLSE* rto (TLSE *l, int elem){
    if(!l) exit(1);
    TLSE *aux = l, *anterior = NULL;
    while(l){
        if((l->info) == elem){
          if(l->prox){
            TLSE *temp = l;
            l = l->prox;
            free(temp);
          }
          else free(l);
        }
        else l = l->prox;
    }
    return aux;
}

//------QUESTÃO-6------//
TLSE* i_p1 (TLSE *l){
    TLSE *impar = TLSE_inicializa(), *par = TLSE_inicializa(), *resp = TLSE_inicializa();
    while (l){
        if (l->info % 2 == 0){par = TLSE_insere(par, l->info);}
        else impar = TLSE_insere(impar, l->info);
        l = l->prox;
    }
    while (par){
        resp = TLSE_insere(resp, par->info);
        par = par->prox;
    }
    while (impar){
        resp = TLSE_insere(resp, impar->info);
        impar = impar->prox;
    }

    TLSE_libera(par);
    TLSE_libera(impar);
    return resp;
}

//------QUESTÃO-7------//
void i_p2 (TLSE *l){
  TLSE *marcador = l;
  TLSE *impar = TLSE_inicializa(), *par = TLSE_inicializa(), *resp = TLSE_inicializa();
  while (l){
      if (l->info % 2 == 0){par = TLSE_insere(par, l->info);}
      else impar = TLSE_insere(impar, l->info);
      l = l->prox;
  }
  while (par){
      resp = TLSE_insere(resp, par->info);
      par = par->prox;
  }
  while (impar){
      resp = TLSE_insere(resp, impar->info);
      impar = impar->prox;
  }
  while(resp){
    marcador->info = resp->info;
    marcador = marcador->prox;
    resp = resp->prox;
  }

  TLSE_libera(par);
  TLSE_libera(impar);
  TLSE_libera(resp);
}

//------QUESTÃO-8------//
int igual (TLSE *l1, TLSE *l2){
  TLSE *aux1 = l1, *aux2 = l2;
  if(!aux1){
    if(!aux2) return 1;
    else return 0;
  }
  if(!aux2) return 0;
  while(aux1){
    if (aux1->info != aux2->info) return 0;
    if (!aux1->prox){
      if(!aux2->prox) return 1;
      else return 0;
    }
    if(!aux2->prox) return 0;
    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }
  return 1;
}

//------QUESTÃO-9------//
TLSE* junta_listas (TLSE *l1, TLSE* l2){
  if(!l1){
    if(!l2) return NULL;
    else return l2;
  }
  if(!l2) return l1;
  TLSE *aux1 = l1, *aux2 = l2, *resp = (TLSE *) malloc (sizeof(TLSE)); 
  TLSE *inicioresp = resp;
  while(aux1){
    resp->info = aux1->info;
    if (aux1->prox){ 
      resp->prox = (TLSE *) malloc (sizeof(TLSE));
      resp = resp->prox;
    }
    aux1 = aux1->prox;
  }
  resp->prox = (TLSE *) malloc (sizeof(TLSE));
  resp = resp->prox;
  while(aux2){
    resp->info = aux2->info;
    if (aux2->prox){ 
      resp->prox = (TLSE *) malloc (sizeof(TLSE));
      resp = resp->prox;
    }
    aux2 = aux2->prox;
  }
  return inicioresp;
}

//------QUESTÃO-10------//
int contrario (TLSE *l1, TLSE *l2){
  if(!l1){
    if(!l2) return 1;
    else return 0;
  }
  if(!l2) return 0;
  TLSE *inv_l1 = TLSE_inicializa();
  TLSE *aux1 = l1, *aux2 = l2;
  while(aux1){
    inv_l1 = TLSE_insere(inv_l1,aux1->info);
    aux1 = aux1->prox;
  }
  while(inv_l1 && aux2){
    if(inv_l1->info != aux2->info) return 0;
    inv_l1 = inv_l1->prox;
    aux2 = aux2->prox;
  }
  if (inv_l1 || aux2){
    TLSE_libera(inv_l1);
    return 0;
  }
  TLSE_libera(inv_l1);
  return 1;
}

int Contrario_2 (TLSE *l1, TLSE *l2){
    TLSE *inverso_l2 = TLSE_insere(NULL, l2->info);
    l2 = l2->prox;
    while (l2){
          inverso_l2 = TLSE_insere(inverso_l2, l2->info);
          l2 = l2->prox;
    }
    while (l1 && inverso_l2){
        if(l1->info != inverso_l2->info){TLSE_libera(inverso_l2); return 0;}
        l1 = l1->prox;
        inverso_l2 = inverso_l2->prox;
    }
    if(l1 || inverso_l2) {TLSE_libera(inverso_l2); return 0;}
    TLSE_libera(inverso_l2);
    return 1;
}

//------QUESTÃO-11------//
TLSE *ordena (TLSE *l){
  if (!l) return l;
  TLSE *l_ord = copia(l);
  TLSE *p;
  for(p = l_ord;p;p = p->prox){
    TLSE *menor = p, *q;
    for(q = p->prox; q; q = q->prox){
      if(menor->info > q->info) menor = q;
    }
    if (menor != p){
      int tmp = p->info;
      p->info = menor->info;
      menor->info = tmp;
    }
  }
  return l_ord;
}

