/* 11_1.c */
/* Skriver ut programparametrarna argv[1] .. på bildskärmen */

#include <stdio.h>     /* printf() */

int main(int argc, char *argv[])
{
  unsigned  i;

  printf("argc har värdet %d\n", argc);
  for (i = 0; i < argc; i++)
    printf("argv[%d] har värdet %s\n", i, argv[i]);
}
