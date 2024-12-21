/* 9_2.c */

#include <stdio.h>

#define ABS(x) ((x) < 0 ? (-x) : (x))

int main()
{
  float  tal;

  printf("Ange ett tal: "); scanf("%f", &tal);
  while (tal != 0.0) {
    printf("|%f| = %f\n", tal, ABS(tal));
    printf("Ange ett tal/<0>: "); scanf("%f", &tal);
  }
}
