/* 11_1.c */
/* Skriver ut programparametrarna argv[1] .. p� bildsk�rmen */

#include <stdio.h>     /* printf() */

int main(int argc, char *argv[])
{
  unsigned  i;

  printf("argc har v�rdet %d\n", argc);
  for (i = 0; i < argc; i++)
    printf("argv[%d] har v�rdet %s\n", i, argv[i]);
}
