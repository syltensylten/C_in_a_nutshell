/* 2_7.c */

#include <stdio.h>   /* printf(), scanf(), EOF */

int main()
{
  char  word[256];

  printf("Skriv in ord, separerade med blank-, tabulator-\n");
  printf("och/eller nyradstecken. Avsluta med EOF.\n");
  while (scanf("%s", word) == 1) {
    printf("%s\n", word);
  }
}

