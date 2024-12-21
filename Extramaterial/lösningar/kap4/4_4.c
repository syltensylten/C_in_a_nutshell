/* 4_4.c */

#include <stdio.h> 
#include <math.h>  

#define T  5730      /* halveringstid för C14 */

int main()
{
  float  n, k, s;

  printf("RADIOAKTIVT SÖNDERFALL\n");
  printf("Ange tid (i år): ");
  scanf("%f", &s);
  k = 0.693/T;
  n = 100*exp(-k*s);
  printf("\nEfter %.1f år återstår %.2f%\n", s, n);
}

