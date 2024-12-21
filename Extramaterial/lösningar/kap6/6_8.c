/* 6_8.c */

/* Test */
#include <stdio.h> 
#include "slump.h"

int main()
{
  unsigned  antal, kast, antal_krona = 0;

  printf("Ange antal kast: "); scanf("%u", &antal);
  for (kast = 0; kast < antal; kast++) {
    if (krona_klave()) {
      antal_krona++;
    }
  }
  printf("\nRelativa frekvensen för:\n");
  printf("Krona = %.0f %%\n", 100.0 * antal_krona / antal);
  printf("Klave = %.0f %%\n", 100.0 * (antal - antal_krona) / antal);
}
