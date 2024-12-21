/* 5_8.c */
/* Primtalsberäkning med "råräkningsmetod" */

#include <stdio.h>   

int main()
{
  unsigned int max, d, i, numPrimes = 0;

  printf("PRIMTAL\n");
  printf("Ange största tal som ska undersökas: ");
  scanf("%u", &max);
  for (i=2; i<= max; i++) {
    for(d = 2; d < i ; d++) {
      if (i % d == 0) {
        break;
      }
    }
    if (d == i) {
      printf("%8u", i);
      numPrimes++;
    }
  }
  printf("\n%u primtal utskrivna\n", numPrimes);
}
