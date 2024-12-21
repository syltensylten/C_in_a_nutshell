/* 2_2.c */

#include <stdio.h>   /* printf(), scanf() */

int main()
{
  float  mil_i_fjol, mil_i_dag, lit, mil;

  printf("Aktuell mätarställning: ");
  scanf("%f", &mil_i_dag);
  printf("Mätarställning för ett år sedan: ");
  scanf("%f", &mil_i_fjol);
  printf("Antal liter förbrukade under året: ");
  scanf("%f", &lit);
  mil = mil_i_dag - mil_i_fjol;
  printf("Sträcka som bilen gått under året: %8.2f mil\n", mil);
  printf("Genomsnittlig bensinförbrukning: %8.2f l/mil\n", lit/mil);
}

