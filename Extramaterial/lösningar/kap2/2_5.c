/* 2_5.c */

#include <stdio.h>     /* printf(), scanf() */

#define  MINSUM   1000
#define  RABATT   0.10

int main()
{
  float  pris;
  int    num;

  printf("Ange antal köpta enheter: ");
  scanf("%d", &num);
  printf("Ange pris per enhet (i kr): ");
  scanf("%f", &pris);
  pris = pris*num;             /* pris *= num; */
  if (pris >= MINSUM) {
    pris = pris*(1 - RABATT);  /* pris *= (1 - RABATT); */
  }
  printf("\nAtt betala: %6.2f kr\n", pris);
}
