/* 4_4.c */

#include <stdio.h> 
#include <math.h>  

#define T  5730      /* halveringstid f�r C14 */

int main()
{
  float  n, k, s;

  printf("RADIOAKTIVT S�NDERFALL\n");
  printf("Ange tid (i �r): ");
  scanf("%f", &s);
  k = 0.693/T;
  n = 100*exp(-k*s);
  printf("\nEfter %.1f �r �terst�r %.2f%\n", s, n);
}

