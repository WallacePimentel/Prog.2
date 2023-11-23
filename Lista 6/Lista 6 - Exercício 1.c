#include <stdio.h>
#include <stdlib.h>

typedef struct TPTO2D{
    int x;
    int y;
}TPTO2D;

int dentroRet (TPTO2D *inf, TPTO2D *sup, TPTO2D *p){
  if ((inf->x) < (p->x)) && ((p->x) < (sup->x)) && ((inf->y) < (p->y)) && ((p->y) < (sup->y)) return 1;
  return 0;
}

int main(void){
  TPTO2D *inf, *sup, *p;

  inf = (TPTO2D *) malloc (sizeof(TPTO2D));
  sup = (TPTO2D *) malloc (sizeof(TPTO2D));
  p = (TPTO2D *) malloc (sizeof(TPTO2D));

  scanf(" %d %d",&inf->x,&inf->y);
  scanf(" %d %d",&sup->x,&sup->y);
  scanf(" %d %d",&p->x,&p->y);

  if (dentroRet(inf, sup, p)) printf("O ponto P esta dentro do retangulo!");
  else printf("O ponto P nao esta dentro do retangulo!");
  free(inf);
  free(sup);
  free(p);
  return 0;
}