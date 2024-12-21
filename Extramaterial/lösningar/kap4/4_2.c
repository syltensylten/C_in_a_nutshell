/* 4_2.c */

#include <stdio.h>   /* printf(), scanf() */

int main()
{
  int year, leap;

  printf("Skriv ett årtal: ");
  scanf("%d", &year);
  leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
  printf("%d är %s skottår\n", year, leap ? "ett" : "inget");
}

