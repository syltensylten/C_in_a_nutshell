/* 2_2.c */

#include <stdio.h>   /* printf(), scanf() */

int main()
{
  float  mil_i_fjol, mil_i_dag, lit, mil;

  printf("Aktuell m�tarst�llning: ");
  scanf("%f", &mil_i_dag);
  printf("M�tarst�llning f�r ett �r sedan: ");
  scanf("%f", &mil_i_fjol);
  printf("Antal liter f�rbrukade under �ret: ");
  scanf("%f", &lit);
  mil = mil_i_dag - mil_i_fjol;
  printf("Str�cka som bilen g�tt under �ret: %8.2f mil\n", mil);
  printf("Genomsnittlig bensinf�rbrukning: %8.2f l/mil\n", lit/mil);
}

