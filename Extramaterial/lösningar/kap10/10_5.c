/* 10_5.c */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char  *path;

  path = getenv("PATH");
  printf("PATH = %s\n", path);
  exit(0); /* Avslutningskod till operativsystemet */
}
