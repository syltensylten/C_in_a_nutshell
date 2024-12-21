/* 3_4.c */

#include <stdio.h>   /* printf(), putchar(), scanf() */

int main()
{
  char  ord[81];
  int   len, i;

  printf("Skriv ett ord: ");
  scanf("%s", ord);

  /* Nedanstående för skrivare, på bildskärm överskrivs texten. */
  printf("%s", ord);
  putchar('\r');
  len = 0;
  while (ord[len] != '\0') {
    len++;
  }
  for (i = 0; i < len; i++) {
    putchar('_');
  }
  putchar('\n');
}
