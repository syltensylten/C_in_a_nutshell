/* 4_2.c */

#include <stdio.h>   /* printf(), scanf() */

int main()
{
  int year, leap;

  printf("Skriv ett �rtal: ");
  scanf("%d", &year);
  leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
  printf("%d �r %s skott�r\n", year, leap ? "ett" : "inget");
}

